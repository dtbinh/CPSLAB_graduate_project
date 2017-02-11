% CCMH with obstacle avoidance
yalmip('clear');
clc; clear;
%% -- [ settings ] -- %
% Initialize - the motion of the target
pseq=8+[0,-2;-1,3;3,5;9,5;10,6;12,7;15,8;11,13;11,15]';
pseq = [0,8;8,15;15,17;20,20;30,20;30,30;30,40;17,43;30,45;45,40;50,30;50,40]';
pseq=[interp(pseq(1,:),10);interp(pseq(2,:),10)];
pseq = pseq(:,1:2:end);
p = pseq(:,1);%[2,7]'; 
% robot's position
s = [-2,4]'; phi=pi*0.4;
T = 1;
pS = [s;phi];

% estimatimation (mean, covariance matrix)
pT_est = p;
sigT = eye(2)*1^2;
pModel=1;

% sensor model
RS = 15; ThetaS = 57/180*pi; 
sensor_model = [RS, ThetaS];
NBOUND = 4; % N-sided appproximated sensing region

% directions of visibility-lines of a laser scanner
ThetaL=135/180*pi; RL=10; % field of view and range
angleL_res = 100;
angleL = phi+linspace(-ThetaL,ThetaL,angleL_res);

% Robot's dynamic model
VMAX_const = 7;
VMIN=-5;
Urng = [-pi/2,pi/2]; Vrng = [VMIN, VMAX_const];
[uvseeds, uwseeds]=meshgrid(linspace(Vrng(1)+0.1,Vrng(2)-0.1,3),linspace(Urng(1)-pi/10,Urng(2)+pi/10,3));
H=5; % horizon
numseeds=9;
ctrlseeds_init = [repmat(uvseeds(:),[1,H]),repmat(uwseeds(:),[1,H])]';
ctrlseeds = ctrlseeds_init;

% Thresholds for CCMH
EPSILON_UP = 3; 
EPSILON_LOW = 0; 

% directions of control-lines of a sensor 
angleC_res = 20;
uw_seed = linspace(-pi/2,pi/2,angleC_res);
angleC = (phi + uw_seed/2*T); %linspace(0,2*pi,angleS_res);
dirL = [cos(angleL'),sin(angleL')];% fr

% obstacles
load('maps/map1.mat');
%{
[ox, oy] = meshgrid(linspace(-0.3,0.3,20),linspace(-0.3,0.3,20));
obs_unit = [ox(:)';oy(:)';ones(size(ox(:)'))]; % unit
obs_trans = [-10,2;1.5,2;3,2;10,10;20,5]'; % position of obstacles
obs_ang = [0,pi/3,0,pi/7,0]; % angle of obstacles
obs_scale = [1.5,3,3,5,3]; % scale
obs_points = [];
for ii=1:numel(obs_ang)
    R = [cos(obs_ang(ii)), sin(obs_ang(ii)) obs_trans(1,ii); -sin(obs_ang(ii)), cos(obs_ang(ii)), obs_trans(2,ii); 0,1,1];
    obs_unit_scale= obs_unit*obs_scale(ii);
    obs_unit_scale(3,:) = 1;
    obs_points = [obs_points, R*obs_unit_scale];
end
obs_points(3,:) = [];
%}

% draw
plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
plot(pseq(1,:),pseq(2,:),'b+-'); hold off;
axis equal;
pause(0.1);

pSlog = []; pTlog = []; problog=[];
%% ---- [ Start target tracking ] -- %
% robot's position
tt = 10;
s = pseq(:,tt)-[2,2]'; phi=pi*0.4;
T = 1;
pS = [s;phi];
for timestamps = tt:length(pseq)-H-1-15%30
   % the current position of the target
    %p=pseq(:,timestamps);
    pT_est =pseq(:,timestamps+1);
    
    % set control headings
    angleL = phi+linspace(-ThetaL,ThetaL,angleL_res); % sensing region of laser scanner
    angleC = (phi + uw_seed/2*T);
    dirL = [cos(angleL'),sin(angleL')];% fr
    angleS = phi+linspace(-ThetaS/2,ThetaS/2,angleL_res); 
    
    % -- [ Sense environments (obstacles) ] -- %
    % distance between the sensor and obstacles
    tmp = [pdist2(s',gmap.obspoints'); atan2(gmap.obspoints(2,:)-s(2),gmap.obspoints(1,:)-s(1))];
    DL = inf*ones(1,angleL_res);
    threshold_ang = cos((angleL(1)-angleL(2)));
    for ii=1:size(tmp,2)
        [diff,jj] = max(cos(tmp(2,ii)-angleL));
        if(diff > threshold_ang)
            DL(jj) = min(DL(jj),tmp(1,ii));
        end
    end
    DL(DL>RL)=inf;
    
    % -- [Regression of an occupancy map using GP] -- %
    % select grid map near the current position
    idxs_x = zeros(1,2);
    idxs_x(1) = find(gmap.xaxis>= min(pT_est(1,:)) | gmap.xaxis>= pS(1)- Vrng(2)*H*T,1,'first');
    idxs_x(2) = find(gmap.xaxis<= max(pT_est(1,:)) | gmap.xaxis <= pS(1)+ Vrng(2)*H*T,1,'last');
    idxs_y = zeros(1,2);
    idxs_y(1) = find(gmap.yaxis>= min(pT_est(2,:)) | gmap.yaxis>= pS(2)- Vrng(2)*H*T,1,'first');
    idxs_y(2) = find(gmap.yaxis<= max(pT_est(2,:)) | gmap.yaxis <= pS(2)+ Vrng(2)*H*T,1,'last');
    
    [idxs_x,idxs_y] = meshgrid(idxs_x(1):2:idxs_x(2),idxs_y(1):2:idxs_y(2));
    
    gpreg.xd = [gmap.xaxis(idxs_x(:));gmap.yaxis(idxs_y(:))]';
    gpreg.yd = gmap.omap(sub2ind([gmap.ynum,gmap.xnum],idxs_y(:),idxs_x(:)));
    
    gpreg.sig = 0.7; 
    nn=size(gpreg.xd,1);
    gpreg.K = exp(-pdist2(gpreg.xd,gpreg.xd).^2/2/gpreg.sig^2+eye(nn)*1e-4);
    gpreg.Kinvy=gpreg.K\gpreg.yd;
    [test.x,test.y]=meshgrid(linspace(-10,40,50));
    test.prob=zeros(size(test.x));
    for ii=1:numel(test.x)
         kstar = exp(-pdist2(gpreg.xd,[test.x(ii),test.y(ii)]).^2/2/gpreg.sig^2);
         test.prob(ii) = kstar'*gpreg.Kinvy;
    end
    imagesc(test.x(:),test.y(:),test.prob,[-1,10]);
    
    % -- [ obstacle avoidence ] -- %
    
    % Prediction
    pEst = struct('mean',pT_est, 'sig',sqrt(sigT(1)),'prob',1,'M',1);
    for hh=1:H
        pEst(hh).mean =  pseq(:,timestamps+hh);
        pEst(hh).sig = sqrt(sigT(1)); 
        pEst(hh).prob = 1;  
        pEst(hh).M=1; 
       
    end
    tic;
 
    % --- [ optimization yamlip] -- %
    
    % --- [ Optimization proble] -- % 
    options = optimoptions('fmincon','Display','off','TolX',1e-3,'TolFun',1e-3,'Gradobj','off','GradConstr','off');%,'Algorithm','sqp');
  
    %fmin=@(Uctrl)fcn_dist(Uctrl);
    fmin=@(Uctrl)fcn_visibility(Uctrl,pS,pEst,T,sensor_model,NBOUND,gpreg);
    fcon=@(Uctrl)fcn_con(Uctrl,pS,pEst,T,sensor_model,NBOUND,gpreg,linspace(0.2,0.2,H),2);
  
    prob_opt = inf; 
    Uctrl_opt = zeros(2*H,1);
    for itmp = 1:size(ctrlseeds,2)
        Uctrl0 = ctrlseeds(:,itmp);
    
        [Uctrl,probval,existflag,minout,~,gradval] = fmincon(fmin,Uctrl0,[],[],[],[],[Vrng(1)*ones(H,1);Urng(1)*ones(H,1)],[Vrng(2)*ones(H,1);Urng(2)*ones(H,1)],fcon,options);

       % condition check
        [concheck,~,~,~]=fcn_con(Uctrl,pS,pEst,T,sensor_model,NBOUND,gpreg,linspace(0.1,0.2,H),2);
        if(probval<=prob_opt &&existflag~=-2 && sum(concheck>0)==0)
            prob_opt = probval;
            Uctrl_opt = Uctrl;
        end
    end
    [concheck,~,~,~]=fcn_con(Uctrl_opt,pS,pEst,T,sensor_model,NBOUND,gpreg,linspace(0.1,0.2,H),2);
    currprob = concheck(1)+0.1;
    fprintf('condition check:');
    fprintf(' %d',concheck<=0);
    fprintf('\n');
    %tlog(timestamps)=toc;
    toc;
    fprintf('objective value: %.3e\n',prob_opt);
    uv_opt = Uctrl_opt(1:H);
    uw_opt = Uctrl_opt(H+1:end);
    
    uv_opt = Uctrl_opt(1);
    uw_opt = Uctrl_opt(H+1);
    
    % update seeds
   % ctrlseeds = [repmat(Uctrl_opt(2:H),1,numel(uvseeds));uvseeds(:)';...
   %     repmat(Uctrl_opt(H+2:end),1,numel(uvseeds));uwseeds(:)'];
    ctrlseeds = bsxfun(@plus,[Uctrl_opt(2:H);Uctrl(H);Uctrl_opt(H+2:end);Uctrl_opt(end)],...
        [(randn(H,numseeds))*(Vrng(2)-Vrng(1))/10;(randn(H,numseeds))*(Urng(2)-Urng(1))/10]);
    %pS=fcn_unicycle([s;phi],[uv_opt,uw_opt,T]);
    % approximate dynamics
    pS = [s;phi]+[cos(phi),0;sin(phi),0;0,1]*[uv_opt,uw_opt]'*T;
    pS(3) = mod(pS(3),2*pi);
    s=pS(1:2);
    phi=pS(3);
    % -- [ save ] -- %
    pSlog = [pSlog, pS];
    pTlog = [pTlog, pT_est];
    problog = [problog,currprob];
 
    % -- [ draw ] --- %

    % obstacles
    subplot(1,2,1);
    imagesc(gmap.xlim,gmap.ylim,gmap.cmap,[0,20]); hold on;
    colormap(flipud(colormap('copper')))
    %plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
    set(gca,'ydir','normal');
    % sensor
    predict_phi = phi+[0;cumsum(Uctrl_opt(H+1:end))*T];
    f_dynamic = [cos(predict_phi(1:end-1)).*Uctrl_opt(1:H)*T,sin(predict_phi(1:end-1)).*Uctrl_opt(1:H)*T]';
    predict_s = repmat(pS(1:2,1),[1,H+1]);
    predict_s(:,2:end) = predict_s(:,2:end)+cumsum(f_dynamic,2);

    psmp = mvnrnd(pT_est,sigT,200);
    plot(psmp(:,1),psmp(:,2),'m.');  
    plot(pseq(1,timestamps+(1:H)),pseq(2,timestamps+(1:H)),'r','linewidth',2); hold on;
    
    plot(pT_est(1),pT_est(2),'m+'); hold on;
    plot(predict_s(1,:),predict_s(2,:),'blue');
    
    
    plot(s(1),s(2),'*','color','red');
    DL_show=DL; DL_show(isinf(DL))=RL;
    plot(DL_show.*cos(angleL)+s(1),DL_show.*sin(angleL)+s(2),'color','red'); 
    plot([s(1),RS*cos(angleS)+s(1),s(1)],[s(2),RS.*sin(angleS)+s(2),s(2)],'color','green'); 
    axis equal;
    xxyy=[get(gca,'XLim'),get(gca,'YLim')];
    hold off;
    subplot(1,2,2);
    imagesc(test.x(:),test.y(:),test.prob,[0,20]); hold on;
     plot(pT_est(1),pT_est(2),'m+'); hold on;
    set(gca,'Ydir','normal');
    axis(xxyy)
    colormap(flipud(colormap('copper')))
    hold off;
    pause(0.01);
    
    %saveas(gcf,sprintf('scene%d.png',timestamps));
    hold off;
    
end
save('result_tmp.mat','pTlog','pSlog','problog')
%% draw
if(1)
    for tt=1:size(pSlog,2);
        plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
        plot(pTlog(1,1:tt),pTlog(2,1:tt),'color','red','linewidth',2);
        plot(pSlog(1,1:tt),pSlog(2,1:tt),'color','blue','linewidth',2);
        s=pSlog(1:2,tt);
        
        if(mod(tt,1)==0)
        angleS = pSlog(3,tt)+linspace(-ThetaS/2,ThetaS/2,angleL_res); 
        plot([s(1),RS*cos(angleS)+s(1),s(1)],[s(2),RS.*sin(angleS)+s(2),s(2)],'color','green','linewidth',2); 
        plot([s(1),pTlog(1,tt)],[s(2),pTlog(2,tt)],'m--','linewidth',2);
        end
        
        axis equal; 
        pause(0.5);
        hold off; 
    end
    hold off;
    
    
end

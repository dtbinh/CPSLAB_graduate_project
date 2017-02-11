% Compare CCDP algorithm
yalmip('clear');
clear;

%% -- [ settings ] -- %
if(~exist('pseq','var'))
    % Map
    load('maps/map1.mat');

    % load trajectories
    load('pseq.mat');
    mapnum=1;
    sim_iternum=42;
    trajname=2;
    load(sprintf('./target_traj/TargetTraj_Map%d_%d_%d.mat',mapnum,sim_iternum,trajname)); % load a trajectory
end
if(~exist('H','var'))
     H=3; % horizon
end
if(~exist('sigT','var'))
    sigT = eye(2)*0.2^2;
end

% initial positions
ndir = 10; % the number of discrete values of directions.
p = pseq(:,1); % target
s = pseq(:,1)-[1,1]'; phi=2*pi/ndir; % robot
T = 1;
pS = [s;phi];

% estimatimation (mean, covariance matrix)
pT_est = p;

pModel=1;

% sensor model
Rs = 10; ThetaS = 57/180*pi; 
sensor_model = [Rs, ThetaS];
Nside = 4; % N-sided appproximated sensing region

% Robot's dynamic model
VMAX_const = 5;
VMIN=-5;
Urng = [-pi/2,pi/2]; Vrng = [VMIN, VMAX_const];
[uvseeds, uwseeds]=meshgrid(linspace(Vrng(1)+0.1,Vrng(2)-0.1,3),linspace(Urng(1)-pi/10,Urng(2)+pi/10,3));

numseeds=9;
ctrlseeds_init = [repmat(uvseeds(:),[1,H]),repmat(uwseeds(:),[1,H])]';
ctrlseeds = ctrlseeds_init;


% settgins for CCDP
threshold_track = 0.1;  

% -- [ Parameters for cost ] -- %
costparam.ndir = 10; % number of headings of the sensor
costparam.gnum = 2; % the length of a grid map for ccdp = costparam.gnum* the length of a grid map for gmap
costparam.glen = gmap.glen*costparam.gnum;
s_dirs = (0:ndir-1)*2*pi/ndir; % headings of the sensor

% sensing region
phi_a = [ThetaS/2+pi/2; -ThetaS/2-pi/2; ThetaS*(2*(3:Nside)'-3-Nside)/(2*(Nside-2))]; % angles of the normal vector a = [cos(phi_s+phi_a), sin(phi_s+phi_a)]'
costparam.cc = zeros(Nside,1);
costparam.cc(3:end)=Rs*cos(ThetaS/2/(Nside-2));

% matrix of normal vectors of sensing region, A(:,:,ii) are normavectors when current heading is ii
costparam.A = zeros(Nside,2,ndir);
for ii=1:ndir
    costparam.A(:,:,ii) = [cos(s_dirs(ii)+phi_a), sin(s_dirs(ii)+phi_a)];

end

% -- [ settings for back recursion ] - %
shiftdir = unique(round(linspace(Urng(1),Urng(2),20)/2/pi*ndir));
for ii = 1:ndir
    nextstate(ii).sidxs = unique(round(kron(Vrng*[linspace(0,1,20);1-linspace(0,1,20)],[sin(s_dirs(ii)),cos(s_dirs(ii))]'/costparam.glen)'),'rows'); %delta [ys, xs], next yx = current yx + nextstate.sidxs
    nextstate(ii).dir = mod(ii+shiftdir,ndir);
    nextstate(ii).dir(nextstate(ii).dir==0) = ndir;
    
end


% draw
if(0)
plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
plot(pseq(1,:),pseq(2,:),'b+-'); hold off;
axis equal;
pause(0.01);
end

pSlog = []; pTlog = []; problog=[];
%% ---- [ Start target tracking ] -- %
for timestamps = 1:50%50%length(pseq)-H-2%30
    %tic;
   % the current position of the target
    pT_est =pseq(:,timestamps+1);

    tic;
    % Prediction
    pEst = struct('mean',pT_est, 'sig',sqrt(sigT(1)),'prob',1,'M',1);
    for hh=1:H
        pEst(hh).mean =  pseq(:,timestamps+hh);
        pEst(hh).sig = sqrt(sigT(1)); 
        pEst(hh).prob = 1;  
        pEst(hh).M=1; 
       
    end
    
    % -- [ select grid map near the current position ] -- %
    idxs_x = zeros(1,2);
    idxs_x(1) = find(gmap.xaxis>= min(pT_est(1,:)) | gmap.xaxis>= pS(1)- Vrng(2)*H*T*2,1,'first');
    idxs_x(2) = find(gmap.xaxis<= max(pT_est(1,:)) | gmap.xaxis <= pS(1)+ Vrng(2)*H*T*2,1,'last');
    idxs_y = zeros(1,2);
    idxs_y(1) = find(gmap.yaxis>= min(pT_est(2,:)) | gmap.yaxis>= pS(2)- Vrng(2)*H*T*2,1,'first');
    idxs_y(2) = find(gmap.yaxis<= max(pT_est(2,:)) | gmap.yaxis <= pS(2)+ Vrng(2)*H*T*2,1,'last');

    [idxs_x,idxs_y] = meshgrid(idxs_x(1):costparam.gnum:idxs_x(2),idxs_y(1):costparam.gnum:idxs_y(2));
    [rlen, clen] = size(idxs_x);
    ccdp = struct('xs',[],'ys',[],'omap',[],'cvis',[],'ctrack',struct('val',[]),'cavoid',[],'cconst',struct('val',[]));
    ccdp.xs = gmap.xaxis(idxs_x);
    ccdp.ys = gmap.yaxis(idxs_y);
    ccdp.glen = gmap.glen*costparam.gnum;
    ccdp.gmap = reshape( gmap.gmap(sub2ind([gmap.ynum,gmap.xnum],idxs_y(:),idxs_x(:))),[rlen,clen]);

    %% CCDP
    
    [ uv_opt, uw_opt, predict_s ] = fcn_track_ccdp_fast( pS, pEst, H, T, ccdp, threshold_track, costparam,nextstate );
    taketime(timestamps)=toc;
    %% update
    % approximate dynamics
    %pS = [s;phi]+[cos(phi),0;sin(phi),0;0,1]*[uv_opt,uw_opt]'*T;
    pS = predict_s(:,2);
    s=pS(1:2);
    phi=pS(3);
    
    pT = pT_est;
    %pT = mvnrnd(pT_est,eye(2)*pEst(1).sig^2)'; % insert noise
   
    % -- [ save ] -- %
    pSlog = [pSlog, pS];
    pTlog = [pTlog, pT_est];
   % problog = [problog,currprob];
    %toc;
    
     %% Check visibility
     if(isinf(uv_opt)&&isinf(uw_opt))
         Failflag=1;
         successflag = 0;
         fprintf('Fail: infeasible\n');
         break;
     end
    % within sensing region
    check_dist = norm(pS(1:2)-pT);
    check_angle = [cos(pS(3)),sin(pS(3))]*(pT-pS(1:2))/check_dist;
    check_visibility = unique(round(([linspace(pT(2),pS(2),20)-gmap.ylim(1);linspace(pT(1),pS(1),20)-gmap.xlim(1)])/gmap.glen)'+1,'rows'); 
    check_collision = round(([pS(2)-gmap.ylim(1),pS(1)-gmap.xlim(1)])/gmap.glen)'+1; 
    
    if(check_dist > Rs || check_angle< cos(ThetaS/2))
        Failflag = 2; % out of sensing region
        successflag =0;
        fprintf('Fail: out of sensing region\n');
        break;
    elseif(sum(gmap.gmap(sub2ind(size(gmap.gmap),check_collision(1),check_collision(2)))>0)~=0)
        Failflag = 4; % collision fail
        successflag =0;
        fprintf('Fail:collision\n');
        break;
    elseif(sum(gmap.gmap(sub2ind(size(gmap.gmap),check_visibility(:,1),check_visibility(:,2)))>0)~=0)
        Failflag = 3; % visibility fail
        successflag =0;
        fprintf('Fail: occlusion\n');
        break;
    
    else
        %fprintf('success\n');
        successflag =1;
        Failflag = 0;
        
    end
%     if(check_dist <=Rs && check_angle>= cos(ThetaS/2) && sum(gmap.gmap(sub2ind(size(gmap.gmap),check_visibility(:,1),check_visibility(:,2)))>0)==0)
%         fprintf('success\n');
%         successflag = 1;
%         
%     else
%         fprintf('fail: %d\n',timestamps);
%         successflag =0;
%         break;
%     end
    
    % -- [ draw ] --- %
   if(1)
        % obstacles
       % subplot(1,2,1);
        drawmap = gmap.gmap;% + (conv2(double(gmap.gmap),ones(2*Rfree+1),'same')>0);
        imagesc(gmap.xlim,gmap.ylim,drawmap,[0,2]); hold on;
        colormap(flipud(colormap('copper')))
        %plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
        set(gca,'ydir','normal');

        psmp = mvnrnd(pT_est,sigT,200);
       % plot(psmp(:,1),psmp(:,2),'m.');  
        plot(pseq(1,timestamps+(1:H)),pseq(2,timestamps+(1:H)),'r','linewidth',2); hold on;

        plot(pT_est(1),pT_est(2),'m+'); hold on;
        plot(predict_s(1,:),predict_s(2,:),'blue');


        plot(s(1),s(2),'*','color','red');
        angleS = phi+linspace(-ThetaS/2,ThetaS/2,20); 
        plot([s(1),Rs*cos(angleS)+s(1),s(1)],[s(2),Rs.*sin(angleS)+s(2),s(2)],'color','green'); 
        axis equal;
        xxyy=[get(gca,'XLim'),get(gca,'YLim')];

        hold off;
        pause(0.01);

        %saveas(gcf,sprintf('scene%d.png',timestamps));
        hold off;
   end
    
end
%save('result_tmp.mat','pTlog','pSlog','problog')
%% draw
if(0)
    for tt=1:size(pSlog,2);
        plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
        plot(pTlog(1,1:tt),pTlog(2,1:tt),'-','color',[1,0.5,0.5],'linewidth',2);
        plot(pTlog(1,tt),pTlog(2,tt),'+r','markersize',10,'linewidth',2);
        plot(pSlog(1,1:tt),pSlog(2,1:tt),'-','color','blue','linewidth',2);
        s=pSlog(1:2,tt);
        
        if(mod(tt,1)==0)
        %angleS = pSlog(3,tt)+linspace(-ThetaS/2,ThetaS/2,20); 
        %plot([s(1),Rs*cos(angleS)+s(1),s(1)],[s(2),Rs.*sin(angleS)+s(2),s(2)],'color','green','linewidth',2); 
        %plot([s(1),pTlog(1,tt)],[s(2),pTlog(2,tt)],'m--','linewidth',2);
        plot([pTlog(1,tt),pSlog(1,tt)],[pTlog(2,tt),pSlog(2,tt)],'g');
        end
        
        axis equal; 
        xlim([-10,90]);
        ylim([-10,50]);
        %pause(0.01);
        
        hold off; 
    end
    hold off;
    pause(0.1);
    
    
end

% summuraized drawing
if(1)
    drawseq = 1:1:size(pSlog,2);
    plot([pTlog(1,drawseq);pSlog(1,drawseq)],[pTlog(2,drawseq);pSlog(2,drawseq)],'linewidth',1.5,'color',[0,0.7,0]); hold on;

    plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
    plot(pTlog(1,drawseq),pTlog(2,drawseq),'o','color',[1,0,0],'linewidth',2,'markerfacecolor',[1,0,0]);
    plot(pTlog(1,drawseq),pTlog(2,drawseq),'color',[1,0,0],'linewidth',1.5);
    plot(pSlog(1,1),pSlog(2,1),'oc','markersize',10,'linewidth',2);
    plot(pSlog(1,drawseq),pSlog(2,drawseq),'o','color','blue','linewidth',2);
    
    
    axis equal; 
    xlim([-10,90]);
    ylim([-10,50]);
    hold off;
    pause(0.1);
    
    
end

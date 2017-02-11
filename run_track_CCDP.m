% CCMH with obstacle avoidance
yalmip('clear');
clc; clear;
%% -- [ settings ] -- %
% Map
load('maps/map1.mat');

% Initialize - the motion of the target
%pseq=8+[0,-2;-1,3;3,5;9,5;10,6;12,7;15,8;11,13;11,15]';
pseq = [0,8;8,15;15,17;20,20;30,20;30,30;30,40;17,43;30,45;45,40;50,30;50,40]'; % scene1
pseq = [0,8;8,15;15,17;20,20;30,20;30,30;30,40;17,43;30,45;45,40;50,30;50,40]';
% scene2
pseq=[interp(pseq(1,:),10);interp(pseq(2,:),10)];
pseq = pseq(:,1:2:end);
%save('pseq.mat','pseq');
%load('pseq.mat');
pseq = fcn_gen_path( gmap, 2 , 60 , [30;15] );
p = pseq(:,1);%[2,7]'; 
% robot's position
s = p-[2,2]'; phi=pi*0.4;
T = 1;
pS = [s;phi];

% estimatimation (mean, covariance matrix)
pT_est = p;
sigT = eye(2)*1^2;
pModel=1;

% sensor model
Rs = 7; ThetaS = 57/180*pi; 
sensor_model = [Rs, ThetaS];
Nside = 4; % N-sided appproximated sensing region

% directions of visibility-lines of a laser scanner
ThetaL=135/180*pi; RL=10; % field of view and range
angleL_res = 100;
angleL = phi+linspace(-ThetaL,ThetaL,angleL_res);

% Robot's dynamic model
VMAX_const = 4;
VMIN=-4;
Urng = [-pi/2,pi/2]; Vrng = [VMIN, VMAX_const];
[uvseeds, uwseeds]=meshgrid(linspace(Vrng(1)+0.1,Vrng(2)-0.1,3),linspace(Urng(1)-pi/10,Urng(2)+pi/10,3));
H=10; % horizon
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



% draw
plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
plot(pseq(1,:),pseq(2,:),'b+-'); hold off;
axis equal;
pause(0.1);

pSlog = []; pTlog = []; problog=[];
%% ---- [ Start target tracking ] -- %
% -- [ settings for tracking cost ] -- %
ndir = 10; % number of headings of the sensor
    
% robot's position
ttmp = 10;
s = pseq(:,ttmp)-[1,1]'; phi=2*pi/ndir;
T = 1;
pS = [s;phi];
for timestamps = ttmp:length(pseq)-H-2%30
    tic;
   % the current position of the target
    pT_est =pseq(:,timestamps+1);

    % Prediction
    pEst = struct('mean',pT_est, 'sig',sqrt(sigT(1)),'prob',1,'M',1);
    for hh=1:H
        pEst(hh).mean =  pseq(:,timestamps+hh);
        pEst(hh).sig = sqrt(sigT(1)); 
        pEst(hh).prob = 1;  
        pEst(hh).M=1; 
       
    end
    
    %% CCDP
    % -- [ select grid map near the current position ] -- %
    idxs_x = zeros(1,2);
    idxs_x(1) = find(gmap.xaxis>= min(pT_est(1,:)) | gmap.xaxis>= pS(1)- Vrng(2)*H*T*2,1,'first');
    idxs_x(2) = find(gmap.xaxis<= max(pT_est(1,:)) | gmap.xaxis <= pS(1)+ Vrng(2)*H*T*2,1,'last');
    idxs_y = zeros(1,2);
    idxs_y(1) = find(gmap.yaxis>= min(pT_est(2,:)) | gmap.yaxis>= pS(2)- Vrng(2)*H*T*2,1,'first');
    idxs_y(2) = find(gmap.yaxis<= max(pT_est(2,:)) | gmap.yaxis <= pS(2)+ Vrng(2)*H*T*2,1,'last');
    
    [idxs_x,idxs_y] = meshgrid(idxs_x(1):2:idxs_x(2),idxs_y(1):2:idxs_y(2));
    [rlen, clen] = size(idxs_x);
    ccdp = struct('xs',[],'ys',[],'omap',[],'nextstate',struct('sidxs',[],'dir',[]),'cvis',[],'ctrack',struct('val',[]),'cavoid',[],'cconst',struct('val',[]));
    ccdp.xs = gmap.xaxis(idxs_x);
    ccdp.ys = gmap.yaxis(idxs_y);
    ccdp.glen = ccdp.xs(1,2)-ccdp.xs(1,1);
    ccdp.gmap = reshape( gmap.gmap(sub2ind([gmap.ynum,gmap.xnum],idxs_y(:),idxs_x(:))),[rlen,clen]);
  
    % -- [ settings for visibility cost ] -- %
    nvis = 20; % the number of angles to compute visibility cost
    ccdp.cvis = zeros([rlen,clen,H]); % initialize the visibility cost
   
    % -- [ settings for tracking cost ] -- %
    ndir = 10; % number of headings of the sensor
    s_dirs = (0:ndir-1)*2*pi/ndir; % headings of the sensor
    ccdp.dirs = s_dirs;
    % sensing region
    phi_a = [ThetaS/2+pi/2; -ThetaS/2-pi/2; ThetaS*(2*(3:Nside)'-3-Nside)/(2*(Nside-2))]; % angles of the normal vector a = [cos(phi_s+phi_a), sin(phi_s+phi_a)]'
    cc = zeros(Nside,1);
    cc(3:end)=Rs*cos(ThetaS/2/(Nside-2));

    A = zeros(Nside,2,ndir);
    threshold_track = 0.3;
    for ii=1:ndir
        A(:,:,ii) = [cos(s_dirs(ii)+phi_a), sin(s_dirs(ii)+phi_a)];% matrix of normal vectors of sensing region, A(:,:,ii) are normavectors when current heading is ii
        
    end
    
    % -- [ settings for back recursion ] - %
    shiftdir = unique(round(linspace(Urng(1),Urng(2),20)/2/pi*ndir));
    for ii = 1:ndir
        ccdp.nextstate(ii).sidxs = unique(round(kron(Vrng*[linspace(0,1,20);1-linspace(0,1,20)],[sin(s_dirs(ii)),cos(s_dirs(ii))]'/ccdp.glen)'),'rows'); %delta [ys, xs], next yx = current yx + nextstate.sidxs
        ccdp.nextstate(ii).dir = mod(ii+shiftdir,ndir);
        ccdp.nextstate(ii).dir(ccdp.nextstate(ii).dir==0) = ndir;
        
        ccdp.nextstate;
    end
    
    
    
    % -- [ Compute one-step cost ] -- %
    ccdp.cvis = zeros(rlen,clen,H+1);
    ccdp.ctrack(1).val = zeros(rlen,clen,ndir);
    ccdp.cavoid = zeros(rlen,clen,H+1);
    ccdp.cconst(1).val = zeros(rlen,clen,ndir);
    for tt=1:H
        % --- [ Cvis ]  --- %
        % distance and angle from the target's prediction to grids
        dist2target = (ccdp.xs-pEst(tt).mean(1)).^2+ (ccdp.ys-pEst(tt).mean(2)).^2;
        angle2target = round((atan2(ccdp.ys-pEst(tt).mean(2),ccdp.xs-pEst(tt).mean(1))+pi)/2/pi*nvis)+1;
        angle2target(angle2target==9)=1;
        
        minradius = zeros(1,nvis); % distance between the target and an obstacle in nvis directions
        cvistmp = zeros([rlen,clen]);
        for ii=1:nvis
            obsidx = ccdp.gmap(:)==1 & angle2target(:)==ii;
            if(sum(obsidx)>=1)
                minradius(ii) = min(dist2target(obsidx));
                
                cvistmp(dist2target(:)>= minradius(ii) & angle2target(:)==ii)=1;
                
                
            end
            ccdp.cvis(:,:,tt+1) = cvistmp;
           % 
        end
        
        % -- [ Ctrack ] -- %
       % sensing region
        for ii=1:ndir
            ccdp.ctrack(tt+1).val(:,:,ii) = reshape(sum(1-normcdf(bsxfun(@plus,A(:,:,ii)*[ccdp.xs(:)-pEst(tt).mean(1),ccdp.ys(:)-pEst(tt).mean(2)]',cc)/pEst(tt).sig),1) > threshold_track,[rlen,clen]);% matrix of normal vectors of sensing region
        
        end
        
         % -- [Cavoid ] -- %
        Rfree = 2; % probability of collision is determined by Rfree
        ccdp.cavoid(:,:,tt+1) = conv2(double(ccdp.gmap),ones(Rfree*2+1),'same')>=1;
        
        % -- [ value of constraint ] -- %
        ccdp.cconst(tt+1).val = bsxfun(@or,ccdp.ctrack(tt+1).val,ccdp.cavoid(:,:,tt+1));
                
        
    end
    
   
    
        
    
    % -- [ Backward recursion ] -- %
    % find the optimal control when lambda is given
    lagcoeff = 0; %lagrangian coefficient
    lagrng = [0,1];
    lag_feas=1; % use to check the feasibility
         
    for ilagran = 1:100
        
        % initialize the optimal control: 'col': current column+col,
        % 'row': current row+'row',   dirs: replace current dirs with dirs
        Optctrl(1:H)=struct('row',zeros([size(idxs_x),ndir]),'col',zeros([size(idxs_x),ndir]),'dirs',0*ones([size(idxs_x),ndir]));
        Jmin(1:H+1) = struct('Jmin',100*ones([size(idxs_x),ndir]));
        Jmin(H+1).Jmin = bsxfun(@plus, lagcoeff*ccdp.cconst(H+1).val, lag_feas*ccdp.cvis(:,:,H+1)); %Value: Cvis + lambda * Ctrack
        for tt=H:-1:1
            % lagrangian - onestep
            Lk = bsxfun(@plus, lagcoeff*ccdp.cconst(tt).val, lag_feas*ccdp.cvis(:,:,tt)); %Value: Cvis + lambda * Ctrack
            for ii=1:ndir
                [Jmin_dir,mindiridx] = min(Jmin(tt+1).Jmin(:,:,ccdp.nextstate(ii).dir),[],3); 
                mindiridx = ccdp.nextstate(ii).dir(mindiridx);
                
                
 
                % find the optimal control-onestep
                for jj= 1:size(ccdp.nextstate(ii).sidxs,1)
                    original_rng_r = max(1,1-ccdp.nextstate(ii).sidxs(jj,1)):min(rlen,rlen-ccdp.nextstate(ii).sidxs(jj,1));
                    original_rng_c = max(1,1-ccdp.nextstate(ii).sidxs(jj,2)):min(clen,clen-ccdp.nextstate(ii).sidxs(jj,2));
                    comp_rng_r = max(1,1+ccdp.nextstate(ii).sidxs(jj,1)):min(rlen,rlen+ccdp.nextstate(ii).sidxs(jj,1));
                    comp_rng_c = max(1,1+ccdp.nextstate(ii).sidxs(jj,2)):min(clen,clen+ccdp.nextstate(ii).sidxs(jj,2));

                    % compare two matrix
                     CompMat = (Jmin(tt).Jmin(original_rng_r,original_rng_c,ii)  >  Jmin_dir(comp_rng_r,comp_rng_c)) |...
                         (Jmin(tt).Jmin(original_rng_r,original_rng_c,ii)==Jmin_dir(comp_rng_r,comp_rng_c) & abs(Optctrl(tt).dirs(original_rng_r,original_rng_c,ii))>abs(mindiridx(comp_rng_r,comp_rng_c)));
                    % update Jmin
                     Jmin(tt).Jmin(original_rng_r,original_rng_c,ii)  = (1-CompMat).*Jmin(tt).Jmin(original_rng_r,original_rng_c,ii) + CompMat.* Jmin_dir(comp_rng_r,comp_rng_c);

                    % update optimal control
                    Optctrl(tt).row(original_rng_r,original_rng_c,ii) =  (~CompMat).*Optctrl(tt).row(original_rng_r,original_rng_c,ii) + CompMat.*ccdp.nextstate(ii).sidxs(jj,1);
                    Optctrl(tt).col(original_rng_r,original_rng_c,ii) =  (~CompMat).*Optctrl(tt).col(original_rng_r,original_rng_c,ii) + CompMat.*ccdp.nextstate(ii).sidxs(jj,2);
                    Optctrl(tt).dirs(original_rng_r,original_rng_c,ii) =  (~CompMat).*Optctrl(tt).dirs(original_rng_r,original_rng_c,ii) + CompMat.*mindiridx(comp_rng_r,comp_rng_c);
                    
                end

                
                %Debug
                %{
                subplot(1,2,1);
                imagesc(Jmin_propagate);
                subplot(1,2,2);
                [fixing.cs, fixing.rs]= meshgrid(1:clen,1:rlen);
                fixing.rsopt = fixing.rs+Optctrl(tt).row(:,:,ii);
                fixing.csopt = fixing.cs+Optctrl(tt).col(:,:,ii);
                fixing.diropt = Optctrl(tt).dirs(:,:,ii);
                fixing.Jminopt = Jmin(tt+1).Jmin(sub2ind([rlen,clen,ndir],fixing.rsopt(:),fixing.csopt(:),fixing.diropt(:)));
                fixing.Jmintmp = [];
                for idebug = 1:length(ccdp.nextstate(ii).dir);
                    fixing.Jmintmp(:,:,idebug) = reshape(Jmin(tt+1).Jmin(sub2ind([rlen,clen,ndir],fixing.rsopt(:),fixing.csopt(:),ccdp.nextstate(ii).dir(idebug)*ones(rlen*clen,1))),[rlen,clen]);
                end
                
                fixing.Jmindir = Jmin(tt+1).Jmin(sub2ind([rlen,clen,ndir],fixing.rs(:),fixing.cs(:),fixing.diropt(:)));
                [~, fixing.diropttmp] = min(fixing.Jmintmp,[],3);
                fixing.diroptmp = ccdp.nextstate(ii).dir(fixing.diropttmp);
                imagesc(reshape(fixing.Jminopt,rlen,clen));
                %imagesc(min(fixing.Jmintmp,[],3));
                 pause();
                %}

            end
            Jmin(tt).Jmin=Jmin(tt).Jmin + Lk;
            
        end
        
        % -- [ Find the optimal control ] -- %
        currs_idx = [round([s(2)-ccdp.ys(1),s(1)-ccdp.xs(1)]/ccdp.glen)'+1; mod(round(pS(3)/2/pi*ndir),ndir)+1];
        %if(currs_idx(3)==0) 
        %    currs_idx(3) = ndir;
        %end
        const_val = 0; % number of violations of constraints
        optidx = zeros(3,H); 
        for tt=1:H
            optidx(:,tt) = [Optctrl(tt).row(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt)),Optctrl(tt).col(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt)),Optctrl(tt).dirs(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt))]';
            currs_idx(1:2,tt+1) = currs_idx(1:2,tt)+optidx(1:2,tt);
            currs_idx(3,tt+1) = optidx(3,tt);
            const_val = const_val + ccdp.cconst(tt+1).val(currs_idx(1,tt+1),currs_idx(2,tt+1),currs_idx(3,tt+1));
        end
        predict_s = [(currs_idx(2,:)-1)*ccdp.glen+ccdp.xs(1);(currs_idx(1,:)-1)*ccdp.glen+ccdp.ys(1)];
        predict_s(3,:) = (currs_idx(3,:)-1)*2*pi/ndir;
    
        % though we doesn't consider constraints, the optimal solution
        % satisfies constraints
        if(const_val<=0 && ilagran==1) 
           fprintf('feasible\n ');
           break;
        elseif(ilagran==1)
           lag_feas=0; lagcoeff=1;
                  
        end
        % check feasibility
        if(ilagran==2 && const_val >0)
            fprintf('infeasible\n');
            break;
        elseif(ilagran==2)
           lagcoeff = lagrng(2);
           lag_feas = 1;
        end
        if(ilagran>2)
           if(const_val>0) % violate constraints
               lagrng(1) = lagcoeff;
           else
               lagrng(2) = lagcoeff;
           end
           if(lagrng(2)-lagrng(1)<1e-2)
               break;  % stop iterations
           else
              lagcoeff = mean(lagrng);
           end
            
        end
            
            
    end
    fprintf('the number of iterations: %d,  coeff: %.3e\n',ilagran,lagcoeff);
    %%
    
%     % -- [ Find the optimal control ] -- %
%     currs_idx = [round([s(2)-ccdp.ys(1),s(1)-ccdp.xs(1)]/ccdp.glen)'+1; mod(round(pS(3)/2/pi*ndir),ndir)+1];
%     const_val = 0;
%     for tt=1:H
%             optidx(:,tt) = [Optctrl(tt).row(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt)),Optctrl(tt).col(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt)),Optctrl(tt).dirs(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt))]';
%             currs_idx(1:2,tt+1) = currs_idx(1:2,tt)+optidx(1:2,tt);
%             currs_idx(3,tt+1) = optidx(3,tt);
%             const_val = const_val + ccdp.cconst(tt).val(currs_idx(1,tt+1),currs_idx(2,tt+1),currs_idx(3,tt+1));
%     end
%     predict_s = [(currs_idx(2,:)-1)*ccdp.glen+ccdp.xs(1);(currs_idx(1,:)-1)*ccdp.glen+ccdp.ys(1)];
%     predict_s(3,:) = (currs_idx(3,:)-1)*2*pi/ndir;

 
    %% update
    uv_opt = norm(optidx(1:2,1))*ccdp.glen/T;
    uw_opt = (predict_s(3,2)-predict_s(3,1))/T;
    
%    fprintf('objective value: %.3e\n',prob_opt);
    
    
   
    % approximate dynamics
    pS = [s;phi]+[cos(phi),0;sin(phi),0;0,1]*[uv_opt,uw_opt]'*T;
  %  pS(1:2) = predict_s(1:2,2);
    %pS(3) = mod(pS(3),2*pi);
  %  pS = predict_s(:,2);
    s=pS(1:2);
    phi=pS(3);
    % -- [ save ] -- %
    pSlog = [pSlog, pS];
    pTlog = [pTlog, pT_est];
   % problog = [problog,currprob];
 toc;
    % -- [ draw ] --- %

    % obstacles
   % subplot(1,2,1);
   drawmap = gmap.gmap + (conv2(double(gmap.gmap),ones(2*Rfree+1),'same')>0);
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
    angleS = phi+linspace(-ThetaS/2,ThetaS/2,angleL_res); 
    plot([s(1),Rs*cos(angleS)+s(1),s(1)],[s(2),Rs.*sin(angleS)+s(2),s(2)],'color','green'); 
    axis equal;
    xxyy=[get(gca,'XLim'),get(gca,'YLim')];
    
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
        plot([s(1),Rs*cos(angleS)+s(1),s(1)],[s(2),Rs.*sin(angleS)+s(2),s(2)],'color','green','linewidth',2); 
        plot([s(1),pTlog(1,tt)],[s(2),pTlog(2,tt)],'m--','linewidth',2);
        end
        
        axis equal; 
        pause(0.5);
        hold off; 
    end
    hold off;
    
    
end

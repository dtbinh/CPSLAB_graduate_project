%% Expalain
%{
generation data for learning
represent an occupancy grid map and predicted positions of the target as a
relative position
%}
% -------------------------------------------------------------------------
%% Load Data
mapname = './maps/map1.mat'; % map name
dataname = './results/201607061303/simlog_traj_H8_var_1.000e-02_201607061303.mat'; % training data

% load data
load(mapname);
load(dataname);
H = simlog_traj.H; % H
pSlog = simlog_traj.pSlog; % pSlog
pTmean = simlog_traj.pTmean; % predicted position of the target

savedir = fprintf('./data4learning/H%d',H);

%% New map
Vmax = 5;
Lmax = Vmax*H;
Lnum = ceil(2*Lmax/gmap.glen);

% -------------------------------------------------------------------------
%% Make data
for tt = 1:size(pSlog,2)-H;
    % Rotation Matrix
    T = [cos(pSlog(3,tt)), -sin(pSlog(3,tt)), -pSlog(1,tt); ...
        sin(pSlog(3,tt)), cos(pSlog(3,tt)), -pSlog(2,tt); ...
        0,0,1];
    
    % transform obstalces
    obspoints = [gmap.obspoints;ones(1,size(gmap.obspoints,2))]; % occupied points
    obspoints_conv= T*obspoints; % occupied points => relative points
    
    % transform target's position
    targets_rel = T*[pTmean(:,tt:tt+H-1);ones(1,H)];
    
    % Build a map
    RelMap = zeros(Lnum); % relative map
    % obstacle
    rc = round((obspoints_conv([2,1],:)-(-Lmax))/gmap.glen)+1; % assign occupied points into grids
    rc = rc(:,rc(1,:)<=Lnum & rc(2,:) <=Lnum & rc(1,:) >0 & rc(2,:)>0);
    inds = sub2ind([Lnum,Lnum],rc(1,:),rc(2,:));
    RelMap(inds) = 1;
    
    % target
    rc = round((obspoints_conv([2,1],:)-(-Lmax))/gmap.glen)+1; % assign target's position into grids
    rc = rc(:,rc(1,:)<=Lnum & rc(2,:) <=Lnum & rc(1,:) >0 & rc(2,:)>0);
    inds = sub2ind([Lnum,Lnum],rc(1,:),rc(2,:));
    RelMap(inds) = 1;
    
    
    
    %% Draw
    % original image
    subplot(1,2,1); 
    imagesc(gmap.xlim,gmap.ylim,gmap.gmap,[0,2]); hold on;
    colormap(flipud(colormap('copper')))
    plot(pSlog(1,tt),pSlog(2,tt),'om');
    quiver(pSlog(1,tt),pSlog(2,tt),cos(pSlog(3,tt)),sin(pSlog(3,tt)),2,'color','red');
    hold off;
    set(gca,'ydir','normal');
    
    % transformed image
    subplot(1,2,2);
    imagesc([-Lmax,Lmax],[-Lmax,Lmax],RelMap,[0,2]); hold on;
    set(gca,'ydir','normal');
    hold off;
   
    pause();
    
end
    
    
    
    
    
    
    % check if conversion is correctly done.
    
        

function [ opt_v,opt_w] = Copy_of_fcn_track_greedy_objective( pS, pT, T, Rs, ThetaS,gmap ,Vseed, Useed, vp)
% T. Bandyopadhyay, Y. Li, M. H. Ang.Jr, D. Hsu, "A greedy Strategy for
% Tracking a Locally Predictable Target among obstacles",ICRA2006
% T. Bandyopadhyay, N. Rong, M. Ang, D. Hsu, W.S. Lee, "Motion Planning for
% People Tracking in Uncertain and Dynamic Environments", workshop on
% people detection and tracking , ICRA 2009
% vs: current sensor's velocity, vs_ang: angular velocity
% vp: target's velocity
% Compute the objective function when the position and velocity of the
% target and the robot are given.

%% Sensing: Find range edges, occlusion edges, and O
angleS_res= 50;
angleS = pS(3) + linspace(-ThetaS/2,ThetaS/2,angleS_res);  % sensing range

% compute the distance between the robot and obstacles
Dist_obs=pdist2(pS(1:2)',gmap.obspoints');
Ang_obs = atan2(gmap.obspoints(2,:)-pS(2),gmap.obspoints(1,:)-pS(1));% angle 
valid_ind = Dist_obs <= Rs & (cos(Ang_obs-pS(3))>=cos(ThetaS/2)) ; % with in the sensing region

DS = Rs* ones(1,angleS_res); % value of a range sensor
threshold_ang = cos((angleS(1)-angleS(2))*5);
% read data from a range sensor
for ii=find(valid_ind)
    jj = cos(Ang_obs(ii)-angleS)> threshold_ang;
    DS(jj) = min(DS(jj),Dist_obs(ii));
   
end
DS_pos = [DS.*cos(angleS)+pS(1); DS.*sin(angleS)+pS(2)]; % position of the sensing region
%% Find edges
threshold_edge = gmap.glen*1.5;
irng = 1;
edge_rng(1).ind=[]; len.rng = 0;
iocc = 1;
edge_occ(iocc).ind = []; len.occ = 0;
edge_fov.ind = 1; edge_fov(2).ind = angleS_res; len.fov = 2;
edge_min.R = 0.001; % minimum bound of sensing region
% Assign points on the laser into {range edge, fov edge, occedge}
for ii=2:angleS_res
    if(DS(ii)==Rs) % range edge
        if(len.rng==0)
            edge_rng(irng).ind = ii;
            len.rng = 1;
        elseif(ii-edge_rng(irng).ind(end)==1)
            edge_rng(irng).ind(end+1) = ii;
        else
            len.rng = len.rng+1;
            irng=irng+1;
            edge_rng(irng).ind=ii;
        end
    end
    if(abs(DS(ii)-DS(ii-1))>threshold_edge)
        len.occ = len.occ+1;
        edge_occ(iocc).ind = (DS(ii)>DS(ii-1))*ii + (DS(ii) < DS(ii-1))*(ii-1) ;
        edge_occ(iocc).O = ((DS(ii)<=DS(ii-1))*DS(ii) + (DS(ii) > DS(ii-1))*DS(ii-1))*...
            [cos(angleS(edge_occ(iocc).ind)),sin(angleS(edge_occ(iocc).ind))]'+pS(1:2);
        edge_occ(iocc).r0 = norm(pS(1:2)-edge_occ(iocc).O);
        edge_occ(iocc).finepos = [linspace(edge_occ(iocc).O(1),DS_pos(1,edge_occ(iocc).ind),30);...
            linspace(edge_occ(iocc).O(2),DS_pos(2,edge_occ(iocc).ind),30)];
        iocc = iocc+1;
    end
end

%% Find O
for ii=1:len.rng%Range edge
    
    dist_edge = pdist2(pT',DS_pos(:,edge_rng(ii).ind)');
    [~,minidx]=min(dist_edge);
    edge_rng(ii).O = DS_pos(:,edge_rng(ii).ind(minidx));
    edge_rng(ii).r0 = norm(pS(1:2)-edge_rng(ii).O);
    fineang = linspace(angleS(edge_rng(ii).ind(1)),angleS(edge_rng(ii).ind(end)),30); % fine angle
    edge_rng(ii).finepos = [pS(1)+Rs*cos(fineang);pS(2)+Rs*sin(fineang)]; % fine space
end
edge_fov(1).finepos = [linspace(pS(1)+cos(angleS(1))*edge_min.R,DS_pos(1,1),30);linspace(pS(2)+sin(angleS(1))*edge_min.R,DS_pos(2,1),30)];
edge_fov(2).finepos = [linspace(pS(1)+cos(angleS(end))*edge_min.R,DS_pos(1,end),30);linspace(pS(2)+sin(angleS(end))*edge_min.R,DS_pos(2,end),30)];

edge_min(ii).O = (pT-pS(1:2))/norm(pT-pS(1:2))*edge_min.R;
edge_rng(ii).r0 = edge_min.R;
fineang = linspace(angleS(edge_rng(ii).ind(1)),angleS(edge_rng(ii).ind(end)),30); % fine angle
edge_rng(ii).finepos = [pS(1)+Rs*cos(fineang);pS(2)+Rs*sin(fineang)]; % fine space


%% Ingredients of the risk function
robot_dir = [cos(pS(3)),sin(pS(3))]';
for ii=1:len.occ % purple
    a = [cos(angleS(edge_occ(ii).ind)),sin(angleS(edge_occ(ii).ind))]; % the directional vector of the occlusion ray
    aper = [a(2),-a(1)]; % the normal vector w.r.t. a
    
    vr_unit = [cos(angleS(edge_occ(ii).ind)),sin(angleS(edge_occ(ii).ind))]; % robot's unit velocity vector towards O
    vr_dir_proj = vr_unit*robot_dir; % the robot's projected direction to vr_unit
    vt_unit = [sin(angleS(edge_occ(ii).ind)),-cos(angleS(edge_occ(ii).ind))]; % perpendicular vector of vr_unit
    vt_dir_proj = vt_unit*robot_dir; % the size of robot's projected velocity to vt_unit
    ve = abs(vt_unit*vp); % the size of target's projected velocity to vt_unit
    
    e= abs(aper*(pT-pS(1:2)));% distance between the edge and the target
    if(e < norm(pT-edge_occ(ii).O)) % IV-A. CASE I
        edge_occ(ii).crosspoint = [a;aper]\[a*pT;aper*pS(1:2)];% the point with the minimum distance from the target on the edge
        edge_occ(ii).r0dash = norm(edge_occ(ii).crosspoint-edge_occ(ii).O);
        edge_occ(ii).e = e;
        
        %edge_occ(ii).mgradrisk = edge_occ(ii).riskfun/veff*(edge_occ(ii).r0dash/edge_occ(ii).r0*vt_unit+vr_unit); % -gradient
    else % IV-A. CASE II
        
        edge_occ(ii).crosspoint = edge_occ(ii).O;
        edge_occ(ii).e= norm(pT-edge_occ(ii).O);
        edge_occ(ii).r0dash = 0;
        %veff = vr-ve;
        %edge_occ(ii).riskfun = (edge_occ(ii).r0-edge_occ(ii).e)/veff;
        %edge_occ(ii).mgradrisk = edge_occ(ii).riskfun/veff*vr_unit;
    end
   

end

% Fov 



%% Compute the risk function for each control
% Vseed
Vrisk = struct('occ_risk',0,'range_risk',0);
for jj = 1:length(Vseed)
    % occlusion edge
    for ii=1:len.occ
        a = [cos(angleS(edge_occ(ii).ind)),sin(angleS(edge_occ(ii).ind))]; % the directional vector of the occlusion ray
        aper = [a(2),-a(1)]; % the normal vector w.r.t. a

        vr_unit = [cos(angleS(edge_occ(ii).ind)),sin(angleS(edge_occ(ii).ind))]; % robot's unit velocity vector towards O
        vr_dir_proj = vr_unit*robot_dir; % the robot's projected direction to vr_unit
        vt_unit = [sin(angleS(edge_occ(ii).ind)),-cos(angleS(edge_occ(ii).ind))]; % perpendicular vector of vr_unit
        vt_dir_proj = vt_unit*robot_dir; % the size of robot's projected velocity to vt_unit
        ve = abs(vt_unit*vp); % the size of target's projected velocity to vt_unit

        e= abs(aper*(pT-pS(1:2)));% distance between the edge and the target
        if(e < norm(pT-edge_occ(ii).O)) % IV-A. CASE I
            edge_occ(ii).crosspoint = [a;aper]\[a*pT;aper*pS(1:2)];% the point with the minimum distance from the target on the edge
            edge_occ(ii).r0dash = norm(edge_occ(ii).crosspoint-edge_occ(ii).O);
            edge_occ(ii).e = e;

            %edge_occ(ii).mgradrisk = edge_occ(ii).riskfun/veff*(edge_occ(ii).r0dash/edge_occ(ii).r0*vt_unit+vr_unit); % -gradient
        else % IV-A. CASE II

            edge_occ(ii).crosspoint = edge_occ(ii).O;
            edge_occ(ii).e= norm(pT-edge_occ(ii).O);
            edge_occ(ii).r0dash = 0;
            %veff = vr-ve;
            %edge_occ(ii).riskfun = (edge_occ(ii).r0-edge_occ(ii).e)/veff;
            %edge_occ(ii).mgradrisk = edge_occ(ii).riskfun/veff*vr_unit;
        end

        veff = Vseed(jj)*(vr_dir_proj +vt_dir_proj*(edge_occ(ii).r0dash/edge_occ(ii).r0))-ve;

        Vrisk(jj).occ_risk(ii) = (edge_occ(ii).r0-edge_occ(ii).e)/veff; % risk function
        
    end
    % range edge
    for ii=1:len.rng
        vr_unit_rng = normr((edge_rng(ii).O-pS(1:2,1))')';
        vr_dir_rng = vr_unit_rng'*robot_dir;
        ve = vr_unit_rng'*vp;
        veff = ve - Vseed(jj)*vr_dir_rng;
        Vrisk(jj).range_risk(ii) =  norm(edge_rng(ii).O-pT)/veff;
    end 
    
end
% Useed - Fov edge
Urisk.fov_risk = 0;
for jj=1:length(Useed)
   weff = target_w_vel-Useed(jj);
   Urisk(jj).fov_risk(1) =  (-angleS(1)+target_w_curr)/weff;
   Urisk(jj).fov_risk(2) = (-angleS(end)+target_w_curr)/weff;

end

%% the next control of a sensor
% compute the probability
meandir = atan2(vp(2),vp(1)); % the current heading of the target
sigdir = (pi/10);
angleP = meandir+linspace(-pi,pi,100); 
dirP = [cos(angleP); sin(angleP)];
probP = normpdf(angleP,meandir,sigdir); % probability of target's heading
distP = inf(size(probP));
indexP = zeros(size(probP)); % assign edge
% assign  probability
% fov:1,2,  edge_occ = 2+(1:len.occ), edge_rng = 2+len.occ+(1:len.rng)
% edge_min = 2+len.occ+len.rng+1
for ii=1:2+len.occ+len.rng
    if(ii<=2)
        for jj=1:size(edge_fov(ii).finepos,2)
            relpos = edge_fov(ii).finepos(:,jj)-pT; % relative position
            [~, minidx] = max(relpos' * dirP);  % assign angle
            if(norm(relpos) < distP(minidx))
                indexP(minidx) = ii;
                distP(minidx) = norm(relpos);
            end
        end
    elseif(ii<=2+len.occ)
        for jj=1:size(edge_occ(ii-2).finepos,2)
            relpos = edge_occ(ii-2).finepos(:,jj)-pT; % relative position
            [~, minidx] = max(relpos' * dirP);  % assign angle
            if(norm(relpos) < distP(minidx))
                indexP(minidx) = ii;
                distP(minidx) = norm(relpos);
            end
        end
    else
        for jj=1:size(edge_rng(ii-2-len.occ).finepos,2)
            relpos = edge_rng(ii-2-len.occ).finepos(:,jj)-pT; % relative position
            [~, minidx] = max(relpos' * dirP);  % assign angle
            if(norm(relpos) < distP(minidx))
                indexP(minidx) = ii;
                distP(minidx) = norm(relpos);
            end
        end
    end
end
   
% compute the probabilty of edge
%vs_next = zeros(2,1);
for ii=1:2+len.occ+len.rng
    if(ii<=2)
        edge_fov(ii).prob = sum(probP(indexP==ii));
        %vs_next = vs_next+edge_fov(ii).prob*edge_fov(ii).mgradrisk;
    elseif(ii<=2+len.occ)
        edge_occ(ii-2).prob = sum(probP(indexP==ii));
        %vs_next = vs_next+edge_occ(ii-2).prob*edge_occ(ii-2).mgradrisk;
    else
        edge_rng(ii-2-len.occ).prob = sum(probP(indexP==ii));
        %vs_next = vs_next+edge_rng(ii-2-len.occ).prob*edge_rng(ii-2-len.occ).mgradrisk;
        
    end
end
    
%% Compute the cost function
Risksum = zeros(length(Vseed),length(Useed));
for jj=1:length(Vseed)
    for kk = 1:length(Useed)
        probsum = 0;
        for ii=1:2
            Risksum(jj,kk) = Risksum(jj,kk)+Urisk(kk).fov_risk(ii)*edge_fov(ii).prob;
            probsum = probsum+edge_fov(ii).prob;
        end
        for ii=1:len.occ
            Risksum(jj,kk) = Risksum(jj,kk)+Vrisk(jj).occ_risk(ii)*edge_occ(ii).prob;
            probsum = probsum+edge_occ(ii).prob;
        end
        for ii=1:len.rng
            Risksum(jj,kk) = Risksum(jj,kk)+Vrisk(jj).range_risk(ii)*edge_rng(ii).prob;
            probsum = probsum+edge_rng(ii).prob;
        end
    end
end
[~,optind] = min(Risksum(:));
[optjj, optkk]=ind2sub(size(Risksum),optind);
nextvel = [Vseed(optjj),Useed(optkk)];
opt_v = nextvel(1);
opt_w = nextvel(2);
%% draw1
if(1)
plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
%plot([0,DS.*cos(angleS),0]+pS(1), [0,DS.*sin(angleS),0]+pS(2),'color',[1,0.5,0]); 
plot(pT(1),pT(2),'o','markerfacecolor','r');
quiver(pT(1),pT(2),vp(1),vp(2),1,'r')

for ii=1:len.rng %blue
    %plot(DS_pos(1,edge_rng(ii).ind),DS_pos(2,edge_rng(ii).ind),'color',[0,0,1]);
    plot(edge_rng(ii).finepos(1,:),edge_rng(ii).finepos(2,:),'-','color',[1,1,1]-[1,1,0]*edge_rng(ii).prob/probsum,'linewidth',3); 
     plot(edge_rng(ii).finepos(1,:),edge_rng(ii).finepos(2,:),'--','color',[0,0,0]);
    plot(edge_rng(ii).O(1),edge_rng(ii).O(2),'+','color',[0,0,1]);
    
end

for ii=1:len.occ % purple
    %plot(pS(1)+[0,Rs*cos(angleS(edge_occ(ii).ind))],pS(2)+[0,Rs*sin(angleS(edge_occ(ii).ind))],'color',[1,0,1]);
    plot(edge_occ(ii).finepos(1,:),edge_occ(ii).finepos(2,:),'-','color',[1,1,1]-[1,1,0]*edge_occ(ii).prob/probsum,'linewidth',3); 
    plot(edge_occ(ii).finepos(1,:),edge_occ(ii).finepos(2,:),'--','color',[0,0,0]);
    edge_occ(ii)
    plot(edge_occ(ii).O(1),edge_occ(ii).O(2),'+','color',[1,0,1]);
end

for ii=1:len.fov % green
    %plot(pS(1)+[0,Rs*cos(angleS(edge_fov(ii).ind))],pS(2)+[0,Rs*sin(angleS(edge_fov(ii).ind))],'color',[0,0.8,0]);
    plot(edge_fov(ii).finepos(1,:),edge_fov(ii).finepos(2,:),'-','color',[1,1,1]-[1,1,0]*edge_fov(ii).prob/probsum,'linewidth',3); 
    plot(edge_fov(ii).finepos(1,:),edge_fov(ii).finepos(2,:),'--','color',[0,0,0]);
end
    hold off;
    axis equal;
pause();
end
%% draw2
if(0)
    pS = pS + nextvel;
    angleS = pS(3) + linspace(-ThetaS/2,ThetaS/2,angleS_res);  
    pT = pT+vp;
    plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
    plot([0,DS.*cos(angleS),0]+pS(1), [0,DS.*sin(angleS),0]+pS(2),'color',[1,0.5,0]); 
    plot(pT(1),pT(2),'o','markerfacecolor','r');
    axis equal;
    hold off;
    pause();
end
end

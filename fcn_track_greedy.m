function [ nextvel] = fcn_track_greedy( pS, pT,pEst, T, Rs, ThetaS,gmap ,vs,vs_ang,vp)
% T. Bandyopadhyay, Y. Li, M. H. Ang.Jr, D. Hsu, "A greedy Strategy for
% Tracking a Locally Predictable Target among obstacles",ICRA2006
% T. Bandyopadhyay, N. Rong, M. Ang, D. Hsu, W.S. Lee, "Motion Planning for
% People Tracking in Uncertain and Dynamic Environments", workshop on
% people detection and tracking , ICRA 2009
% vs: current sensor's velocity, vs_ang: angular velocity
% vp: target's velocity

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
    jj = cos(An                                                                                                                                                                                                                                                                                                                              g_obs(ii)-angleS)> threshold_ang;
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
edge_fov(1).finepos = [linspace(pS(1),DS_pos(1,1),30);linspace(pS(2),DS_pos(2,1),30)];
edge_fov(2).finepos = [linspace(pS(1),DS_pos(1,end),30);linspace(pS(2),DS_pos(2,end),30)];

%% Compute the risk function

for ii=1:len.occ % purple
    a = [cos(angleS(edge_occ(ii).ind)),sin(angleS(edge_occ(ii).ind))]; % the directional vector of the occlusion ray
    aper = [a(2),-a(1)]; % the normal vector w.r.t. a
    
    vr_unit = [cos(angleS(edge_occ(ii).ind)),sin(angleS(edge_occ(ii).ind))]; % robot's unit velocity vector towards O
    vr = vr_unit*vs; % the size of robot's projected velocity to vr_unit
    vt_unit = [sin(angleS(edge_occ(ii).ind)),-cos(angleS(edge_occ(ii).ind))]; % perpendicular vector of vr_unit
    vt = vt_unit*vs; % the size of robot's projected velocity to vt_unit
    ve = abs(vt_unit*vp); % the size of target's projected velocity to vt_unit
    
    e= abs(aper*(pT-pS(1:2)));% distance between the edge and the target
    if(e < norm(pT-edge_occ(ii).O)) % IV-A. CASE I
        edge_occ(ii).crosspoint = [a;aper]\[a*pT;aper*pS(1:2)];% the point with the minimum distance from the target on the edge
        edge_occ(ii).r0dash = norm(edge_occ(ii).crosspoint-edge_occ(ii).O);
        edge_occ(ii).e = e;
        
        veff = (vr+vt*(edge_occ(ii).r0dash/edge_occ(ii).r0)-ve);
        
        edge_occ(ii).riskfun = (edge_occ(ii).r0-edge_occ(ii).e)/veff; % risk function
        edge_occ(ii).mgradrisk = edge_occ(ii).riskfun/veff*(edge_occ(ii).r0dash/edge_occ(ii).r0*vt_unit+vr_unit); % -gradient
    else % IV-A. CASE II
        
        edge_occ(ii).crosspoint = edge_occ(ii).O;
        edge_occ(ii).e= norm(pT-edge_occ(ii).O);
        
        veff = vr-ve;
        edge_occ(ii).riskfun = (edge_occ(ii).r0-edge_occ(ii).e)/veff;
        edge_occ(ii).mgradrisk = edge_occ(ii).riskfun/veff*vr_unit;
    end

end

% Fov 
target_w_curr = atan2(pT(2)-pS(2),pT(1)-pS(1)); % current relative target's angle from the robot
target_w_next = atan2(pT(2)+vp(2)*T-pS(2),pT(1)+vp(1)*T-pS(1)); % next relative target's angle
target_w_vel = (target_w_next-target_w_curr)/T; % angular velocity
weff = target_w_vel-vs_ang;
edge_fov(1).riskfun = (angleS(1)-target_w_curr)/weff;
edge_fov(1).mgradrisk = edge_fov(1).riskfun/weff;

edge_fov(2).riskfun = (angleS(end)-target_w_curr)/weff;
edge_fov(2).mgradrisk = edge_fov(2).riskfun/weff;

% Range 
for ii=1:len.rng
    vr_unit = normr((edge_rng(ii).O-pS(1:2,1))')';
    vr = vr_unit'*vs;
    ve = vr_unit'*vp;
    veff = ve-vr;
    edge_rng(ii).riskfun = norm(edge_rng(ii).O-pT)/veff;
    edge_rng(ii).mgradrisk = edge_rng(ii).riskfun/veff*vr_unit;
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
    
%% Compute the next velocity
nextvel = [0,0,0]';
probsum = 0;
for ii=1:2
    nextvel(3) = nextvel(3)+edge_fov(ii).mgradrisk*edge_fov(ii).prob;
    probsum = probsum+edge_fov(ii).prob;
end
for ii=1:len.occ
    nextvel(1:2) = nextvel(1:2)+edge_occ(ii).mgradrisk'*edge_occ(ii).prob;
    probsum = probsum+edge_occ(ii).prob;
end
for ii=1:len.rng
    nextvel(1:2) = nextvel(1:2)+edge_rng(ii).mgradrisk*edge_rng(ii).prob;
    probsum = probsum+edge_rng(ii).prob;
end


nextvel = nextvel/probsum;
%nextvel = [vs;vs_ang]+nextvel;
%nextvel =[vs;vs_ang] + nextvel;
%nextvel(3) = sign(nextvel(3))*0.4; % normalize

%% draw1
if(0)
plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.','color','black'); hold on;
%plot([0,DS.*cos(angleS),0]+pS(1), [0,DS.*sin(angleS),0]+pS(2),'color',[1,0.5,0]); 
plot(pT(1),pT(2),'o','markerfacecolor','r');

for ii=1:len.rng %blue
    %plot(DS_pos(1,edge_rng(ii).ind),DS_pos(2,edge_rng(ii).ind),'color',[0,0,1]);
    plot(edge_rng(ii).finepos(1,:),edge_rng(ii).finepos(2,:),'.','color',[0,0,1]);
    plot(edge_rng(ii).O(1),edge_rng(ii).O(2),'+','color',[0,0,1]);
end

for ii=1:len.occ % purple
    %plot(pS(1)+[0,Rs*cos(angleS(edge_occ(ii).ind))],pS(2)+[0,Rs*sin(angleS(edge_occ(ii).ind))],'color',[1,0,1]);
    plot(edge_occ(ii).finepos(1,:),edge_occ(ii).finepos(2,:),'.','color',[1,0,1]);
    edge_occ(ii)
    plot(edge_occ(ii).O(1),edge_occ(ii).O(2),'+','color',[1,0,1]);
end

for ii=1:len.fov % green
    %plot(pS(1)+[0,Rs*cos(angleS(edge_fov(ii).ind))],pS(2)+[0,Rs*sin(angleS(edge_fov(ii).ind))],'color',[0,0.8,0]);
    plot(edge_fov(ii).finepos(1,:),edge_fov(ii).finepos(2,:),'.','color',[0,0.8,0]);
end
    hold off;
    axis equal;
pause();
end
%% draw2
if(1)
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

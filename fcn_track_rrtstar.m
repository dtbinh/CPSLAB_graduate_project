function [ tr ] = fcn_track_rrtstar( pS, pEst,  T, gmap,  Urng, Vrng, Rs, ThetaS )
% ---------------------------------------------------------------%
% Find the optimal control which follows the target 
% without collision and occlusion
% -- Input -- %
% current position
% pEst: estimated position of the target
% smpspace: [xmin, xlen, ymin, ylen, zmin, zlen]
% -- Output -- %

% run: fcn_track_rrtstar( pS, pEst,  T, gmap, smpspace,  Umin, Umax, Vmin, Vmax )
% ----------------------------------------------------------------%

% F. Shkurti and G. Dudek, ¡°Maximizing visibility in collaborative trajectory planning,¡± in 2014 IEEE International Conference on Robotics and Automation (ICRA), May 2014, pp.3771?3776.
% RRT*: Sertac Karaman, Emilio Frazzoli, "Optimal Kinodynamic Motion
% Planning using Increental Sampling-based Methods", ICRA2010

%% Setting
rho = 1; % the minimum turning radius
Umax = min(Urng(2),Vrng(2)/rho); Umin = - min(abs(Urng(1)),Vrng(2)/rho);
Vmin = Vrng(1); Vmax = Vrng(2);
smpspace = [gmap.xlim(1),gmap.xlim(2)-gmap.xlim(1),gmap.ylim(1),gmap.ylim(2)-gmap.ylim(1),-pi,2*pi]';
%% Initialize a tree
tr = struct('pos',pS,'cost',0,'parent',0','depth',0,'costcum',0); % initialize tree
while 1
%% Sample from a configuration space
while 1
    zrnd = rand(3,1).*smpspace(2:2:6)+smpspace(1:2:5); % randomly sampled state
    zrnd_indx = round((zrnd(2:-1:1)-[gmap.ylim(1);gmap.xlim(1)])/gmap.glen)+1;
    if(zrnd(1)<gmap.xlim(2) && zrnd(1) > gmap.xlim(1) && zrnd(2) < gmap.ylim(2) && zrnd(2) > gmap.ylim(1))
    if(gmap.gmap(zrnd_indx(1),zrnd_indx(2))==0) % check if the sampled state is not occupied
        break;
    end
    end
end
   

%% Select the nearest vertex
[~, z_nearest_indx] = min(pdist2(tr.pos(1:2,:)',zrnd(1:2)'));
z_nearest = tr.pos(:,z_nearest_indx);
pTest = pEst(tr.depth(z_nearest_indx)+1).mean;
 
%% Steer
% the center of circles around the z_nearest
% right circle
cr1 = z_nearest(1:2) + rho * [cos(z_nearest(3)-pi/2);sin(z_nearest(3)-pi/2)];
% left circle
cl1 = z_nearest(1:2) + rho * [cos(z_nearest(3)+pi/2);sin(z_nearest(3)+pi/2)];

% the center of circles around the zrnd (sampled state)
% right circle
cr2 = zrnd(1:2) + rho * [cos(z_nearest(3)-pi/2);sin(z_nearest(3)-pi/2)];
% left circle
cl2 = zrnd(1:2) + rho * [cos(z_nearest(3)+pi/2);sin(z_nearest(3)+pi/2)];

% n_r* : the directional vector for a right turn [s(th),-c(th)]
% n_l* : the directional vector for a left turn [-s(th),c(th)]
% th_* : at th_*, the robot stop turns and go straight (rr,rl, ll, lr)
% RR 
n_rr= (cr2-cr1)/norm(cr2-cr1); 
th(1) = atan2(n_rr(1),-n_rr(2));
% RL
delx = cl2-cr1;
v = sqrt(delx(1)^2+delx(2)^2-rho^2);
cotheta = (-2*rho*delx(1)+v*delx(2))/(4*rho^2+v^2); % cos(theta)
n_rl(2)= -cotheta ;
n_rl(1) = (delx(1)-2*rho*cotheta)/v;
th(2) = atan2(n_rl(1),-n_rl(2));
% LL
n_ll = (cl2-cl1)/norm(cl2-cl1);
th(3) = atan2(-n_ll(1),n_ll(2));
% LR
delx = cr2-cl1;
v = sqrt(delx(1)^2+delx(2)^2-rho^2);
cotheta = (2*rho*delx(1)+v*delx(2))/(4*rho^2+v^2); % cos(theta)
sitheta= (-delx(1)+2*rho*cotheta)/v;
n_lr(2)= cotheta;
n_lr(1) = -sitheta;
th(4) = atan2(-n_lr(1),n_lr(2));

% start steering
u_ext = zeros(4,1); v_ext = zeros(4,1);
z_ext = zeros(3,1);
dir_ext = zeros(2,4); c_ext = zeros(4,1); % cost
for ii=1:2
delth = th(ii) - z_nearest(3);
if(delth>=0)
    delth = delth-2*pi;
end
u_ext(ii) = delth/T;
if(u_ext(ii)<= Umax && u_ext(ii)>= Umin)
    v_ext(ii) = rho*abs(u_ext(ii));
else    
    u_ext(ii) = Umin;
    v_ext(ii) = rho*abs(u_ext(ii));
end

end
for ii=3:4
delth = th(ii) - z_nearest(3);
if(delth<=0)
    delth = delth-2*pi;
end
u_ext(ii) = delth/T;
if(u_ext(ii)<= Umax && u_ext(ii)>= Umin)
    v_ext(ii) = rho*abs(u_ext(ii));
else    
    u_ext(ii) = Umax;
    v_ext(ii) = rho*abs(u_ext(ii));
end
end
%% Check visibility
for ii=1:4
z_ext(3,ii) = z_nearest(3)+u_ext(ii)*T;
z_ext(1:2,ii) = cr1 + rho*[cos(z_ext(3,ii)+pi/2);sin(z_ext(3,ii)+pi/2)];

% check visibility
check_dist = norm(z_ext(1:2,ii)-pTest);
check_angle = [cos(z_ext(3,ii)),sin(z_ext(3,ii))]*(pTest-z_ext(1:2,ii))/check_dist;
check_visibility = unique(round(([linspace(pTest(2),z_ext(2,ii),20)-gmap.ylim(1);linspace(pTest(1),z_ext(1,ii),20)-gmap.xlim(1)])/gmap.glen)'+1,'rows'); 
check_collision = round(([z_ext(2,ii)-gmap.ylim(1),z_ext(1,ii)-gmap.xlim(1)])/gmap.glen)'+1; 
if(sum(gmap.gmap(sub2ind(size(gmap.gmap),check_collision(1),check_collision(2)))>0)~=0)
    c_ext(ii) = inf;
elseif(check_dist > Rs || check_angle< cos(ThetaS/2) || sum(gmap.gmap(sub2ind(size(gmap.gmap),check_visibility(:,1),check_visibility(:,2)))>0)~=0)
    c_ext(ii) = 1;
else
    c_ext(ii) = 0;
end
end

[cmin, cidx] = min(c_ext);

%% New vertex
if(cmin~=inf) % collision free
   z_new = z_ext(:,cidx);
   curridx = size(tr.pos,2)+1;
   tr.pos(:,curridx) = z_new; % add a new vertex
   tr.cost(:,curridx) = c_ext(ii);
   tr.parent(curridx) = z_nearest_indx;
   tr.depth(curridx) = tr.depth(z_nearest_indx)+1;
   tr.costcum(curridx) = tr.costcum(z_nearest_indx) + tr.cost(:,curridx);
   % neighbor
   ind_znearby = find(pdist2(tr.pos(1:2,1:end-1)',z_new(1:2)')<3);
   %% Edge
   costcum_min = tr.costcum(z_nearest_indx) + tr.cost(:,curridx);
   for ii=ind_znearby'
       znearby = tr.pos(:,ii);
       currdepth = tr.depth(ii)+1;
       % check possible to go
       utmp = (z_new(3) - znearby(3))/T;
       if(utmp <= Umax && utmp >=Umin)
           if(utmp~=0)
               fr = [sin(z_new(3))-sin(znearby(3));-cos(z_new(3))+cos(znearby(3))]/utmp;
           else
               fr = T*[cos(z_new(3));sin(z_new(3))];
           end

           if(sum((z_new(1:2)-znearby(1:2))/norm((z_new(1:2)-znearby(1:2))) - fr/norm(fr))<1e-3)
                uvtmp = norm(z_new(1:2)-znearby(1:2))/norm(fr);
                if(uvtmp <= Vmax && uvtmp >= Vmin)

                   % check the visibility
                   if(currdepth ~= tr.depth(curridx))
                       pTest = pEst(currdepth).mean;
                       check_dist = norm(z_new(1:2)-pTest);
                        check_angle = [cos(z_new(3)),sin(z_new(3))]*(pTest-z_new(1:2))/check_dist;
                        check_visibility = unique(round(([linspace(pTest(2),z_new(2),20)-gmap.ylim(1);linspace(pTest(1),z_new(1),20)-gmap.xlim(1)])/gmap.glen)'+1,'rows'); 

                        if(check_dist > Rs || check_angle< cos(ThetaS/2) || sum(gmap.gmap(sub2ind(size(gmap.gmap),check_visibility(:,1),check_visibility(:,2)))>0)~=0)
                            currcost = 1;
                        else
                            currcost = 0;
                        end
                   else
                       currcost = tr.cost(:,curridx);

                   end
                   if(tr.costcum(ii)+currcost < costcum_min)
                       tr.parent(curridx) = ii;
                       tr.depth = currdepth;
                       costcum_min = tr.costcum(ii)+currcost ;
                       tr.cost(:,curridx) = currcost;
                       tr.costcum(curridx) = costcum_min;
                   end
                end
           end
       end
       %% rewiring

       
       
       
       
   end
   
   
 
    
    
end
if(length(tr.parent)>100)
    break
end
end

%% Draw
plot(tr.pos(1,1),tr.pos(2,1),'r*'); hold on;
for ii=2:length(tr.parent)
    edgenow = tr.pos(:,[ii,tr.parent(ii)]);
    plot(edgenow(1,:),edgenow(2,:),'b.-'); hold on;
    
end
hold off;
end


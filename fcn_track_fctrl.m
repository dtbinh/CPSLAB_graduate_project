function [ uv_opt, uw_opt ] = fcn_track_fctrl( pS, pT,pEst,vmax,sensor_model,T )
% ---------------------------------------------------------------%
% Formation control
% Paper: S. Panagou, V. Kumar, "Cooperative Visibility Maintenance for
% Leader-Follower Formations in Obstacle Envionments", TRO 2014
% Find the optimal control which follows the target 
% without collision and occlusion
% -- Input -- %
% current position
% pS: the robot's configuration
% pT: the target's current position
% pEst: estimated position of the target
% T: unit time step
% -- Output -- %

% ----------------------------------------------------------------%
% Sensor
alp = sensor_model(2)/2; % fov/2
Ls = sensor_model(2)/2; % sensing range

% -- [ settings for visibility cost ] -- %
pT = pEst(1).mean;
% current leader's state
vxy_l = (pEst(2).mean-pT)/T; % leader's velocity
headL = atan2(vxy_l(2),vxy_l(1)); % leader's heading

% rotational matrix
Rot = [cos(headL), sin(headL);-sin(headL), cos(headL)];
% relative position
r = Rot * ( pS(1:2)-pT); % the position of a follower w.r.t. leader's frame
bet = pS(3)-headL;% relative angle

% compute the desired position
RADIUS_DESIRED = Ls*0.6;
THETA_POS = atan2(r(2),r(1));
THETA_DESIRED = THETA_POS+sign(r(2))*pi;

rd = RADIUS_DESIRED*[cos(THETA_POS),sin(THETA_POS)]';
pxy = [cos(THETA_DESIRED),sin(THETA_DESIRED)]';

%  
r1 = r-rd;

% Dipolar vector field
Fx = 2*pxy(1)*r1(1)^2 - pxy(1)*r1(2)^2 + 3* pxy(2)*r1(1)*r1(2);
Fy = 2*pxy(2)*r1(2)^2 - pxy(2)*r1(1)^2 + 3* pxy(1)*r1(1)*r1(2);
varphi = atan2(Fy,Fx);
phidot = 0;
% velocity

% set parameters- based on eq 23 and 24
f = cos(bet+alp) - sin(bet+alp)*tan(alp); 
g = cos(alp)-sin(alp)*tan(alp);
k1_ref = vmax*(f/g-1)/(Ls-RADIUS_DESIRED);
if(k1_ref<3)
    k1 =3;
else
    k1 = k1_ref*1.1;
end

k2_ref = (k1*(Ls-RADIUS_DESIRED)*g-vmax*f)/(alp*Ls*tan(alp));
if(k2_ref<1)
    k2 = 1;
else
    k2 = k2_ref*1.1;
end



uv_opt = -k1*sign(r1'*[cos(bet),sin(bet)]')*norm(r1) - sign(pxy'*r1)*vmax;
uw_opt = -k2*(bet-varphi)+phidot;

fprintf('k1: %.2e, k2: %.2e, ctrl ( %.2e, %.2e)\n',k1,k2,uv_opt,uw_opt);

 % test
pS_next = fcn_unicycle(pS,[uv_opt,uw_opt,T]);
rd_global = inv(Rot)*rd+pT;
r_global = inv(Rot)*r+pT;
th_global = THETA_DESIRED + headL;
f_global = inv(Rot)*[Fx,Fy]';
pxy_global = [cos(th_global),sin(th_global)];
quiver(rd_global(1),rd_global(2),pxy_global(1),pxy_global(2),'m'); hold on;
%plot(pEst(2).mean(1),pEst(2).mean(2),'c+')
quiver(pS(1),pS(2),cos(pS(3)),sin(pS(3)),'color','red');
plot(r_global(1),r_global(2),'r^');
quiver(pS_next(1),pS_next(2),cos(pS_next(3)),sin(pS_next(3)),'r');
%quiver(pS(1),pS(2),f_global(1),f_global(2),'color',[0,0.8,0]);
plot(pS_next(1),pS_next(2),'rsquare');
plot(pT(1),pT(2),'b+');
hold off;
pause();
end


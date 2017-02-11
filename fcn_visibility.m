function [ Cvis,Cvis_gr_u ] = fcn_visibility( Uctrl,pS,pEst,dt,sensor_model,Nside,gpreg )
%{
Explain
Compute the probability that the target is out of the sensing region given
the control is given.

------------ input -------------------------------
# Uctrl = [uv, uw];  2Tx1,   T step look ahead
# pS = [xs,ys,thetaS]' : a sensor's current position
# pEst: 1xT , a structure which contains predictions of  target's position
  pEst(t).mean=pT(:,j) = [xT,yT]' : the traget's position estimated by Model j at time t
  pEst(t).cov(:,:,j) : variance of the target position by Model j
  pEst(t).sig(:,:,j) : sig^2 is variance of the target position by Model j
  pEst(t).cov(;:,j)=pEst(t).sig^2*I(2,2)
  pEst(t).prob : p(Mj) 1 x M dimension matrix, probability of each model j (Gaussian Mixture)
  pEst(t).M : the number of models
# dt : time interval
# sensor_model : [RS,ThetaS] the range of a sensor
# Nside: the number of sides of an approximated sensing region
# x_occ: 2xNocc, Occupied points
# gmap: grid map made by 'figure2map.m'
-------------output ----------------------------------
# fout : the probability that the target is out of the sensing region
# gout : the current gradient
-------------------------------------------------------

%}
%% Initialize
H = length(Uctrl)/2; % the number of steps for lookahead
uv = Uctrl(1:H); uw = Uctrl(H+1:end);

% sensor
Rs = sensor_model(1); ThetaS = sensor_model(2);
phi_a = [ThetaS/2+pi/2; -ThetaS/2-pi/2; ThetaS*(2*(3:Nside)'-3-Nside)/(2*(Nside-2))]; % the normal vector a = [cos(phi_s+phi_a), sin(phi_s+phi_a)]'
cc = zeros(Nside,1);
cc(3:end)=Rs*cos(ThetaS/2/(Nside-2));

% the current position of a sensor
%phi_s = pS(3)*ones(H+1,1);
%s = repmat(pS(1:2,1),[1,H+1]);

%% Compute fr for dynamic model
phi_s = cumsum([pS(3);uw])*dt;
s = cumsum([pS(1:2,1)';[cos(phi_s(1:end-1)).*uv*dt,sin(phi_s(1:end-1)).*uv*dt]],1)';
%f_dynamic = [cos(phi_s(1:end-1)).*uv*dt,sin(phi_s(1:end-1)).*uv*dt];
%s(:,2:end) = s(:,2:end)+cumsum(f_dynamic)';


%% Compute the probabilitiy of failures and its gradient
% --- initialize --- %
% 1. fail
Ctrack = zeros(1,H);
Ctrack_gr_u = zeros(H,2*H);

% 3. occlusion
Cvis = zeros(1,H);
Cvis_gr_u = zeros(1,H*2);

% Obstacle parameters
alpsnum = 10;
alps = linspace(0,1,alpsnum+1);
alps = alps(2:end); % determine the number of line segments
%% start
 
% Compute normal vectors of a sensor's boundaries
%a = zeros(2,Nside);%,H+1);  

for_s_gr_uv = dt*[cos(phi_s(1:H)') ;sin(phi_s(1:H)')];
for_s_gr_uw = dt*[-sin(phi_s(1:H)).*uv ,cos(phi_s(1:H)).*uv]';


for tt=2:H+1 % look ahead

%     % Normal vectors of boundaries of a sensing region at t
%     a = [cos(phi_s(tt)+phi_a), sin(phi_s(tt)+phi_a)]';
%     
     % A gradient of s(t) w.r.t u
     s_gr_u = [for_s_gr_uv(:,1:tt-1), zeros(2,H+1-tt),cumsum(for_s_gr_uw(:,1:tt-2),2,'reverse'),zeros(2,min(H+2-tt,H))];
%     
%     % 1. Target in the sensing region
%     for mm=1:pEst(tt-1).M % the number of model
%         
%         % compute Ctrack
%         curr_pnt = (a'*(s(:,tt)-pEst(tt-1).mean(:,mm))+cc)/pEst(tt-1).sig(mm);
%         Ctrack(tt-1) = Ctrack(tt-1) +  sum((1-normcdf(curr_pnt))*pEst(tt-1).prob(mm));
%         
%         % compute a gradient of Ctrack w.r.t. u
%         
%         Ctrack_gr_u_tmp = -normpdf(curr_pnt)'/pEst(tt-1).sig(:,mm)*(a'*s_gr_u...
%             + [zeros(Nside,H), repmat(dt*[-sin(phi_s(tt)+phi_a),cos(phi_s(tt)+phi_a)]*(s(:,tt)-pEst(tt-1).mean(:,mm)),[1,tt-1]),...
%             zeros(Nside,H-tt+1)])*pEst(tt-1).prob(mm);
%         Ctrack_gr_u(tt-1,:) = Ctrack_gr_u(tt-1,:) + Ctrack_gr_u_tmp;
%        
%     end
%     
    
    
    % 2. Obstacles
    xx = [s(:,tt),pEst(tt-1).mean]*[alps;(1-alps)]; % visibility region: vertual line between s(t) and p_est(t)
  
    
    % Occlusion: visibility cost and gradient of Cvis w.r.t u
    for ii=1:alpsnum

        kstar = exp(-((gpreg.xd(:,1)-xx(1,ii)).^2 + (gpreg.xd(:,2)-xx(2,ii)).^2 )/2/gpreg.sig^2);
        Cvis(tt-1) = Cvis(tt-1) + kstar'*gpreg.Kinvy; % visibility cost
        Cvis_gr_u = Cvis_gr_u - gpreg.Kinvy'*bsxfun(@times,kstar,[xx(1,ii)-gpreg.xd(:,1),xx(2,ii)-gpreg.xd(:,2)])/gpreg.sig^2*alps(ii)*s_gr_u; % gradient of the cost
        
    end
    %fprintf('%.3e ',errs);
    %fprintf('\n');

end


%% Compute the cost to avoid collision and occlusion

Cvis = sum(Cvis);
    


end


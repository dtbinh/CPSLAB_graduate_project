function [ uv_opt, uw_opt, predict_s ] = fcn_track_ccdp_fast( pS, pEst, H, T, ccdp, threshold_track, costparam,nextstate )
% ---------------------------------------------------------------%
% Find the optimal control which follows the target 
% without collision and occlusion
% -- Input -- %
% current position
% pEst: estimated position of the target

% -- Output -- %

% ----------------------------------------------------------------%


% -- [ settings for visibility cost ] -- %
nvis = 20; % the number of angles to compute visibility cost
[rlen, clen] = size(ccdp.xs);
%ccdp.cvis = zeros([rlen,clen,H]); % initialize the visibility cost

% -- [ settings for tracking cost ] -- %
ndir=costparam.ndir;
%s_dirs = costparam.s_dirs;


% -- [ Compute one-step cost ] -- %

ccdp_ctrack = zeros(rlen,clen,ndir,H+1);
ccdp_cvis = zeros(rlen,clen,H+1);
%ccdp.ctrack(1).val = zeros(rlen,clen,ndir);
ccdp_cavoid = zeros(rlen,clen,H+1);
ccdp_cconst= zeros(rlen,clen,ndir,H+1);
for tt=1:H
    % --- [ Cost: Cvis ]  --- %
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
        ccdp_cvis(:,:,tt+1) = cvistmp;
       % 
    end

    % -- [ Cost: Ctrack ] -- %
   % sensing region
    for ii=1:ndir
        %ccdp.ctrack(tt+1).val(:,:,ii) = reshape(sum(1-normcdf(bsxfun(@plus,costparam.A(:,:,ii)*[ccdp.xs(:)-pEst(tt).mean(1),ccdp.ys(:)-pEst(tt).mean(2)]',costparam.cc)/pEst(tt).sig),1) > threshold_track,[rlen,clen]);% matrix of normal vectors of sensing region
        ccdp_ctrack(:,:,ii,tt+1) =  reshape(sum(1-normcdf(bsxfun(@plus,costparam.A(:,:,ii)*[ccdp.xs(:)-pEst(tt).mean(1),ccdp.ys(:)-pEst(tt).mean(2)]',costparam.cc)/pEst(tt).sig),1) > threshold_track,[rlen,clen]);% matrix of normal vectors of sensing region
    end

     % -- [Cost: Cavoid ] -- %
    Rfree = 2; % probability of collision is determined by Rfree
    ccdp_cavoid(:,:,tt+1) = conv2(double(ccdp.gmap),ones(Rfree*2+1),'same')>=1;

    % -- [ value of constraint ] -- %
    %ccdp.cconst(tt+1).val = bsxfun(@or,ccdp.ctrack(tt+1).val,ccdp.cavoid(:,:,tt+1));
    ccdp_cconst(:,:,:,tt+1)= bsxfun(@or,ccdp_ctrack(:,:,:,tt+1),ccdp_cavoid(:,:,tt+1));


end



% -- [ Backward recursion ] -- %
% find the optimal control when lambda is given
lagcoeff = 0; %lagrangian coefficient
lagrng = [0,0.01];
lag_feas=1; % use to check the feasibility
flag_converge = 0;


for ilagran = 1:100

    % initialize the optimal control: 'col': current column+col,
    % 'row': current row+'row',   dirs: replace current dirs with dirs
    Optctrl_row = zeros(rlen,clen,ndir,H);
    Optctrl_col = zeros(rlen,clen,ndir,H);
    Optctrl_dirs = zeros(rlen,clen,ndir,H);
 
    
    Jmin = 100*ones([rlen,clen,ndir,H+1]);
    Jmin(:,:,:,H+1) =  bsxfun(@plus, lagcoeff*ccdp_cconst(:,:,:,H+1), lag_feas*ccdp_cvis(:,:,H+1)); %Value: Cvis + lambda * Ctrack
    for tt=H:-1:1
                
        % lagrangian - onestep
        Lk = bsxfun(@plus, lagcoeff*ccdp_cconst(:,:,:,tt), lag_feas*ccdp_cvis(:,:,tt)); %Value: Cvis + lambda * Ctrack
        for ii=1:ndir
            [Jmin_dir,mindiridx] = min(Jmin(:,:,nextstate(ii).dir,tt+1),[],3); 
            mindiridx = nextstate(ii).dir(mindiridx);



            % find the optimal control-onestep
            for jj= 1:size(nextstate(ii).sidxs,1)
                original_rng_r = max(1,1-nextstate(ii).sidxs(jj,1)):min(rlen,rlen-nextstate(ii).sidxs(jj,1));
                original_rng_c = max(1,1-nextstate(ii).sidxs(jj,2)):min(clen,clen-nextstate(ii).sidxs(jj,2));
                comp_rng_r = max(1,1+nextstate(ii).sidxs(jj,1)):min(rlen,rlen+nextstate(ii).sidxs(jj,1));
                comp_rng_c = max(1,1+nextstate(ii).sidxs(jj,2)):min(clen,clen+nextstate(ii).sidxs(jj,2));

                % compare two matrix
                 CompMat = (Jmin(original_rng_r,original_rng_c,ii,tt)  >  Jmin_dir(comp_rng_r,comp_rng_c)) |...
                     (Jmin(original_rng_r,original_rng_c,ii,tt)==Jmin_dir(comp_rng_r,comp_rng_c) & abs(Optctrl_dirs(original_rng_r,original_rng_c,ii,tt))>abs(mindiridx(comp_rng_r,comp_rng_c)));
                % update Jmin
                 Jmin(original_rng_r,original_rng_c,ii,tt)  = (1-CompMat).*Jmin(original_rng_r,original_rng_c,ii,tt) + CompMat.* Jmin_dir(comp_rng_r,comp_rng_c);

                % update optimal control
                Optctrl_row(original_rng_r,original_rng_c,ii,tt) =  (~CompMat).*Optctrl_row(original_rng_r,original_rng_c,ii,tt) + CompMat.*nextstate(ii).sidxs(jj,1);
                Optctrl_col(original_rng_r,original_rng_c,ii,tt) =  (~CompMat).*Optctrl_col(original_rng_r,original_rng_c,ii,tt) + CompMat.*nextstate(ii).sidxs(jj,2);
                Optctrl_dirs(original_rng_r,original_rng_c,ii,tt) =  (~CompMat).*Optctrl_dirs(original_rng_r,original_rng_c,ii,tt) + CompMat.*mindiridx(comp_rng_r,comp_rng_c);

            end



        end
        %Jmin(tt).Jmin=Jmin(tt).Jmin + Lk;
        Jmin(:,:,:,tt)=Jmin(:,:,:,tt) + Lk;

    end

    % -- [ Find the optimal control ] -- %
    currs_idx = zeros(3,H+1);
    currs_idx(:,1) = [round([pS(2)-ccdp.ys(1),pS(1)-ccdp.xs(1)]/ccdp.glen)'+1; mod(round(pS(3)/2/pi*ndir),ndir)+1];

    const_val = 0; % number of violations of constraints
    optidx = zeros(3,H); 
    for tt=1:H
        optidx(:,tt) = [Optctrl_row(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt),tt),...
            Optctrl_col(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt),tt),...
            Optctrl_dirs(currs_idx(1,tt),currs_idx(2,tt),currs_idx(3,tt),tt)]';
        currs_idx(1:2,tt+1) = currs_idx(1:2,tt)+optidx(1:2,tt);
        currs_idx(3,tt+1) = optidx(3,tt);
        const_val = const_val + ccdp_cconst(currs_idx(1,tt+1),currs_idx(2,tt+1),currs_idx(3,tt+1),tt+1);
    end
    predict_s = zeros(3,H+1);
    predict_s(1:2,:) = [(currs_idx(2,:)-1)*ccdp.glen+ccdp.xs(1);(currs_idx(1,:)-1)*ccdp.glen+ccdp.ys(1)];
    predict_s(3,:) = (currs_idx(3,:)-1)*2*pi/ndir;

    % though we doesn't consider constraints, the optimal solution
    % satisfies constraints
    if(const_val<=0 && ilagran==1) 
       %fprintf('feasible\n ');
       break;
    elseif(ilagran==1)
       lag_feas=0; lagcoeff=0.01;

    end
    % check feasibility
    if(ilagran==2 && const_val >0)
        fprintf('infeasible\n');
        predict_s(:)=inf;
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
       if(flag_converge==1)
           break;
       end
       if(lagrng(2)-lagrng(1)<1e-2)
           lagcoeff=lagrng(2);
           flag_converge = 1;
           
       else
          lagcoeff = mean(lagrng);
       end

    end


end

%fprintf('the number of iterations: %d,  coeff: %.3e\n',ilagran,lagcoeff);
% wrong, initial state is not same as predict_s(:,1)
movement=predict_s(:,2)-pS; 
uv_opt = norm(movement(1:2,1))/T;
uw_opt = (movement(3))/T;

end


clear; 
MODE_SIM = 0*[0, 0,0,1];
MODE_Analyze=1*[0,0,0,1];

%% Path generation
if(MODE_SIM(1)==1)
    mapnum = 1; % select a map
    traj_len=100; % select the length of the target's trajectory
    load(sprintf('maps/map%d.mat',mapnum));

    % generate paths
    for ii=1:100
        pseq = fcn_gen_path( gmap, 2 , traj_len, [30;15] );
        save(sprintf('./target_traj/TargetTraj_Map%d_%d_tmp.mat',mapnum,ii),'pseq'); % save
    end
end

%% run simulations several times
if(MODE_SIM(2)==1) 
     mapnum = 1; % select a map
     simlog = struct('Failtimestamps',zeros(1,50)); % save simulation lon
    
     for sim_iternum = 1:50
         fprintf('simulation %d\n',sim_iternum);
        clearvars -except MODE_SIM sim_iternum mapnum simlog MODE_Analyze; % initialize
     
        load(sprintf('maps/map%d.mat',mapnum)); % load a map
        load(sprintf('./target_traj/TargetTraj_Map%d_%d.mat',mapnum,sim_iternum)); % load a trajectory
        
        % run simulation
        run_track_algcompare_1; 
        
        % save log
        if(successflag==1)
            simlog.Failtimestamps(sim_iternum) = -1;
            simlog.Failmsg(sim_iternum) = Failflag;
        else
            simlog.Failtimestamps(sim_iternum) = timestamps;
            simlog.Failmsg(sim_iternum) = Failflag;
        end
     end
    currtime = datestr(now,'yyyymmddHHMM');
    save(sprintf('./results/simlog_%s.mat',currtime),'simlog');
    stitle=sprintf('variance: %.3f I(2), threshold: %.3f',sigT(1),threshold_track);
    plot(simlog.Failtimestamps); xlabel('index'); ylabel('failure time');
    title(stitle);
    saveas(gcf,sprintf('./results/failtime_var_%.3f_threshold_%.3f_currtime_%s.png',sigT(1),threshold_track,currtime));
    saveas(gcf,sprintf('./results/failtime_var_%.3f_threshold_%.3f_currtime_%s.fig',sigT(1),threshold_track,currtime));
    
    figure;
    histogram(simlog.Failmsg,[-0.5,0.5,1.5,2.5,3.5]);
    xlabel('0: success, 1: miss, 2: occlusion, 3: collision');
    saveas(gcf,sprintf('./results/failhist_var_%.3f_threshold_%.3f_currtime_%s.png',sigT(1),threshold_track,currtime));
    saveas(gcf,sprintf('./results/failhist_var_%.3f_threshold_%.3f_currtime_%s.fig',sigT(1),threshold_track,currtime));
end

%% run simulations w.r.t. Horizon, we assume that the target is detected at the mean
if(MODE_SIM(3)==1) 
     mapnum = 1; % select a map
     %simlog = struct('Failtimestamps',zeros(1,50)); % save simulation lon
     currtime = datestr(now,'yyyymmddHHMM');
     mkdir(['./results/',currtime]);
     Hsets = 3;%[1,3,5];%[1,3,5,7,10,15];
     simlog.Hsets = Hsets;
     simlog.Failmsgstr={'infeasible','Out of sensing region','occlusioni','collision'};
     simlog.mapname=sprintf('maps/map%d.mat',mapnum);
     simlog.trajname = 2;
     for signum=1:length(Hsets)
        for sim_iternum = 1:50
         
             H=Hsets(signum);
            fprintf('simulation %d\n',sim_iternum);
            clearvars -except MODE_SIM sim_iternum mapnum simlog Hsets hnum H currtime MODE_Analyze simlog_traj; % initialize

            load(sprintf('maps/map%d.mat',mapnum)); % load a map
            load(sprintf('./target_traj/TargetTraj_Map%d_%d_%d.mat',mapnum,sim_iternum,simlog.trajname)); % load a trajectory

            % set figure
            figure(signum);
            title(sprintf('H=%d',H));
            % run simulation
            run_track_algcompare_1; 

            % save figure
            saveas(gcf,sprintf('./results/%s/traj%d_H_%d_currtime_%s.png',currtime,sim_iternum,H,currtime));
            saveas(gcf,sprintf('./results/%s/traj%d_H_%d_currtime_%s.fig',currtime,sim_iternum,H,currtime));   
            
            % save log
            if(successflag==1)
                simlog.Failtimestamps(sim_iternum,signum) = -1;
                simlog.Failmsg(sim_iternum,signum) = Failflag;
            else
                simlog.Failtimestamps(sim_iternum,signum) = timestamps;
                simlog.Failmsg(sim_iternum,signum) = Failflag;
            end
            simlog_traj(sim_iternum).H = H;
            simlog_traj(sim_iternum).pSlog = pSlog;
            simlog_traj(sim_iternum).pTmean = pTlog;
         end
        save(sprintf('./results/%s/simlog_traj_H%d_%s.mat',currtime,H,currtime),'simlog_traj');
        clear simlog_traj
     end
     simlog.sigT = sigT;
     simlog.sensor_model = sensor_model;
     simlog.Urng = Urng; simlog.Vrng = Vrng;
     simlog.H = H; simlog.threshold_track=threshold_track;
     save(sprintf('./results/%s/simlog_%s.mat',currtime,currtime),'simlog');
    
     
end
%% Analyze performance w.r.t H
if(MODE_Analyze(3)==1)
    currtime = '201607041545';
    load(sprintf('./results/%s/simlog_%s.mat',currtime,currtime),'simlog');
    stitle=sprintf('variance: %.3f I(2), threshold: %.3f',simlog.sigT(1),simlog.threshold_track);
    
    markers = {'o','+','^','*'};
    for ii=1:size(simlog.Failtimestamps,2)
        drawdata=simlog.Failtimestamps(simlog.Failtimestamps(:,ii)~=-1,ii);
        if(~isempty(drawdata))
            [vals, edges]=histcounts(drawdata); 
            plot((edges(1:end-1)+edges(2:end))/2,cumsum(vals),'marker',markers{ii},'linewidth',2); hold on;
        end
        legend_names{ii} = sprintf('H=%d',simlog.Hsets(ii)); 
    end    
    xlabel('index'); ylabel('number');
    hold off;
    legend(legend_names,'fontsize',12,'location','northwest');
    title(stitle);
    saveas(gcf,sprintf('./results/%s/failtime_var_%.3f_threshold_%.3f_currtime_%s.png',...
        currtime,simlog.sigT(1),simlog.threshold_track,currtime));
    saveas(gcf,sprintf('./results/%s/failtime_var_%.3f_threshold_%.3f_currtime_%s.fig',...
        currtime,simlog.sigT(1),simlog.threshold_track,currtime));
    
    figure;
    vals = zeros(5,size(simlog.Failtimestamps,2));
    for ii=1:size(simlog.Failtimestamps,2)
       vals(:,ii)=histcounts(simlog.Failmsg(:,ii),[-0.5,0.5,1.5,2.5,3.5,4.5]);
        legend_names{ii} = sprintf('H=%d',simlog.Hsets(ii)); 
    end    
    bar(0:4,vals);
    ylabel('number');
    hold off;
    legend(legend_names,'fontsize',12);
    title(stitle);    
    
    xlabel('0: success, 1: infeasible, 2: out of V, 3: occlusion, 4: collision');
    saveas(gcf,sprintf('./results/%s/failhist_var_%.3f_threshold_%.3f_currtime_%s.png',...
        currtime,simlog.sigT(1),simlog.threshold_track,currtime));
    saveas(gcf,sprintf('./results/%s/failhist_var_%.3f_threshold_%.3f_currtime_%s.fig',...
        currtime,simlog.sigT(1),simlog.threshold_track,currtime));
end

%% run simulations w.r.t. variance, we assume that the target is detected at the mean
if(MODE_SIM(4)==1) 
     mapnum = 1; % select a map
     %simlog = struct('Failtimestamps',zeros(1,50)); % save simulation lon
     currtime = datestr(now,'yyyymmddHHMM');
     mkdir(['./results/',currtime]);
     Sigsets = [0.01,0.1,0.2,0.5,1];
     simlog.sigma = Sigsets;
     simlog.Failmsgstr={'infeasible','Out of sensing region','occlusioni','collision'};
     simlog.mapname=sprintf('maps/map%d.mat',mapnum);
     simlog.trajname = 2;
     for signum=1:length(Sigsets)
        for sim_iternum = 1:50
         
            sigT = eye(2)*Sigsets(signum)^2;
            H=8;
            fprintf('simulation %d\n',sim_iternum);
            clearvars -except MODE_SIM sim_iternum mapnum simlog Sigsets signum H currtime MODE_Analyze simlog_traj sigT; % initialize

            load(sprintf('maps/map%d.mat',mapnum)); % load a map
            load(sprintf('./target_traj/TargetTraj_Map%d_%d_%d.mat',mapnum,sim_iternum,simlog(1).trajname)); % load a trajectory

            % set figure
            figure(signum);
            title(sprintf('H=%d',H));
            % run simulation
            run_track_algcompare_with_noise; 

            % save figure
            saveas(gcf,sprintf('./results/%s/traj%d_H_%d_currtime_%s.png',currtime,sim_iternum,H,currtime));
            saveas(gcf,sprintf('./results/%s/traj%d_H_%d_currtime_%s.fig',currtime,sim_iternum,H,currtime));   
            
            % save log
            simlog(sim_iternum,signum).FailLog = FailLog;
            simlog(sim_iternum,signum).sigT= sigT;
%             if(successflag==1)
%                 simlog.Failtimestamps(sim_iternum,signum) = -1;
%                 simlog.Failmsg(sim_iternum,signum) = Failflag;
%             else
%                 simlog.Failtimestamps(sim_iternum,signum) = timestamps;
%                 simlog.Failmsg(sim_iternum,signum) = Failflag;
%             end
            simlog_traj(sim_iternum).H = H;
            simlog_traj(sim_iternum).pSlog = pSlog;
            simlog_traj(sim_iternum).pTmean = pTlog;
         end
        save(sprintf('./results/%s/simlog_traj_H%d_var_%.3e_%s.mat',currtime,H,Sigsets(signum),currtime),'simlog_traj');
        clear simlog_traj
     end

     simlog(1).sensor_model = sensor_model;
     simlog(1).Urng = Urng; simlog(1).Vrng = Vrng;
     simlog(1).H = H; simlog(1).threshold_track=threshold_track;
     simlog(1).SMP_NUM = NUM_SMP_INIT;
     save(sprintf('./results/%s/simlog_%s.mat',currtime,currtime),'simlog');
    
     
end
%% Analyze performance w.r.t variance
if(MODE_Analyze(4)==1)
    currtime = '201607061303';
    load(sprintf('./results/%s/simlog_%s.mat',currtime,currtime),'simlog');
    %stitle=sprintf('variance: %.3f I(2), threshold: %.3f',simlog(1).sigT(1),simlog.threshold_track);
    
 
    FailLog_cum = zeros([size(simlog(1).FailLog),length(simlog(1).sigma)]);
    for ii=1:size(simlog,2)
        for jj=1:size(simlog,1)
           FailLog_cum(:,:,ii) = FailLog_cum(:,:,ii) +  simlog(jj,ii).FailLog;
            
        end
        
        legend_names{ii} = sprintf('sigma=%.3e',sqrt(simlog(jj,ii).sigT(1))); 
    end    
    FailLog_cum = cumsum(FailLog_cum,1);
    TOTAL_NUM = size(simlog,1)*simlog(1).SMP_NUM;
    Err_msgs={ 'Infeasible', 'Out of V', 'Occlusion', 'Collision'};
    markers = {'^-','-','--',':','-.'}; 
    colors = colormap('lines');
    colors= colors([7,5,4,1,2],:);
    for ii=1:4
        for jj=1:size(FailLog_cum,3)
            plot(FailLog_cum(:,ii,jj)/TOTAL_NUM*100,markers{jj},'linewidth',2,'color',colors(jj,:)); hold on;
            
        end
        hold off;
        %ylim([0,simlog(1).SMP_NUM*size(simlog,1)*size(simlog,2)]);
        set(gcf,'name',Err_msgs{ii});
        legend(legend_names,'Location','northwest');
        set(gca,'Position',[0.12,0.1,0.85,0.88],'fontsize',13);
        xlabel('time steps'); ylabel('rate(fail cases/total cases) (%)');
        saveas(gcf,sprintf('./results/%s/failLog_%s_threshold_%.3f_%s.png',...
        currtime,Err_msgs{ii},simlog(1).threshold_track,currtime));
        saveas(gcf,sprintf('./results/%s/failLog_%s_threshold_%.3f_%s.fig',...
        currtime,Err_msgs{ii},simlog(1).threshold_track,currtime));
        
        pause();
    end
        
        

%     xlabel('index'); ylabel('number');
%     hold off;
%     legend(legend_names,'fontsize',12,'location','northwest');
%     title(stitle);

    
end
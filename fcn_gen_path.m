 function [ pseq ] = fcn_gen_path( gmap, v , L , pinit )
% Generate a random path of a padestrian when a map is given
% A pedestrian is assumed to move with a constant linear velocity
% gmap: map
% v: the linear velocity 
% L: length of the path
% pinit: initial position of the path

% settings
% range of angular transition
Angrng = [-pi/3, pi/3];


pseq = zeros(2,L);
pseq(:,1) = pinit;
pdir = rand(1)*2*pi*ones(1,L);

iternum = 2;
trynum=1;
while(iternum<=L)
    pdirsmp = pdir(iternum-1)+(Angrng(2)-Angrng(1))*rand(1)+Angrng(1);
    
    psmp = pseq(:,iternum-1)+v*[cos(pdirsmp);sin(pdirsmp)];
    if(min(pdist2(gmap.obspoints',psmp'))>1 && psmp(1) < gmap.xlim(2)-5 && psmp(2) <gmap.ylim(2)-5 && psmp(1) > gmap.xlim(1)+5 && psmp(2) > gmap.ylim(1)+5 )
        pseq(:,iternum) = psmp;
        pdir(iternum) = pdirsmp;
        iternum=iternum+1;
    else
        if(trynum>10)
            iternum = max(2,iternum-5);
            pseq=pseq(:,1:iternum-1);
            pdir = pdir(1:iternum-1);
        else
            trynum = trynum+1;
        end
    end
        

end




end


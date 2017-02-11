%{
Change a figure (e.g. jpg, png,..) to a grid map
input : an image file
output : a structure gmap
- gmap: an occupancy grid map
- xlim: 2x1 vector (the minimum and the maximum value of x
- ylim: 2x1 vector (the minimum and the maximum value of y
- xaxis : centers of grids in an x-direction
- yaxis : centers of grids in an y-direction
- xnum: the number of grids in x-direction
- ynum: the number of grids in y-direction
- glen: a length of a grid
- obspoints : 2xN,  [x,y]'x N , xy positions of occupied grids

- cmap: cost map of collision which represents how far each grid point is from obstacles
        max(-alpha*(minimum distance^2 - beta),0)
- cparam : 2x1 vector [alpha, beta]>0

- omap: cost map of occlusion represents how far each grid point is from obstacles
        max(-alpha*(minimum distance^2 - beta),0)
- oparam:  2x1 vector [alpha, beta]>0
%}
clc; clear;

% 1. input image
mapname = 'map1'; mapformat = '.png';
A = imread(['./maps/',mapname,mapformat]);

% 2. make a grid map
gmap.glen = 0.7;
gmap.xnum = 128;
gmap.ynum = 96;
gmap.xlim = -10+[0,gmap.glen*gmap.xnum];
gmap.ylim = -10+[0,gmap.glen*gmap.ynum];
gmap.gmap = sum(imresize(A,[gmap.ynum,gmap.xnum],'nearest'),3)<1;

% find occupied grids
[rows, cols] = find(gmap.gmap);
gmap.obspoints = [gmap.xlim(1) + gmap.glen*(cols-0.5), gmap.ylim(1) + gmap.glen*(rows-0.5)]';

% 3. build a cost map
gmap.cparam = [3,6]; %[alpha, beta]
gmap.oparam = [4,3];%[4,2]
% make a filter
filtsize = ceil(sqrt(gmap.cparam(2))/gmap.glen);
[xs, ys ] = meshgrid(gmap.glen*(-filtsize:filtsize));
cfilter =max(-gmap.cparam(1)*(xs.^2+ys.^2-gmap.cparam(2)),0);
ofilter =max(-gmap.oparam(1)*(xs.^2+ys.^2-gmap.oparam(2)),0);


% make a cost map using convolution and max pooling
maplarge = zeros(size(gmap.gmap)+filtsize*2*[1,1]);
maplarge(filtsize+1:end-filtsize,filtsize+1:end-filtsize) = gmap.gmap;
gmap.cmap = zeros(size(gmap.gmap));
for ix= 1:gmap.xnum
    for iy = 1:gmap.ynum
        gmap.cmap(iy,ix) = max(max(maplarge(iy:iy+filtsize*2,ix:ix+filtsize*2).*cfilter));
        gmap.omap(iy,ix) = max(max(maplarge(iy:iy+filtsize*2,ix:ix+filtsize*2).*ofilter));
        %mapconv(iy+(0:filtsize*2),ix+(0:filtsize*2))));
    end
end
gmap.xaxis = conv(linspace(gmap.xlim(1),gmap.xlim(2),gmap.xnum+1),[0.5,0.5],'valid');
gmap.yaxis = conv(linspace(gmap.ylim(1),gmap.ylim(2),gmap.ynum+1),[0.5,0.5],'valid');
% save
save(['./maps/',mapname,'.mat'],'gmap');

% 4. draw
subplot(1,2,1);
imagesc(gmap.xlim,gmap.ylim,gmap.gmap); hold on;
plot(gmap.obspoints(1,:),gmap.obspoints(2,:),'.'); hold off;
subplot(1,2,2);
imagesc(gmap.xlim,gmap.ylim,gmap.cmap);
%colormap('gray');
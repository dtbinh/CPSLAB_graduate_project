function [ dist,graddist ] = fcn_dist( Uctrl )
dist = Uctrl'*Uctrl;
graddist=2*Uctrl';
end


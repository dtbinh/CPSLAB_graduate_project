function [ robot_pos_next] = fcn_unicycle( robot_pos, robot_control)
% robot moves from robot_pos to robot_pos_next. robot_T is for a change in
% robot coordinate systems.
% robot_pos : 3 x N vector
% robot_control : N x 3 vector [tr_vel, ang_vel, del_t]

robot_control = robot_control';
del_t = robot_control(3,:);
small_range = abs(robot_control(2,:)) <(1e-10);

tx = zeros(size(small_range)); ty = tx; ttheta = tx;
% small_range o
tx(small_range) = robot_control(1,small_range).*del_t(1,small_range).*cos(robot_pos(3,small_range));
ty(small_range) = robot_control(1,small_range).*del_t(1,small_range).*sin(robot_pos(3,small_range));
ttheta(small_range) = 0;

% small_range x
r = robot_control(1,~small_range)./robot_control(2,~small_range); 
tx(~small_range) = -r.*sin(robot_pos(3,~small_range)) + r.*sin(robot_pos(3,~small_range) + robot_control(2,~small_range) .* del_t(1,~small_range));
ty(~small_range) = r.*cos(robot_pos(3,~small_range)) - r.*cos(robot_pos(3,~small_range) + robot_control(2,~small_range) .* del_t(1,~small_range));
ttheta(~small_range) = robot_control(2,~small_range) .* del_t(1,~small_range);


robot_pos_next =  [tx + robot_pos(1,:); ty + robot_pos(2,:) ; ttheta+robot_pos(3,:)]; 

end


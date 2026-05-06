function [data, info] = gains
%Gains gives an empty data for quadrotor_msgs/Gains
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'quadrotor_msgs/Gains';
[data.Kp, info.Kp] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Kd, info.Kd] = ros.internal.ros.messages.ros.default_type('double',1);
[data.KpYaw, info.KpYaw] = ros.internal.ros.messages.ros.default_type('double',1);
[data.KdYaw, info.KdYaw] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'quadrotor_msgs/Gains';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,4);
info.MatPath{1} = 'Kp';
info.MatPath{2} = 'Kd';
info.MatPath{3} = 'Kp_yaw';
info.MatPath{4} = 'Kd_yaw';

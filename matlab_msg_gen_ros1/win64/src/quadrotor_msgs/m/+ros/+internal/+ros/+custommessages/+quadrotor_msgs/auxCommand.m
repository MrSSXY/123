function [data, info] = auxCommand
%AuxCommand gives an empty data for quadrotor_msgs/AuxCommand
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'quadrotor_msgs/AuxCommand';
[data.CurrentYaw, info.CurrentYaw] = ros.internal.ros.messages.ros.default_type('double',1);
[data.KfCorrection, info.KfCorrection] = ros.internal.ros.messages.ros.default_type('double',1);
[data.AngleCorrections, info.AngleCorrections] = ros.internal.ros.messages.ros.default_type('double',2);
[data.EnableMotors, info.EnableMotors] = ros.internal.ros.messages.ros.default_type('logical',1);
[data.UseExternalYaw, info.UseExternalYaw] = ros.internal.ros.messages.ros.default_type('logical',1);
info.MessageType = 'quadrotor_msgs/AuxCommand';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,5);
info.MatPath{1} = 'current_yaw';
info.MatPath{2} = 'kf_correction';
info.MatPath{3} = 'angle_corrections';
info.MatPath{4} = 'enable_motors';
info.MatPath{5} = 'use_external_yaw';

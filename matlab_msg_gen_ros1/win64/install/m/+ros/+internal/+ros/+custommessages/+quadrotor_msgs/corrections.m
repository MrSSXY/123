function [data, info] = corrections
%Corrections gives an empty data for quadrotor_msgs/Corrections
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'quadrotor_msgs/Corrections';
[data.KfCorrection, info.KfCorrection] = ros.internal.ros.messages.ros.default_type('double',1);
[data.AngleCorrections, info.AngleCorrections] = ros.internal.ros.messages.ros.default_type('double',2);
info.MessageType = 'quadrotor_msgs/Corrections';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,2);
info.MatPath{1} = 'kf_correction';
info.MatPath{2} = 'angle_corrections';

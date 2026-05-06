function [data, info] = tRPYCommand
%TRPYCommand gives an empty data for quadrotor_msgs/TRPYCommand
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'quadrotor_msgs/TRPYCommand';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.Thrust, info.Thrust] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Roll, info.Roll] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Pitch, info.Pitch] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Yaw, info.Yaw] = ros.internal.ros.messages.ros.default_type('single',1);
[data.Aux, info.Aux] = ros.internal.ros.custommessages.quadrotor_msgs.auxCommand;
info.Aux.MLdataType = 'struct';
info.MessageType = 'quadrotor_msgs/TRPYCommand';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,16);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'thrust';
info.MatPath{8} = 'roll';
info.MatPath{9} = 'pitch';
info.MatPath{10} = 'yaw';
info.MatPath{11} = 'aux';
info.MatPath{12} = 'aux.current_yaw';
info.MatPath{13} = 'aux.kf_correction';
info.MatPath{14} = 'aux.angle_corrections';
info.MatPath{15} = 'aux.enable_motors';
info.MatPath{16} = 'aux.use_external_yaw';

function [data, info] = statusData
%StatusData gives an empty data for quadrotor_msgs/StatusData
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'quadrotor_msgs/StatusData';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.LoopRate, info.LoopRate] = ros.internal.ros.messages.ros.default_type('uint16',1);
[data.Voltage, info.Voltage] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Seq, info.Seq] = ros.internal.ros.messages.ros.default_type('uint8',1);
info.MessageType = 'quadrotor_msgs/StatusData';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,9);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'loop_rate';
info.MatPath{8} = 'voltage';
info.MatPath{9} = 'seq';

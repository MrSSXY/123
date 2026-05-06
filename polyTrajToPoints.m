function [xx, yy, zz] = polyTrajToPoints(traj_msg, dt)
% polyTrajToPoints 从 quadrotor_msgs/PolynomialTrajectory 消息生成离散轨迹点
%   traj_msg : 一个 PolynomialTrajectory 消息对象
%   dt       : 采样时间步长（秒，默认 0.02）
%   xx, yy, zz : 离散点坐标列向量

if nargin < 2
    dt = 0.02;
end

% 获取分段数量 (转为 double)
num_seg = double(traj_msg.NumSegment);
if num_seg == 0
    xx = []; yy = []; zz = [];
    return;
end

% 各段的时间长度（double[]，长度为 num_seg）
seg_durations = double(traj_msg.Time);
if length(seg_durations) ~= num_seg
    error('分段数与 Time 长度不匹配：%d vs %d', num_seg, length(seg_durations));
end

% 各段的多项式阶数（uint32[] -> double[]）
orders = double(traj_msg.Order);
if length(orders) ~= num_seg
    error('分段数与 Order 长度不匹配：%d vs %d', num_seg, length(orders));
end

% 系数是 flat 数组（double[]）
coefX_flat = double(traj_msg.CoefX);
coefY_flat = double(traj_msg.CoefY);
coefZ_flat = double(traj_msg.CoefZ);

% 计算系数总数（所有分段系数个数之和）
total_coefs = sum(orders + 1);
if length(coefX_flat) ~= total_coefs || length(coefY_flat) ~= total_coefs || length(coefZ_flat) ~= total_coefs
    error('系数数组总长度与期望不符：期望 %d，实际 X:%d Y:%d Z:%d', ...
        total_coefs, length(coefX_flat), length(coefY_flat), length(coefZ_flat));
end

% 分割系数到每个分段
coefX_cell = cell(num_seg, 1);
coefY_cell = cell(num_seg, 1);
coefZ_cell = cell(num_seg, 1);
idx = 1;  % double
for i = 1:num_seg
    order = orders(i);
    ncoef = order + 1;
    coefX_cell{i} = reshape(coefX_flat(idx:idx+ncoef-1), 1, ncoef);
    coefY_cell{i} = reshape(coefY_flat(idx:idx+ncoef-1), 1, ncoef);
    coefZ_cell{i} = reshape(coefZ_flat(idx:idx+ncoef-1), 1, ncoef);
    idx = idx + ncoef;
end

% 生成整条轨迹
xx = []; yy = []; zz = [];
for seg = 1:num_seg
    T = seg_durations(seg);
    if T <= 1e-6
        continue;
    end
    order = orders(seg);
    ncoef = order + 1;
    coefX = coefX_cell{seg};
    coefY = coefY_cell{seg};
    coefZ = coefZ_cell{seg};
    
    % 采样时刻（从 0 到 T，步长 dt）
    t_sample = (0:dt:T)';
    if t_sample(end) < T - 1e-6
        t_sample = [t_sample; T];
    end
    
    % 构建时间矩阵 [1, t, t^2, ..., t^order]
    t_pow = ones(length(t_sample), ncoef);
    for k = 1:order
        t_pow(:, k+1) = t_sample .^ k;
    end
    
    % 计算该段 x,y,z
    x_seg = t_pow * coefX';
    y_seg = t_pow * coefY';
    z_seg = t_pow * coefZ';
    
    % 拼接（除第一段外，去掉第一个点避免重复）
    if seg == 1
        xx = x_seg; yy = y_seg; zz = z_seg;
    else
        xx = [xx; x_seg(2:end)];
        yy = [yy; y_seg(2:end)];
        zz = [zz; z_seg(2:end)];
    end
end
end
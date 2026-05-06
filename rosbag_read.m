%% 清理工作区
clear; close all; clc;

%% 1. 打开 bag 文件
bag_file = 'D:\bag\data1.bag';
if ~exist(bag_file, 'file')
    error('找不到 bag 文件: %s', bag_file);
end
bag = rosbag(bag_file);
fprintf('成功打开 bag 文件: %s\n', bag_file);

%% 2. 读取各话题消息
odom = bag.select('Topic', '/visual_slam/odom');
odom_data = readMessages(odom);
fprintf('读取 /visual_slam/odom: %d 条消息\n', length(odom_data));

static_obs = bag.select('Topic', '/random_complex/static_obstacle_markers');
static_obs_data = readMessages(static_obs);
fprintf('读取 /random_complex/static_obstacle_markers: %d 条消息\n', length(static_obs_data));

dynamic_obs = bag.select('Topic', '/random_complex/obstacle_markers');
dynamic_obs_data = readMessages(dynamic_obs);
fprintf('读取 /random_complex/obstacle_markers: %d 条消息\n', length(dynamic_obs_data));

raw_path = bag.select('Topic', '/trajectory_generator_node/vis_path');
raw_path_data = readMessages(raw_path);
fprintf('读取 /trajectory_generator_node/vis_path: %d 条消息\n', length(raw_path_data));

optimized_traj = bag.select('Topic', '/trajectory_generator_node/trajectory');
optimized_traj_data = readMessages(optimized_traj);
fprintf('读取 /trajectory_generator_node/trajectory: %d 条消息\n', length(optimized_traj_data));

%% 3. 提取无人机里程计数据（nav_msgs/Odometry）
n_odom = length(odom_data);
odom_time = zeros(n_odom, 1);
odom_x = zeros(n_odom, 1);
odom_y = zeros(n_odom, 1);
odom_z = zeros(n_odom, 1);
odom_vx = zeros(n_odom, 1);
odom_vy = zeros(n_odom, 1);

for i = 1:n_odom
    msg = odom_data{i};
    odom_time(i) = msg.Header.Stamp.Sec + msg.Header.Stamp.Nsec * 1e-9;
    odom_x(i) = msg.Pose.Pose.Position.X;
    odom_y(i) = msg.Pose.Pose.Position.Y;
    odom_z(i) = msg.Pose.Pose.Position.Z;
    odom_vx(i) = msg.Twist.Twist.Linear.X;
    odom_vy(i) = msg.Twist.Twist.Linear.Y;
end
odom_time = odom_time - odom_time(1);   % 时间归零

%% 4. 无人机高度图
figure('Name', 'Drone Height');
plot(odom_time, odom_z, 'b-', 'LineWidth', 1.5);
xlabel('Time (s)'); ylabel('Height (m)'); title('Drone Height over Time'); grid on;

%% 5. 无人机速度图
figure('Name', 'Drone Velocity');
plot(odom_time, odom_vx, 'r-', 'LineWidth', 1.5); hold on;
plot(odom_time, odom_vy, 'g-', 'LineWidth', 1.5);
xlabel('Time (s)'); ylabel('Velocity (m/s)'); legend('Vx', 'Vy');
title('Drone Linear Velocities'); grid on;

%% 6. 无人机三维轨迹
figure('Name', 'Drone 3D Trajectory');
plot3(odom_x, odom_y, odom_z, 'k-', 'LineWidth', 2);
xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)'); title('Drone 3D Trajectory');
grid on; view(45, 30);

%% 7. 静态障碍物（从 MarkerArray 中提取）
figure('Name', 'Static Obstacles');
hold on;
for i = 1:length(static_obs_data)
    marker_array = static_obs_data{i};
    for j = 1:length(marker_array.Markers)
        marker = marker_array.Markers(j);
        x = marker.Pose.Position.X; y = marker.Pose.Position.Y;
        z = marker.Pose.Position.Z; h = marker.Scale.Z;
        plot3([x x], [y y], [z z+h], 'r-', 'LineWidth', 2);
        plot3(x, y, z + h/2, 'ro', 'MarkerSize', 6, 'MarkerFaceColor', 'r');
    end
end
xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)'); title('Static Obstacles');
grid on; view(45, 30); hold off;

%% 8. 动态障碍物
figure('Name', 'Dynamic Obstacles');
hold on;
for i = 1:length(dynamic_obs_data)
    marker_array = dynamic_obs_data{i};
    for j = 1:length(marker_array.Markers)
        marker = marker_array.Markers(j);
        x = marker.Pose.Position.X; y = marker.Pose.Position.Y;
        z = marker.Pose.Position.Z; h = marker.Scale.Z;
        plot3([x x], [y y], [z z+h], 'b-', 'LineWidth', 2);
        plot3(x, y, z + h/2, 'bo', 'MarkerSize', 6, 'MarkerFaceColor', 'b');
    end
end
xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)'); title('Dynamic Obstacles');
grid on; view(45, 30); hold off;

%% 9. 原始路径（vis_path 是 visualization_msgs/Marker）
figure('Name', 'Raw Path (Before Minisnap)');
hold on;
for i = 1:length(raw_path_data)
    marker = raw_path_data{i};
    pts = marker.Points;          % Point 对象数组
    if isempty(pts), continue; end
    x = [pts.X]; y = [pts.Y]; z = [pts.Z];
    plot3(x, y, z, 'g-', 'LineWidth', 1.5);
end
xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)');
title('Raw Path (Before Minisnap)');
grid on; view(45, 30); hold off;

%% 10. 优化轨迹：从多项式消息生成离散点
figure('Name', 'Optimized Trajectory (After Minisnap)');
hold on;
if ~isempty(optimized_traj_data)
    for i = 1:length(optimized_traj_data)
        try
            [x_opt, y_opt, z_opt] = polyTrajToPoints(optimized_traj_data{i}, 0.02);
            if ~isempty(x_opt)
                plot3(x_opt, y_opt, z_opt, 'm-', 'LineWidth', 2);
            else
                warning('第 %d 条优化轨迹生成点集为空', i);
            end
        catch ME
            warning('无法处理第 %d 条优化轨迹消息: %s', i, ME.message);
        end
    end
else
    text(0.5, 0.5, 0.5, '无优化轨迹数据', 'HorizontalAlignment', 'center');
end
xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)');
title('Optimized Trajectory (After Minisnap)');
grid on; view(45, 30); hold off;

%% 11. 综合三维视图
figure('Name', 'Comprehensive View');
hold on;

% 静态障碍物
for i = 1:length(static_obs_data)
    marker_array = static_obs_data{i};
    for j = 1:length(marker_array.Markers)
        marker = marker_array.Markers(j);
        x = marker.Pose.Position.X; y = marker.Pose.Position.Y;
        z = marker.Pose.Position.Z; h = marker.Scale.Z;
        plot3([x x], [y y], [z z+h], 'r-', 'LineWidth', 1);
    end
end

% 动态障碍物
for i = 1:length(dynamic_obs_data)
    marker_array = dynamic_obs_data{i};
    for j = 1:length(marker_array.Markers)
        marker = marker_array.Markers(j);
        x = marker.Pose.Position.X; y = marker.Pose.Position.Y;
        z = marker.Pose.Position.Z; h = marker.Scale.Z;
        plot3([x x], [y y], [z z+h], 'b-', 'LineWidth', 1);
    end
end

% 原始路径
for i = 1:length(raw_path_data)
    marker = raw_path_data{i};
    pts = marker.Points;
    if isempty(pts), continue; end
    x = [pts.X]; y = [pts.Y]; z = [pts.Z];
    plot3(x, y, z, 'g--', 'LineWidth', 1);
end

% 无人机轨迹
plot3(odom_x, odom_y, odom_z, 'k-', 'LineWidth', 2);

% 优化轨迹（多项式采样）
for i = 1:length(optimized_traj_data)
    try
        [x_opt, y_opt, z_opt] = polyTrajToPoints(optimized_traj_data{i}, 0.05);
        if ~isempty(x_opt)
            plot3(x_opt, y_opt, z_opt, 'c-', 'LineWidth', 1.5);
        end
    catch
    end
end

legend('Static Obs', 'Dynamic Obs', 'Raw Path', 'Drone Traj', 'Optimized', 'Location', 'best');
xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)'); title('Comprehensive 3D View');
grid on; view(45, 30); hold off;

fprintf('绘图完成。\n');
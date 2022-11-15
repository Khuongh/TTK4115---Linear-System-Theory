load('Lab_4_case_files\Encoder_and_estimate_data\case_1.11.mat')
load('Lab_4_case_files\Measurements_data\case_1.11.mat');


figure(1)

subplot(2,1,1)
plot( data_y(1,:), data_y(2,:), data_p(1,:), data_p(3,:), data_p(1,:), data_p(2,:))
grid on;
legend('IMU value', 'Estimation value', 'Encoder value')
xlabel('Time [s]')
ylabel('Value [rad]')
xlim([0 50])
title('PITCH')

subplot(2,1,2)
plot(data_y(1,:), data_y(3,:), data_y(1,:), data_y(3,:), data_p(1,:), data_p(5,:))
grid on;,

legend('IMU value', 'Estimation value', 'Encoder value')
xlabel('Time [s]')
ylabel('Value [rad/s]')
xlim([0 50])
title('PITCH RATE')


figure(2)

subplot(2,1,1)
plot( data_y(1,:), data_y(4,:), data_p(1,:), data_p(7,:), data_p(1,:), data_p(6,:))
grid on;
legend('IMU value', 'Estimation value', 'Encoder value')
xlabel('Time [s]')
ylabel('Value [rad]')
xlim([0 50])
title('ELEVATION')

subplot(2,1,2)
plot( data_y(1,:), data_y(5,:), data_p(1,:), data_p(9,:), data_p(1,:), data_p(8,:))
grid on;
legend('IMU value', 'Estimation value', 'Encoder value')
xlabel('Time [s]')
ylabel('Value [rad/s]')
xlim([0 50])
title('ELEVATION RATE')


figure(3)

subplot(2,1,1)
plot( data_y(1,:), data_y(6,:), data_p(1,:), data_p(11,:), data_p(1,:), data_p(10,:))
grid on;
legend('IMU value', 'Estimation value', 'Encoder value')
xlabel('Time [s]')
ylabel('Value [rad/s]')
xlim([0 50])
title('TRAVEL')

subplot(2,1,2)
plot(data_y(1,:), data_y(7,:), data_p(1,:), data_p(13,:), data_p(1,:), data_p(12,:))
grid on;
legend('IMU value', 'Estimation value', 'Encoder value')
xlabel('Time [s]')
ylabel('Value [rad/s]')
xlim([0 50])
title('TRAVEL RATE')
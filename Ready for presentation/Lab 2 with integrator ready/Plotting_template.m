load('Lab_2_case_files\Lab2_case_3.1.mat')

figure(1)

subplot(2,1,1)
plot(data(1,:), data(4,:), data(1,:), data(5,:), data(1,:), data(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('PITCH')

subplot(2,1,2)
plot(data(1,:), data(6,:), data(1,:), data(7,:), data(1,:), data(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('ELEVATION')

load('Lab_2_case_files\Lab2_case_3.2.mat')

figure(2)

subplot(2,1,1)
plot(data(1,:), data(4,:), data(1,:), data(5,:), data(1,:), data(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('PITCH')

subplot(2,1,2)
plot(data(1,:), data(6,:), data(1,:), data(7,:), data(1,:), data(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('ELEVATION')
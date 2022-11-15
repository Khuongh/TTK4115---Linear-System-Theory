load('Lab_4_case_files\Lab_4_noise_flying.mat')

data_new = data'
data_new(:,1) = []
data_cov = cov(data_new)



figure(1)

subplot(2,1,1)
plot(data(1,:), data(2,:))
grid on;
legend('Pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 20])
ylim([0 0.025])
title('PITCH')

subplot(2,1,2)
plot(data(1,:), data(3,:))
grid on;
legend('Pitch rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 20])
ylim([-0.01 0.01])
title('PITCH RATE')

figure(2)

subplot(2,1,1)
plot(data(1,:), data(4,:))
grid on;
legend('Elevation [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 20])
ylim([-0.55 -0.5])
title('ELEVATION')

subplot(2,1,2)
plot(data(1,:), data(5,:))
grid on;
legend('Elevation rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 20])
ylim([-0.01 0.01])
title('ELEVATION RATE')

figure(3)

subplot(2,1,1)
plot(data(1,:), data(6,:))
grid on;
legend('Travel [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 20])
title('TRAVEL')

subplot(2,1,2)
plot(data(1,:), data(7,:))
grid on;
legend('Travel rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 20])
ylim([-0.01 0.01])
title('TRAVEL RATE')
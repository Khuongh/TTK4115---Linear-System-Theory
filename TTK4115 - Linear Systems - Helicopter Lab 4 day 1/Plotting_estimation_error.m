load('Lab_4_case_files\Lab_4_case_1.4_error.mat')


figure(1)

subplot(2,1,1)
plot(data(1,:), data(2,:))
grid on;
legend('Pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 30])
title('PITCH ESTIMATION ERROR')

subplot(2,1,2)
plot(data(1,:), data(3,:))
grid on;
legend('Pitch rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 30])
title('PITCH RATE ESTIMATION ERROR')


figure(2)

subplot(2,1,1)
plot(data(1,:), data(4,:))
grid on;
legend('Elevation [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 30])
title('ELEVATION ESTIMATION ERROR')

subplot(2,1,2)
plot(data(1,:), data(5,:))
grid on;
legend('Elevation rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 30])
title('ELEVATION RATE ESTIMATION ERROR')


figure(3)

subplot(2,1,1)
plot(data(1,:), data(6,:))
grid on;
legend('Travel [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 30])
title('TRAVEL ESTIMATION ERROR')

subplot(2,1,2)
plot(data(1,:), data(7,:))
grid on;
legend('Travel rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 30])
title('TRAVEL RATE ESTIMATION ERROR')
load('Lab_3_case_files\Lab_3_case_1.10.mat')

figure(1)

subplot(2,1,1)
plot(data(1,:), data(2,:), data(1,:), data(3,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad]', 'Estimated [rad]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('PITCH')

subplot(2,1,2)
plot(data(1,:), data(4,:), data(1,:), data(5,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad/s]', 'Estimated [rad/s]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('PITCH RATE')

sgtitle('PITCH AND PITCH RATE')


figure(2)

subplot(2,1,1)
plot(data(1,:), data(6,:), data(1,:), data(7,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad]', 'Estimated [rad]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('ELEVATION')

subplot(2,1,2)
plot(data(1,:), data(8,:), data(1,:), data(9,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad/s]', 'Estimated [rad/s]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('ELEVATION RATE')

sgtitle('ELEVATION AND ELEVATION RATE')


figure(3)
plot(data(1,:), data(10,:), data(1,:), data(11,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad/s]', 'Estimated [rad/s]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('TRAVEL RATE')





load('Lab_3_case_files\Lab_3_case_1.1.mat')

figure(4)

subplot(2,1,1)
plot(data(1,:), data(2,:), data(1,:), data(3,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad]', 'Estimated [rad]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('PITCH')

subplot(2,1,2)
plot(data(1,:), data(4,:), data(1,:), data(5,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad/s]', 'Estimated [rad/s]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('PITCH RATE')

sgtitle('PITCH AND PITCH RATE')


figure(5)

subplot(2,1,1)
plot(data(1,:), data(6,:), data(1,:), data(7,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad]', 'Estimated [rad]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('ELEVATION')

subplot(2,1,2)
plot(data(1,:), data(8,:), data(1,:), data(9,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad/s]', 'Estimated [rad/s]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('ELEVATION RATE')

sgtitle('ELEVATION AND ELEVATION RATE')


figure(6)
plot(data(1,:), data(10,:), data(1,:), data(11,:), data(1,:), data(12,:), data(1,:), data(13,:))
grid on;
legend('Encoder [rad/s]', 'Estimated [rad/s]', 'Ref. pitch [rad]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 60])
title('TRAVEL RATE')
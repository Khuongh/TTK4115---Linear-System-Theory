%% 
%Loading data
load('Lab_2_case_files\Lab2_case_1.1.1.mat')
data1 = data;
load('Lab_2_case_files\Lab2_case_1.2.1.mat')
data2 = data;
load('Lab_2_case_files\Lab2_case_1.2.2.mat')
data3 = data;
load('Lab_2_case_files\Lab2_case_1.2.3.mat')
data4 = data;
load('Lab_2_case_files\Lab2_case_1.2.4.mat')
data5 = data;
load('Lab_2_case_files\Lab2_case_1.3.1.mat')
data6 = data;
load('Lab_2_case_files\Lab2_case_1.3.2.mat')
data7 = data;
load('Lab_2_case_files\Lab2_case_1.3.3.mat')
data8 = data;
load('Lab_2_case_files\Lab2_case_1.3.4.mat')
data9 = data;
load('Lab_2_case_files\Lab2_case_1.4.1.mat')
data10 = data;
load('Lab_2_case_files\Lab2_case_1.4.2.mat')
data11 = data;
load('Lab_2_case_files\Lab2_case_1.4.3.mat')
data12 = data;
load('Lab_2_case_files\Lab2_case_1.4.3.2.mat')
data13 = data;
load('Lab_2_case_files\Lab2_case_1.4.4.mat')
data14 = data;
load('Lab_2_case_files\Lab2_case_1.5.1.mat')
data15 = data;
load('Lab_2_case_files\Lab2_case_1.5.2.mat')
data16 = data;
load('Lab_2_case_files\Lab2_case_1.5.3.mat')
data17 = data;
load('Lab_2_case_files\Lab2_case_2.1.1.mat')
data18 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.1.mat')
data19 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.2.mat')
data30 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.3.mat')
data31 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.4.mat')
data32 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.5.mat')
data33 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.6.mat')
data34 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.7.mat')
data35 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.8.mat')
data36 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.9.mat')
data37 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.10.mat')
data38 = data;
load('Lab_2_case_files_2\Lab2_case_2.2.11.mat')
data39 = data;

%% 

figure(1)

subplot(2,1,1)
plot(data1(1,:), data1(4,:), data1(1,:), data1(5,:), data1(1,:), data1(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 1])
title('Case 1.1.1, PITCH')

subplot(2,1,2)
plot(data(1,:), data(6,:), data(1,:), data(7,:), data(1,:), data(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.1.1, ELEVATION')

%%

figure(2)

subplot(2,2,1)
plot(data3(1,:), data3(4,:), data3(1,:), data3(5,:), data3(1,:), data3(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1.1 1])
title('Case 1.2.2, PITCH')

subplot(2,2,3)
plot(data3(1,:), data3(6,:), data3(1,:), data3(7,:), data3(1,:), data3(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.2.2, ELEVATION')

subplot(2,2,2)
plot(data5(1,:), data5(4,:), data5(1,:), data5(5,:), data5(1,:), data5(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 1])
title('Case 1.2.4, PITCH')

subplot(2,2,4)
plot(data5(1,:), data5(6,:), data5(1,:), data5(7,:), data5(1,:), data5(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]',  'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.2.4, ELEVATION')

%%

figure(3)

subplot(2,2,1)
plot(data7(1,:), data7(4,:), data7(1,:), data7(5,:), data7(1,:), data7(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 1])
title('Case 1.3.2, PITCH')

subplot(2,2,3)
plot(data7(1,:), data7(6,:), data7(1,:), data7(7,:), data7(1,:), data7(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.3.2, ELEVATION')

subplot(2,2,2)
plot(data9(1,:), data9(4,:), data9(1,:), data9(5,:), data9(1,:), data9(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 1])
title('Case 1.3.4, PITCH')

subplot(2,2,4)
plot(data9(1,:), data9(6,:), data9(1,:), data9(7,:), data9(1,:), data9(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]',  'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.3.4, ELEVATION')

%%

figure(4)

subplot(2,2,1)
plot(data12(1,:), data12(4,:), data12(1,:), data12(5,:), data12(1,:), data12(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 1])
title('Case 1.4.3, PITCH')

subplot(2,2,3)
plot(data12(1,:), data12(6,:), data12(1,:), data12(7,:), data12(1,:), data12(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.4.3, ELEVATION')

subplot(2,2,2)
plot(data14(1,:), data14(4,:), data14(1,:), data14(5,:), data14(1,:), data14(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 1])
title('Case 1.4.4, PITCH')

subplot(2,2,4)
plot(data14(1,:), data14(6,:), data14(1,:), data14(7,:), data14(1,:), data14(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]',  'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.4.4, ELEVATION')

%%

figure(5)

subplot(2,2,1)
plot(data15(1,:), data15(4,:), data15(1,:), data15(5,:), data15(1,:), data15(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 1])
title('Case 1.4.3, PITCH')

subplot(2,2,3)
plot(data15(1,:), data15(6,:), data15(1,:), data15(7,:), data15(1,:), data15(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]', 'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.4.3, ELEVATION')

subplot(2,2,2)
plot(data16(1,:), data16(4,:), data16(1,:), data16(5,:), data16(1,:), data16(8,:))
grid on;
legend('Pitch [rad]', 'Pitch rate [rad/s]', 'Ref. pitch [rad]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 1])
title('Case 1.4.4, PITCH')

subplot(2,2,4)
plot(data16(1,:), data16(6,:), data16(1,:), data16(7,:), data16(1,:), data16(9,:))
grid on;
legend('Elevation [rad]', 'Elevation rate [rad/s]',  'Ref. elev. rate [rad/s]')
xlabel('Time [s]')
ylabel('Value')
xlim([0 70])
ylim([-1 2])
title('Case 1.4.4, ELEVATION')

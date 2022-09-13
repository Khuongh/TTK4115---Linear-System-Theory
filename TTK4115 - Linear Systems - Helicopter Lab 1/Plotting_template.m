%% Load all files and store arrays in workspace
load('Lab1_case1_1_1.mat')
data1 = data;
load('Lab1_case1_1_2.mat')
data2 = data;
load('Lab1_case1_1_3.mat')
data3 = data;

load('Lab1_case1_2_1.mat')
data4 = data;
load('Lab1_case1_2_2.mat')
data5 = data;
load('Lab1_case1_2_3.mat')
data6 = data;
load('Lab1_case1_2_4.mat')
data7 = data;

load('Lab1_case1_3_1.mat')
data8 = data;
load('Lab1_case1_3_2.mat')
data9 = data;

load('Lab1_case1_4_1.mat')
data10 = data;
load('Lab1_case1_4_2.mat')
data11 = data;
load('Lab1_case1_4_3.mat')
data12 = data;

load('Lab1_case1_5_1.mat')
data13 = data;
load('Lab1_case1_5_2.mat')
data14 = data;

load('Lab1_case1_6_1.mat')
data15 = data;

load('Lab1_case1_7_1.mat')
data16 = data;
load('Lab1_case1_7_2.mat')
data17 = data;

%% Plot figures
figure(1)
subplot(3,1,1)
plot(data1(1,:),data1(4,:), data1(1,:),data1(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
xlim([0 50])
title('Case 1.1.1: \lambda_1 = \lambda_2 = -1');

subplot(3,1,2)
plot(data2(1,:),data2(4,:), data2(1,:),data2(8,:))
grid on;
legend('Pitch [rad]', 'Step response')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('Case 1.1.2: \lambda_1 = \lambda_2 = -3')

subplot(3,1,3)
plot(data3(1,:),data3(4,:), data3(1,:),data3(8,:))
grid on;
legend('Pitch [rad]', 'Step response')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('Case 1.1.3: \lambda_1 = \lambda_2 = -7')

figure(2)
subplot(2,2,1)
plot(data4(1,:),data4(4,:), data4(1,:),data4(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
xlim([0 50])
title('Case 1.2.1: \lambda_1 = -10 , \lambda_2 = -3');

subplot(2,2,2)
plot(data5(1,:),data5(4,:), data5(1,:),data5(8,:))
grid on;
legend('Pitch [rad]', 'Step response')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('Case 1.2.2: \lambda_1 = -7 , \lambda_2 = -3')

subplot(2,2,3)
plot(data6(1,:),data6(4,:), data6(1,:),data6(8,:))
grid on;
legend('Pitch [rad]', 'Step response')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('Case 1.2.3: \lambda_1 = -7 , \lambda_2 = -0.5')

subplot(2,2,4)
plot(data7(1,:),data7(4,:), data7(1,:),data7(8,:))
grid on;
legend('Pitch [rad]', 'Step response')
xlabel('Time [s]')
ylabel('Value')
xlim([0 50])
title('Case 1.2.4: \lambda_1 = -15 , \lambda_2 = -3')

figure(3)
subplot(2,1,1)
plot(data8(1,:),data8(4,:), data8(1,:),data8(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
title('Case 1.3.1: \lambda_1 = j , \lambda_2 = -j');

subplot(2,1,2)
plot(data9(1,:),data9(4,:), data9(1,:),data9(8,:))
grid on;
legend('Pitch [rad]', 'Step response')
xlabel('Time [s]')
ylabel('Value')
title('Case 1.3.2: \lambda_1 = j5 , \lambda_2 = -j5')

figure(4)
subplot(3,1,1)
plot(data10(1,:),data10(4,:), data10(1,:),data10(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
title('Case 1.4.1: \lambda_1 = -3+j3 , \lambda_2 = -3-j3');

subplot(3,1,2)
plot(data11(1,:),data11(4,:), data11(1,:),data11(8,:))
grid on;
legend('Pitch [rad]', 'Step response')
xlabel('Time [s]')
ylabel('Value')
title('Case 1.4.2: \lambda_1 = -3+j4 , \lambda_2 = -3-j4')

subplot(3,1,3)
plot(data12(1,:),data12(4,:), data12(1,:),data12(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
title('Case 1.4.3: \lambda_1 = -1+j4 , \lambda_2 = -1-j4');

figure(5)
subplot(2,1,1)
plot(data13(1,:),data13(4,:), data13(1,:),data13(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
title('Case 1.5.1: \lambda_1 = 0.1+j0.1 , \lambda_2 = 0.1-j0.1');

subplot(2,1,2)
plot(data14(1,:),data14(4,:), data14(1,:),data14(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
title('Case 1.5.2: \lambda_1 = ??? , \lambda_2 = ???');

figure(6)
plot(data15(1,:),data15(4,:), data15(1,:),data15(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
title('Case 1.6.1: \lambda_1 = 0.01 , \lambda_2 = 0.03');

figure(7)
subplot(2,1,1)
plot(data16(1,:),data16(4,:), data16(1,:),data16(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
title('Case 1.7.1: \lambda_1 = -3 , \lambda_2 = 0.05');

subplot(2,1,2)
plot(data17(1,:),data17(4,:), data17(1,:),data17(8,:))
grid on;
legend('Pitch [rad]', 'Step response');
xlabel('Time [s]');
ylabel('Value');
title('Case 1.7.2: \lambda_1 = -3 , \lambda_2 = 0.2');
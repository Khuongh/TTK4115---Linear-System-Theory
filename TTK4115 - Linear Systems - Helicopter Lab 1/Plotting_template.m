load('Lab1_case1_7_2.mat')

figure(1)
plot(data(1,:),data(4,:), data(1,:),data(8,:))
grid on;
legend('Pitch [rad]', 'Step response')
xlabel('Time [s]')
ylabel('Value')
title('Case 1.1.1: lambda1 = -1, lambda2 = -1')
%plot(Data.spec(:,1), Data.spec(:,2))

%, data(1,:),data(5,:)
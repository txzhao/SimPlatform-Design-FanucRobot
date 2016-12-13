figure(1)
subplot(2,1,1);
plot(xxx(:,1),xxx(:,2),'b');
xlabel('Time(s)');
ylabel('v(m/s)');
legend('EndVz');
grid on
subplot(2,1,2);
plot(yyy(:,1),yyy(:,2),'b');
grid on;
xlabel('Time(s)');
ylabel('v(m/s)');
legend('EndVy');
figure(2)
plot(xxx(:,2),yyy(:,2));
figure(3)
plot3(xxx(:,2),yyy(:,2),zeros(32001,1));
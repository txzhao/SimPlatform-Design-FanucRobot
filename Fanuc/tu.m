Axis=1;
Num=size(RefPosVelPulse.signals.values,1);
t=[0:1:Num-1]*Ts;
Input_pp=RefPosPulse.signals.values(:,1)/Gear(Axis)/EncRes*360 +a1;
Response_pp=(EncJVAJ1.signals.values(:,1));
figure(1)
plot(t,Input_pp,'b');
hold on;
plot(t,Response_pp,'r');
hold off;
grid on;
figure(2)
plot(t,Input_pp-Response_pp,'b');
grid on;
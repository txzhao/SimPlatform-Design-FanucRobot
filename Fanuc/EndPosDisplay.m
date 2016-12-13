function EndPosDisplay(EndPosX,EndPosY,EndPosZ)
tX=EndPosX(:,1);
tY=EndPosY(:,1);
tZ=EndPosZ(:,1);
EndX=EndPosX(:,2);
EndY=EndPosY(:,2);
EndZ=EndPosZ(:,2);
RefEndX=EndPosX(:,3);
RefEndY=EndPosY(:,3);
RefEndZ=EndPosZ(:,3);
    
figure(1)
plot(tX,EndX,'r');
hold on;
plot(tX,RefEndX,'b');
hold off;
grid on;
title('End Position of X (mm)');
xlabel('Time(s)');
ylabel('X(mm)');
legend('Response','Input');

figure(2)
plot(tY,EndY,'r');
hold on;
plot(tY,RefEndY,'b');
hold off;
grid on;
title('End Position of Y (mm)');
xlabel('Time(s)');
ylabel('Y(mm)');
legend('Response','Input');

figure(3)
plot(tZ,EndZ,'r');
hold on;
plot(tZ,RefEndZ,'b');
hold off;
grid on;
title('End Position of Z (mm)');
xlabel('Time(s)');
ylabel('Z(mm)');
legend('Response','Input');

figure(4)
plot(tX,RefEndX-EndX,'b');
grid on;
title('Position Error of X (mm)');
xlabel('Time(s)');
ylabel('X(mm)');

figure(5)
plot(tY,RefEndY-EndY,'b');
grid on;
title('Position Error of Y (mm)');
xlabel('Time(s)');
ylabel('Y(mm)');

figure(6)
plot(tZ,RefEndZ-EndZ,'b');
grid on;
title('Position Error of Z (mm)');
xlabel('Time(s)');
ylabel('Z(mm)');

figure(7)
plot3(EndX,EndY,EndZ,'r');
hold on;
plot3(RefEndX,RefEndY,RefEndZ,'b');
hold off;
grid on;
title('End Trajectory in 3D');
xlabel('X(mm)');
ylabel('Y(mm)');
zlabel('Z(mm)');
legend('Response','Input');

figure(8)
plot(EndX,EndY,'r');
hold on;
plot(RefEndX,RefEndY,'b');
hold off;
grid on;
title('End Trajectory in X-Y Coordinates');
xlabel('X(mm)');
ylabel('Y(mm)');
legend('Response','Input');

figure(9)
plot(EndY,EndZ,'r');
hold on;
plot(RefEndY,RefEndZ,'b');
hold off;
grid on;
title('End Trajectory in Y-Z Coordinates');
xlabel('Y(mm)');
ylabel('Z(mm)');
legend('Response','Input');

figure(10)
plot(EndX,EndZ,'r');
hold on;
plot(RefEndX,RefEndZ,'b');
hold off;
grid on;
title('End Trajectory in X-Z Coordinates');
xlabel('X(mm)');
ylabel('Z(mm)');
legend('Response','Input');

end

        

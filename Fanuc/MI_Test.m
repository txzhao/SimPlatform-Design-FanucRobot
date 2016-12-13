clear all;
clc;

ma1 = 170.31;
in1 = [5.2954 -0.2565 -0.6366;-0.2565 4.7000 0.2830;-0.6366 0.2829 5.8635];
cen1 = [0.0407 -0.0528 0.4702];

ma2 = 63.74;
in2 = [5.8840 0.0072 0.0135;0.0072 6.0178 -0.1907;0.0135 -0.1907 0.3374];
cen2 = [0.1510 0.1746 0.9687];

ma3 = 98.98;
in3 = [1.8201 -0.2274 -0.3112;-0.2274 2.2537 -0.1441;-0.3112 -0.1441 1.9485];
cen3 = [0.1568 -0.0318 1.5191];

ma4 = 24.46;
in4 = [0.0607 -0.0922 0;-0.0922 1.4493 0;0 0,1.4620];
cen4 = [0.8245 -0.0110 1.606];

ma5 = 5.24;
in5 = [0.0191 0.0032 0;0.0032 0.0228 0;0 0 0.0291];
cen5 = [1.2407 0.0180 1.606];

ma6 = 0.6;
in6 = [0.0012 0 0;0 0.0007 0;0 0 0.0007];
cen6 = [1.330 0 1.606];

Ma = [ma1  ma2  ma3  ma4  ma5  ma6];
Ie1 = in1(:)';
Ie2 = in2(:)';
Ie3 = in3(:)';
Ie4 = in4(:)';
Ie5 = in5(:)';
Ie6 = in6(:)';
Cen = [cen1;cen2;cen3;cen4;cen5;cen6];
Cen = Cen(:)';

DH_EU=[266     300     0       0       1016     0      174;
    0       0       -pi/2   0       pi      pi       0;
    0       150     870     170     0       0        0;
    0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;];
L=[266 300 150 870 0 170 1016 174]/1000;

%%%%%%%%% Assign different configurations%%%%%%%%%%%%%%
%theta=[0 0 0 0 0 0];
num=361;
th1=zeros(1,num);
th2=[-pi/2:3*pi/4/(num-1):pi/4];
th3=zeros(1,num);
th4=zeros(1,num);
th5=zeros(1,num);
th6=zeros(1,num);

for i=1:num

theta=[th1(i) th2(i) th3(i) th4(i) th5(i) th6(i)];
M6r=MotorM6(theta,L,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6,Cen);
Iz6(i)=M6r(6,6);
M5r=MotorM5(theta,L,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6,Cen);
Iz5(i)=M5r(6,6);
M4r=MotorM4(theta,L,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6,Cen);
Iz4(i)=M4r(6,6);
M3r=MotorM3(theta,L,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6,Cen);
Iz3(i)=M3r(6,6);
M2r=MotorM2(theta,L,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6,Cen);
Iz2(i)=M2r(6,6);
M1r=MotorM1(theta,L,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6,Cen);
Iz1(i)=M1r(6,6);

end


figure(1);
plot([0:1:360],Iz1);

% disp('Inertia to Motor:(kg*m^2)')
% disp([Iz1 Iz2 Iz3 Iz4 Iz5 Iz6]);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: FanucDynCAD.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 09/03/2014
%
%@Description: To calculate dynamic parameters based CAD model
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Param_a,rParam_a]=FanucDynCAD()

%%%%DH parameters, unit:m %%%%%%%%%
%%%%%%%%%%%%%%%%%%
DH=[0       0       0       566;
    -pi/2   150     -pi/2    0;
    0       870     0       0;
    -pi/2   170    0       1016;
    pi/2    0       0       0;
    -pi/2   0       0       0;
    0       0       0       174]';
DH(2,:) = DH(2,:)/1000;
DH(4,:) = DH(4,:)/1000;
Ld=[566 150 870 170 1016]/1000;


ez = [0;0;1];
ex = [1;0;0];
eo = [0;0;0];
g01_0 = expWre([ex;eo],DH(2,1))*expWre([eo;ex],DH(1,1))*expWre([ez;eo],DH(4,1))*expWre([eo;ez],DH(3,1));
g12_0 = expWre([ex;eo],DH(2,2))*expWre([eo;ex],DH(1,2))*expWre([ez;eo],DH(4,2))*expWre([eo;ez],DH(3,2));
g23_0 = expWre([ex;eo],DH(2,3))*expWre([eo;ex],DH(1,3))*expWre([ez;eo],DH(4,3))*expWre([eo;ez],DH(3,3));
g34_0 = expWre([ex;eo],DH(2,4))*expWre([eo;ex],DH(1,4))*expWre([ez;eo],DH(4,4))*expWre([eo;ez],DH(3,4));
g45_0 = expWre([ex;eo],DH(2,5))*expWre([eo;ex],DH(1,5))*expWre([ez;eo],DH(4,5))*expWre([eo;ez],DH(3,5));
g56_0 = expWre([ex;eo],DH(2,6))*expWre([eo;ex],DH(1,6))*expWre([ez;eo],DH(4,6))*expWre([eo;ez],DH(3,6));


%%%%Actual Dynamic Parameters%%%%%%%%%%%%%
%%%%%% Mass: kg  Inertia: kg/m^2  Center: m
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
in4 = [0.0607 -0.0922 0;-0.0922 1.4493 0;0 0 1.4620];
cen4 = [0.8245 -0.0110 1.606];



ma5 = 5.24;
in5 = [0.0191 0.0032 0;0.0032 0.0228 0;0 0 0.0291];
cen5 = [1.2407 0.0180 1.606];


ma6 = 0.6;
in6 = [0.0012 0 0;0 0.0007 0;0 0 0.0007];
cen6 = [1.330 0 1.606];


%%%%%%%%%%%%%%%%%%%%%%%%%%%
Ma = [ma1 ma2 ma3 ma4 ma5 ma6]';
Ie1 = in1(:);
Ie2 = in2(:);
Ie3 = in3(:);
Ie4 = in4(:);
Ie5 = in5(:);
Ie6 = in6(:);

Cen = [cen1,cen2,cen3,cen4,cen5,cen6]';
Ie = [Ie1;Ie2;Ie3;Ie4;Ie5;Ie6];

% %% calculate ri: ith link mass center offset relative to ith joint frame,i=1,2,3,4,5,6
m1  = Ma(1);
I1  = reshape(Ie(1:9),3,3);
m2  = Ma(2);
I2  = reshape(Ie(10:18),3,3);
m3  = Ma(3);
I3  = reshape(Ie(19:27),3,3);
m4  = Ma(4);
I4  = reshape(Ie(28:36),3,3);
m5  = Ma(5);
I5  = reshape(Ie(37:45),3,3);
m6  = Ma(6);
I6  = reshape(Ie(46:54),3,3);

g=g01_0;
r1 = g\[Cen(1:3);1];
r1 = r1(1:3);
g=g*g12_0;
r2 = g\[Cen(4:6);1];
r2 = r2(1:3);
R = g(1:3,1:3);
I2 = R'*I2*R;
g=g*g23_0;
r3 = g\[Cen(7:9);1];
r3 = r3(1:3);
R = g(1:3,1:3);
I3 = R'*I3*R;
g=g*g34_0;
r4 = g\[Cen(10:12);1];
r4 = r4(1:3);
R = g(1:3,1:3);
I4 = R'*I4*R;
g=g*g45_0;
r5 = g\[Cen(13:15);1];
r5 = r5(1:3);
R = g(1:3,1:3);
I5 = R'*I5*R;
g=g*g56_0;
r6 = g\[Cen(16:18);1];
r6 = r6(1:3);
R = g(1:3,1:3);
I6 = R'*I6*R;

% %% calculate momentt of inertia in Ci,i=1,2,3,4,5,6
M1  = [ m1*eye(3),      -m1*hat(r1);
        m1*hat(r1),    I1 - m1*hat(r1)*hat(r1)];


M2  = [ m2*eye(3),      -m2*hat(r2);
        m2*hat(r2),    I2 - m2*hat(r2)*hat(r2)];

M3  = [ m3*eye(3),      -m3*hat(r3);
        m3*hat(r3),    I3 - m3*hat(r3)*hat(r3)];
    

M4  = [ m4*eye(3),      -m4*hat(r4);
        m4*hat(r4),    I4 - m4*hat(r4)*hat(r4)];
    

M5  = [ m5*eye(3),      -m5*hat(r5);
        m5*hat(r5),    I5 - m5*hat(r5)*hat(r5)];
    

M6  = [ m6*eye(3),      -m6*hat(r6);
        m6*hat(r6),    I6 - m6*hat(r6)*hat(r6)];    

%%%%%Acutual Dynamic Parameters for Euler Equation%%%%%%%%%%%%%%%%%%%%%    
Param_a =[M1(1,1);M1(2,6);-M1(1,6);M1(1,5);M1(4,4);M1(5,5);M1(6,6);M1(4,5);M1(4,6);M1(5,6);
         M2(1,1);M2(2,6);-M2(1,6);M2(1,5);M2(4,4);M2(5,5);M2(6,6);M2(4,5);M2(4,6);M2(5,6);
         M3(1,1);M3(2,6);-M3(1,6);M3(1,5);M3(4,4);M3(5,5);M3(6,6);M3(4,5);M3(4,6);M3(5,6);
         M4(1,1);M4(2,6);-M4(1,6);M4(1,5);M4(4,4);M4(5,5);M4(6,6);M4(4,5);M4(4,6);M4(5,6);
         M5(1,1);M5(2,6);-M5(1,6);M5(1,5);M5(4,4);M5(5,5);M5(6,6);M5(4,5);M5(4,6);M5(5,6);
         M6(1,1);M6(2,6);-M6(1,6);M6(1,5);M6(4,4);M6(5,5);M6(6,6);M6(4,5);M6(4,6);M6(5,6)];
     
B=EulerBasis(Ld);
rParam_a=B*Param_a;

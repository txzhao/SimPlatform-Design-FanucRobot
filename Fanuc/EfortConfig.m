clear all;
clc;


%%%%%%%%%%%General Setting%%%%%%%%%%%%
% Initial Configuration
% unit of angle: deg
a1 = 0;
a2 = 0;
a3 = 0;
a4 = 0;
a5 = 90;
%a5 = 0;
a6 = 0;
A = [a1 a2 a3 a4 a5 a6]/180*pi;
%Gravity=-9.8;
Gravity=0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


    %%%%%%%%%%%%% unit of length: mm
    l1 = 504;
    l2 = 170;
    l3 = 780;
    l4 = 140;
    l5 = 760;
    l6 = 105;
    l7 = 20;
    l8 = 0;
    l9 = 0;
    L = [l1 l2 l3 l4 l5 l6 l7 l8 l9];


    %%%%%%%%%%%%%%% Mass: kg  Inertia: kg/m^2  Center: m
    %Center: relative to world frame
    %Inertia: relative to center frame, body inertia
    %ceni: mass center coordinate relative to world frame
    %ceni_1: offset coordiante of origin of visualized link relative to world frame, only for visualization
    %ceni_2: coordinate of intersection between Link i-1 and Link i relative to world frame
    %ceni_3: coordinate of intersection between Link i and Link i+1 relative to world frame
    %ceni_4: coordinate of joint frame relative to world frame
    ma1 = 77.75;
    in1 = [0.54  -0.01 0.23;
           -0.01 0.79  -0.02;
           0.23  -0.02 0.62];
    cen1 = [0.1 0.04 0.454];
    cen1_1=[0 0 0];
    cen1_2=[0 0 0];
    cen1_3=[0.17 0 0.504];
    cen1_4=[0 0 0];

    ma2 = 32.31;
    in2 = [0.1    0.01       -0.02;
           0.01   1.73       0;
           -0.02    0       1.75];
    cen2 = [0.17 0 0.974];
    cen2_1=[0 0 0];
    cen2_2=[0.17 0 0.504];
    cen2_3=[0.17 0 1.284];
    cen2_4=[0.17 0 0.504];

    ma3 = 18.61;
    in3 = [0.16   0.05   -0.02;
           0.05   0.21    -0.01;
           -0.02  -0.01   0.25];
    cen3 = [0.28 0.13 1.404];
    cen3_1=[0 0 0];
    cen3_2=[0.17 0 1.284];
    cen3_3=[0.17 0 1.424];
    cen3_4=[0.17 0 1.284];

    ma4 = 15.65;
    in4 = [0.5   0     0;
           0     0.47  0;
           0     0     0.09];
    cen4 = [0.7 0 1.424];
    cen4_1=[0 0 0];
    cen4_2=[0.17 0 1.424];
    cen4_3=[0.93 0 1.424];
    cen4_4=[0.17 0 1.424];


    ma5 = 3.32;
    in5 = [0.01    0       0;
           0       0.01    0;
           0       0       0.01];
    cen5 = [0.94  0.01 1.424];
    cen5_1=[0 0 0];
    cen5_2=[0.93 0 1.424];
    cen5_3=[1.035 0 1.424];
    cen5_4=[0.93 0 1.424];

    ma6 = 0.6;
    in6 = [0.0012   0        0;
            0       0.0007   0;
            0       0        0.0007];
    cen6 = [1.045 0 1.424];
    cen6_1=[0 0 0];
    cen6_2=[1.035 0 1.424];
    cen6_3=[1.055 0 1.424];
    cen6_4=[1.035 0 1.424];
    %%%%%%%%%%%%%
    R_x=[1 0 0;
        0  0 -1;
        0 1  0];
    R_y=[0 0 1;
        0 1 0;
        -1 0 0];
    R_z=[0 -1 0;
         1 0 0;
         0 0 1];
     Rz = [-1 0 0;
           0 -1 0;
           0 0 1];
    in2=(R_x*R_z)*in2*(R_x*R_z)';
    in3=(R_x*R_z)*in3*(R_x*R_z)';
    in4=(R_y*Rz)*in4*(R_y*Rz)';
    in5=(R_x*R_y)*in5*(R_x*R_y)';
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    Ma = [ma1 ma2 ma3 ma4 ma5 ma6]; %%%M:1x6
    Ie1 = in1(:)';  %%%Ie1: 9x1
    Ie2 = in2(:)';
    Ie3 = in3(:)';
    Ie4 = in4(:)';
    Ie5 = in5(:)';
    Ie6 = in6(:)';
    Cen = [cen1;cen2;cen3;cen4;cen5;cen6]; %%%Cen: 6x3
    Cen = Cen(:)'; %%%Cen:18x1, x1...x6 y1...y6 z1...z6

    %%%%%%%% Parameters For Newton Euler Dynamics
    %DH parameters
    %DH parameters: d(z),theta(z),a(z),alpha(x),
    %DH(1): Joint 1 Frame ----> Base Frame
    %DH(2): Joint 2 Frame ----> Joint 1 Frame
    %.......
    %DH(6): Joint 6 Frame ----> Joint 5 Frame
    %DH(7): Tool Frame    ----> Joint 6 Frame
    %For DH parameters, we didn't include tool frame considering different kinds of tools.

  
    %%%%%%%%%%%%%Efort%%%%%%%%%%%%%%%%%%
    DH_EU=[0       504     0       0       760    0         125;
            0       0       -pi/2   0       pi      pi      0;
            0       170     780     140     0       0       0;
            0       -pi/2   0       -pi/2   -pi/2    -pi/2  0; ];

    L_EU =[DH_EU(1,1) DH_EU(1,2) DH_EU(3,2) DH_EU(3,3) DH_EU(1,4) DH_EU(3,4) DH_EU(1,5) DH_EU(1,7)]/1000;  %%%L_EU:1x8
    DH_EU(1,:) = DH_EU(1,:)/1000;
    DH_EU(3,:) = DH_EU(3,:)/1000;
    Ma_EU = Ma';  %%%Ma_EU: 6x1
    Cen_EU = [cen1,cen2,cen3,cen4,cen5,cen6]';  %%%Cen_EU:18x1, x1 y1 z1 ... x6 y6 z6
    Ie_EU = [Ie1';Ie2';Ie3';Ie4';Ie5';Ie6'];    %%%Ie_EU: 54x1, Ixx1 Iyx1 Izx1 Ixy1 Iyy1 Izy1 Ixz1 Iyz1 Izz1 .... Ixx6 Iyx6 Izx6 Ixy6 Iyy6 Izy6 Ixz6 Iyz6 Izz6
    Ft_EU = [0;0;0;0;0;0];
    
    %%%%%%%%%%%%%%%%%%
    DH_Min=[0       0       0       504;
        -pi/2   170     -pi/2    0;
        0       780     0       0;
        -pi/2   140    0       760;
        pi/2    0       0       0;
        -pi/2   0       0       0;
        0       0       0       125]';
    DH_Min(2,:) = DH_Min(2,:)/1000;
    DH_Min(4,:) = DH_Min(4,:)/1000;

    Ma_Min = Ma';  
    Cen_Min = [cen1,cen2,cen3,cen4,cen5,cen6]';  
    Ie_Min= [Ie1';Ie2';Ie3';Ie4';Ie5';Ie6'];    
    Ft_Min = [0;0;0;0;0;0];

%%
tvel = 120; % tangent velocity 
radius = 120; % radius of target circle
freq = tvel/radius;

gd_init = fwd_kin(L,A);
init_Endx = gd_init(1,4);
init_Endy = gd_init(2,4);
init_Endz = gd_init(3,4);
init_Rot = gd_init(1:3,1:3);



%%%%%%%%Read Actual Data%%%%%%%%%%%%
% ControlFile = 'C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\Dynamic Debug\ActualData\20140611\ControlData.txt';
ControlFile='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva.txt';
ConData = importdata(ControlFile);
D2R = 1;%pi/180;
Pos = ConData(:,1:6)*D2R;
Vel = ConData(:,7:12)*D2R;
Acc = ConData(:,13:18)*D2R;
Nc = size(ConData,1);
t=[0:1:Nc-1];
%SmpT=t'*4e-3;
SmpT = t'*31.25*180*1e-6;
b1=1;
b2=1;
b3=1;
b4=1;
b5=1;
b6=1;
i5=pi/2;
SimPos1=[SmpT,Pos(:,1)*b1];
SimVel1=[SmpT,Vel(:,1)*b1];
SimAcc1=[SmpT,Acc(:,1)*b1];

SimPos2=[SmpT,Pos(:,2)*b2+pi/2];
SimVel2=[SmpT,Vel(:,2)*b2];
SimAcc2=[SmpT,Acc(:,2)*b2];

SimPos3=[SmpT,Pos(:,3)*b3];
SimVel3=[SmpT,Vel(:,3)*b3];
SimAcc3=[SmpT,Acc(:,3)*b3];

SimPos4=[SmpT,Pos(:,4)*b4];
SimVel4=[SmpT,Vel(:,4)*b4];
SimAcc4=[SmpT,Acc(:,4)*b4];

SimPos5=[SmpT,Pos(:,5)*b5 + i5*(1-b5)];
SimVel5=[SmpT,Vel(:,5)*b5];
SimAcc5=[SmpT,Acc(:,5)*b5];

SimPos6=[SmpT,Pos(:,6)*b6];
SimVel6=[SmpT,Vel(:,6)*b6];
SimAcc6=[SmpT,Acc(:,6)*b6];


%%%%
DH_a=DH_EU(:,1:6);
ToolOffset_a=[0;0;125];
o = [0;0;0;1];
z = [0;0;1;0];
x = [1;0;0;0];
y = [0;1;0;0];
ez = [0;0;1];
ex = [1;0;0];
eo = [0;0;0];

g01= expg([eo;ez],DH_a(2,1))*expg([ez;eo],DH_a(1,1))*expg([eo;ex],DH_a(4,1))*expg([ex;eo],DH_a(3,1));
g12= expg([eo;ez],DH_a(2,2))*expg([ez;eo],DH_a(1,2))*expg([eo;ex],DH_a(4,2))*expg([ex;eo],DH_a(3,2));
g23= expg([eo;ez],DH_a(2,3))*expg([ez;eo],DH_a(1,3))*expg([eo;ex],DH_a(4,3))*expg([ex;eo],DH_a(3,3));
g34= expg([eo;ez],DH_a(2,4))*expg([ez;eo],DH_a(1,4))*expg([eo;ex],DH_a(4,4))*expg([ex;eo],DH_a(3,4));
g45= expg([eo;ez],DH_a(2,5))*expg([ez;eo],DH_a(1,5))*expg([eo;ex],DH_a(4,5))*expg([ex;eo],DH_a(3,5));
g56= expg([eo;ez],DH_a(2,6))*expg([ez;eo],DH_a(1,6))*expg([eo;ex],DH_a(4,6))*expg([ex;eo],DH_a(3,6));
g06= g01*g12*g23*g34*g45*g56;
g_st_a(:,4)=g06*[ToolOffset_a;1];
g_st_a(1:3,1:3)=eye(3);

Ksi_a = DH2Twist_S6(DH_a,g_st_a);







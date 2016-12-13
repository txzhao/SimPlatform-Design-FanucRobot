%% Robot Controller Parameter Configuration
% created by xu.x, on Dec 15, 2014
%
clear all;
clc;
%% Simulation Param
FrHz = 4e3;
% FrHz = 1e4;
Ts=1/FrHz ;   %%% s
%Ts=0.00025;
% Ts_Dyn=0.004;  %%% 4ms 
Ts_Dyn=Ts;      %%% Change...

%% feedback Configuration
EncRes = 32768;          %%% Line per rotation,For EFORT Robot
%EncRes = 2500;              %%%For Test
%% Source Parameter Configuration
%Pulse
CurPulseEnable=0;
CurPulseGain=1;             %%% Amp
CurPulseFreq=0.25*2*pi;     %%% T=2*pi/Freq=4

VelPulseEnable=0;
VelPulseGain=500;             %%% Rpm
VelPulseFreq=0.25*2*pi;

PosPulseEnable=1;
PosVelPulseGain=500;          %%% Rpm
PosVelPulseFreq=0.25*2*pi;

Rpm2LinePTs=EncRes*Ts/60;        %%% Line per Ts
LinePTs2Rpm=60/(EncRes*Ts);      %%% Rpm

%Trajectory Generator
DynTrjMode=3;             %%% 1: Arbitary Trj; 2: Velocity Tunning Trj; 3: Pos Tunning Trj 4: Zero
VelLpAxisNum=1;           %选择关节调节速度控制环参数(1-6)
PosLpAxisNum=1;           %选择关节调节位置控制环参数(1-6)
DisturbSelect=2;          %%% 1: Gaussian Noise 2: Zero
FbDisturbSelect=2;        %%% 1: Gaussian Noise 2: Zero

%% Control Loop and Exciting Signal: For Source Selector
% For Vel & Pos controller
% source type: 1 for Pulse
% source type: 2 for Control Loop Signal 
% source type: 3 for Zero
% For Cur
% source type : 1 for control loop signal
% source type : 2 for zero
%% Configure Axis 1
RobotAxis(1).CurSourceSelect = 1;
RobotAxis(1).VelSourceSelect = 2;
RobotAxis(1).PosSourceSelect = 1;
RobotAxis(1).FilterSelect = 1;
RobotAxis(1).FwdSelect = 1;
RobotAxis(1).AxisNO = 1;

RobotAxis(2).CurSourceSelect = 1;
RobotAxis(2).VelSourceSelect = 2;
RobotAxis(2).PosSourceSelect = 2;
RobotAxis(2).FilterSelect = 1;
RobotAxis(2).FwdSelect = 1;
RobotAxis(2).AxisNO = 2;

RobotAxis(3).CurSourceSelect = 1;
RobotAxis(3).VelSourceSelect = 2;
RobotAxis(3).PosSourceSelect = 2;
RobotAxis(3).FilterSelect = 1;
RobotAxis(3).FwdSelect = 1;
RobotAxis(3).AxisNO = 3;

RobotAxis(4).CurSourceSelect = 1;
RobotAxis(4).VelSourceSelect = 2;
RobotAxis(4).PosSourceSelect = 2;
RobotAxis(4).FilterSelect = 1;
RobotAxis(4).FwdSelect = 1;
RobotAxis(4).AxisNO = 4;

RobotAxis(5).CurSourceSelect = 1;
RobotAxis(5).VelSourceSelect = 2;
RobotAxis(5).PosSourceSelect = 2;
RobotAxis(5).FilterSelect = 1;
RobotAxis(5).FwdSelect = 1;
RobotAxis(5).AxisNO = 5;

RobotAxis(6).CurSourceSelect = 1;
RobotAxis(6).VelSourceSelect = 2;
RobotAxis(6).PosSourceSelect = 2;
RobotAxis(6).FilterSelect = 1;
RobotAxis(6).FwdSelect = 1;
RobotAxis(6).AxisNO = 6;

%% Parameters for Controller
% Kpp: position loop proportion
% Kpi: position loop integration, ignored
% Kpd: position loop derivation, ignored
% VelLimit: Position Controller Output Command Velocity Limit: Rmp ==> Line per Ts
% Kvp: velocity loop proportion
% Kvi: velocity loop integration
% Kvd: velocity loop derivation, ignored
% CurLimit: Velocity Controller Output Command Cuurent Limit: Amp
% Cur2Volt: Transfer Current to Volatage Output: V(-10~+10) 
% VelErrorCheckLimit: Velocity Error Check up bound, Line per Ts
% PosErrorCheckLimit: Position Error Check up bound, Line
% VelFwdGain: Velocity Feedforward Gain, add before going into vel controller
% CurFwdGain: Current Feedforward Gain, add before going into cur controller
%             It is calculated based on dynamic model.

%%
% Gravity=0;
% %%%%%Without gravity and dynamics feedforward
% RobotAxis(1).Kpp = 0.01;
% RobotAxis(1).Kpi = 0;
% RobotAxis(1).Kpd = 0;
% RobotAxis(1).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(1).Kvp = 0.5;
% RobotAxis(1).Kvi = 0.005;
% RobotAxis(1).Kvd = 0;
% RobotAxis(1).CurLimit = 15;  %A, Max Current Value
% RobotAxis(1).Cur2Volt = 10/RobotAxis(1).CurLimit; 
% RobotAxis(1).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(1).PosErrorCheckLimit = EncRes/5; % 360/72=5 deg ==> Line
% RobotAxis(1).VelFwdGain=1;
% RobotAxis(1).CurFwdGain=0;
% 
% 
% 
% RobotAxis(2).Kpp = 0.005;
% RobotAxis(2).Kpi = 0;
% RobotAxis(2).Kpd = 0;
% RobotAxis(2).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(2).Kvp = 1;
% RobotAxis(2).Kvi = 0.005;
% RobotAxis(2).Kvd = 0;
% RobotAxis(2).CurLimit = 15;  %A, Max Current Value
% RobotAxis(2).Cur2Volt = 10/RobotAxis(2).CurLimit; 
% RobotAxis(2).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(2).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(2).VelFwdGain=1;
% RobotAxis(2).CurFwdGain=0;
% 
% RobotAxis(3).Kpp = 0.003;
% RobotAxis(3).Kpi = 0;
% RobotAxis(3).Kpd = 0;
% RobotAxis(3).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(3).Kvp = 0.3;
% RobotAxis(3).Kvi = 0.0005;
% RobotAxis(3).Kvd = 0;
% RobotAxis(3).CurLimit = 10;  %A, Max Current Value
% RobotAxis(3).Cur2Volt = 10/RobotAxis(3).CurLimit; 
% RobotAxis(3).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(3).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(3).VelFwdGain=1;
% RobotAxis(3).CurFwdGain=0;
% 
% RobotAxis(4).Kpp = 0.003;
% RobotAxis(4).Kpi = 0;
% RobotAxis(4).Kpd = 0;
% RobotAxis(4).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(4).Kvp = 0.015;
% RobotAxis(4).Kvi = 0.0005;
% RobotAxis(4).Kvd = 0;
% RobotAxis(4).CurLimit = 5;  %A, Max Current Value
% RobotAxis(4).Cur2Volt = 10/RobotAxis(4).CurLimit; 
% RobotAxis(4).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(4).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(4).VelFwdGain=1;
% RobotAxis(4).CurFwdGain=0;
% 
% RobotAxis(5).Kpp = 0.003;
% RobotAxis(5).Kpi = 0;
% RobotAxis(5).Kpd = 0;
% RobotAxis(5).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(5).Kvp = 0.006;
% RobotAxis(5).Kvi = 0.0005;
% RobotAxis(5).Kvd = 0;
% RobotAxis(5).CurLimit = 5;  %A, Max Current Value
% RobotAxis(5).Cur2Volt = 10/RobotAxis(5).CurLimit; 
% RobotAxis(5).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(5).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(5).VelFwdGain=1;
% RobotAxis(5).CurFwdGain=0;
% 
% RobotAxis(6).Kpp = 0.002; 
% RobotAxis(6).Kpi = 0.005;
% RobotAxis(6).Kpd = 0;
% RobotAxis(6).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(6).Kvp = 0.0002;
% RobotAxis(6).Kvi = 0.0005;
% RobotAxis(6).Kvd = 0;
% RobotAxis(6).CurLimit = 5;  %A, Max Current Value
% RobotAxis(6).Cur2Volt = 10/RobotAxis(6).CurLimit; 
% RobotAxis(6).VelErrorCheckLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(6).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(6).VelFwdGain=1;
% RobotAxis(6).CurFwdGain=0;

% %%
% Gravity=9.8;
% %%%%%With gravity and without dynamics feedforward
% %%%%%Not need to change much of parameters!!!
% RobotAxis(1).Kpp = 0.01;
% RobotAxis(1).Kpi = 0;
% RobotAxis(1).Kpd = 0;
% RobotAxis(1).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(1).Kvp = 0.5;
% RobotAxis(1).Kvi = 0.005;
% RobotAxis(1).Kvd = 0;
% RobotAxis(1).CurLimit = 15;  %A, Max Current Value
% RobotAxis(1).Cur2Volt = 10/RobotAxis(1).CurLimit; 
% RobotAxis(1).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(1).PosErrorCheckLimit = EncRes/5; % 360/72=5 deg ==> Line
% RobotAxis(1).VelFwdGain=1;
% RobotAxis(1).CurFwdGain=0;
% 
% 
% 
% RobotAxis(2).Kpp = 0.005;
% RobotAxis(2).Kpi = 0;
% RobotAxis(2).Kpd = 0;
% RobotAxis(2).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(2).Kvp = 1;
% RobotAxis(2).Kvi = 0.005;
% RobotAxis(2).Kvd = 0;
% RobotAxis(2).CurLimit = 15;  %A, Max Current Value
% RobotAxis(2).Cur2Volt = 10/RobotAxis(2).CurLimit; 
% RobotAxis(2).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(2).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(2).VelFwdGain=1;
% RobotAxis(2).CurFwdGain=0;
% 
% RobotAxis(3).Kpp = 0.003;
% RobotAxis(3).Kpi = 0;
% RobotAxis(3).Kpd = 0;
% RobotAxis(3).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(3).Kvp = 0.3;
% RobotAxis(3).Kvi = 0.0005;
% RobotAxis(3).Kvd = 0;
% RobotAxis(3).CurLimit = 10;  %A, Max Current Value
% RobotAxis(3).Cur2Volt = 10/RobotAxis(3).CurLimit; 
% RobotAxis(3).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(3).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(3).VelFwdGain=1;
% RobotAxis(3).CurFwdGain=0;
% 
% RobotAxis(4).Kpp = 0.003;
% RobotAxis(4).Kpi = 0;
% RobotAxis(4).Kpd = 0;
% RobotAxis(4).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(4).Kvp = 0.015;
% RobotAxis(4).Kvi = 0.0005;
% RobotAxis(4).Kvd = 0;
% RobotAxis(4).CurLimit = 5;  %A, Max Current Value
% RobotAxis(4).Cur2Volt = 10/RobotAxis(4).CurLimit; 
% RobotAxis(4).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(4).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(4).VelFwdGain=1;
% RobotAxis(4).CurFwdGain=0;
% 
% RobotAxis(5).Kpp = 0.003;
% RobotAxis(5).Kpi = 0;
% RobotAxis(5).Kpd = 0;
% RobotAxis(5).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(5).Kvp = 0.006;
% RobotAxis(5).Kvi = 0.0005;
% RobotAxis(5).Kvd = 0;
% RobotAxis(5).CurLimit = 5;  %A, Max Current Value
% RobotAxis(5).Cur2Volt = 10/RobotAxis(5).CurLimit; 
% RobotAxis(5).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(5).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(5).VelFwdGain=1;
% RobotAxis(5).CurFwdGain=0;
% 
% RobotAxis(6).Kpp = 0.002; 
% RobotAxis(6).Kpi = 0.005;
% RobotAxis(6).Kpd = 0;
% RobotAxis(6).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(6).Kvp = 0.0002;
% RobotAxis(6).Kvi = 0.0005;
% RobotAxis(6).Kvd = 0;
% RobotAxis(6).CurLimit = 5;  %A, Max Current Value
% RobotAxis(6).Cur2Volt = 10/RobotAxis(6).CurLimit; 
% RobotAxis(6).VelErrorCheckLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
% RobotAxis(6).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
% RobotAxis(6).VelFwdGain=1;
% RobotAxis(6).CurFwdGain=0;


%%
Gravity=9.8;
%%%%%With gravity and with dynamics feedforward
%%%%%Not need to change much of parameters!!!
RobotAxis(1).Kpp = 0.01;
RobotAxis(1).Kpi = 0;
RobotAxis(1).Kpd = 0;
RobotAxis(1).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(1).Kvp = 0.5;
RobotAxis(1).Kvi = 0.005;
RobotAxis(1).Kvd = 0;
RobotAxis(1).CurLimit = 15;  %A, Max Current Value
RobotAxis(1).Cur2Volt = 10/RobotAxis(1).CurLimit; 
RobotAxis(1).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(1).PosErrorCheckLimit = EncRes/5; % 360/72=5 deg ==> Line
RobotAxis(1).VelFwdGain=1;
RobotAxis(1).CurFwdGain=1;
RobotAxis(1).KP=0.06; 
RobotAxis(1).KD=0;
RobotAxis(1).Limit=10;

RobotAxis(2).Kpp = 0.005;
RobotAxis(2).Kpi = 0;
RobotAxis(2).Kpd = 0;
RobotAxis(2).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(2).Kvp = 1;
RobotAxis(2).Kvi = 0.005;
RobotAxis(2).Kvd = 0;
RobotAxis(2).CurLimit = 15;  %A, Max Current Value
RobotAxis(2).Cur2Volt = 10/RobotAxis(2).CurLimit; 
RobotAxis(2).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(2).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
RobotAxis(2).VelFwdGain=1;
RobotAxis(2).CurFwdGain=1;
RobotAxis(2).KP=0.08; 
RobotAxis(2).KD=0;
RobotAxis(2).Limit=10;

RobotAxis(3).Kpp = 0.003;
RobotAxis(3).Kpi = 0;
RobotAxis(3).Kpd = 0;
RobotAxis(3).VelLimit = 1500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(3).Kvp = 0.3;
RobotAxis(3).Kvi = 0.0005;
RobotAxis(3).Kvd = 0;
RobotAxis(3).CurLimit = 10;  %A, Max Current Value
RobotAxis(3).Cur2Volt = 10/RobotAxis(3).CurLimit; 
RobotAxis(3).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(3).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
RobotAxis(3).VelFwdGain=1;
RobotAxis(3).CurFwdGain=1;
RobotAxis(3).KP=0.08; 
RobotAxis(3).KD=0;
RobotAxis(3).Limit=10;

RobotAxis(4).Kpp = 0.003;
RobotAxis(4).Kpi = 0;
RobotAxis(4).Kpd = 0;
RobotAxis(4).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(4).Kvp = 0.035;
RobotAxis(4).Kvi = 0.005;
RobotAxis(4).Kvd = 0;
RobotAxis(4).CurLimit = 5;  %A, Max Current Value
RobotAxis(4).Cur2Volt = 10/RobotAxis(4).CurLimit; 
RobotAxis(4).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(4).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
RobotAxis(4).VelFwdGain=1;
RobotAxis(4).CurFwdGain=1;
RobotAxis(4).KP=0.08; 
RobotAxis(4).KD=0;
RobotAxis(4).Limit=10;

RobotAxis(5).Kpp = 0.003;
RobotAxis(5).Kpi = 0;
RobotAxis(5).Kpd = 0;
RobotAxis(5).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(5).Kvp = 0.006;
RobotAxis(5).Kvi = 0.0005;
RobotAxis(5).Kvd = 0;
RobotAxis(5).CurLimit = 5;  %A, Max Current Value
RobotAxis(5).Cur2Volt = 10/RobotAxis(5).CurLimit; 
RobotAxis(5).VelErrorCheckLimit = 500*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(5).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
RobotAxis(5).VelFwdGain=1;
RobotAxis(5).CurFwdGain=1;
RobotAxis(5).KP=0.08; 
RobotAxis(5).KD=0;
RobotAxis(5).Limit=10;

RobotAxis(6).Kpp = 0.002; 
RobotAxis(6).Kpi = 0.005;
RobotAxis(6).Kpd = 0;
RobotAxis(6).VelLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(6).Kvp = 0.0002;
RobotAxis(6).Kvi = 0.0005;
RobotAxis(6).Kvd = 0;
RobotAxis(6).CurLimit = 5;  %A, Max Current Value
RobotAxis(6).Cur2Volt = 10/RobotAxis(6).CurLimit; 
RobotAxis(6).VelErrorCheckLimit = 2000*Rpm2LinePTs; % Rpm*Rpm2LinePTs, Line per Ts
RobotAxis(6).PosErrorCheckLimit = EncRes/72; % 360/72 deg ==> Line
RobotAxis(6).VelFwdGain=1;
RobotAxis(6).CurFwdGain=1;
RobotAxis(6).KP=0.02; 
RobotAxis(6).KD=0;
RobotAxis(6).Limit=10;


%% %%%%%%%%%%Unit Conversion
Cur2Trq=[0.73;0.73;0.5;0.4;0.4;0.39];   %%% Motor-->Motor: Nm/Amp
Gear = [-147;-153;153;-76.95;-80;-51];  %%% Motor-->Joint
Trq2Cur=1./Gear;           %%% Joint-->Motor
Trq2Cur=Trq2Cur./Cur2Trq;  %%% Motor-->Motor: Amp/Nm

Rad2Line=Gear*EncRes/(2*pi); %%%Joint(Rad)-->Motor(Line)
Line2Rad=2*pi/EncRes./Gear;  %%%Motor(Line)-->Joint(Rad)
Deg2Rad=pi/180;
Rad2Deg=180/pi;

LinePTs2RadpS=2*pi/(EncRes*Ts)./Gear;  %%%Motor (LinePTs)--> Joint(Rad/s)
Volt2Trq=1./[RobotAxis(1).Cur2Volt;RobotAxis(2).Cur2Volt;RobotAxis(3).Cur2Volt;RobotAxis(4).Cur2Volt;RobotAxis(5).Cur2Volt;RobotAxis(6).Cur2Volt];
Volt2Trq=Volt2Trq./Trq2Cur;
%% %%%%%%%%%%%%Fanuc Kinematic Parameters%%%%%%%%%
l1 = 566;
l2 = 150;
l3 = 870;
l4 = 170;
l5 = 1016;
l6 = 154;
l7 = 20;
l8 = 0;
l9 = 0;
L = [l1 l2 l3 l4 l5 l6 l7 l8 l9];


%%%%%%%%%%%%%%%Inital Postion, Change....%%%%%%%%%%%%%
a1 = 0;
a2 = 0;
a3 = 0;
a4 = 0;
a5 = 90;
%a5 = 0;
a6 = 0;
A = [a1 a2 a3 a4 a5 a6]/180*pi;

JntOffset1=A(1);  %%% Rad
JntOffset2=A(2);
JntOffset3=A(3);
JntOffset4=A(4);
JntOffset5=A(5);
JntOffset6=A(6);


RobotAxis(1).InitialPos=A(1)*Rad2Line(1);
RobotAxis(2).InitialPos=A(2)*Rad2Line(2);
RobotAxis(3).InitialPos=A(3)*Rad2Line(3);
RobotAxis(4).InitialPos=A(4)*Rad2Line(4);
RobotAxis(5).InitialPos=A(5)*Rad2Line(5);
RobotAxis(6).InitialPos=A(6)*Rad2Line(6);

%% %%%%%%%%%%%%%Fanuc Dynamic Parameters%%%%%%%%%%%
%%%%%%%%%%%%%%% Mass: kg  Inertia: kg/m^2  Center: m
%Center: relative to world frame
%Inertia: relative to center frame, body inertia
%ceni: mass center coordinate relative to world frame
%ceni_1: offset coordiante of origin of visualized link relative to world frame, only for visualization
%ceni_2: coordinate of intersection between Link i-1 and Link i relative to world frame
%ceni_3: coordinate of intersection between Link i and Link i+1 relative to world frame
%ceni_4: coordinate of joint frame relative to world frame
ma1 = 170.31;
% ma1 = 100;
in1 = [5.2954 -0.2565 -0.6366;-0.2565 4.7000 0.2830;-0.6366 0.2829 5.8635];
cen1 = [0.0407 -0.0528 0.4702];
cen1_1=[0 0 0];
cen1_2=[0 0 0.266];
cen1_3=[0.15 0.062 0.566];
cen1_4=[0 0 0.266];

ma2 = 63.74;
% ma2 = 70;
in2 = [5.8840 0.0072 0.0135;0.0072 6.0178 -0.1907;0.0135 -0.1907 0.3374];
cen2 = [0.1510 0.1746 0.9687];
cen2_1=[0 0 0];
cen2_2=[0.15 0.062 0.566];
cen2_3=[0.15 0.227 1.436];
cen2_4=[0.15 0 0.566];

ma3 = 98.98;
% ma3 = 92;
in3 = [1.8201 -0.2274 -0.3112;-0.2274 2.2537 -0.1441;-0.3112 -0.1441 1.9485];
cen3 = [0.1568 -0.0318 1.5191];
cen3_1=[0 0 0];
cen3_2=[0.15 0.227 1.436];
cen3_3=[0.510 0 1.606];
cen3_4=[0.15 0 1.436];

ma4 = 24.46;
% ma4 = 22;
in4 = [0.0607 -0.0922 0;-0.0922 1.4493 0;0 0 1.4620];
cen4 = [0.8245 -0.0110 1.606];
cen4_1=[0.4525 0 1.606];
cen4_2=[0.510 0 1.606];
cen4_3=[1.166 -0.113 1.606];
cen4_4=[0.15 0 1.606];


ma5 = 5.24;
% ma5 = 7;
in5 = [0.0191 0.0032 0;0.0032 0.0228 0;0 0 0.0291];
cen5 = [1.2407 0.0180 1.606];
cen5_1=[0 0 0];
cen5_2=[1.166 -0.113 1.606];
cen5_3=[1.320 0 1.606];
cen5_4=[1.166 0 1.606];

ma6 = 0.6;
% ma6 = 1;
in6 = [0.0012 0 0;0 0.0007 0;0 0 0.0007];
cen6 = [1.330 0 1.606];
cen6_1=[1.34 0 1.606];
cen6_2=[1.320 0 1.606];
cen6_3=[1.34 0 1.606];
cen6_4=[1.166 0 1.606];

%%%%%%%%%Actual Dynamics Param%%%%%%%%%



Ma = [ma1 ma2 ma3 ma4 ma5 ma6]; %%%M:1x6
Ie1 = in1(:)';  %%%Ie1: 9x1
Ie2 = in2(:)';
Ie3 = in3(:)';
Ie4 = in4(:)';
Ie5 = in5(:)';
Ie6 = in6(:)';
Cen = [cen1;cen2;cen3;cen4;cen5;cen6]; %%%Cen: 6x3
Cen = Cen(:)'; %%%Cen:18x1, x1...x6 y1...y6 z1...z6

%% Trajectory Generation

tvel = 120; % tangent velocity 
radius = 120; % radius of target circle
freq = tvel/radius;
TrajSwitch = 1;

gd_init = fwd_kin(L,A);
init_Endx = gd_init(1,4);
init_Endy = gd_init(2,4);
init_Endz = gd_init(3,4);
init_Rot = gd_init(1:3,1:3);



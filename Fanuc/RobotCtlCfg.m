%% Robot Controller Parameter Configuration
% created by xu.x, on Dec 15, 2014
%
%% Source Parameter Configuration
%Pulse
Ts=1/8000;
%PulseGain = 100/180*pi;

%%%%%%Axis 6%%%%%%%%%%%
%PulseGain = 60/180*pi*Ts;  %%%%Vel
PulseGain = 50/180*pi;     %%%%Pos

%PulseGain = 160/180*pi*Ts;  %%%%Vel
%PulseGain = 100/180*pi;     %%%%Pos
PulseFrq = 0.1;

% Single Sine
SineGain = 0;
SineFrq = 1; % Hz

%PRBS
PRBSGain = 0;
PRBSBand = 1/4; % 1 for Sample Frequence
PRBSTimeLength = 1; % 1 s
PRBSOffset = 0 ; 

%SineSweept
%% feedback Configuration
LinesPerRevolutin = 65536/4;
%Rad2Line=65536/4/(2*pi);
Rad2Line=1;
V2T=[1 1 1 1 1 1];
%% Control Loop and Exciting Signal
% source type: 1 for Pulse
% source type: 2 for Sine
% source type: 3 for PRBS
% source type: 4 for SineSweep
% source type: 5 for Control Loop Signal 
% source type: 6 for Step
%% Configure Axis 1
RobotAxis(1).CurrentSourceSelect =6;
RobotAxis(1).VelSourceSelect =6;
RobotAxis(1).PosSourceSelect =6;
RobotAxis(1).AxisNO = 1;

RobotAxis(2).CurrentSourceSelect = 6;
RobotAxis(2).VelSourceSelect = 6;
RobotAxis(2).PosSourceSelect = 6;
RobotAxis(2).AxisNO = 2;

RobotAxis(3).CurrentSourceSelect = 6;
RobotAxis(3).VelSourceSelect = 6;
RobotAxis(3).PosSourceSelect = 6;
RobotAxis(3).AxisNO = 3;

RobotAxis(4).CurrentSourceSelect = 6;
RobotAxis(4).VelSourceSelect =6;
RobotAxis(4).PosSourceSelect = 6;
RobotAxis(4).AxisNO = 4;

RobotAxis(5).CurrentSourceSelect = 6;
RobotAxis(5).VelSourceSelect = 6;
RobotAxis(5).PosSourceSelect = 6;
RobotAxis(5).AxisNO = 5;

RobotAxis(6).CurrentSourceSelect = 5;%5;
RobotAxis(6).VelSourceSelect = 5;%5;
RobotAxis(6).PosSourceSelect =1;%1;
RobotAxis(6).AxisNO = 6;

%% Parameters for Controller


RobotAxis(1).PLKp = 0.008;
%RobotAxis(1).PLLimit = 5000/60*LinesPerRevolutin*Ts; % Max Vel with diff lines
RobotAxis(1).PLLimit = inf;160/180*pi*Ts;
RobotAxis(1).VLKp = 70000000;
RobotAxis(1).VLKi = 5000;
%RobotAxis(1).VLLimit = 3;  %A, Max Current Value
RobotAxis(1).VLLimit = inf;%200000;
%RobotAxis(1).Current2Volt = 10/RobotAxis(1).VLLimit; 
RobotAxis(1).Current2Volt = 1;
RobotAxis(1).VelErrorCheckLimit = 500/60*LinesPerRevolutin*Ts; % different lines

RobotAxis(2).PLKp = 0.007;
%RobotAxis(2).PLLimit = 5000/60*LinesPerRevolutin*Ts; % Max Vel with diff lines
RobotAxis(2).PLLimit = inf; %120/180*pi*Ts;
RobotAxis(2).VLKp = 120000000;
RobotAxis(2).VLKi = 40000;
%RobotAxis(2).VLLimit = 3;  %A, Max Current Value
RobotAxis(2).VLLimit = inf;%2000;
%RobotAxis(2).Current2Volt = 10/RobotAxis(2).VLLimit; 
RobotAxis(2).Current2Volt = 1;
RobotAxis(2).VelErrorCheckLimit = 500/60*LinesPerRevolutin*Ts; % different lines

RobotAxis(3).PLKp = 0.0068;
%RobotAxis(3).PLLimit = 5000/60*LinesPerRevolutin*Ts; % Max Vel with diff lines
RobotAxis(3).PLLimit = inf;%120/180*pi*Ts;
RobotAxis(3).VLKp = 25000000;
RobotAxis(3).VLKi = 2000;
%RobotAxis(3).VLLimit = 3;  %A, Max Current Value
RobotAxis(3).VLLimit = inf;
%RobotAxis(3).Current2Volt = 10/RobotAxis(3).VLLimit; 
RobotAxis(3).Current2Volt = 1;
RobotAxis(3).VelErrorCheckLimit = 500/60*LinesPerRevolutin*Ts; % different lines

RobotAxis(4).PLKp = 0.006;
%RobotAxis(4).PLLimit = 5000/60*LinesPerRevolutin*Ts; % Max Vel with diff lines
RobotAxis(4).PLLimit = inf;%225/180*pi*Ts;
RobotAxis(4).VLKp = 130000;
RobotAxis(4).VLKi = 40;
%RobotAxis(4).VLLimit = 3;  %A, Max Current Value
RobotAxis(4).VLLimit = inf;
%RobotAxis(4).Current2Volt = 10/RobotAxis(4).VLLimit; 
RobotAxis(4).Current2Volt = 1;
RobotAxis(4).VelErrorCheckLimit = 500/60*LinesPerRevolutin*Ts; % different lines

RobotAxis(5).PLKp = 0.006;
%RobotAxis(5).PLLimit = 5000/60*LinesPerRevolutin*Ts; % Max Vel with diff lines
RobotAxis(5).PLLimit = inf; %225/180*pi*Ts;
RobotAxis(5).VLKp = 60000;
RobotAxis(5).VLKi = 30;
%RobotAxis(5).VLLimit = 3;  %A, Max Current Value
RobotAxis(5).VLLimit = inf;
%RobotAxis(5).Current2Volt = 10/RobotAxis(5).VLLimit; 
RobotAxis(5).Current2Volt = 1;
RobotAxis(5).VelErrorCheckLimit = 500/60*LinesPerRevolutin*Ts; % different lines

RobotAxis(6).PLKp = 0.006;%0.006;
%RobotAxis(6).PLLimit = 1000/60*LinesPerRevolutin*Ts; % Max Vel with diff lines
RobotAxis(6).PLLimit = inf; %225/180*pi*Ts;
RobotAxis(6).VLKp = 1250;
RobotAxis(6).VLKi = 1;%1;
%RobotAxis(6).VLLimit = 5;  %5 A, Max Current Value
RobotAxis(6).VLLimit = inf;
%RobotAxis(6).Current2Volt = 10/RobotAxis(6).VLLimit; 
RobotAxis(6).Current2Volt = 1;
RobotAxis(6).VelErrorCheckLimit = 3000/60*LinesPerRevolutin*Ts; % rpm to different lines


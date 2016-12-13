%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerStaticDyn.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 12/6/2014
%
%@Description: To verify accuracy of static dynamics based on identified parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;
format short g

RobotType ={ 'Kawasaki','Yaskawa','Fanuc','Staubli','Efort','Other'};
SelectedType = RobotType{1};
bMotor = false;
PosType = 7;

switch SelectedType
    case 'Kawasaki'
        I2T = [0.77;0.77;0.524;0.375;0.375;0.375];
        K = [-145.7;140;-173.5;104.7;-100;-51.5];        
        % %% Lenght: m,  Angle: rad
        DH=[
        0       430     0       0       700     0        88;
        0       0       -pi/2   0       pi      pi       0;
        0       100     650     0       0       0        0;
        0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;];
        DH(1,:) = DH(1,:)/1000;
        DH(3,:) = DH(3,:)/1000;
        if bMotor
            LoadParam = load('DynParamM.mat');
            Param = LoadParam.Param_c
        else
            Imz = [0.65;0.65;0.047;0.017;0.017;0.017]*1e-3; %Unit: kg*m^2
            LoadParam = load('DynParam.mat');
            Param = LoadParam.Param_c;
        end
        switch PosType
            case 1
                TrqFile='C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140619\1.txt';
                Pos=[0,0,0,0,90,0];
            case 2
                TrqFile='C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140619\2.txt';
                Pos=[0,0,0,0,90,0];
            case 3
                TrqFile='C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140619\3.txt';
                Pos=[30,15,15,30,30,30];
            case 4
                TrqFile='C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140619\4.txt';
                Pos=[30,-15,-15,-30,-30,-30];
            case 5
                TrqFile='C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140619\5.txt';
                Pos=[-30,-15,-15,-30,-30,-30];
            case 6
                TrqFile='C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140619\6.txt';
                Pos=[-30,15,15,30,30,30];
            case 7
                TrqFile='C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140619\7.txt';
                Pos=[0,0,0,0,0,0];
            otherwise
        end
        
    otherwise 
end

Pos=Pos/180*pi;
Vel=[0,0,0,0,0,0];
Acc=[0,0,0,0,0,0];

TrqData = importdata(TrqFile);
Trq_a = mean(TrqData)'.*I2T.*K;


Ld = [DH(1,1) DH(1,2) DH(3,2) DH(3,3) DH(1,4) DH(3,4) DH(1,5) DH(1,6)];
Wd = EulerWd(Ld,Pos,Vel,Acc);
Wm = EulerWm(Ld,abs(K'),Pos,Vel,Acc);
Wfs = zeros(6);
Wfv = zeros(6);
   
if bMotor
    Trq_c = [Wd,Wm,Wfs,Wfv]*Param;
else
    TrqM = Wm*Imz;
    Trq_c = [Wd,Wfs,Wfv]*Param + TrqM;
end

disp('Static Dynamic Comparison:');
disp('Static Position:');
disp(Pos/pi*180);
disp('Actual Torque  |  Calculated Torque:');
disp([Trq_a,Trq_c]);

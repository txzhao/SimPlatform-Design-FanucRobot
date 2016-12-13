%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerOptimalTrj.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 12/5/2014
%
%@Description: To find optimal trajectory  for Newton Euler Dynamic Algorithm
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear;
clc;

D2R = 1/180*pi;
PosRng(1,:)=[-135,135]*D2R;
PosRng(2,:)=[-45,45]*D2R;
PosRng(3,:)=[-45,45]*D2R;
PosRng(4,:)=[-200,200]*D2R;
PosRng(5,:)=[-100,100]*D2R;
PosRng(6,:)=[-360,360]*D2R;

Vco = 0.75;
VelRng(1,:)=[-190,190]*D2R*Vco;
VelRng(2,:)=[-205,205]*D2R*Vco;
VelRng(3,:)=[-210,210]*D2R*Vco;
VelRng(4,:)=[-400,400]*D2R*Vco;
VelRng(5,:)=[-360,360]*D2R*Vco;
VelRng(6,:)=[-600,600]*D2R*Vco;

Aco = 0.5;
AccRng(1,:)=[-180,180]*D2R*Aco;
AccRng(2,:)=[-180,180]*D2R*Aco;
AccRng(3,:)=[-540,540]*D2R*Aco;
AccRng(4,:)=[-1600,1600]*D2R*Aco;
AccRng(5,:)=[-1200,1200]*D2R*Aco;
AccRng(6,:)=[-2400,2400]*D2R*Aco;

N=20;
Pos = zeros(N,6);
Vel = zeros(N,6);
Acc = zeros(N,6);

GenData=2;
switch GenData
    case 1
    %%%%%%%%%%%%Random Trajectory%%%%%%%%%%%%%%
    for j=1:6
        Pos(:,j)= (PosRng(j,2)-PosRng(j,1))*rand([N 1])+PosRng(j,1);
        Vel(:,j)= (VelRng(j,2)-VelRng(j,1))*rand([N 1])+VelRng(j,1);
        Acc(:,j)= (AccRng(j,2)-AccRng(j,1))*rand([N 1])+AccRng(j,1);
    end
    case 2
    %%%%%%%%%%%%Acc satisfies sin(t) Trajectory%%%%%%%%%%%%%
    t=[0:1:N-1]*0.1*pi;
    for j=1:6
        Acc(:,j) = 0.8*PosRng(j,2)/(2*pi) * sin(t)';
        Vel(:,j) = 0.8*PosRng(j,2)/(2*pi)*(1 - cos(t)');
        Pos(:,j) = 0.8*PosRng(j,2)/(2*pi)*(t' - sin(t)');
    end
    case 3
    %%%%%%%%%%%%Pos satisfies x^2 Trajectory%%%%%%%%%%%%%%
    t=[0:0.1:(N-1)*0.1]';
    for j=1:6
        Pos(:,j) = PosRng(j,2)/4*t.^2;
        Vel(:,j) = PosRng(j,2)/2*t;
        Acc(:,j) = PosRng(j,2)/2;
    end    
    case 4
    %%%%%%%%%%%%Pos satisfies x^3 Trajectory%%%%%%%%%%%%%%
    t=[0:0.1:(N-1)*0.1]';
    for j=1:6
        Pos(:,j) = PosRng(j,2)/12*t.^3;
        Vel(:,j) = PosRng(j,2)/4*t.^2;
        Acc(:,j) = PosRng(j,2)/2*t;
    end
    case 5
    %%%%%%%%%%%%Pos satisfies x^4 Trajectory%%%%%%%%%%%%%%
    t=[0:0.1:(N-1)*0.1]';
    for j=1:6
        Pos(:,j) = PosRng(j,2)/32*t.^4;
        Vel(:,j) = PosRng(j,2)/8*t.^3;
        Acc(:,j) = PosRng(j,2)/8*3*t.^2;
    end
    otherwise
end
% figure(1);
% plot(t,Pos(:,1));


X0 = zeros(18*N,1);
for i=1:N
    X0(18*(i-1)+1:18*(i-1)+6) = Pos(i,:)';
    X0(18*(i-1)+7:18*(i-1)+12) = Vel(i,:)';
    X0(18*(i-1)+13:18*i) = Acc(i,:)';
end

lb = [PosRng(:,1);VelRng(:,1);AccRng(:,1)];
ub = [PosRng(:,2);VelRng(:,2);AccRng(:,2)];
lb = repmat(lb,N,1);
ub = repmat(ub,N,1);

InitCost = EulerCostFunM(X0);
disp('Initial Cost:');
disp(InitCost);

options = optimset('Algorithm','active-set','Display','iter','PlotFcns',@optimplotfval,'MaxIter',15);
%Optimal = fmincon(@EulerCostFun,X0,[],[],[],[],lb,ub,[],options);
Optimal = fmincon(@EulerCostFunM,X0,[],[],[],[],lb,ub,[],options);

%%
for i=1:N
    OptPos(i,:)= Optimal(18*(i-1)+1:18*(i-1)+6)';
    OptVel(i,:)= Optimal(18*(i-1)+7:18*(i-1)+12)';
    OptAcc(i,:)= Optimal(18*(i-1)+13:18*i)';
end

Xe = zeros(18*N,1);
for i=1:N
    Xe(18*(i-1)+1:18*(i-1)+6) = OptPos(i,:)';
    Xe(18*(i-1)+7:18*(i-1)+12) = OptVel(i,:)';
    Xe(18*(i-1)+13:18*i) = OptAcc(i,:)';
end
EndCost = EulerCostFun(Xe);
disp('Initial Cost:');
disp(EndCost);

for i=1:6
    figure(i+1);
    plot(t,Acc(:,i),'g','Marker','o');
    hold on;
    plot(t,OptAcc(:,i),'r','Marker','o');
    grid on;
end



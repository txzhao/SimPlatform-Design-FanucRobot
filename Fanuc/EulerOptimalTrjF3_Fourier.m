%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerOptimalTrjF3_Fourier.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 28/02/2015
%
%@Description: To find optimal trajectory  for Newton Euler Dynamic Algorithm, in the Fourier Form,only
%considering first 3 joints
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;



%%%%%%%%%%%% Intialization %%%%%%%%%%%%%%%%%%
Wf = 0.2*pi;
hr = 5;
Jn = 3;
fs = 20;
Nf = 2*pi/Wf*fs+1;
t = linspace(0,2*pi/Wf,Nf);
Mx=[1 1 1];
X0 = ones(Jn*(2*hr+1),1)*0.15;
X0([1,12,23],1)=0;

% OptTrj_ = load('EfCndIpZvaF3LfOpt1.mat');
% X0=OptTrj_.Optimal;
% X0(34:end)=[];
% X0(11*2+2:11*3)=X0(11*2+2:11*3)*1.4;
% X0(11*3+2:11*4)=X0(11*3+2:11*4)*4;
% X0(11*4+2:11*5)=X0(11*4+2:11*5)*1.3;
% X0(11*5+2:11*6)=X0(11*5+2:11*6)*1.8;

%InitCost = EulerCostFun_Fourier(X0);
InitCost = EulerCostFunF3_Fourier(X0);
disp('Initial Cost:');
disp(InitCost);
[Cons,Ceq]=Nonlcon_Fourier(X0);
Cons=Cons';
Ceq=Ceq';



%%
options = optimset('Algorithm','interior-point','Display','iter','PlotFcns',@optimplotfval,'MaxIter',100);
%options = optimset('Algorithm','active-set','Display','iter','PlotFcns',@optimplotfval,'MaxIter',50);
Optimal = fmincon(@EulerCostFunF3_Fourier,X0,[],[],[],[],[],[],@Nonlcon_Fourier,options);


%%


N=Nf;
Nj=11;
Nh=5;
X=Optimal;
[oCons,oCeq]=Nonlcon_Fourier(X);
oCeq=oCeq';
oCons=oCons';

%X=X0;

Pos = zeros(N,3);
Vel = zeros(N,3);
Acc = zeros(N,3);

for i=1:N
    for j=1:3
        Pos(i,j) = X(1+(j-1)*Nj);
        Vel(i,j) = 0;
        Acc(i,j) = 0;
        for k=1:Nh
            a=X(2+(k-1)*2+(j-1)*Nj);
            b=X(3+(k-1)*2+(j-1)*Nj);
            Pos(i,j) = Pos(i,j) + a*sin(Mx(j)*k*Wf*t(i)) + b*cos(Mx(j)*k*Wf*t(i));
            Vel(i,j) = Vel(i,j) + a*Mx(j)*k*Wf*cos(Mx(j)*k*Wf*t(i)) - b*Mx(j)*k*Wf*sin(Mx(j)*k*Wf*t(i));
            Acc(i,j) = Acc(i,j) - a*(Mx(j)*k*Wf)^2*sin(Mx(j)*k*Wf*t(i)) - b*(Mx(j)*k*Wf)^2*cos(Mx(j)*k*Wf*t(i));
        end
           
    end
   
end

%%
%%%%%%%%%%%%%Drawing Trajectory%%%%%%%%%%%%%%%%%%%%%%%
%%%Efort: [-180,180],[-65,145],[-220,65],[-180,180],[-135,135],[-360,360]
D2R = 1/180*pi;
PosRng(1,:)=[-160,160]*D2R;
PosRng(2,:)=[-45,45]*D2R;
PosRng(3,:)=[-135,60]*D2R;
PosRng(4,:)=[-150,150]*D2R;
PosRng(5,:)=[-120,120]*D2R;
PosRng(6,:)=[-360,360]*D2R;

%%%%%%%%%%%% Need to check with specs %%%%%%%%%%%%%%%
%%%Efort Joint Vel : 170,  165,    170,    360,   360,  600
%%%Efort Gear Ratio: 147,  179.18, 164.07, 76.95, 80,   51
%%%Efort Rated Speed:2000, 2000,   3000,   3000,  3000, 3000
%%%Efort Maximum Sp: 5000, 5000,   6000,   6000,  6000, 6000
%%%Recal Jnt Vel based on Rated Speed: 82,67,110,234,225,353
Vco = 1;
VelRng(1,:)=[-80,80]*D2R*Vco;
VelRng(2,:)=[-65,65]*D2R*Vco;
VelRng(3,:)=[-110,110]*D2R*Vco;
VelRng(4,:)=[-230,230]*D2R*Vco;
VelRng(5,:)=[-220,220]*D2R*Vco;
VelRng(6,:)=[-350,350]*D2R*Vco;

%%%%%%%%%%%% Need to check with specs %%%%%%%%%%%%%%%
%%%Controller define acc=2*vmax, is it Reasonable????
Aco = 1;
AccRng(1,:)=[-160,160]*D2R*Aco;
AccRng(2,:)=[-130,130]*D2R*Aco;
AccRng(3,:)=[-220,220]*D2R*Aco;
AccRng(4,:)=[-460,460]*D2R*Aco;
AccRng(5,:)=[-440,440]*D2R*Aco;
AccRng(6,:)=[-700,700]*D2R*Aco;


%color={'r','g','b','k','y','c'};
color={'r','r','r','r','r','r'};
for i=1:3
    figure(i+1);
    plot(t,Acc(:,i),color{i});
    hold on;
    plot(t,ones(1,Nf)*AccRng(i,1),color{i});
    hold on;
    plot(t,ones(1,Nf)*AccRng(i,2),color{i});
    grid on;
    hold off;
    str=sprintf('%d Optimal Trajectory',i);
    title(str);
end



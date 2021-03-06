%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: VerifyOptimalTrjF3_Fourier.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 06/03/2015
%
%@Description: To verify optimal trajectory  complied with all constraints
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;

%OptTrj_ = load('EfCndIpZvaOneOpt1.mat');
%OptTrj_ = load('EfCndIpZvaMulOpt1.mat');
%OptTrj_ = load('EfCndIpZvaOpt1.mat');
%OptTrj_ = load('EfdOpIpZvaOneOpt1.mat');
%OptTrj_ = load('EfCndIpZvaNfOpt1.mat');
%OptTrj_ = load('EfdOpIpZvaNfOpt2.mat');
% X=OptTrj_.Optimal;
% X(34:end)=0;

OptTrj_ = load('EfCndIpZvaF3Opt1.mat');
X=OptTrj_.Optimal;


% %%%%%%%%%%Method 1: Amplify Coef
% X(11*2+2:11*3)=X(11*2+2:11*3)*1.4;
% X(11*3+2:11*4)=X(11*3+2:11*4)*4;
% X(11*4+2:11*5)=X(11*4+2:11*5)*1.3;
% X(11*5+2:11*6)=X(11*5+2:11*6)*1.8;
%%%%%%%%%Method 2: Copy Joint 1 and Amplify Coef
% X(11*2+2:11*3)=X(11*2+2:11*3)*1.4;
% X(11*3+1:11*4)=X(1:11)*1.3;
% X(11*4+1:11*5)=X(1:11)*1;
% X(11*5+1:11*6)=X(1:11)*3.2;


[Cons,Ceq]=Nonlcon_Fourier(X);
cst=EulerCostFunF3_Fourier(X)
% X0 = ones(6*(2*5+1),1)*0.15;
% X0([1,12,23,34,45,56],1)=0;
% InitCost = EulerCostFun_Fourier(X0)

%%
Wf = 0.2*pi;
Nj=11;
Nh=5;

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


SmpT=6e-3;
N=1667;
to=[0:SmpT:(N-1)*SmpT];
for i=1:N
    for j=1:3
        IdnPos(i,j) = X(1+(j-1)*Nj);
        IdnVel(i,j) = 0;
        IdnAcc(i,j) = 0;
        for k=1:Nh
            a=X(2+(k-1)*2+(j-1)*Nj);
            b=X(3+(k-1)*2+(j-1)*Nj);
            IdnPos(i,j) = IdnPos(i,j) + a*sin(k*Wf*to(i)) + b*cos(k*Wf*to(i));
            IdnVel(i,j) = IdnVel(i,j) + a*k*Wf*cos(k*Wf*to(i)) - b*k*Wf*sin(k*Wf*to(i));
            IdnAcc(i,j) = IdnAcc(i,j) - a*(k*Wf)^2*sin(k*Wf*to(i)) - b*(k*Wf)^2*cos(k*Wf*to(i));

        end
           
    end    
end
%%
%color={'r','g','b','k','y','c'};
color={'r','r','r','r','r','r'};
for i=1:3
    figure(i);
    plot(to,IdnVel(:,i),color{i});
    hold on;
    plot(to,ones(1,N)*VelRng(i,1),color{i});
    hold on;
    plot(to,ones(1,N)*VelRng(i,2),color{i});
    grid on;
    hold off;
    str=sprintf('%d Optimal Trajectory',i);
    title(str);
end
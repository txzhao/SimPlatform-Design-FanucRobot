%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: VarIdnTrj.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 04/03/2015
%
%@Description: To generate offline trajectory to verify the variance of noise on torque or current
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
clear all;
clc;
%%%%%%%%%%%%%
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

Wf = 0.25*pi;
Cof=[1.6 0.7 0.8 2.5 2 6];
Ts=6e-3;
Ns=2000;
t=[0:Ts:Ts*Ns];

for i=1:(Ns+1)
    Pos(i,:)=Cof*cos(Wf*t(i));
    Vel(i,:)=-Cof*Wf*sin(Wf*t(i));
    Acc(i,:)=Cof*Wf^2*sin(Wf*t(i));
end

%%
%%%%%%%%%%%%Vel & Acc Verification%%%%%%%%
color={'r','g','b','k','y','c'};
for i=1:6
    figure(i);
    plot(t,Pos(:,i),color{i});
    hold on;
    plot(t,ones(1,Ns+1)*PosRng(i,1),color{i});
    hold on;
    plot(t,ones(1,Ns+1)*PosRng(i,2),color{i});
    grid on;
    hold off;
    str=sprintf('%d Trajectory for Variance',i);
    title(str);
end


% %%
% %%%%%%%%%%%Descarte Trajectory Verification%%%%%%%%%%
% %%%%%%%%%%%%%%%%Efort DH%%%%%%%%%%%%%%%%%%%%%%%%%%%
% DH=[0       504     0       0       760    0;
%         0       0       -pi/2   0       pi      pi;
%         0       170     780     140     0       0;
%         0       -pi/2   0       -pi/2   -pi/2    -pi/2;];
% 
% g_st=eye(4);
%     
% g_st(1:3,4)=[1055;0;1424];    % For situation measuring only one point attached to end-frame
% Ksi_n = DH2Twist_S6(DH,g_st);
% Jnt=Pos';
% Jnt(7,:)=1;
% 
% for j=1:Ns+1
%     g_tmp = Fwd_Kin(Ksi_n,Jnt(:,j));
%     Pnt(1:3,j)=g_tmp(1:3,4);
% end
% 
% %%
% figure(10);
% plot3(Pnt(1,:),Pnt(2,:),Pnt(3,:),'.b');
% hold on;
% plot3(Pnt(1,1),Pnt(2,1),Pnt(3,1),'.r');
% grid on;


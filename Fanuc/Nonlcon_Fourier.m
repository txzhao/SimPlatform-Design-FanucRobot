%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: Nonlcon_Fourier.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 28/02/2015
%
%@Function: Nonlcon_Fourier
%@Description: nonlinear constraints for trajectory optimization in the Fourier Form.
%@Input:
%X: [a01,a11,b11,a21,b21...a06,a16,b16...]
%@Output:
%Cost: cost
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [c,ceq]=Nonlcon_Fourier(X)
%ceq=[];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Ld=[566 150 870 170 1016]/1000;  %%%%%For Fanuc
Ld=[504 170 780 140 760]/1000; %%%%%%For Efort


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


L=Ld(3)+Ld(4)+Ld(5);
Hmax=L;
Hmin=(Ld(3)+Ld(4))*cos(PosRng(2,2))-Ld(5)*sin(PosRng(3,2));
if abs(Hmin)>Ld(1) && Hmin<0
    Hmin=0;
end
HeiRng=[Hmin,Hmax];
RadRng=[0, Ld(5)+(Ld(2)+Ld(3))*sin(PosRng(2,2))];

JntNum=6;  %%%%Need to change when we only considering first 3 joints, defaut value is 6

Wf = 0.2*pi;
fs = 20;
N = 2*pi/Wf*fs+1;
Nx=size(X,1);
Nj=Nx/JntNum;
Nh=(Nx/JntNum-1)/2;
t = linspace(0,2*pi/Wf,N);


Pos = zeros(N,JntNum);
Vel = zeros(N,JntNum);
Acc = zeros(N,JntNum);

PaNum=JntNum*6+4;

for i=1:N
    for j=1:JntNum
        Pos(i,j) = X(1+(j-1)*Nj);
        Vel(i,j) = 0;
        Acc(i,j) = 0;
        for k=1:Nh
            a=X(2+(k-1)*2+(j-1)*Nj);
            b=X(3+(k-1)*2+(j-1)*Nj);
            Pos(i,j) = Pos(i,j) + a*sin(k*Wf*t(i)) + b*cos(k*Wf*t(i));
            Vel(i,j) = Vel(i,j) + a*k*Wf*cos(k*Wf*t(i)) - b*k*Wf*sin(k*Wf*t(i));
            Acc(i,j) = Acc(i,j) - a*(k*Wf)^2*sin(k*Wf*t(i)) - b*(k*Wf)^2*cos(k*Wf*t(i));
        end
        
        %%%%To ensure initial and final zero velocity%%%%%%%%
        if i==1
            ceq(2*j-1)=Vel(i,j);
            ceq(2*j)=Acc(i,j);
        end
        
        if i==N
            ceq(2*JntNum+2*j-1)=Vel(i,j);
            ceq(2*JntNum+2*j)=Acc(i,j);
        end
        
        %%%%%%%%%%%%%Impose Constraint%%%%%%%%%%%%%%
        c(1+(j-1)*6+(i-1)*PaNum)=Pos(i,j)-PosRng(j,2);
        c(2+(j-1)*6+(i-1)*PaNum)=-Pos(i,j)+PosRng(j,1);
        c(3+(j-1)*6+(i-1)*PaNum)=Vel(i,j)-VelRng(j,2);
        c(4+(j-1)*6+(i-1)*PaNum)=-Vel(i,j)+VelRng(j,1);
        c(5+(j-1)*6+(i-1)*PaNum)=Acc(i,j)-AccRng(j,2);
        c(6+(j-1)*6+(i-1)*PaNum)=-Acc(i,j)+AccRng(j,1);        
    end
    Hei=(Ld(3)+Ld(4))*cos(Pos(i,2))-Ld(5)*sin(Pos(i,3));
    Rad=(Ld(3)+Ld(4))*sin(Pos(i,2))+Ld(5)*cos(Pos(i,3));
    c(1+6*JntNum+(i-1)*PaNum)=Hei-HeiRng(2);
    c(2+6*JntNum+(i-1)*PaNum)=-Hei+HeiRng(1);
    c(3+6*JntNum+(i-1)*PaNum)=Rad-RadRng(2);
    c(4+6*JntNum+(i-1)*PaNum)=-Rad+RadRng(1);
end




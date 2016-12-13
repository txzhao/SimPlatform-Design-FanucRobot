%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DynEulerTest.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 12/5/2014
%
%@Description: Get Symbolic Expression for Dynamic Parameters Identification
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;

syms Ld1 Ld2 Ld3 Ld4 Ld5 Ld6 Ld7 Ld8
syms pos1 pos2 pos3 pos4 pos5 pos6 
syms vel1 vel2 vel3 vel4 vel5 vel6
syms acc1 acc2 acc3 acc4 acc5 acc6
syms gr

kxi = [0;0;0;0;0;1];
V0 = [0;0;0;0;0;0];
%dV0 = [0;0;9.8;0;0;0];
dV0 = [0;0;gr;0;0;0];
Ft = [0;0;0;0;0;0];


% DH=[Ld1     Ld2     0       Ld5     Ld7     0        Ld8;
%     0       0       -pi/2   0       pi      pi       0;
%     0       Ld3     Ld4     Ld6     0       0        0;
%     0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;];
DH=[Ld1     Ld2     0       0     Ld7     0        Ld8;
    0       0       -pi/2   0       pi      pi       0;
    0       Ld3     Ld4     Ld6     0       0        0;
    0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;];

ez = [0;0;1];
ex = [1;0;0];
eo = [0;0;0];
g01_0= simplify(expWre([eo;ez],DH(2,1))*expWre([ez;eo],DH(1,1))*expWre([eo;ex],DH(4,1))*expWre([ex;eo],DH(3,1)));
g12_0= simplify(expWre([eo;ez],DH(2,2))*expWre([ez;eo],DH(1,2))*expWre([eo;ex],DH(4,2))*expWre([ex;eo],DH(3,2)));
g23_0= simplify(expWre([eo;ez],DH(2,3))*expWre([ez;eo],DH(1,3))*expWre([eo;ex],DH(4,3))*expWre([ex;eo],DH(3,3)));
g34_0= simplify(expWre([eo;ez],DH(2,4))*expWre([ez;eo],DH(1,4))*expWre([eo;ex],DH(4,4))*expWre([ex;eo],DH(3,4)));
g45_0= simplify(expWre([eo;ez],DH(2,5))*expWre([ez;eo],DH(1,5))*expWre([eo;ex],DH(4,5))*expWre([ex;eo],DH(3,5)));
g56_0= simplify(expWre([eo;ez],DH(2,6))*expWre([ez;eo],DH(1,6))*expWre([eo;ex],DH(4,6))*expWre([ex;eo],DH(3,6)));
g67_0= simplify(expWre([eo;ez],DH(2,7))*expWre([ez;eo],DH(1,7))*expWre([eo;ex],DH(4,7))*expWre([ex;eo],DH(3,7)));

g01 = simplify(g01_0*expWre(kxi,pos1));
g12 = simplify(g12_0*expWre(kxi,pos2));
g23 = simplify(g23_0*expWre(kxi,pos3));
g34 = simplify(g34_0*expWre(kxi,pos4));
g45 = simplify(g45_0*expWre(kxi,pos5));
g56 = simplify(g56_0*expWre(kxi,pos6));

Adinvg01 = simplify(AdjointInv(g01));
Adinvg12 = simplify(AdjointInv(g12));
Adinvg23 = simplify(AdjointInv(g23));
Adinvg34 = simplify(AdjointInv(g34));
Adinvg45 = simplify(AdjointInv(g45));
Adinvg56 = simplify(AdjointInv(g56));
Adinvg67 = simplify(AdjointInv(g67_0));

Adinvg02 = simplify(Adinvg12*Adinvg01);
Adinvg03 = simplify(Adinvg23*Adinvg02);
Adinvg04 = simplify(Adinvg34*Adinvg03);
Adinvg05 = simplify(Adinvg45*Adinvg04);
Adinvg06 = simplify(Adinvg56*Adinvg05);
Adinvg13 = simplify(Adinvg23*Adinvg12);
Adinvg14 = simplify(Adinvg34*Adinvg13);
Adinvg15 = simplify(Adinvg45*Adinvg14);
Adinvg16 = simplify(Adinvg56*Adinvg15);
Adinvg24 = simplify(Adinvg34*Adinvg23);
Adinvg25 = simplify(Adinvg45*Adinvg24);
Adinvg26 = simplify(Adinvg56*Adinvg25);
Adinvg35 = simplify(Adinvg45*Adinvg34);
Adinvg36 = simplify(Adinvg56*Adinvg35);
Adinvg46 = simplify(Adinvg56*Adinvg45);

ad1 = simplify(ads(kxi*vel1));
ad2 = simplify(ads(kxi*vel2));
ad3 = simplify(ads(kxi*vel3));
ad4 = simplify(ads(kxi*vel4));
ad5 = simplify(ads(kxi*vel5));
ad6 = simplify(ads(kxi*vel6));

I6 = eye(6);
O6 = zeros(6);
G = [I6         O6          O6          O6          O6          O6;
    Adinvg12    I6          O6          O6          O6          O6;
    Adinvg13    Adinvg23    I6          O6          O6          O6;
    Adinvg14    Adinvg24    Adinvg34    I6          O6          O6;
    Adinvg15    Adinvg25    Adinvg35    Adinvg45    I6          O6;
    Adinvg16    Adinvg26    Adinvg36    Adinvg46    Adinvg56    I6];

kxivel(1:6,1)   = kxi*vel1;
kxivel(7:12,1)  = kxi*vel2;
kxivel(13:18,1) = kxi*vel3;
kxivel(19:24,1) = kxi*vel4;
kxivel(25:30,1) = kxi*vel5;
kxivel(31:36,1) = kxi*vel6;

V = G*kxivel;
V1 = V(1:6);
V2 = V(7:12);
V3 = V(13:18);
V4 = V(19:24);
V5 = V(25:30);
V6 = V(31:36);

adV1 = simplify(ads(V1));
adV2 = simplify(ads(V2));
adV3 = simplify(ads(V3));
adV4 = simplify(ads(V4));
adV5 = simplify(ads(V5));
adV6 = simplify(ads(V6));

disp('V--Finsih!');
%%
% %%%%%%%%%%%%%%%%%%%%%%%%
Ov = zeros(6,1);
Am = [kxi   Adinvg12*kxi    Adinvg13*kxi    Adinvg14*kxi    Adinvg15*kxi    Adinvg16*kxi;
      Ov    kxi             Adinvg23*kxi    Adinvg24*kxi    Adinvg25*kxi    Adinvg26*kxi;
      Ov    Ov              kxi             Adinvg34*kxi    Adinvg35*kxi    Adinvg36*kxi;
      Ov    Ov              Ov              kxi             Adinvg45*kxi    Adinvg46*kxi;
      Ov    Ov              Ov              Ov              kxi             Adinvg56*kxi;
      Ov    Ov              Ov              Ov              Ov              kxi];
Am = simplify(Am);
 Bm = [kxi*acc1;
       kxi*acc2 + Adinvg12*kxi*acc1;
       kxi*acc3 + Adinvg23*kxi*acc2 + Adinvg13*kxi*acc1;
       kxi*acc4 + Adinvg34*kxi*acc3 + Adinvg24*kxi*acc2 + Adinvg14*kxi*acc1;
       kxi*acc5 + Adinvg45*kxi*acc4 + Adinvg35*kxi*acc3 + Adinvg25*kxi*acc2 + Adinvg15*kxi*acc1;
       kxi*acc6 + Adinvg56*kxi*acc5 + Adinvg46*kxi*acc4 + Adinvg36*kxi*acc3 + Adinvg26*kxi*acc2 + Adinvg16*kxi*acc1];
Bm = simplify(Bm);
Md = MyMatOp(Am,Bm);

disp('Md--Finish!');
% %%%%%%%%%%%%%%%%
Ac1 = [adV1*kxi     adV2*Adinvg12*kxi   adV3*Adinvg13*kxi   adV4*Adinvg14*kxi   adV5*Adinvg15*kxi   adV6*Adinvg16*kxi;
       Ov           adV2*kxi            adV3*Adinvg23*kxi   adV4*Adinvg24*kxi   adV5*Adinvg25*kxi   adV6*Adinvg26*kxi;
       Ov           Ov                  adV3*kxi            adV4*Adinvg34*kxi   adV5*Adinvg35*kxi   adV6*Adinvg36*kxi;
       Ov           Ov                  Ov                  adV4*kxi            adV5*Adinvg45*kxi   adV6*Adinvg46*kxi;
       Ov           Ov                  Ov                  Ov                  adV5*kxi            adV6*Adinvg56*kxi;
       Ov           Ov                  Ov                  Ov                  Ov                  adV6*kxi];
Ac1 = -Ac1;
Ac1 = simplify(Ac1);
Bc1 = [kxi*vel1;
       kxi*vel2 + Adinvg12*kxi*vel1;
       kxi*vel3 + Adinvg23*kxi*vel2 + Adinvg13*kxi*vel1;
       kxi*vel4 + Adinvg34*kxi*vel3 + Adinvg24*kxi*vel2 + Adinvg14*kxi*vel1;
       kxi*vel5 + Adinvg45*kxi*vel4 + Adinvg35*kxi*vel3 + Adinvg25*kxi*vel2 + Adinvg15*kxi*vel1;
       kxi*vel6 + Adinvg56*kxi*vel5 + Adinvg46*kxi*vel4 + Adinvg36*kxi*vel3 + Adinvg26*kxi*vel2 + Adinvg16*kxi*vel1];
Bc1 = simplify(Bc1);
Cd1 =MyMatOp(Ac1,Bc1);

disp('Cd1--Finish!');
% %%%%%%%%%%%%%%%%%
Ac2 = Am;

Bc2 =[Ov;
      ads(kxi*vel2)*Adinvg12*kxi*vel1;
      ads(kxi*vel3)*Adinvg23*kxi*vel2;
      ads(kxi*vel4)*Adinvg34*kxi*vel3;
      ads(kxi*vel5)*Adinvg45*kxi*vel4;
      ads(kxi*vel6)*Adinvg56*kxi*vel5];

Bc2(13:18,1) = (ads(Adinvg23*kxi*vel2) + ads(kxi*vel3))*Adinvg13*kxi*vel1...
             + Bc2(13:18,1);
Bc2(19:24,1) = (ads(Adinvg24*kxi*vel2) + ads(Adinvg34*kxi*vel3) + ads(kxi*vel4))*Adinvg14*kxi*vel1...
             + (ads(Adinvg34*kxi*vel3) + ads(kxi*vel4))*Adinvg24*kxi*vel2....
             + Bc2(19:24,1);
Bc2(25:30,1) = (ads(Adinvg25*kxi*vel2) + ads(Adinvg35*kxi*vel3) + ads(Adinvg45*kxi*vel4) + ads(kxi*vel5))*Adinvg15*kxi*vel1...
             + (ads(Adinvg35*kxi*vel3) + ads(Adinvg45*kxi*vel4) + ads(kxi*vel5))*Adinvg25*kxi*vel2...
             + (ads(Adinvg45*kxi*vel4) + ads(kxi*vel5))*Adinvg35*kxi*vel3...
             + Bc2(25:30,1);
Bc2(31:36,1) = (ads(Adinvg26*kxi*vel2) + ads(Adinvg36*kxi*vel3) + ads(Adinvg46*kxi*vel4) + ads(Adinvg56*kxi*vel5)+ ads(kxi*vel6))*Adinvg16*kxi*vel1...
             + (ads(Adinvg36*kxi*vel3) + ads(Adinvg46*kxi*vel4) + ads(Adinvg56*kxi*vel5) + ads(kxi*vel6))*Adinvg26*kxi*vel2...
             + (ads(Adinvg46*kxi*vel4) + ads(Adinvg56*kxi*vel5) + ads(kxi*vel6))*Adinvg36*kxi*vel3...
             + (ads(Adinvg56*kxi*vel5) + ads(kxi*vel6))*Adinvg46*kxi*vel4...
             + Bc2(31:36,1);
         
         
% Bc2(13:18,1) = (ads(kxi*vel2) + ads(kxi*vel3))*Adinvg13*kxi*vel1...
%              + Bc2(13:18,1);
% Bc2(19:24,1) = (ads(kxi*vel2) + ads(kxi*vel3) + ads(kxi*vel4))*Adinvg14*kxi*vel1...
%              + (ads(kxi*vel3) + ads(kxi*vel4))*Adinvg24*kxi*vel2....
%              + Bc2(19:24,1);
% Bc2(25:30,1) = (ads(kxi*vel2) + ads(kxi*vel3) + ads(kxi*vel4) + ads(kxi*vel5))*Adinvg15*kxi*vel1...
%              + (ads(kxi*vel3) + ads(kxi*vel4) + ads(kxi*vel5))*Adinvg25*kxi*vel2...
%              + (ads(kxi*vel4) + ads(kxi*vel5))*Adinvg35*kxi*vel3...
%              + Bc2(25:30,1);
% Bc2(31:36,1) = (ads(kxi*vel2) + ads(kxi*vel3) + ads(kxi*vel4) + ads(kxi*vel5)+ ads(kxi*vel6))*Adinvg16*kxi*vel1...
%              + (ads(kxi*vel3) + ads(kxi*vel4) + ads(kxi*vel5) + ads(kxi*vel6))*Adinvg26*kxi*vel2...
%              + (ads(kxi*vel4) + ads(kxi*vel5) + ads(kxi*vel6))*Adinvg36*kxi*vel3...
%              + (ads(kxi*vel5) + ads(kxi*vel6))*Adinvg46*kxi*vel4...
%              + Bc2(31:36,1);         
Bc2 = -Bc2;         
Bc2 = simplify(Bc2);
Cd2 = MyMatOp(Ac2,Bc2);

disp('Cd2--Finish!');
% %%%%%%%%%%%%%%%%
An = Am;
Bn = [Adinvg01*dV0;
      Adinvg02*dV0;
      Adinvg03*dV0;
      Adinvg04*dV0;
      Adinvg05*dV0;
      Adinvg06*dV0];

Nd = MyMatOp(An,Bn);

disp('Nd--Finish!');
%% 
%%%%%%%%%%%%%%%%%
Wd_ = Md + Cd1 + Cd2 + Nd;
%%
%Ld = [Ld1 Ld2 Ld3 Ld4 Ld5 Ld6 Ld7 Ld8];
Ld = [Ld1 Ld2 Ld3 Ld4 Ld6 Ld7 Ld8];
Pos =[pos1 pos2 pos3 pos4 pos5 pos6];
Vel =[vel1 vel2 vel3 vel4 vel5 vel6];
Acc =[acc1 acc2 acc3 acc4 acc5 acc6];
%EulerWd_ = matlabFunction(Wd_,'file','EulerWd','vars',{Ld,Pos,Vel,Acc,gr});

disp('Wd--Finish!');

% %% Considering Motor
% syms k1 k2 k3 k4 k5 k6 
% 
% % Attn: in order to decrease the number of symbol parameters, we choose specific direction of zm
% % However, different types need to reassign different value to zm based on different motor installation
% zm1 = [0;0;1]; % relative to base frame
% zm2 = [0;-1;0]; % relative to joint 1 frame
% zm3 = [0;0;1];  % relative to joint 2 frame
% zm4 = [0;1;0];  % relative to joint 3 frame
% zm5 = [0;-1;0];  % relative to joint 4 frame
% zm6 = [0;1;0];  % relative to joint 4 frame
% 
% % calculate motor angular velocity
% wm1 = 0         + k1*acc1*zm1 + k1*vel1*0;
% wm2 = V1(4:6)   + k2*acc2*zm2 + k2*vel2*cross(V1(4:6),zm2);
% wm3 = V2(4:6)   + k3*acc3*zm3 + k3*vel3*cross(V2(4:6),zm3);
% wm4 = V3(4:6)   + k4*acc4*zm4 + k4*vel4*cross(V3(4:6),zm4);
% wm5 = V4(4:6)   + k5*acc5*zm5 + k5*vel5*cross(V4(4:6),zm5);
% wm6 = V4(4:6)   + k6*acc6*zm6 + k6*vel6*cross(V4(4:6),zm6);
% 
% R1 = [0;0;0;(k2*acc2)*zm2 + (k2*vel2)*cross(V1(4:6),zm2)];
% R2 = [0;0;0;(k3*acc3)*zm3 + (k3*vel3)*cross(V2(4:6),zm3)];
% R3 = [0;0;0;(k4*acc4)*zm4 + (k4*vel4)*cross(V3(4:6),zm4)];
% R4 = [0;0;0;(k5*acc5)*zm5 + (k5*vel5)*cross(V4(4:6),zm5)+(k6*acc6)*zm6 + (k6*vel6)*cross(V4(4:6),zm6)];
% R5 = [0;0;0;0;0;0];
% R6 = [0;0;0;0;0;0];
% 
% % calculate Wm
% Wm = [k1*wm1'*zm1   kxi'*R1         0               0               0               0;
%       0             k2*wm2'*zm2     kxi'*R2         0               0               0;
%       0             0               k3*wm3'*zm3     kxi'*R3         0               0;
%       0             0               0               k4*wm4'*zm4     kxi'*R4         0;
%       0             0               0               0               k5*wm5'*zm5     kxi'*R5;
%       0             0               0               0               0               k6*wm6'*zm6];
%   
% K = [k1 k2 k3 k4 k5 k6];
% Ld = [Ld1 Ld2 Ld3 Ld4 Ld5 Ld6 Ld7 Ld8];
% Pos =[pos1 pos2 pos3 pos4 pos5 pos6];
% Vel =[vel1 vel2 vel3 vel4 vel5 vel6];
% Acc =[acc1 acc2 acc3 acc4 acc5 acc6];
% 
% EulerWm = matlabFunction(Wm,'file','EulerWm','vars',{Ld,K,Pos,Vel,Acc});
% 
% disp('Wm--Finish!');







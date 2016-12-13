%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EuleSetup_MinF3.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 14/3/2015
%
%@Description: Get Symbolic Expression for Dynamic Parameters Identification
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;

syms Ld1 Ld2 Ld3 Ld4 Ld5 
syms pos1 pos2 pos3 pos4 pos5 pos6 
syms vel1 vel2 vel3 vel4 vel5 vel6
syms acc1 acc2 acc3 acc4 acc5 acc6
syms gr

kxi = [0;0;0;0;0;1];
V0 = [0;0;0;0;0;0];
%dV0 = [0;0;9.8;0;0;0];
dV0 = [0;0;gr;0;0;0];
Ft = [0;0;0;0;0;0];



DH=[0       0       pos1       Ld1;
    -pi/2   Ld2     pos2       0;
    0       Ld3     pos3       0;]';

ez = [0;0;1];
ex = [1;0;0];
eo = [0;0;0];
g01= simplify(expWre([ex;eo],DH(2,1))*expWre([eo;ex],DH(1,1))*expWre([ez;eo],DH(4,1))*expWre([eo;ez],DH(3,1)));
g12= simplify(expWre([ex;eo],DH(2,2))*expWre([eo;ex],DH(1,2))*expWre([ez;eo],DH(4,2))*expWre([eo;ez],DH(3,2)));
g23= simplify(expWre([ex;eo],DH(2,3))*expWre([eo;ex],DH(1,3))*expWre([ez;eo],DH(4,3))*expWre([eo;ez],DH(3,3)));



Adinvg01 = simplify(AdjointInv(g01));
Adinvg12 = simplify(AdjointInv(g12));
Adinvg23 = simplify(AdjointInv(g23));


Adinvg02 = simplify(Adinvg12*Adinvg01);
Adinvg03 = simplify(Adinvg23*Adinvg02);
Adinvg13 = simplify(Adinvg23*Adinvg12);

ad1 = simplify(ads(kxi*vel1));
ad2 = simplify(ads(kxi*vel2));
ad3 = simplify(ads(kxi*vel3));


I6 = eye(6);
O6 = zeros(6);
G = [I6         O6          O6;
    Adinvg12    I6          O6;
    Adinvg13    Adinvg23    I6;];

kxivel(1:6,1)   = kxi*vel1;
kxivel(7:12,1)  = kxi*vel2;
kxivel(13:18,1) = kxi*vel3;

V = G*kxivel;
V1 = V(1:6);
V2 = V(7:12);
V3 = V(13:18);


adV1 = simplify(ads(V1));
adV2 = simplify(ads(V2));
adV3 = simplify(ads(V3));


disp('V--Finsih!');
%%
% %%%%%%%%%%%%%%%%%%%%%%%%
Ov = zeros(6,1);
Am = [kxi   Adinvg12*kxi    Adinvg13*kxi    ;
      Ov    kxi             Adinvg23*kxi    ;
      Ov    Ov              kxi             ;];
Am = simplify(Am);
Bm = [ kxi*acc1;
       kxi*acc2 + Adinvg12*kxi*acc1;
       kxi*acc3 + Adinvg23*kxi*acc2 + Adinvg13*kxi*acc1;];
Bm = simplify(Bm);
Md = MyMatOp(Am,Bm);

disp('Md--Finish!');
% %%%%%%%%%%%%%%%%
Ac1 = [adV1*kxi     adV2*Adinvg12*kxi   adV3*Adinvg13*kxi   ;
       Ov           adV2*kxi            adV3*Adinvg23*kxi   ;
       Ov           Ov                  adV3*kxi            ;];
Ac1 = -Ac1;
Ac1 = simplify(Ac1);
Bc1 = [kxi*vel1;
       kxi*vel2 + Adinvg12*kxi*vel1;
       kxi*vel3 + Adinvg23*kxi*vel2 + Adinvg13*kxi*vel1;];
Bc1 = simplify(Bc1);
Cd1 =MyMatOp(Ac1,Bc1);

disp('Cd1--Finish!');
% %%%%%%%%%%%%%%%%%
Ac2 = Am;

Bc2 =[Ov;
      ads(kxi*vel2)*Adinvg12*kxi*vel1;
      ads(kxi*vel3)*Adinvg23*kxi*vel2;];

Bc2(13:18,1) = (ads(Adinvg23*kxi*vel2) + ads(kxi*vel3))*Adinvg13*kxi*vel1...
             + Bc2(13:18,1);

Bc2 = -Bc2;         
Bc2 = simplify(Bc2);
Cd2 = MyMatOp(Ac2,Bc2);

disp('Cd2--Finish!');
% %%%%%%%%%%%%%%%%
An = Am;
Bn = [Adinvg01*dV0;
      Adinvg02*dV0;
      Adinvg03*dV0;];

Nd = MyMatOp(An,Bn);

disp('Nd--Finish!');
%% 
%%%%%%%%%%%%%%%%%
Wd_ = Md + Cd1 + Cd2 + Nd;
%%
%Ld = [Ld1 Ld2 Ld3 Ld4 Ld5 Ld6 Ld7 Ld8];
Ld = [Ld1 Ld2 Ld3];
Pos =[pos1 pos2 pos3];
Vel =[vel1 vel2 vel3];
Acc =[acc1 acc2 acc3];
EulerWd_ = matlabFunction(Wd_,'file','EulerWd_MinF3','vars',{Ld,Pos,Vel,Acc,gr});

disp('Wd--Finish!');

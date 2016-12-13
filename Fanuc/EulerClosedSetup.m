%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerClose.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 12/5/2014
%
%@Description: Get Symbolic Expression for Closed-Form Euler Dynamic
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;

%%
syms pos1 pos2 pos3 pos4 pos5 pos6 
syms vel1 vel2 vel3 vel4 vel5 vel6

syms Ld1 Ld2 Ld3 Ld4 Ld5 Ld6 Ld7 Ld8 gr
syms Cx1 Cx2 Cx3 Cx4 Cx5 Cx6
syms Cy1 Cy2 Cy3 Cy4 Cy5 Cy6
syms Cz1 Cz2 Cz3 Cz4 Cz5 Cz6
syms Ma1 Ma2 Ma3 Ma4 Ma5 Ma6 
syms I1_11 I1_12 I1_13 I1_21 I1_22 I1_23 I1_31 I1_32 I1_33 
syms I2_11 I2_12 I2_13 I2_21 I2_22 I2_23 I2_31 I2_32 I2_33 
syms I3_11 I3_12 I3_13 I3_21 I3_22 I3_23 I3_31 I3_32 I3_33 
syms I4_11 I4_12 I4_13 I4_21 I4_22 I4_23 I4_31 I4_32 I4_33 
syms I5_11 I5_12 I5_13 I5_21 I5_22 I5_23 I5_31 I5_32 I5_33 
syms I6_11 I6_12 I6_13 I6_21 I6_22 I6_23 I6_31 I6_32 I6_33 


Pos =[pos1 pos2 pos3 pos4 pos5 pos6];
Vel =[vel1 vel2 vel3 vel4 vel5 vel6];
Ld = [Ld1 Ld2 Ld3 Ld4 Ld5 Ld6 Ld7 Ld8];
Cen = [Cx1 Cx2 Cx3 Cx4 Cx5 Cx6 Cy1 Cy2 Cy3 Cy4 Cy5 Cy6 Cz1 Cz2 Cz3 Cz4 Cz5 Cz6];
Ma = [Ma1 Ma2 Ma3 Ma4 Ma5 Ma6];
Ie1 = [I1_11 I1_21 I1_31 I1_12 I1_22 I1_32 I1_13 I1_23 I1_33];
Ie2 = [I2_11 I2_21 I2_31 I2_12 I2_22 I2_32 I2_13 I2_23 I2_33];
Ie3 = [I3_11 I3_21 I3_31 I3_12 I3_22 I3_32 I3_13 I3_23 I3_33];
Ie4 = [I4_11 I4_21 I4_31 I4_12 I4_22 I4_32 I4_13 I4_23 I4_33];
Ie5 = [I5_11 I5_21 I5_31 I5_12 I5_22 I5_32 I5_13 I5_23 I5_33];
Ie6 = [I6_11 I6_21 I6_31 I6_12 I6_22 I6_32 I6_13 I6_23 I6_33];

kxi=[0;0;0;0;0;1];
V0=[0;0;0;0;0;0];
dV0=[0;0;gr;0;0;0];

DH=[Ld1     Ld2     0       Ld5     Ld7     0        Ld8;
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

I1=reshape(Ie1,3,3);
I2=reshape(Ie2,3,3);
I3=reshape(Ie3,3,3);
I4=reshape(Ie4,3,3);
I5=reshape(Ie5,3,3);
I6=reshape(Ie6,3,3);

g=g01_0;
r1 = simplify(g\[Cx1;Cy1;Cz1;1]);
r1 = r1(1:3);
g=g*g12_0;
r2 = simplify(g\[Cx2;Cy2;Cz2;1]);
r2 = r2(1:3);
R = g(1:3,1:3);
I2 = simplify(R.'*I2*R);
g=g*g23_0;
r3 = simplify(g\[Cx3;Cy3;Cz3;1]);
r3 = r3(1:3);
R = g(1:3,1:3);
I3 = simplify(R.'*I3*R);
g=g*g34_0;
r4 = simplify(g\[Cx4;Cy4;Cz4;1]);
r4 = r4(1:3);
R = g(1:3,1:3);
I4 = simplify(R.'*I4*R);
g=g*g45_0;
r5 = simplify(g\[Cx5;Cy5;Cz5;1]);
r5 = r5(1:3);
R = g(1:3,1:3);
I5 = simplify(R.'*I5*R);
g=g*g56_0;
r6 = simplify(g\[Cx6;Cy6;Cz6;1]);
r6 = r6(1:3);
R = g(1:3,1:3);
I6 = simplify(R.'*I6*R);

I_3=eye(3);
hr1 = skew(r1);
M1=[Ma1*I_3          -Ma1*hr1;
    Ma1*hr1         I1-Ma1*hr1*hr1];

hr2 = skew(r2);
M2=[Ma2*I_3          -Ma2*hr2;
    Ma2*hr2         I2-Ma2*hr2*hr2];

hr3 = skew(r3);
M3=[Ma3*I_3          -Ma3*hr3;
    Ma3*hr3         I3-Ma3*hr3*hr3];

hr4 = skew(r4);
M4=[Ma4*I_3          -Ma4*hr4;
    Ma4*hr4         I4-Ma4*hr4*hr4];

hr5 = skew(r5);
M5=[Ma5*I_3          -Ma5*hr5;
    Ma5*hr5         I5-Ma5*hr5*hr5];

hr6 = skew(r6);
M6=[Ma6*I_3          -Ma6*hr6;
    Ma6*hr6         I6-Ma6*hr6*hr6];

I6 = eye(6);
O6 = zeros(6);
M=[M1 O6 O6 O6 O6 O6;
   O6 M2 O6 O6 O6 O6;
   O6 O6 M3 O6 O6 O6;
   O6 O6 O6 M4 O6 O6;
   O6 O6 O6 O6 M5 O6;
   O6 O6 O6 O6 O6 M6];

disp('M Finished!!!');
%%
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

Xi=zeros(36,6);
for i=1:6
    Xi((i-1)*6+1:6*i,i)=kxi;
end

G = [I6         O6          O6          O6          O6          O6;
    Adinvg12    I6          O6          O6          O6          O6;
    Adinvg13    Adinvg23    I6          O6          O6          O6;
    Adinvg14    Adinvg24    Adinvg34    I6          O6          O6;
    Adinvg15    Adinvg25    Adinvg35    Adinvg45    I6          O6;
    Adinvg16    Adinvg26    Adinvg36    Adinvg46    Adinvg56    I6];

P0=[Adinvg01;O6;O6;O6;O6;O6];

disp('G and P0 Finished!!!');
%%
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

adVT =[ -adV1.'  O6         O6          O6          O6          O6;
        O6       -adV2.'    O6          O6          O6          O6;
        O6       O6         -adV3.'     O6          O6          O6;
        O6       O6         O6          -adV4.'     O6          O6;
        O6       O6         O6          O6          -adV5.'     O6;
        O6       O6         O6          O6          O6          -adV6.'];

disp('adVT Finished!!!');    
%%
ad1 = simplify(ads(kxi*vel1));
ad2 = simplify(ads(kxi*vel2));
ad3 = simplify(ads(kxi*vel3));
ad4 = simplify(ads(kxi*vel4));
ad5 = simplify(ads(kxi*vel5));
ad6 = simplify(ads(kxi*vel6));

adxi =[ -ad1     O6         O6          O6          O6          O6;
        O6       -ad2       O6          O6          O6          O6;
        O6       O6         -ad3        O6          O6          O6;
        O6       O6         O6          -ad4        O6          O6;
        O6       O6         O6          O6          -ad5        O6;
        O6       O6         O6          O6          O6          -ad6];
    
Gamma=[ O6          O6          O6          O6          O6          O6;
        Adinvg12    O6          O6          O6          O6          O6;
        O6          Adinvg23    O6          O6          O6          O6;
        O6          O6          Adinvg34    O6          O6          O6;
        O6          O6          O6          Adinvg45    O6          O6;
        O6          O6          O6          O6          Adinvg56    O6]; 
disp('adxi and Gamma Finished!!!');    
%% 

GXi = G*Xi;
XiG_ = Xi.'*G.';

EulerMd_ = XiG_*M*GXi;
EulerMd = matlabFunction(EulerMd_,'file','EulerMd','vars',{Ld,Ma,Cen,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6,Pos});
disp('Euler Md Finished!!!');



%%
EulerNd_ = XiG_*M*G*P0*dV0;
EulerNd = matlabFunction(EulerNd_,'file','EulerNd','vars',{Ld,Ma,Cen,Pos,gr});
disp('Euler Nd Finished!!!');

disp('Finished!!!');

%%

EulerCd_ = XiG_*M*G*adxi*Gamma*GXi;
EulerCd_ = EulerCd_ + XiG_*adVT*M*GXi;
disp('Finish Expression Calculation!');
EulerCd = matlabFunction(EulerCd_,'file','EulerCd','vars',{Ld,Ma,Cen,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6,Pos,Vel});
disp('Euler Cd Finished!!!');    
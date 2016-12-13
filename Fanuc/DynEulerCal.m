%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DynEulerCal.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 14/5/2014
%
%@Function: DynEulerCal
%@Description: Implementing Newton-Euler Recursion Algorithm(Parameters Type) to get computed torque
%Instead of accurate Ma,Cen,Ie, it only need equivalent dynmaic parameters set which may obtained from
%standard identification process. 
%@Input:
%DH: DH parameters
%Param: [m1 mr1 mr2 mr3 Ixx1 Iyy1 Izz1 Ixy1 Ixz1 Iyz1....]
%Ft: generalized force exerted on endeffetor 
%Pos: joint angle
%Vel: joint velocity
%Acc: joint acceleration
%@Output:
%Tau: Torque
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Torque = DynEulerCal(DH,Param,Ft,Pos,Vel,Acc)

% %% Calculate kxi in corresponding joint frame, different from in base frame
w_o = [0;0;0];
w_z = [0;0;1];

kxi1 = [w_o;w_z];
kxi2 = [w_o;w_z];
kxi3 = [w_o;w_z];
kxi4 = [w_o;w_z];
kxi5 = [w_o;w_z];
kxi6 = [w_o;w_z];

% %% Calculate initial configuration matrix g_{i-1,i}
% 0: means base frame;
% 1,2,3,4,5,6: means i-th joint frame, Ci
% 7: means endeffector frame
% DH=[266     300     0       0       1016     0      174;
%     0       0       -pi/2   0       pi      pi       0;
%     0       150     870     170     0       0        0;
%     0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;];

ez = [0;0;1];
ex = [1;0;0];
eo = [0;0;0];

g01_0= expg([eo;ez],DH(2,1))*expg([ez;eo],DH(1,1))*expg([eo;ex],DH(4,1))*expg([ex;eo],DH(3,1));
g12_0= expg([eo;ez],DH(2,2))*expg([ez;eo],DH(1,2))*expg([eo;ex],DH(4,2))*expg([ex;eo],DH(3,2));
g23_0= expg([eo;ez],DH(2,3))*expg([ez;eo],DH(1,3))*expg([eo;ex],DH(4,3))*expg([ex;eo],DH(3,3));
g34_0= expg([eo;ez],DH(2,4))*expg([ez;eo],DH(1,4))*expg([eo;ex],DH(4,4))*expg([ex;eo],DH(3,4));
g45_0= expg([eo;ez],DH(2,5))*expg([ez;eo],DH(1,5))*expg([eo;ex],DH(4,5))*expg([ex;eo],DH(3,5));
g56_0= expg([eo;ez],DH(2,6))*expg([ez;eo],DH(1,6))*expg([eo;ex],DH(4,6))*expg([ex;eo],DH(3,6));
g67_0= expg([eo;ez],DH(2,7))*expg([ez;eo],DH(1,7))*expg([eo;ex],DH(4,7))*expg([ex;eo],DH(3,7));

% %% Equivalent Dynamic Parameters %%%%%%%%%
M1 = [  Param(1)      0           0           0           Param(4)    -Param(3);
        0             Param(1)    0           -Param(4)   0           Param(2);
        0             0           Param(1)    Param(3)    -Param(2)   0;
        0             -Param(4)   Param(3)    Param(5)    Param(8)    Param(9); 
        Param(4)      0           -Param(2)   Param(8)    Param(6)    Param(10);
        -Param(3)     Param(2)    0           Param(9)    Param(10)   Param(7)];
  
M2 = [  Param(11)     0           0            0            Param(14)    -Param(13);
        0             Param(11)   0            -Param(14)   0            Param(12);
        0             0           Param(11)    Param(13)    -Param(12)   0;
        0             -Param(14)  Param(13)    Param(15)    Param(18)    Param(19); 
        Param(14)     0           -Param(12)   Param(18)    Param(16)    Param(20);
        -Param(13)    Param(12)   0            Param(19)    Param(20)    Param(17)];

M3 = [  Param(21)     0           0            0            Param(24)    -Param(23);
        0             Param(21)   0            -Param(24)   0            Param(22);
        0             0           Param(21)    Param(23)    -Param(22)   0;
        0             -Param(24)  Param(23)    Param(25)    Param(28)    Param(29); 
        Param(24)     0           -Param(22)   Param(28)    Param(26)    Param(30);
        -Param(23)    Param(22)   0            Param(29)    Param(30)    Param(27)];

M4 = [  Param(31)     0           0            0            Param(34)    -Param(33);
        0             Param(31)   0            -Param(34)   0            Param(32);
        0             0           Param(31)    Param(33)    -Param(32)   0;
        0             -Param(34)  Param(33)    Param(35)    Param(38)    Param(39); 
        Param(34)     0           -Param(32)   Param(38)    Param(36)    Param(40);
        -Param(33)    Param(32)   0            Param(39)    Param(40)    Param(37)];

M5 = [  Param(41)     0           0            0            Param(44)    -Param(43);
        0             Param(41)   0            -Param(44)   0            Param(42);
        0             0           Param(41)    Param(43)    -Param(42)   0;
        0             -Param(44)  Param(43)    Param(45)    Param(48)    Param(49); 
        Param(44)     0           -Param(42)   Param(48)    Param(46)    Param(50);
        -Param(43)    Param(42)   0            Param(49)    Param(50)    Param(47)];
    
M6 = [  Param(51)     0           0            0            Param(54)    -Param(53);
        0             Param(51)   0            -Param(54)   0            Param(52);
        0             0           Param(51)    Param(53)    -Param(52)   0;
        0             -Param(54)  Param(53)    Param(55)    Param(58)    Param(59); 
        Param(54)     0           -Param(52)   Param(58)    Param(56)    Param(60);
        -Param(53)    Param(52)   0            Param(59)    Param(60)    Param(57)];    

% %% Forward Recursion (kinematic)
% Initial State
V0 = [0;0;0;0;0;0];
dV0 = [0;0;9.8;0;0;0];

% Joint 1:
g01 = g01_0 * expg(kxi1,Pos(1));
Adinvg01 = Adj(g01\eye(4));
V1  = Adinvg01 * V0 + kxi1*Vel(1);
dV1 = kxi1*Acc(1) +  Adinvg01 * dV0 - ad(kxi1*Vel(1))*(Adinvg01*V0);

% Joint 2:
g12 = g12_0 * expg(kxi2,Pos(2));
Adinvg12 = Adj(g12\eye(4));
V2  = Adinvg12 * V1 + kxi2*Vel(2);
dV2 = kxi2*Acc(2) +  Adinvg12 * dV1 - ad(kxi2*Vel(2))*(Adinvg12*V1);

% Joint 3:
g23 = g23_0 * expg(kxi3,Pos(3));
Adinvg23 = Adj(g23\eye(4));
V3  = Adinvg23 * V2 + kxi3*Vel(3);
dV3 = kxi3*Acc(3) +  Adinvg23 * dV2 - ad(kxi3*Vel(3))*(Adinvg23*V2);

% Joint 4:
g34 = g34_0 * expg(kxi4,Pos(4));
Adinvg34 = Adj(g34\eye(4));
V4  = Adinvg34 * V3 + kxi4*Vel(4);
dV4 = kxi4*Acc(4) +  Adinvg34 * dV3 - ad(kxi4*Vel(4))*(Adinvg34*V3);

% Joint 5:
g45 = g45_0 * expg(kxi5,Pos(5));
Adinvg45 = Adj(g45\eye(4));
V5  = Adinvg45 * V4 + kxi5*Vel(5);
dV5 = kxi5*Acc(5) +  Adinvg45 * dV4 - ad(kxi5*Vel(5))*(Adinvg45*V4);

% Joint 6:
g56 = g56_0 * expg(kxi6,Pos(6));
Adinvg56 = Adj(g56\eye(4));
V6  = Adinvg56 * V5 + kxi6*Vel(6);
dV6 = kxi6*Acc(6) +  Adinvg56 * dV5 - ad(kxi6*Vel(6))*(Adinvg56*V5);

% %% Backward Recursion (inverse dynamic)
% Initial State
Tau=zeros(6,1);
F7 = Ft;
Adinvg67 = Adj(g67_0\eye(4));

% Joint 6
F6 = Adinvg67'* F7 + M6*dV6 - ad(V6)'*M6*V6;
Tau(6) = kxi6'* F6;

% Joint 5
F5 = Adinvg56'* F6 + M5*dV5 - ad(V5)'*M5*V5;
Tau(5) = kxi5'* F5;

% Joint 4
F4 = Adinvg45'* F5 + M4*dV4 - ad(V4)'*M4*V4;
Tau(4) = kxi4'* F4;

% Joint 3
F3 = Adinvg34'* F4 + M3*dV3 - ad(V3)'*M3*V3;
Tau(3) = kxi3'* F3;

% Joint 2
F2 = Adinvg23'* F3 + M2*dV2 - ad(V2)'*M2*V2;
Tau(2) = kxi2'* F2;

% Joint 1
F1 = Adinvg12'* F2 + M1*dV1 - ad(V1)'*M1*V1;
Tau(1) = kxi1'* F1;

Torque = Tau;
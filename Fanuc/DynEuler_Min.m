%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DynEuler_Min.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 26/02/2015
%
%@Function: DynEuler_Min
%@Description: Implementing Newton-Euler Recursion Algorithm(Classic Type) to get computed torque
%@Input:
%DH: DH parameters, it is different from normal definition as implemented by DynEuler.m
%Ma: link mass
%Cen: link masss center
%Ie: link inertial
%Ft: generalized force exerted on endeffetor 
%Pos: joint angle
%Vel: joint velocity
%Acc: joint acceleration
%@Output:
%Tau: Torque
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Torque,JntVel,JntAcc,JntF] = DynEuler_Min(DH,Ma,Cen,Ie,Ft,Pos,Vel,Acc)

JntVel=zeros(36,1);
JntAcc=zeros(36,1);
JntF=zeros(36,1);
Torque=[0;0;0;0;0;0];

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
% DH=[0       0       pos1    Ld1;
%     -pi/2   Ld2     pos2    0;
%     0       Ld3     pos3    0;
%     -pi/2   Ld4     pos4    Ld5;
%     pi/2    0       pos5    0;
%     -pi/2   0       pos6    0;
%     0       0       0       Ld7]';

ez = [0;0;1];
ex = [1;0;0];
eo = [0;0;0];

g01_0 = expWre([ex;eo],DH(2,1))*expWre([eo;ex],DH(1,1))*expWre([ez;eo],DH(4,1))*expWre([eo;ez],DH(3,1));
g12_0 = expWre([ex;eo],DH(2,2))*expWre([eo;ex],DH(1,2))*expWre([ez;eo],DH(4,2))*expWre([eo;ez],DH(3,2));
g23_0 = expWre([ex;eo],DH(2,3))*expWre([eo;ex],DH(1,3))*expWre([ez;eo],DH(4,3))*expWre([eo;ez],DH(3,3));
g34_0 = expWre([ex;eo],DH(2,4))*expWre([eo;ex],DH(1,4))*expWre([ez;eo],DH(4,4))*expWre([eo;ez],DH(3,4));
g45_0 = expWre([ex;eo],DH(2,5))*expWre([eo;ex],DH(1,5))*expWre([ez;eo],DH(4,5))*expWre([eo;ez],DH(3,5));
g56_0 = expWre([ex;eo],DH(2,6))*expWre([eo;ex],DH(1,6))*expWre([ez;eo],DH(4,6))*expWre([eo;ez],DH(3,6));
g67_0 = expWre([ex;eo],DH(2,7))*expWre([eo;ex],DH(1,7))*expWre([ez;eo],DH(4,7))*expWre([eo;ez],DH(3,7));

m1  = Ma(1);
I1  = reshape(Ie(1:9),3,3);
m2  = Ma(2);
I2  = reshape(Ie(10:18),3,3);
m3  = Ma(3);
I3  = reshape(Ie(19:27),3,3);
m4  = Ma(4);
I4  = reshape(Ie(28:36),3,3);
m5  = Ma(5);
I5  = reshape(Ie(37:45),3,3);
m6  = Ma(6);
I6  = reshape(Ie(46:54),3,3);
% %% calculate ri: ith link mass center offset relative to ith joint frame,i=1,2,3,4,5,6

g=g01_0;
r1 = g\[Cen(1:3);1];
r1 = r1(1:3);
g=g*g12_0;
r2 = g\[Cen(4:6);1];
r2 = r2(1:3);
R = g(1:3,1:3);
I2 = R'*I2*R;
g=g*g23_0;
r3 = g\[Cen(7:9);1];
r3 = r3(1:3);
R = g(1:3,1:3);
I3 = R'*I3*R;
g=g*g34_0;
r4 = g\[Cen(10:12);1];
r4 = r4(1:3);
R = g(1:3,1:3);
I4 = R'*I4*R;
g=g*g45_0;
r5 = g\[Cen(13:15);1];
r5 = r5(1:3);
R = g(1:3,1:3);
I5 = R'*I5*R;
g=g*g56_0;
r6 = g\[Cen(16:18);1];
r6 = r6(1:3);
R = g(1:3,1:3);
I6 = R'*I6*R;


% %% calculate momentt of inertia in Ci,i=1,2,3,4,5,6

M1  = [ m1*eye(3),      -m1*hat(r1);
        m1*hat(r1),    I1 - m1*hat(r1)*hat(r1)];

M2  = [ m2*eye(3),      -m2*hat(r2);
        m2*hat(r2),    I2 - m2*hat(r2)*hat(r2)];

M3  = [ m3*eye(3),      -m3*hat(r3);
        m3*hat(r3),    I3 - m3*hat(r3)*hat(r3)]; 

M4  = [ m4*eye(3),      -m4*hat(r4);
        m4*hat(r4),    I4 - m4*hat(r4)*hat(r4)];    

M5  = [ m5*eye(3),      -m5*hat(r5);
        m5*hat(r5),    I5 - m5*hat(r5)*hat(r5)];
    
M6  = [ m6*eye(3),      -m6*hat(r6);
        m6*hat(r6),    I6 - m6*hat(r6)*hat(r6)];    

% %% Forward Recursion (kinematic)
% Initial State
V0 = [0;0;0;0;0;0];
dV0 = [0;0;9.8;0;0;0];

% Joint 1:
g01 = g01_0 * expg(kxi1,Pos(1));
Adinvg01 = Adj(g01\eye(4));
V1  = Adinvg01 * V0 + kxi1*Vel(1);
dV1 = kxi1*Acc(1) +  Adinvg01 * dV0 - ad(kxi1*Vel(1))*(Adinvg01*V0);
% dV1 = kxi1*Acc(1) + Adinvg01 * dV0;
% dV1(1:3) = dV1(1:3) + g01(1:3,1:3)'*cross(V0(4:6),cross(V0(4:6),g01(1:3,4)));
% dV1(4:6) = dV1(4:6) + g01(1:3,1:3)'*Vel(1)*cross(V0(4:6),g01(1:3,1:3)*kxi1(4:6));

%JntVel(1) =[0;0;0;0;0;1]'*(Adj(g01)*V1);
JntVel(1:6)=V1;
JntAcc(1:6)=dV1;

% Joint 2:

g12 = g12_0 * expg(kxi2,Pos(2));
Adinvg12 = Adj(g12\eye(4));
V2  = Adinvg12 * V1 + kxi2*Vel(2);
dV2 = kxi2*Acc(2) +  Adinvg12 * dV1 - ad(kxi2*Vel(2))*(Adinvg12*V1);
% dV2 = kxi2*Acc(2) + Adinvg12 * dV1;
% dV2(1:3) = dV2(1:3) + g12(1:3,1:3)'*cross(V1(4:6),cross(V1(4:6),g12(1:3,4)));
% dV2(4:6) = dV2(4:6) + g12(1:3,1:3)'*Vel(2)*cross(V1(4:6),g12(1:3,1:3)*kxi2(4:6));


%JntVel(2) = [0;0;0;0;1;0]'*(Adj(g01*g12)*V2);
JntVel(7:12)=V2;
JntAcc(7:12)=dV2;

% Joint 3:
g23 = g23_0 * expg(kxi3,Pos(3));
Adinvg23 = Adj(g23\eye(4));
V3  = Adinvg23 * V2 + kxi3*Vel(3);
dV3 = kxi3*Acc(3) +  Adinvg23 * dV2 - ad(kxi3*Vel(3))*(Adinvg23*V2);
% dV3 = kxi3*Acc(3) + Adinvg23 * dV2;
% dV3(1:3) = dV3(1:3) + g23(1:3,1:3)'*cross(V2(4:6),cross(V2(4:6),g23(1:3,4)));
% dV3(4:6) = dV3(4:6) + g23(1:3,1:3)'*Vel(3)*cross(V2(4:6),g23(1:3,1:3)*kxi3(4:6));

%JntVel(3) = [0;0;0;0;1;0]'*(Adj(g01*g12*g23)*V3);
JntVel(13:18)=V3;
JntAcc(13:18)=dV3;

% Joint 4:
g34 = g34_0 * expg(kxi4,Pos(4));
Adinvg34 = Adj(g34\eye(4));
V4  = Adinvg34 * V3 + kxi4*Vel(4);
dV4 = kxi4*Acc(4) +  Adinvg34 * dV3 - ad(kxi4*Vel(4))*(Adinvg34*V3);
% dV4 = kxi4*Acc(4) + Adinvg34 * dV3;
% dV4(1:3) = dV4(1:3) + g34(1:3,1:3)'*cross(V3(4:6),cross(V3(4:6),g34(1:3,4)));
% dV4(4:6) = dV4(4:6) + g34(1:3,1:3)'*Vel(4)*cross(V3(4:6),g34(1:3,1:3)*kxi4(4:6));

%JntVel(4) = [0;0;0;1;0;0]'*(Adj(g01*g12*g23*g34)*V4);
JntVel(19:24)=V4;
JntAcc(19:24)=dV4;

% Joint 5:
g45 = g45_0 * expg(kxi5,Pos(5));
Adinvg45 = Adj(g45\eye(4));
V5  = Adinvg45 * V4 + kxi5*Vel(5);
dV5 = kxi5*Acc(5) +  Adinvg45 * dV4 - ad(kxi5*Vel(5))*(Adinvg45*V4);
% dV5 = kxi5*Acc(5) + Adinvg45 * dV4;
% dV5(1:3) = dV5(1:3) + g45(1:3,1:3)'*cross(V4(4:6),cross(V4(4:6),g45(1:3,4)));
% dV5(4:6) = dV5(4:6) + g45(1:3,1:3)'*Vel(5)*cross(V4(4:6),g45(1:3,1:3)*kxi5(4:6));

%JntVel(5) = [0;0;0;0;1;0]'*(Adj(g01*g12*g23*g34*g45)*V5);
JntVel(25:30)=V5;
JntAcc(25:30)=dV5;

% Joint 6:
g56 = g56_0 * expg(kxi6,Pos(6));
Adinvg56 = Adj(g56\eye(4));
V6  = Adinvg56 * V5 + kxi6*Vel(6);
dV6 = kxi6*Acc(6) +  Adinvg56 * dV5 - ad(kxi6*Vel(6))*(Adinvg56*V5);
% dV6 = kxi6*Acc(6) + Adinvg56 * dV5;
% dV6(1:3) = dV6(1:3) + g56(1:3,1:3)'*cross(V5(4:6),cross(V5(4:6),g56(1:3,4)));
% dV6(4:6) = dV6(4:6) + g56(1:3,1:3)'*Vel(5)*cross(V5(4:6),g56(1:3,1:3)*kxi6(4:6));

%JntVel(6) = [0;0;0;1;0;0]'*(Adj(g01*g12*g23*g34*g45*g56)*V6);
JntVel(31:36)=V6;
JntAcc(31:36)=dV6;



%%%%%
% g6e =[eye(3),[0; 0;  154];0 0 0 1];
% g5e =[eye(3),[0; 0;  -113];0 0 0 1];
% g4e =[eye(3),[0; 0;  302.5];0 0 0 1];
% g3e =[eye(3),[0; 0;  227];0 0 0 1];
% g2e =[eye(3),[0; 0;  62];0 0 0 1];
% g1e =[eye(3),[0; 0;  1];0 0 0 1];


% %% Backward Recursion (inverse dynamic)
% Initial State
Tau=zeros(6,1);
F7 = Ft;
Adinvg67 = Adj(g67_0\eye(4));

% Joint 6
F6 = Adinvg67'* F7 + M6*dV6 - ad(V6)'*M6*V6;
Tau(6) = kxi6'* F6;
JntF(31:36)=F6;
%Tau(6) = kxi6'*(Adj(g6e)'* F6);

% Joint 5
F5 = Adinvg56'* F6 + M5*dV5 - ad(V5)'*M5*V5;
Tau(5) = kxi5'* F5;
JntF(25:30)=F5;
%Tau(5) = kxi5'* (Adj(g5e)'*F5);

% Joint 4
F4 = Adinvg45'* F5 + M4*dV4 - ad(V4)'*M4*V4;
Tau(4) = kxi4'* F4;
JntF(19:24)=F4;
%Tau(4) = kxi4'* (Adj(g4e)'*F4);


% Joint 3
F3 = Adinvg34'* F4 + M3*dV3 - ad(V3)'*M3*V3;
Tau(3) = kxi3'* F3;
JntF(13:18)=F3;
%Tau(3) = kxi3'* (Adj(g3e)'*F3);

% Joint 2
F2 = Adinvg23'* F3 + M2*dV2 - ad(V2)'*M2*V2;
Tau(2) = kxi2'* F2;
JntF(7:12)=F2;
%Tau(2) = kxi2'* (Adj(g2e)'*F2);

% Joint 1
F1 = Adinvg12'* F2 + M1*dV1 - ad(V1)'*M1*V1;
Tau(1) = kxi1'* F1;
JntF(1:6)=F1;
%Tau(1) = kxi1'* (Adj(g1e)'*F1);

Torque = Tau;
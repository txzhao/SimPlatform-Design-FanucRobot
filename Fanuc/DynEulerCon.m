%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DynEulerCon.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 05/5/2014
%
%@Function: DynEulerCon
%@Description: Implementing Newton-Euler Recursion Algorithm(Classic Type) for contorl purpose
%It also makes use of feedback information from encoder
%@Input:
%DH: DH parameters
%Ma: link mass
%Cen: link masss center
%Ie: link inertial
%Ft: generalized force exerted on endeffetor
%RefPos: joint angle frome trajectory generator
%RefVel: joint velocity from trajectory generator
%RefAcc: joint acceleration from trajectory generator
%EnPos: joint angle from encoder
%EnVel: joint velocity from encoder
%EnAcc: joint acceleration from encoder
%@Output:
%Tau: Torque
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function [Torque,JntVel,JntAcc,JntF]  = DynEulerCon(DH,Ma,Cen,Ie,Ft,RefPos,RefVel,RefAcc,EnPos,EnVel,EnAcc)

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

% %% calculate ri: ith link mass center offset relative to ith joint frame,i=1,2,3,4,5,6

g=g01_0;
r1 = g\[Cen(1:3);1];
r1 = r1(1:3);
g=g*g12_0;
r2 = g\[Cen(4:6);1];
r2 = r2(1:3);
g=g*g23_0;
r3 = g\[Cen(7:9);1];
r3 = r3(1:3);
g=g*g34_0;
r4 = g\[Cen(10:12);1];
r4 = r4(1:3);
g=g*g45_0;
r5 = g\[Cen(13:15);1];
r5 = r5(1:3);
g=g*g56_0;
r6 = g\[Cen(16:18);1];
r6 = r6(1:3);

% %% calculate momentt of inertia in Ci,i=1,2,3,4,5,6
m1  = Ma(1);
I1  = reshape(Ie(1:9),3,3);
M1  = [ m1*eye(3),      -m1*hat(r1);
        m1*hat(r1),    I1 - m1*hat(r1)*hat(r1)];

m2  = Ma(2);
I2  = reshape(Ie(10:18),3,3);
M2  = [ m2*eye(3),      -m2*hat(r2);
        m2*hat(r2),    I2 - m2*hat(r2)*hat(r2)];

m3  = Ma(3);
I3  = reshape(Ie(19:27),3,3);
M3  = [ m3*eye(3),      -m3*hat(r3);
        m3*hat(r3),    I3 - m3*hat(r3)*hat(r3)];
    
m4  = Ma(4);
I4  = reshape(Ie(28:36),3,3);
M4  = [ m4*eye(3),      -m4*hat(r4);
        m4*hat(r4),    I4 - m4*hat(r4)*hat(r4)];
    
m5  = Ma(5);
I5  = reshape(Ie(37:45),3,3);
M5  = [ m5*eye(3),      -m5*hat(r5);
        m5*hat(r5),    I5 - m5*hat(r5)*hat(r5)];
    
m6  = Ma(6);
I6  = reshape(Ie(46:54),3,3);
M6  = [ m6*eye(3),      -m6*hat(r6);
        m6*hat(r6),    I6 - m6*hat(r6)*hat(r6)];    

% %% Forward Recursion (kinematic)
% Initial State
V0 = [0;0;0;0;0;0];
dV0 = [0;0;9.8;0;0;0];

% Joint 1:
g01 = g01_0 * expg(kxi1,EnPos(1));
Adinvg01 = Adjoint(g01\eye(4));
V1  = Adinvg01 * V0 + kxi1*RefVel(1);
dV1 = kxi1*RefAcc(1) +  Adinvg01 * dV0 - ad(kxi1*EnVel(1))*(Adinvg01*V0);

JntVel(1:6)=V1;
JntAcc(1:6)=dV1;

% Joint 2:
g12 = g12_0 * expg(kxi2,EnPos(2));
Adinvg12 = Adjoint(g12\eye(4));
V2  = Adinvg12 * V1 + kxi2*RefVel(2);
dV2 = kxi2*RefAcc(2) +  Adinvg12 * dV1 - ad(kxi2*EnVel(2))*(Adinvg12*V1);

JntVel(7:12)=V2;
JntAcc(7:12)=dV2;

% Joint 3:
g23 = g23_0 * expg(kxi3,EnPos(3));
Adinvg23 = Adjoint(g23\eye(4));
V3  = Adinvg23 * V2 + kxi3*RefVel(3);
dV3 = kxi3*RefAcc(3) +  Adinvg23 * dV2 - ad(kxi3*EnVel(3))*(Adinvg23*V2);

JntVel(13:18)=V3;
JntAcc(13:18)=dV3;

% Joint 4:
g34 = g34_0 * expg(kxi4,EnPos(4));
Adinvg34 = Adjoint(g34\eye(4));
V4  = Adinvg34 * V3 + kxi4*RefVel(4);
dV4 = kxi4*RefAcc(4) +  Adinvg34 * dV3 - ad(kxi4*EnVel(4))*(Adinvg34*V3);

JntVel(19:24)=V4;
JntAcc(19:24)=dV4;

% Joint 5:
g45 = g45_0 * expg(kxi5,EnPos(5));
Adinvg45 = Adjoint(g45\eye(4));
V5  = Adinvg45 * V4 + kxi5*RefVel(5);
dV5 = kxi5*RefAcc(5) +  Adinvg45 * dV4 - ad(kxi5*EnVel(5))*(Adinvg45*V4);

JntVel(25:30)=V5;
JntAcc(25:30)=dV5;

% Joint 6:
g56 = g56_0 * expg(kxi6,EnPos(6));
Adinvg56 = Adjoint(g56\eye(4));
V6  = Adinvg56 * V5 + kxi6*RefVel(6);
dV6 = kxi6*RefAcc(6) +  Adinvg56 * dV5 - ad(kxi6*EnVel(6))*(Adinvg56*V5);

JntVel(31:36)=V6;
JntAcc(31:36)=dV6;

% %% Backward Recursion (inverse dynamic)
% Initial State
Tau=zeros(6,1);
F7 = Ft;
Adinvg67 = Adjoint(g67_0\eye(4));

% Joint 6
F6 = Adinvg67'* F7 + M6*dV6 - ad(V6)'*M6*V6;
Tau(6) = kxi6'* F6;
JntF(31:36)=F6;

% Joint 5
F5 = Adinvg56'* F6 + M5*dV5 - ad(V5)'*M5*V5;
Tau(5) = kxi5'* F5;
JntF(25:30)=F5;

% Joint 4
F4 = Adinvg45'* F5 + M4*dV4 - ad(V4)'*M4*V4;
Tau(4) = kxi4'* F4;
JntF(19:24)=F4;

% Joint 3
F3 = Adinvg34'* F4 + M3*dV3 - ad(V3)'*M3*V3;
Tau(3) = kxi3'* F3;
JntF(13:18)=F3;

% Joint 2
F2 = Adinvg23'* F3 + M2*dV2 - ad(V2)'*M2*V2;
Tau(2) = kxi2'* F2;
JntF(7:12)=F2;

% Joint 1
F1 = Adinvg12'* F2 + M1*dV1 - ad(V1)'*M1*V1;
Tau(1) = kxi1'* F1;
JntF(1:6)=F1;


Torque = Tau;

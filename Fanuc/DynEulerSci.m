%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DynEuler.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 12/8/2014
%
%@Function: DynEulerSci
%@Description: Implementing Newton-Euler Recursion Algorithm(Siciliano Type) to get computed torque 
%@Input:
%DH: DH parameters
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
function [Torque,JntVel,JntAcc,JntF] = DynEulerSci(DH,Ma,Cen,Ie,Ft,Pos,Vel,Acc)


Torque=[0;0;0;0;0;0];

% %% Calculate kxi in corresponding joint frame, different from in base frame
w_o = [0;0;0];
w_x = [1;0;0];
w_y = [0;1;0];
w_z = [0;0;1];
kxi = [w_o;w_z];


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
% g01_0= expg([eo;ez],DH(2,1))*expg([ez;eo],DH(1,1))*expg([eo;ex],DH(4,1))*expg([ex;eo],DH(3,1));
% g12_0= expg([eo;ez],DH(2,2))*expg([ez;eo],DH(1,2))*expg([eo;ex],DH(4,2))*expg([ex;eo],DH(3,2))*expg([ez;eo],0.062);
% g23_0= expg([eo;ez],DH(2,3))*expg([ez;eo],DH(1,3)+0.165)*expg([eo;ex],DH(4,3))*expg([ex;eo],DH(3,3));
% g34_0= expg([eo;ez],DH(2,4))*expg([ez;eo],DH(1,4)-0.227)*expg([eo;ex],DH(4,4))*expg([ex;eo],DH(3,4))*expg([ez;eo],0.3025);
% g45_0= expg([eo;ez],DH(2,5))*expg([ez;eo],DH(1,5)-0.3025)*expg([eo;ex],DH(4,5))*expg([ex;eo],DH(3,5))*expg([ez;eo],-0.113);
% g56_0= expg([eo;ez],DH(2,6))*expg([ez;eo],DH(1,6)+0.113)*expg([eo;ex],DH(4,6))*expg([ex;eo],DH(3,6))*expg([ez;eo],0.154);
% g67_0= expg([eo;ez],DH(2,7))*expg([ez;eo],DH(1,7))*expg([eo;ex],DH(4,7))*expg([ex;eo],DH(3,7))*expg([ez;eo],-0.154);


% %% calculate momentt of inertia in Ci,i=1,2,3,4,5,6
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
g=g*g67_0;
r6_ = g\[Cen(16:18);1];
r6_ = r6_(1:3);



% %% Forward Recursion (kinematic)
% Initial State
v0=[0;0;0];
w0=[0;0;0];
dv0=[0;0;0];
dw0=[0;0;0];

%%%%Joint 1
g01 = g01_0 * expg(kxi,Pos(1));
R01 = g01(1:3,1:3);
p01 = g01(1:3,4);
wz1 = R01*w_z;
w1 = R01'*(w0 + Vel(1)*wz1);
dw1 = R01'*(dw0 + Acc(1)*wz1 + Vel(1)*cross(w0,wz1));
v1 = R01*(v0 + cross(w0,p01));
dv1 = R01*(dv0 + cross(dw0,p01) + cross(w0,cross(w0,p01)));
dpc1 = dv1 + cross(dw1,r1) +  cross(w1,cross(w1,r1));

%%%%Joint 2
g12 = g12_0 * expg(kxi,Pos(2));
R12 = g12(1:3,1:3);
p12 = g12(1:3,4);
wz2 = R12*w_z;
w2 = R12'*(w1 + Vel(2)*wz2);
dw2 = R12'*(dw1 + Acc(2)*wz2 + Vel(2)*cross(w1,wz2));
v2 = R12'*(v1 + cross(w1,p12));
dv2 = R12'*(dv1 + cross(dw1,p12) + cross(w1,cross(w1,p12)));
dpc2 = dv2 + cross(dw2,r2) +  cross(w2,cross(w2,r2));

%%%%Joint 3
g23 = g23_0 * expg(kxi,Pos(3));
R23 = g23(1:3,1:3);
p23 = g23(1:3,4);
wz3 = R23*w_z;
w3 = R23'*(w2 + Vel(3)*wz3);
dw3 = R23'*(dw2 + Acc(3)*wz3 + Vel(3)*cross(w2,wz3));
v3 = R23'*(v2 + cross(w2,p23));
dv3 = R23'*(dv2 + cross(dw2,p23) + cross(w2,cross(w2,p23)));
dpc3 = dv3 + cross(dw3,r3) +  cross(w3,cross(w3,r3));


%%%%Joint 4
g34 = g34_0 * expg(kxi,Pos(4));
R34 = g34(1:3,1:3);
p34 = g34(1:3,4);
wz4 = R34*w_z;
w4 = R34'*(w3 + Vel(4)*wz4);
dw4 = R34'*(dw3 + Acc(4)*wz4 + Vel(4)*cross(w3,wz4));
v4 = R34'*(v3 + cross(w3,p34));
dv4 = R34'*(dv3 + cross(dw3,p34) + cross(w3,cross(w3,p34)));
dpc4 = dv4 + cross(dw4,r4) +  cross(w4,cross(w4,r4));

%%%%Joint 5
g45 = g45_0 * expg(kxi,Pos(5));
R45 = g45(1:3,1:3);
p45 = g45(1:3,4);
wz5 = R45*w_z;
w5 = R45'*(w4 + Vel(5)*wz5);
dw5 = R45'*(dw4 + Acc(5)*wz5 + Vel(5)*cross(w4,wz5));
v5 = R45'*(v4 + cross(w4,p45));
dv5 = R45'*(dv4 + cross(dw4,p45) + cross(w4,cross(w4,p45)));
dpc5 = dv5 + cross(dw5,r5) +  cross(w5,cross(w5,r5));

%%%%Joint 6
g56 = g56_0 * expg(kxi,Pos(6));
R56 = g56(1:3,1:3);
p56 = g56(1:3,4);
wz6 = R56*w_z;
w6 = R56'*(w5 + Vel(6)*wz6);
dw6 = R56'*(dw5 + Acc(6)*wz6 + Vel(6)*cross(w5,wz6));
v6 = R56'*(v5 + cross(w4,p56));
dv6 = R56'*(dv5 + cross(dw5,p56) + cross(w5,cross(w5,p56)));
dpc6 = dv6 + cross(dw6,r6) +  cross(w6,cross(w6,r6));


% %% Backward Recursion (inverse dynamic)
% Initial State
Tau=zeros(6,1);
f7 = Ft(1:3);
mu7 = Ft(4:6);

R67 = g67_0(1:3,1:3);


f6 = R67*f7 + m6*dpc6;
mu6 = R67*mu7 + R67*cross(f7,r6_) - cross(f6,r6) + I6*dw6 + cross(w6,I6*w6);
Tau(6)=mu6(3);

r5_ = g56\[r5;1];
r5_ = r5_(1:3);
f5 = R56*f6 + m5*dpc5;
mu5 = R56*mu6 + R56*cross(f6,r5_) - cross(f5,r5) + I5*dw5 + cross(w5,I5*w5);
Tau(5)=mu5(3);

r4_ = g45\[r4;1];
r4_ = r4_(1:3);
f4 = R45*f5 + m4*dpc4;
mu4 = R45*mu5 + R45*cross(f5,r4_) - cross(f4,r4) + I4*dw4 + cross(w4,I4*w4);
Tau(4)=mu4(3);

r3_ = g34\[r3;1];
r3_ = r3_(1:3);
f3 = R34*f4 + m3*dpc3;
mu3 = R34*mu4 + R34*cross(f4,r3_) - cross(f3,r3) + I3*dw3 + cross(w3,I3*w3);
Tau(3)=mu3(3);

r2_ = g23\[r2;1];
r2_ = r2_(1:3);
f2 = R23*f3 + m2*dpc2;
mu2 = R23*mu3 + R23*cross(f3,r2_) - cross(f2,r2) + I2*dw2 + cross(w2,I2*w2);
Tau(2)=mu2(3);

r1_ = g12\[r1;1];
r1_ = r1_(1:3);
f1 = R12*f2 + m1*dpc1;
mu1 = R12*mu2 + R12*cross(f2,r1_) - cross(f1,r1) + I1*dw1 + cross(w1,I1*w1);
Tau(1)=mu1(3);


%%%%%%
JntVel=[v1;w1;v2;w2;v3;w3;v4;w4;v5;w5;v6;w6];
JntAcc=[dv1;dw1;dv2;dw2;dv3;dw3;dv4;dw4;dv5;dw5;dv6;dw6];
JntF=[f1;mu1;f2;mu2;f3;mu3;f4;mu4;f5;mu5;f6;mu6];
Torque=Tau;






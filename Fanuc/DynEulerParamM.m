%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DynEulerParamM.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 30/5/2014
%
%@Function: DynEulerParamM
%@Description: Implementing Newton-Euler Closed-form Algorithm 
%considering effects due to motor inertia and rotation
%@Input:
%DH: DH parameters
%Ma: augment link mass (link + motor)
%Cen: augment link masss center (link + motor)
%Ie: augment link inertia (link + motor)
%Imz: motor inertia along rotating axis, Im =[Imx 0 0;0 Imy 0 0;0 0 Imz]
%Fv: viscous coefficients
%Fs: static coefficients
%k: reduction ratio
%Ft: generalized force exerted on endeffetor 
%Pos: joint angle
%Vel: joint velocity
%Acc: joint acceleration
%@Output:
%Tau: Torque

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Torque = DynEulerParamM(DH,Ma,Cen,Ie,Imz,Fv,Fs,k,Ft,Pos,Vel,Acc)

% %% Calculate kxi in corresponding joint frame, different from in base frame
w_o = [0;0;0];
w_z = [0;0;1];


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
    
RobotParam =[M1(1,1);M1(2,6);-M1(1,6);M1(1,5);M1(4,4);M1(5,5);M1(6,6);M1(4,5);M1(4,6);M1(5,6);
         M2(1,1);M2(2,6);-M2(1,6);M2(1,5);M2(4,4);M2(5,5);M2(6,6);M2(4,5);M2(4,6);M2(5,6);
         M3(1,1);M3(2,6);-M3(1,6);M3(1,5);M3(4,4);M3(5,5);M3(6,6);M3(4,5);M3(4,6);M3(5,6);
         M4(1,1);M4(2,6);-M4(1,6);M4(1,5);M4(4,4);M4(5,5);M4(6,6);M4(4,5);M4(4,6);M4(5,6);
         M5(1,1);M5(2,6);-M5(1,6);M5(1,5);M5(4,4);M5(5,5);M5(6,6);M5(4,5);M5(4,6);M5(5,6);
         M6(1,1);M6(2,6);-M6(1,6);M6(1,5);M6(4,4);M6(5,5);M6(6,6);M6(4,5);M6(4,6);M6(5,6)];
     
MotorParam =Imz;

     
Ld = [DH(1,1) DH(1,2) DH(3,2) DH(3,3) DH(1,4) DH(3,4) DH(1,5) DH(1,6)];
Pos = Pos';
Vel = Vel';
Acc = Acc';
Wd = EulerWd(Ld,Pos,Vel,Acc);
Wm = EulerWm(Ld,k,Pos,Vel,Acc);

Wfv =[Vel(1)    0       0       0       0       0;
      0         Vel(2)  0       0       0       0;
      0         0       Vel(3)  0       0       0;
      0         0       0       Vel(4)  0       0;
      0         0       0       0       Vel(5)  0;
      0         0       0       0       0       Vel(6)];
Wfs =[sign(Vel(1))  0               0               0               0               0;
      0             sign(Vel(2))    0               0               0               0;
      0             0               sign(Vel(3))    0               0               0;
      0             0               0               sign(Vel(4))    0               0;
      0             0               0               0               sign(Vel(5))    0;
      0             0               0               0               0               sign(Vel(6))]; 

Torque = Wd*RobotParam + Wm*MotorParam + Wfv*Fv + Wfs * Fs;





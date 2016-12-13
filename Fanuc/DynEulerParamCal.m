%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DynEulerParamCal.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 05/5/2014
%
%@Function: DynEulerParamCal
%@Description: Implementing Newton-Euler Closed-form Algorithm
%Instead of accurate Ma,Cen,Ie, it only need equivalent dynmaic parameters set which may obtained from
%standard identification process.
%@Input:
%DH: DH parameters
%Ma: link mass
%Cen: link masss center
%Ie: link inertial
%Pos: joint angle
%Vel: joint velocity
%Acc: joint acceleration
%@Output:
%Tau: Torque
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Torque = DynEulerParamCal(DH,Param,Ft,Pos,Vel,Acc)

% %% Calculate initial configuration matrix g_{i-1,i}
% 0: means base frame;
% 1,2,3,4,5,6: means i-th joint frame, Ci
% 7: means endeffector frame
% DH=[266     300     0       0       1016     0      174;
%     0       0       -pi/2   0       pi      pi       0;
%     0       150     870     170     0       0        0;
%     0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;];

Ld = [DH(1,1) DH(1,2) DH(3,2) DH(3,3) DH(1,4) DH(3,4) DH(1,5) DH(1,6)];
Pos = Pos';
Vel = Vel';
Acc = Acc';
Wd = EulerWd(Ld,Pos,Vel,Acc);

Torque = Wd*Param;
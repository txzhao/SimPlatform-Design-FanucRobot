%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DH2Twist_Yas.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 07/1/2014
%
%@Function: DH2Twist_YasGen
%@Description: Convert DH parameters to twists in general case
%@Input:
%DH: DH parameters
%g_st: end tool frame transformation matrix to robot base frame
%@Output:
%Ksi: twists
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Ksi = DH2Twist_S6(DH,g_st)
o = [0;0;0;1];
z = [0;0;1;0];
x = [1;0;0;0];
y = [0;1;0;0];
ez = [0;0;1];
ex = [1;0;0];
eo = [0;0;0];

g01= expg([eo;ez],DH(2,1))*expg([ez;eo],DH(1,1))*expg([eo;ex],DH(4,1))*expg([ex;eo],DH(3,1));
z1 = g01*z;   %relative to base frame
o1 = g01*o;   %relative to base frame
x1 = g01*x;   %relative to base frame
w1 = z1(1:3,1);
q1 = o1(1:3,1);
Ksi(:,1)=[-cross(w1,q1);w1];


g12=expg([eo;ez],DH(2,2))*expg([ez;eo],DH(1,2))*expg([eo;ex],DH(4,2))*expg([ex;eo],DH(3,2));
g02=g01*g12;
z2 = g02*z;   %relative to base frame
o2 = g02*o;   %relative to base frame
x2 = g02*x;   %relative to base frame
w2 = z2(1:3,1);
q2 = o2(1:3,1);
Ksi(:,2)=[-cross(w2,q2);w2];


g23=expg([eo;ez],DH(2,3))*expg([ez;eo],DH(1,3))*expg([eo;ex],DH(4,3))*expg([ex;eo],DH(3,3));
g03=g02*g23;
z3 = g03*z;   %relative to base frame
o3 = g03*o;   %relative to base frame
x3 = g03*x;   %relative to base frame
w3 = z3(1:3,1);
q3 = o3(1:3,1);
Ksi(:,3)=[-cross(w3,q3);w3];


g34=expg([eo;ez],DH(2,4))*expg([ez;eo],DH(1,4))*expg([eo;ex],DH(4,4))*expg([ex;eo],DH(3,4));
g04=g03*g34;
z4 = g04*z;   %relative to base frame
o4 = g04*o;   %relative to base frame
x4 = g04*x;   %relative to base frame
w4 = z4(1:3,1);
q4 = o4(1:3,1);
Ksi(:,4)=[-cross(w4,q4);w4];


g45=expg([eo;ez],DH(2,5))*expg([ez;eo],DH(1,5))*expg([eo;ex],DH(4,5))*expg([ex;eo],DH(3,5));
g05=g04*g45;
z5 = g05*z;   %relative to base frame
o5 = g05*o;   %relative to base frame
x5 = g05*x;   %relative to base frame
w5 = z5(1:3,1);
q5 = o5(1:3,1);
Ksi(:,5)=[-cross(w5,q5);w5];


g56=expg([eo;ez],DH(2,6))*expg([ez;eo],DH(1,6))*expg([eo;ex],DH(4,6))*expg([ex;eo],DH(3,6));
g06=g05*g56;
z6 = g06*z;   %relative to base frame
o6 = g06*o;   %relative to base frame
x6 = g06*x;   %relative to base frame
w6 = z6(1:3,1);
q6 = o6(1:3,1);
Ksi(:,6)=[-cross(w6,q6);w6];

Ksi(1:3,7)=g_st(1:3,4);
Ksi(4:6,7)=0;

Ksi(abs(Ksi)<0.0000001)=0;






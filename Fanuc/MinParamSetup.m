%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: MinParamSetup.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 13/02/2015
%
%@Description: Get Symbolic Expression for minimum inertial parameters based on Largrange Equation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc;

% syms Ld1 Ld2 Ld3 Ld4 Ld5 Ld6 Ld7 Ld8
% syms pos1 pos2 pos3 pos4 pos5 pos6 
% syms vel1 vel2 vel3 vel4 vel5 vel6
% syms gr
% 
% DH=[0       0       pos1       Ld1;
%     -pi/2   Ld2     pos2       0;
%     0       Ld3     pos3       0;
%     -pi/2   Ld4     pos4       Ld5;
%     pi/2    0       pos5       0;
%     -pi/2   0       pos6       0]';
% 
% ez = [0;0;1];
% ex = [1;0;0];
% eo = [0;0;0];
% g01= simplify(expWre([ex;eo],DH(2,1))*expWre([eo;ex],DH(1,1))*expWre([ez;eo],DH(4,1))*expWre([eo;ez],DH(3,1)));
% g12= simplify(expWre([ex;eo],DH(2,2))*expWre([eo;ex],DH(1,2))*expWre([ez;eo],DH(4,2))*expWre([eo;ez],DH(3,2)));
% g23= simplify(expWre([ex;eo],DH(2,3))*expWre([eo;ex],DH(1,3))*expWre([ez;eo],DH(4,3))*expWre([eo;ez],DH(3,3)));
% g34= simplify(expWre([ex;eo],DH(2,4))*expWre([eo;ex],DH(1,4))*expWre([ez;eo],DH(4,4))*expWre([eo;ez],DH(3,4)));
% g45= simplify(expWre([ex;eo],DH(2,5))*expWre([eo;ex],DH(1,5))*expWre([ez;eo],DH(4,5))*expWre([eo;ez],DH(3,5)));
% g56= simplify(expWre([ex;eo],DH(2,6))*expWre([eo;ex],DH(1,6))*expWre([ez;eo],DH(4,6))*expWre([eo;ez],DH(3,6)));
% 
% g=[0;0;gr];
% 
% kxi = [0;0;0;0;0;1];
% Z0=[0;0;1];
% 
% %%%%%%%%%%%Potential Energy%%%%%%%%%%%%%
% DU0 = [0;0;gr;0];
% 
% DU(:,1) = g01.'*DU0;
% DU(:,2) = g12.'*DU(:,1);
% DU(:,3) = g23.'*DU(:,2);
% DU(:,4) = g34.'*DU(:,3);
% DU(:,5) = g45.'*DU(:,4);
% DU(:,6) = g56.'*DU(:,5);
% 
% O6=zeros(6,6);
% sDU=[O6;DU];
% 
% disp('sDU--Finished!');
% %%%%%%%%%%%Kinetic Engergy: Recursive Omega and Velocity%%%%%%%%%%
% w0=[0;0;0];
% v0=[0;0;0];
% A10=g01(1:3,1:3).';
% p01=g01(1:3,4);
% 
% w(:,1)=A10*w0 + Z0*vel1;
% v(:,1)=A10*v0 + A10*(cross(w0,p01));
% A21=g12(1:3,1:3).';
% p12=g12(1:3,4);
% 
% w(:,2)=A21*w(:,1) + Z0*vel2;
% v(:,2)=A21*v(:,1) + A21*(cross(w(:,1),p12));
% A32=g23(1:3,1:3).';
% p23=g23(1:3,4);
% 
% w(:,3)=A32*w(:,2) + Z0*vel3;
% v(:,3)=A32*v(:,2) + A32*(cross(w(:,2),p23));
% A43=g34(1:3,1:3).';
% p34=g34(1:3,4);
% 
% w(:,4)=A43*w(:,3) + Z0*vel4;
% v(:,4)=A43*v(:,3) + A43*(cross(w(:,3),p34));
% A54=g45(1:3,1:3).';
% p45=g45(1:3,4);
% 
% w(:,5)=A54*w(:,4) + Z0*vel5;
% v(:,5)=A54*v(:,4) + A54*(cross(w(:,4),p45));
% A65=g56(1:3,1:3).';
% p56=g56(1:3,4);
% 
% w(:,6)=A65*w(:,5) + Z0*vel6;
% v(:,6)=A65*v(:,5) + A65*(cross(w(:,5),p56));
% 
% for j=1:6
%     DE(1,j)=1/2*w(1,j)*w(1,j);
%     DE(2,j)=w(1,j)*w(2,j);
%     DE(3,j)=w(1,j)*w(3,j);
%     DE(4,j)=1/2*w(2,j)*w(2,j);
%     DE(5,j)=w(2,j)*w(3,j);
%     DE(6,j)=1/2*w(3,j)*w(3,j);
%     DE(7,j)=w(3,j)*v(2,j)-w(2,j)*v(3,j);
%     DE(8,j)=w(1,j)*v(3,j)-w(3,j)*v(1,j);
%     DE(9,j)=w(2,j)*v(1,j)-w(1,j)*v(2,j);
%     DE(10,j)=1/2*v(:,j).'*v(:,j);
% end
% 
% disp('sDE--Finished!');

%%
% %%%%%%%%%%Recursive Equation Derivation%%%%%%%%%
% syms alpha a theta d dtheta
% syms w1 w2 w3
% syms v1 v2 v3
% 
% ez = [0;0;1];
% ex = [1;0;0];
% eo = [0;0;0];
% T=simplify(expWre([ex;eo],a)*expWre([eo;ex],alpha)*expWre([ez;eo],d)*expWre([eo;ez],theta));
% 
% 
% sw =T(1:3,1:3).'*[w1;w2;w3]+ ez*dtheta;
% sv = T(1:3,1:3).'*( [v1;v2;v3] + cross([w1;w2;w3], T(1:3,4)));
% 
% sDE(1,1)=1/2*sw(1)*sw(1);
% sDE(2,1)=sw(1)*sw(2);
% sDE(3,1)=sw(1)*sw(3);
% sDE(4,1)=1/2*sw(2)*sw(2);
% sDE(5,1)=sw(2)*sw(3);
% sDE(6,1)=1/2*sw(3)*sw(3);
% sDE(7,1)=sw(3)*sv(2)-sw(2)*sv(3);
% sDE(8,1)=sw(1)*sv(3)-sw(3)*sv(1);
% sDE(9,1)=sw(2)*sv(1)-sw(1)*sv(2);
% sDE(10,1)=1/2*(sv.'*sv);

%%%%%%%%%%%%%%%%%%%For 6R Manipulator%%%%%%%%%%%%%%
syms l1 l2 l3 l4 l5
syms m1 mx1 my1 mz1 XX1 YY1 ZZ1 XY1 XZ1 YZ1
syms m2 mx2 my2 mz2 XX2 YY2 ZZ2 XY2 XZ2 YZ2
syms m3 mx3 my3 mz3 XX3 YY3 ZZ3 XY3 XZ3 YZ3
syms m4 mx4 my4 mz4 XX4 YY4 ZZ4 XY4 XZ4 YZ4
syms m5 mx5 my5 mz5 XX5 YY5 ZZ5 XY5 XZ5 YZ5
syms m6 mx6 my6 mz6 XX6 YY6 ZZ6 XY6 XZ6 YZ6

p1=[m1 mx1 my1 mz1 XX1 YY1 ZZ1 XY1 XZ1 YZ1].';
p2=[m2 mx2 my2 mz2 XX2 YY2 ZZ2 XY2 XZ2 YZ2].';
p3=[m3 mx3 my3 mz3 XX3 YY3 ZZ3 XY3 XZ3 YZ3].';
p4=[m4 mx4 my4 mz4 XX4 YY4 ZZ4 XY4 XZ4 YZ4].';
p5=[m5 mx5 my5 mz5 XX5 YY5 ZZ5 XY5 XZ5 YZ5].';
p6=[m6 mx6 my6 mz6 XX6 YY6 ZZ6 XY6 XZ6 YZ6].';

Pa=[p1;p2;p3;p4;p5;p6];

B=sym(zeros(36,60));
%%%%%%%Joint 6%%%%%%%%%%%
B(30,52)=1;

B(31,53)=1;

B(32,55)=1; 
B(32,56)=-1;

B(33:36,57:60)=eye(4);

%%%%%%%Joint 5%%%%%%%%%%%
B(23,42)=1;

B(24,43)=1;
B(24,54)=1;

B(25,45)=1;
B(25,46)=-1;
B(25,56)=1;

B(26,47)=1;
B(26,56)=1;

B(27:29,48:50)=eye(3);

%%%%%%%Joint 4%%%%%%%%%%%
B(16,32)=1;

B(17,33)=1;
B(17,44)=-1;

B(18,35)=1;
B(18,36)=-1;
B(18,46)=1;

B(19,37)=1;
B(19,46)=1;

B(20:22,38:40)=eye(3);

%%%%%%%Joint 3%%%%%%%%%%%
B(9,22)=1;
B(9,31)=l4;
B(9,41)=l4;
B(9,51)=l4;

B(10,23)=1;
B(10,34)=1;
B(10,31)=l5;
B(10,41)=l5;
B(10,51)=l5;

B(11,25)=1;
B(11,26)=-1;
B(11,34)=2*l5;
B(11,36)=1;

B(12,27)=1;
B(12,34)=2*l5;
B(12,36)=1;
B(12,31)=l4^2+l5^2;
B(12,41)=l4^2+l5^2;
B(12,51)=l4^2+l5^2;

B(13,28)=1;
B(13,34)=-l4;
B(13,31)=-l4*l5;
B(13,41)=-l4*l5;
B(13,51)=-l4*l5;

B(14:15,29:30)=eye(2);

%%%%%%%Joint 2%%%%%%%%%%%
B(2,12)=1;
B(2,21)=l3;
B(2,31)=l3;
B(2,41)=l3;
B(2,51)=l3;

B(3,13)=1;

B(4,15)=1;
B(4,16)=-1;
B(4,21)=-l3^2;
B(4,31)=-l3^2;
B(4,41)=-l3^2;
B(4,51)=-l3^2;

B(5,17)=1;
B(5,21)=l3^2;
B(5,31)=l3^2;
B(5,41)=l3^2;
B(5,51)=l3^2;

B(6,18)=1;

B(7,19)=1;
B(7,24)=-l3;

B(8,20)=1;

%%%%%%%Joint 1%%%%%%%%%%%
B(1,7)=1;
B(1,16)=1;
B(1,26)=1;
B(1,21)=l2^2+l3^2;
B(1,31)=l2^2+l3^2+l4^2;
B(1,41)=l2^2+l3^2+l4^2;
B(1,51)=l2^2+l3^2+l4^2;
Ld=[l1 l2 l3 l4 l5];

% %matlabFunction(B,'file','EulerBasis','vars',{Ld});
iBBt=inv(B*B.');
matlabFunction(iBBt,'file','EuleriBBt','vars',{Ld});
% 
% rP=B*Pa;

% %%%%%%%%%%%%%%%%%%%For 6R Manipulator: Only Considering First 3 Joints%%%%%%%%%%%%%%
% syms l1 l2 l3
% syms m1 mx1 my1 mz1 XX1 YY1 ZZ1 XY1 XZ1 YZ1
% syms m2 mx2 my2 mz2 XX2 YY2 ZZ2 XY2 XZ2 YZ2
% syms m3 mx3 my3 mz3 XX3 YY3 ZZ3 XY3 XZ3 YZ3
% 
% p1=[m1 mx1 my1 mz1 XX1 YY1 ZZ1 XY1 XZ1 YZ1].';
% p2=[m2 mx2 my2 mz2 XX2 YY2 ZZ2 XY2 XZ2 YZ2].';
% p3=[m3 mx3 my3 mz3 XX3 YY3 ZZ3 XY3 XZ3 YZ3].';  %%%For this case, p3 represents augmented link consisting of Link3,4,5,6
% 
% Pa=[p1;p2;p3];
% 
% B=sym(zeros(15,30));
% 
% %%%%%%%%%%%For Joint 3
% B(9,22)=1;
% B(10,23)=1;
% B(11,25)=1;B(11,26)=-1;
% B(12,27)=1;
% B(13,28)=1;
% B(14,29)=1;
% B(15,30)=1;
% 
% %%%%%%%%%For Joint 2
% B(2,12)=1;B(2,21)=l3;
% B(3,13)=1;
% B(4,15)=1;B(4,26)=-1;B(4,21)=-l3^2;
% B(5,17)=1;B(5,21)=l3^2;
% B(6,18)=1;
% B(7,19)=1;B(7,24)=-l3;
% B(8,20)=1;
% 
% %%%%%%%%%For Joint 1
% B(1,7)=1;B(1,16)=1;B(1,26)=1;B(1,11)=l2^2;B(1,21)=l2^2+l3^2;
% 
% 
% Ld=[l1 l2 l3];
% matlabFunction(B,'file','EulerBasis_F3','vars',{Ld});
% 
% rP=B*Pa;


% %%%%%%%%%%%
% B=sym(zeros(10,60));
% %%%%%%%Joint 6%%%%%%%%%%%
% B(9,52)=1;
% B(10,53)=1;
% %%%%%%%Joint 5%%%%%%%%%%%
% B(7,42)=1;
% 
% B(8,43)=1;
% B(8,54)=1;
% %%%%%%%Joint 4%%%%%%%%%%%
% B(5,32)=1;
% 
% B(6,33)=1;
% B(6,44)=-1;
% %%%%%%%Joint 3%%%%%%%%%%%
% B(3,22)=1;
% B(3,31)=l4;
% B(3,41)=l4;
% B(3,51)=l4;
% 
% B(4,23)=1;
% B(4,34)=1;
% B(4,31)=l5;
% B(4,41)=l5;
% B(4,51)=l5;
% 
% %%%%%%%Joint 2%%%%%%%%%%%
% B(1,12)=1;
% B(1,21)=l3;
% B(1,31)=l3;
% B(1,41)=l3;
% B(1,51)=l3;
% 
% B(2,13)=1;
% 
% 
% Ld=[l1 l2 l3 l4 l5];
% %matlabFunction(B,'file','EulerBasis','vars',{Ld});
% srP=B*Pa;
% %%
% matlabFunction(B,'file','EulerBasis_Static','vars',{Ld});
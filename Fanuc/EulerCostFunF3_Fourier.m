%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerCostFunF3_Fourier.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 28/02/2015
%
%@Function: EulerCostFun_Fourier
%@Description: Cost function for finding optimal trajectory, d-optimality, only considering first 3
%joints
%@Input:
%X: [a01,a11,b11,a21,b21...a03,a13,b13...]
%@Output:
%Cost: cost
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Cost=EulerCostFunF3_Fourier(X)

%var = diag([50 50 20 1 0.5 1]);
%var = diag([100 50 20 1 0.5 1]);
%var = diag([100 200 80 8 12 8]);
%Var = [100 200 80 8 12 8];
Var = [100 200 80 8 12 8];
%Var = [1 1 1 1 1 1];

iStd = eye(3)/(diag(Var(1:3)));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
JntNum=3;

Wf = 0.2*pi;
fs = 20;
N = 2*pi/Wf*fs+1;
Nx=size(X,1);
Nj=Nx/JntNum;
Nh=(Nx/JntNum-1)/2;
t = linspace(0,2*pi/Wf,N);


Pos = zeros(N,JntNum);
Vel = zeros(N,JntNum);
Acc = zeros(N,JntNum);
Mx=[1 1 1 1 1 1];
for i=1:N
    for j=1:JntNum
        Pos(i,j) = X(1+(j-1)*Nj);
        Vel(i,j) = 0;
        Acc(i,j) = 0;
        for k=1:Nh
            a=X(2+(k-1)*2+(j-1)*Nj);
            b=X(3+(k-1)*2+(j-1)*Nj);
            Pos(i,j) = Pos(i,j) + a*sin(Mx(j)*k*Wf*t(i)) + b*cos(Mx(j)*k*Wf*t(i));
            Vel(i,j) = Vel(i,j) + a*Mx(j)*k*Wf*cos(Mx(j)*k*Wf*t(i)) - b*Mx(j)*k*Wf*sin(Mx(j)*k*Wf*t(i));
            Acc(i,j) = Acc(i,j) - a*(Mx(j)*k*Wf)^2*sin(Mx(j)*k*Wf*t(i)) - b*(Mx(j)*k*Wf)^2*cos(Mx(j)*k*Wf*t(i));
        end
           
    end
   
end

%Ld=[566 150 870 170 1016]/1000;  %%%%%For Fanuc
Ld=[504 170 780]/1000; %%%%%%For Efort
gr=9.8;

%Wd_N = zeros(6*N,60);

for i=1:N
    Wd_N((i-1)*3+1:3*i,1:30) = iStd*EulerWd_MinF3(Ld,Pos(i,:),Vel(i,:),Acc(i,:),gr);
    Wfv =[Vel(i,1)    0       0      ;
      0         Vel(i,2)  0       ;
      0         0       Vel(i,3)  ];

    %%%%%%Method 1: classic coulomb 
    Wfc =[sign(Vel(i,1))  0               0           ;
      0             sign(Vel(i,2))    0               ;
      0             0               sign(Vel(i,3))    ;]; 
%     %%%%%%%Method 2: modified coulomb
%      Wfc =[nthroot(Vel(i,1),3)    0       0       ;
%       0         nthroot(Vel(i,2),3)  0       ;
%       0         0       nthroot(Vel(i,3),3)  ;];
  
   Wd_N(3*(i-1)+1:3*i,31:33) = iStd*Wfv;
   Wd_N(3*(i-1)+1:3*i,34:36) = iStd*Wfc;
end
Bd=EulerBasis_F3(Ld);
Basis=[Bd               zeros(15,6);
       zeros(6,30)     eye(6)];

%Basis=Bd;

Wd_=Wd_N*Basis'/(Basis*Basis');

% F = Wd_'*Wd_;
% detF = det(F);
% Cost = -log(detF);
Cost=cond(Wd_);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EfDynIdnActDataF3.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 12/03/2014
%
%@Description: To do dynamic parameters identification for Efort Manipulator,only considering first 3
%joints
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;


IniEnc =[109824;-2846557;-2698244;19752;-4211310;-6879];    %To ensure the same for different sampling

I2T = [0.73;0.73;0.5;0.4;0.4;0.39];
Gear = [-147;-153;153;-76.95;-80;-51];
IniJnt=[0;-pi/2;0;0;pi/2;0];
EncRes = 32768*4;
D2R = pi/180;
R2D = 180/pi;


% %%%%%%%%%%Efort Data sampled in  2015/03/06, dOptimality Optimized Trajectory%%%%%%%%%%%%%%%
% File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva1.txt';
% File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva2.txt';
% File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva3.txt';
% SmpT = 31.25*180*1e-6;                                      %Need to update for different sampling

% %%%%%%%%Efort Data sampled in  2015/03/06, Condition Number Optimized Trajectory%%%%%%%%%%%%%%%
% File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva1.txt';
% File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva2.txt';
% File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva3.txt';
% SmpT = 31.25*180*1e-6;                                      %Need to update for different sampling
%%%%%%%%%%Efort Data sampled in  2015/03/06, dOptimality Optimized Trajectory%%%%%%%%%%%%%%%
File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Fst3\IdnTrjF3_1.txt';
File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Fst3\IdnTrjF3_2.txt';
File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Fst3\IdnTrjF3_3.txt';
SmpT = 31.25*180*1e-6;                                      %Need to update for different sampling


%%%%%%%%%Efort Parameters%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%
    DH=[0       0       0       504;
        -pi/2   170     -pi/2    0;
        0       780     0       0;
        -pi/2   140    0       760;
        pi/2    0       0       0;
        -pi/2   0       0       0;
        0       0       0       125]';

Ld=[504 170 780]/1000;
Bd=EulerBasis_F3(Ld);
gr=9.8;

%%%%%%%%%%Data Processing%%%%%%%%%%%
[TrqIdn,JntIdn,VelIdn,AccIdn,Var]=EfMeanVarCal(File,IniEnc,I2T,Gear,EncRes,IniJnt,SmpT,3);

iStd=eye(3)/(diag(Var(1:3)));
Std=(diag(Var(1:3)));
% iStd=eye(3);
% Std=eye(3);
%%
%%%%%%%%%Identification%%%%%%%%%%%%%
Num=size(TrqIdn,1);


for i=1:Num
   
    Trq_a(3*(i-1)+1:3*i,1) =  iStd*TrqIdn(i,1:3)';
    Wd = EulerWd_MinF3(Ld,JntIdn(i,1:3),VelIdn(i,1:3),AccIdn(i,1:3),gr);
    Wd_N(3*(i-1)+1:3*i,1:30) = iStd*Wd;
     
    Wfv =[VelIdn(i,1)       0               0       ;
            0               VelIdn(i,2)     0       ;
            0               0           VelIdn(i,3)  ;];

%     %%%%%Method 1: classic coulomb 
%     Wfc =[sign(VelIdn(i,1))  0               0              ;
%       0             sign(VelIdn(i,2))    0               ;
%       0             0               sign(VelIdn(i,3))    ;]; 
    %%%%%Method 2: modified coulomb
     Wfc =[nthroot(VelIdn(i,1),3)    0       0       ;
      0         nthroot(VelIdn(i,2),3)  0       ;
      0         0       nthroot(VelIdn(i,3),3)  ];
  
   Wd_N(3*(i-1)+1:3*i,31:33) = iStd*Wfv;
   Wd_N(3*(i-1)+1:3*i,34:36) = iStd*Wfc;
   
end

%%%%%%%%%%%To add friction coefficients%%%%%%%%%%%
Basis=[Bd               zeros(15,6);
       zeros(6,30)     eye(6)];
   
Wd_B=Wd_N*Basis'/(Basis*Basis');
%IdnParam=pcg(Wd_B'*Wd_B,Wd_B'*Trq_a,1e-8,500);
IdnParam=pinv(Wd_B)*Trq_a;

rParam_c=IdnParam(1:15);
fParam_c=IdnParam(16:end);


%%
%%%%%%%%%%To display identification error%%%%%%%%%%%
for i=1:Num
    Trq_c(3*(i-1)+1:3*i,1)=Std*Wd_B(3*(i-1)+1:3*i,:)*IdnParam;
    Fri_c(3*(i-1)+1:3*i,1)=Std*Wd_B(3*(i-1)+1:3*i,16:end)*IdnParam(16:end);
    Dyn_c(3*(i-1)+1:3*i,1)=Std*Wd_B(3*(i-1)+1:3*i,1:15)*IdnParam(1:15);
end

[Q,R,E] = qr(Wd_N);
Tau = 6*Num*(2.2204e-16)*R(1,1);
Rnk = size(find(diag(R)>Tau),1);
Q1 = Q(:,1:Rnk);
R1 = R(1:Rnk,1:Rnk);

W1 = Q1*R1;
S = svd(W1);
MaxS = max(S);
MinS = min(S);
CndNum = MaxS/MinS;
str=sprintf('Rank: %d     Condition Number: %f',Rnk, CndNum);
disp(str);




%%
%%%%%%%%%%To plot actual and computed torque%%%%%%%%
for i=1:3
    figure(i);
    plot([0:1:Num-1]*SmpT, TrqIdn(:,i),'b');
    hold on;
    plot([0:1:Num-1]*SmpT, Trq_c(i:3:end),'r');
    hold off;
    grid on;
    str=sprintf('Torque of Joint %d',i);
    title(str);
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %%
% %%%%%%%%%%To plot friction%%%%%%%
% for i=1:6
%     figure(i+6);
%     plot(VelIdn(:,i), Fri_c(i:6:end),'r');
%     hold on;
%     plot(VelIdn(:,i),Fri_n(i:6:end),'b');
%     hold off;
%     grid on;
%     str=sprintf('Friction of Joint %d',i);
%     title(str);
% end


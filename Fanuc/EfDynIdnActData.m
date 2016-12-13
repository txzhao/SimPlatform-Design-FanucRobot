%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EfDynIdnActData.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 09/03/2014
%
%@Description: To do dynamic parameters identification for Efort Manipulator
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;


IniEnc =[109824;-2846557;-2698244;19752;-4211310;-6879];    %To ensure the same for different sampling
SmpT = 31.25*180*1e-6;                                      %Need to update for different sampling
I2T = [0.73;0.73;0.5;0.4;0.4;0.39];
Gear = [-147;-153;153;-76.95;-80;-51];
IniJnt=[0;-pi/2;0;0;pi/2;0];
EncRes = 32768*4;
D2R = pi/180;
R2D = 180/pi;
JntNum=6;


% %%%%%%%%%%Efort Data sampled in  2015/03/06, dOptimality Optimized Trajectory%%%%%%%%%%%%%%%
% File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva1.txt';
% File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva2.txt';
% File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva3.txt';
% File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva4.txt';
% File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva5.txt';
% File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva6.txt';


% %%%%%%%%Efort Data sampled in  2015/03/06, Condition Number Optimized Trajectory%%%%%%%%%%%%%%%
% File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva1.txt';
% File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva2.txt';
% File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva3.txt';
% File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva4.txt';
% File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva5.txt';
% File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva6.txt';


% %%%%%%%%Efort Data sampled in  2015/03/17, Condition Number Optimized Trajectory£¬ Including Linear Friction%%%%%%%%%%%%%%%
% File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf1.txt';
% File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf2.txt';
% File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf3.txt';
% File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf4.txt';
% File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf5.txt';
% File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf6.txt';

%%%%%%%%Efort Data sampled in  2015/03/18, Condition Number Optimized Trajectory,Multiple Recursion%%%%%%%%%%%%%%%
File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_1.txt';
File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_2.txt';
File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_3.txt';
File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_4.txt';
File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_5.txt';
File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_6.txt';


%%%%%%%%%Efort Parameters%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%
    DH=[0       0       0       504;
        -pi/2   170     -pi/2    0;
        0       780     0       0;
        -pi/2   140    0       760;
        pi/2    0       0       0;
        -pi/2   0       0       0;
        0       0       0       125]';
DH(2,:) = DH(2,:)/1000;
DH(4,:) = DH(4,:)/1000;
Ld=[504 170 780 140 760]/1000;
Bd=EulerBasis(Ld);
[Param_n,rParam_n]=EfDynCAD();
gr=9.8;

%%%%%%%%%%Data Processing%%%%%%%%%%%
[TrqIdn,JntIdn,VelIdn,AccIdn,Var]=EfMeanVarCal(File,IniEnc,I2T,Gear,EncRes,IniJnt,SmpT,JntNum);
%Var = [100 50 25 1 0.5 1];
%Var = [100 200 1 0.1 1 1];
iStd=eye(6)/(diag(Var));
Std=(diag(Var));
% iStd=eye(6);
% Std=eye(6);
%%
%%%%%%%%%Identification%%%%%%%%%%%%%
Num=size(TrqIdn,1);
Ft =[0;0;0;0;0;0];


for i=1:Num-30
   
    Trq_a(6*(i-1)+1:6*i,1) =  iStd*TrqIdn(i,:)';
    Wd = EulerWd_Min(Ld,JntIdn(i,:),VelIdn(i,:),AccIdn(i,:),gr);
    Wd_N(6*(i-1)+1:6*i,1:60) = iStd*Wd;
     
    Wfv =[VelIdn(i,1)    0       0       0       0       0;
      0         VelIdn(i,2)  0       0       0       0;
      0         0       VelIdn(i,3)  0       0       0;
      0         0       0       VelIdn(i,4)  0       0;
      0         0       0       0       VelIdn(i,5)  0;
      0         0       0       0       0       VelIdn(i,6)];

    %%%%%%Method 1: classic coulomb 
    Wfc =[sign(VelIdn(i,1))  0               0               0               0               0;
      0             sign(VelIdn(i,2))    0               0               0               0;
      0             0               sign(VelIdn(i,3))    0               0               0;
      0             0               0               sign(VelIdn(i,4))    0               0;
      0             0               0               0               sign(VelIdn(i,5))    0;
      0             0               0               0               0               sign(VelIdn(i,6))]; 
%     %%%%%%%Method 2: modified coulomb
%      Wfc =[nthroot(VelIdn(i,1),3)    0       0       0       0       0;
%       0         nthroot(VelIdn(i,2),3)  0       0       0       0;
%       0         0       nthroot(VelIdn(i,3),3)  0       0       0;
%       0         0       0       nthroot(VelIdn(i,4),3)  0       0;
%       0         0       0       0       nthroot(VelIdn(i,5),3)  0;
%       0         0       0       0       0       nthroot(VelIdn(i,6),3)];

  
   Wd_N(6*(i-1)+1:6*i,61:66) = iStd*Wfv;
   Wd_N(6*(i-1)+1:6*i,67:72) = iStd*Wfc;
  
   
end
%%
%%%%%%%%%%%To add friction coefficients%%%%%%%%%%%
Basis=[Bd               zeros(36,12);
       zeros(12,60)     eye(12)];

   
Wd_B=Wd_N*Basis'/(Basis*Basis');
%IdnParam=pcg(Wd_B'*Wd_B,Wd_B'*Trq_a,1e-8,500);
IdnParam=pinv(Wd_B)*Trq_a;

rParam_c=IdnParam(1:36);
fParam_c=IdnParam(37:end);

rParam_=[rParam_n rParam_c];

%%
%%%%%%%%%%To display identification error%%%%%%%%%%%
for i=1:Num-30
    Trq_c(6*(i-1)+1:6*i,1)=Std*Wd_B(6*(i-1)+1:6*i,:)*IdnParam;
    Fri_c(6*(i-1)+1:6*i,1)=Std*Wd_B(6*(i-1)+1:6*i,37:end)*IdnParam(37:end);
    Dyn_c(6*(i-1)+1:6*i,1)=Std*Wd_B(6*(i-1)+1:6*i,1:36)*IdnParam(1:36);
    %Dyn_n(6*(i-1)+1:6*i,1)=Std*Wd_B(6*(i-1)+1:6*i,1:36)*rParam_n;
%     Dyn_n(6*(i-1)+1:6*i,1)=Std*Wd_N(6*(i-1)+1:6*i,1:60)*Param_n;
%     Fri_n(6*(i-1)+1:6*i,1)=TrqIdn(i,:)'-Dyn_n(6*(i-1)+1:6*i,1);
end

% [Q,R,E] = qr(Wd_N);
% Tau = 6*Num*(2.2204e-16)*R(1,1);
% Rnk = size(find(diag(R)>Tau),1);
% Q1 = Q(:,1:Rnk);
% R1 = R(1:Rnk,1:Rnk);
% 
% W1 = Q1*R1;
% S = svd(W1);
% MaxS = max(S);
% MinS = min(S);
% CndNum = MaxS/MinS;
% str=sprintf('Rank: %d     Condition Number: %f',Rnk, CndNum);
% disp(str);


% ErrIdn_c = abs(Trq_a - Trq_c);
% 
% ErrIdn_c1 = ErrIdn_c(1:6:end);
% ErrIdn_c2 = ErrIdn_c(2:6:end);
% ErrIdn_c3 = ErrIdn_c(3:6:end);
% ErrIdn_c4 = ErrIdn_c(4:6:end);
% ErrIdn_c5 = ErrIdn_c(5:6:end);
% ErrIdn_c6 = ErrIdn_c(6:6:end);
% for i=1:6
%     MaxTrqIdn(i) = max(abs(TrqIdn(:,i)));
% end
% 
% 
% disp('   AbsMax   |   AbsMean  |  RltMax   |   RltMean');
% disp([max(ErrIdn_c1),mean(ErrIdn_c1),max(ErrIdn_c1)/MaxTrqIdn(1),mean(ErrIdn_c1)/MaxTrqIdn(1)]);
% disp([max(ErrIdn_c2),mean(ErrIdn_c2),max(ErrIdn_c2)/MaxTrqIdn(2),mean(ErrIdn_c2)/MaxTrqIdn(2)]);
% disp([max(ErrIdn_c3),mean(ErrIdn_c3),max(ErrIdn_c3)/MaxTrqIdn(3),mean(ErrIdn_c3)/MaxTrqIdn(3)]);
% disp([max(ErrIdn_c4),mean(ErrIdn_c4),max(ErrIdn_c4)/MaxTrqIdn(4),mean(ErrIdn_c4)/MaxTrqIdn(4)]);
% disp([max(ErrIdn_c5),mean(ErrIdn_c5),max(ErrIdn_c5)/MaxTrqIdn(5),mean(ErrIdn_c5)/MaxTrqIdn(5)]);
% disp([max(ErrIdn_c6),mean(ErrIdn_c6),max(ErrIdn_c6)/MaxTrqIdn(6),mean(ErrIdn_c6)/MaxTrqIdn(6)]);

%%
%%%%%%%%%%To plot actual and computed torque%%%%%%%%
for i=1:6
    figure(i);
    plot([0:1:Num-1-30]*SmpT, TrqIdn(1:end-30,i),'b');
    hold on;
    plot([0:1:Num-1-30]*SmpT, Trq_c(i:6:end),'r');
    hold off;
    grid on;
    str=sprintf('Torque of Joint %d',i);
    title(str);
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% % %%
% %%%%%%%%%%To plot friction%%%%%%%
% for i=1:6
%     figure(i+6);
%     plot(VelIdn(:,i), Fri_c(i:6:end),'r');
% %     hold on;
% %     plot(VelIdn(:,i),Fri_n(i:6:end),'b');
%     hold off;
%     grid on;
%     str=sprintf('Friction of Joint %d',i);
%     title(str);
% end

% %%
% %%%%%%%%%To plot pure dynamic torque%%%%%%%
% for i=1:6
%     figure(i+12);
% %     plot([0:1:Num-1]*SmpT, Trq_a(i:6:end),'b');
% %     hold on;
%     plot([0:1:Num-1]*SmpT, Dyn_n(i:6:end),'y');
%     hold on;
%     plot([0:1:Num-1]*SmpT, Dyn_c(i:6:end),'r');
%     grid on;
%     hold off;
%     str=sprintf('Pure Dynamic Torque of Joint %d',i);
%     title(str);
% end
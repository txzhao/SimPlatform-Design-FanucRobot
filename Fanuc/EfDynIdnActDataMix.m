%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EfDynIdnActDataMix.m
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
VelThre = [0.15,0.15,0.15,0.15,0.09,0.09];
Delta=[0.33 0.33 0.33 0.33 0.33 0.33];
Fv=[0 0 0 7.4757 16.134 8.839];
Fc=[0 0 0 11.1901 24.7273 22.8751];

%%%%%%%%%%Efort Data sampled in  2015/03/06, dOptimality Optimized Trajectory%%%%%%%%%%%%%%%
File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva1.txt';
File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva2.txt';
File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva3.txt';
File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva4.txt';
File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva5.txt';
File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_dOpt_Zva\IdnTrj_dOpt_Zva6.txt';


% %%%%%%%%Efort Data sampled in  2015/03/06, Condition Number Optimized Trajectory%%%%%%%%%%%%%%%
% File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva1.txt';
% File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva2.txt';
% File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva3.txt';
% File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva4.txt';
% File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva5.txt';
% File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj_Cnd_Zva\IdnTrj_Cnd_Zva6.txt';


% %%%%%%%%Efort Data sampled in  2015/03/17, Condition Number Optimized Trajectory£¨ Including Linear Friction%%%%%%%%%%%%%%%
% File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf1.txt';
% File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf2.txt';
% File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf3.txt';
% File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf4.txt';
% File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf5.txt';
% File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Idn_Trj_CndLf\IdnTrj_CndLf6.txt';



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


%%%%%%%%%%%%%%%%%%%%%For File 1 %%%%%%%%%%%%%%%%
%%%%%%%%%%Data Processing%%%%%%%%%%%
[TrqIdn1,JntIdn1,VelIdn1,AccIdn1,Var1]=EfMeanVarCal(File,IniEnc,I2T,Gear,EncRes,IniJnt,SmpT,JntNum);
iStd1=eye(6)/(diag(Var1));
Std1=(diag(Var1));
% iStd1=eye(6);
% Std1=eye(6);

%%
%%%%%%%%%Identification%%%%%%%%%%%%%
Num1=size(TrqIdn1,1);
Ft =[0;0;0;0;0;0];


for i=1:Num1
   
    Trq1_a(6*(i-1)+1:6*i,1) =  iStd1*TrqIdn1(i,:)';
    Wd = EulerWd_Min(Ld,JntIdn1(i,:),VelIdn1(i,:),AccIdn1(i,:),gr);
    Wd(find(abs(Wd)<1e-12))=0;
    Wd1_N(6*(i-1)+1:6*i,1:60) = iStd1*Wd;
     
    Wfv =[VelIdn1(i,1)    0       0       0       0       0;
      0         VelIdn1(i,2)  0       0       0       0;
      0         0       VelIdn1(i,3)  0       0       0;
      0         0       0       VelIdn1(i,4)  0       0;
      0         0       0       0       VelIdn1(i,5)  0;
      0         0       0       0       0       VelIdn1(i,6)];

    %%%%%%Method 1: classic coulomb 
    Wfc =[sign(VelIdn1(i,1))  0               0               0               0               0;
      0             sign(VelIdn1(i,2))    0               0               0               0;
      0             0               sign(VelIdn1(i,3))    0               0               0;
      0             0               0               sign(VelIdn1(i,4))    0               0;
      0             0               0               0               sign(VelIdn1(i,5))    0;
      0             0               0               0               0               sign(VelIdn1(i,6))]; 
%     %%%%%%%Method 2: modified coulomb
%      Wfc =[nthroot(VelIdn1(i,1),3)    0       0       0       0       0;
%       0         nthroot(VelIdn1(i,2),3) 0       0       0       0;
%       0         0       nthroot(VelIdn1(i,3),3)  0       0       0;
%       0         0       0       nthroot(VelIdn1(i,4),3)  0       0;
%       0         0       0       0       nthroot(VelIdn1(i,5),3)  0;
%       0         0       0       0       0       nthroot(VelIdn1(i,6),3)];

  
   Wd1_N(6*(i-1)+1:6*i,61:66) = iStd1*Wfv;
   Wd1_N(6*(i-1)+1:6*i,67:72) = iStd1*Wfc;
    
%    %%%%%%Method 3: nolinear friction
%     Wfv =[VelIdn1(i,1)    0       0       0       0       0;
%       0         VelIdn1(i,2)  0       0       0       0;
%       0         0       VelIdn1(i,3)  0       0       0;
%       0         0       0       VelIdn1(i,4)  0       0;
%       0         0       0       0       VelIdn1(i,5)  0;
%       0         0       0       0       0       VelIdn1(i,6)];
% 
%  
%     Wfc =[sign(VelIdn1(i,1))  0               0               0               0               0;
%       0             sign(VelIdn1(i,2))    0               0               0               0;
%       0             0               sign(VelIdn1(i,3))    0               0               0;
%       0             0               0               sign(VelIdn1(i,4))    0               0;
%       0             0               0               0               sign(VelIdn1(i,5))    0;
%       0             0               0               0               0               sign(VelIdn1(i,6))]; 
%    Wfn =[sign(VelIdn1(i,1))*exp(-abs(VelIdn1(i,1)/VelThre(1))^Delta(1))  0               0               0               0               0;
%       0             sign(VelIdn1(i,2))*exp(-abs(VelIdn1(i,2)/VelThre(2))^Delta(2))    0               0               0               0;
%       0             0               sign(VelIdn1(i,3))*exp(-abs(VelIdn1(i,3)/VelThre(3))^Delta(3))    0               0               0;
%       0             0               0               sign(VelIdn1(i,4))*exp(-abs(VelIdn1(i,4)/VelThre(4))^Delta(4))    0               0;
%       0             0               0               0               sign(VelIdn1(i,5))*exp(-abs(VelIdn1(i,5)/VelThre(5))^Delta(5))    0;
%       0             0               0               0               0               sign(VelIdn1(i,6))*exp(-abs(VelIdn1(i,6)/VelThre(6))^Delta(6))]; 
% 
%    Wd1_N(6*(i-1)+1:6*i,61:66) = iStd1*Wfv;
%    Wd1_N(6*(i-1)+1:6*i,67:72) = iStd1*Wfc;    
%    Wd1_N(6*(i-1)+1:6*i,73:78) = iStd1*Wfn;    

%     %%%%%%%%%%%Method 4: only consider first 3 joints, last 3 joints are known
%     Wfv =[VelIdn1(i,1)    0       0   ;
%       0         VelIdn1(i,2)  0       ;
%       0         0       VelIdn1(i,3)  ;];
%  
% 
%     %%%%%%Method 1: classic coulomb 
%     Wfc =[sign(VelIdn1(i,1))  0               0               ;
%       0             sign(VelIdn1(i,2))    0               ;
%       0             0               sign(VelIdn1(i,3))    ]; 
%   
%    Z3=zeros(3);
%    Wd1_N(6*(i-1)+1:6*i,61:63) = [iStd1(1:3,1:3)*Wfv;Z3];
%    Wd1_N(6*(i-1)+1:6*i,64:66) = [iStd1(1:3,1:3)*Wfc;Z3];  
%    
%    Trq1_a(6*(i-1)+4,1) = Trq1_a(6*(i-1)+4,1) - (iStd1(4,4)*( Fv(4)*VelIdn1(i,4) + sign(VelIdn1(i,4))*Fc(4) ));
%    Trq1_a(6*(i-1)+5,1) = Trq1_a(6*(i-1)+5,1) - (iStd1(5,5)*( Fv(5)*VelIdn1(i,5) + sign(VelIdn1(i,5))*Fc(5) ));
%    Trq1_a(6*(i-1)+6,1) = Trq1_a(6*(i-1)+6,1) - (iStd1(6,6)*( Fv(6)*VelIdn1(i,6) + sign(VelIdn1(i,6))*Fc(6) ));
end

%%%%%%%%%%%To add friction coefficients%%%%%%%%%%%
Basis=[Bd               zeros(36,12);
       zeros(12,60)     eye(12)];
% Basis=[Bd               zeros(36,6);
%        zeros(6,60)     eye(6)];
   
Wd1_B=Wd1_N*Basis'/(Basis*Basis');
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%For File 2%%%%%%%%%%%%%%%%%%
%%%%%%%%Efort Data sampled in  2015/03/18, Condition Number Optimized Trajectory,Multiple Recursion%%%%%%%%%%%%%%%
File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_1.txt';
File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_2.txt';
File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_3.txt';
File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_4.txt';
File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_5.txt';
File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\IdnTrj0318\IdnTrj0318_6.txt';


%%%%%%%%%%Data Processing%%%%%%%%%%%
[TrqIdn2,JntIdn2,VelIdn2,AccIdn2,Var2]=EfMeanVarCal(File,IniEnc,I2T,Gear,EncRes,IniJnt,SmpT,JntNum);
iStd2=eye(6)/(diag(Var2));
Std2=(diag(Var2));


%%%%%%%%%Identification%%%%%%%%%%%%%
Num2=size(TrqIdn2,1);
Ft =[0;0;0;0;0;0];


for i=1:Num2
   
    Trq2_a(6*(i-1)+1:6*i,1) =  iStd2*TrqIdn2(i,:)';
    Wd = EulerWd_Min(Ld,JntIdn2(i,:),VelIdn2(i,:),AccIdn2(i,:),gr);
    Wd(find(abs(Wd)<1e-12))=0;
    Wd2_N(6*(i-1)+1:6*i,1:60) = iStd2*Wd;
     
    Wfv =[VelIdn2(i,1)    0       0       0       0       0;
      0         VelIdn2(i,2)  0       0       0       0;
      0         0       VelIdn2(i,3)  0       0       0;
      0         0       0       VelIdn2(i,4)  0       0;
      0         0       0       0       VelIdn2(i,5)  0;
      0         0       0       0       0       VelIdn2(i,6)];

    %%%%%%Method 1: classic coulomb 
    Wfc =[sign(VelIdn2(i,1))  0               0               0               0               0;
      0             sign(VelIdn2(i,2))    0               0               0               0;
      0             0               sign(VelIdn2(i,3))    0               0               0;
      0             0               0               sign(VelIdn2(i,4))    0               0;
      0             0               0               0               sign(VelIdn2(i,5))    0;
      0             0               0               0               0               sign(VelIdn2(i,6))]; 
%     %%%%%%%Method 2: modified coulomb
%      Wfc =[nthroot(VelIdn2(i,1),3)    0       0       0       0       0;
%       0         nthroot(VelIdn2(i,2),3) 0       0       0       0;
%       0         0       nthroot(VelIdn2(i,3),3)  0       0       0;
%       0         0       0       nthroot(VelIdn2(i,4),3) 0       0;
%       0         0       0       0       nthroot(VelIdn2(i,5),3)  0;
%       0         0       0       0       0       nthroot(VelIdn2(i,6),3)];


   Wd2_N(6*(i-1)+1:6*i,61:66) = iStd2*Wfv;
   Wd2_N(6*(i-1)+1:6*i,67:72) = iStd2*Wfc;
    
%  %%%%%%Method 3: nolinear friction
%     Wfv =[VelIdn2(i,1)    0       0       0       0       0;
%       0         VelIdn2(i,2)  0       0       0       0;
%       0         0       VelIdn2(i,3)  0       0       0;
%       0         0       0       VelIdn2(i,4)  0       0;
%       0         0       0       0       VelIdn2(i,5)  0;
%       0         0       0       0       0       VelIdn2(i,6)];
% 
%  
%     Wfc =[sign(VelIdn2(i,1))  0               0               0               0               0;
%       0             sign(VelIdn2(i,2))    0               0               0               0;
%       0             0               sign(VelIdn2(i,3))    0               0               0;
%       0             0               0               sign(VelIdn2(i,4))    0               0;
%       0             0               0               0               sign(VelIdn2(i,5))    0;
%       0             0               0               0               0               sign(VelIdn2(i,6))]; 
%    Wfn =[sign(VelIdn2(i,1))*exp(-abs(VelIdn2(i,1)/VelThre(1))^Delta(1))  0               0               0               0               0;
%       0             sign(VelIdn2(i,2))*exp(-abs(VelIdn2(i,2)/VelThre(2))^Delta(2))    0               0               0               0;
%       0             0               sign(VelIdn2(i,3))*exp(-abs(VelIdn2(i,3)/VelThre(3))^Delta(3))    0               0               0;
%       0             0               0               sign(VelIdn2(i,4))*exp(-abs(VelIdn2(i,4)/VelThre(4))^Delta(4))    0               0;
%       0             0               0               0               sign(VelIdn2(i,5))*exp(-abs(VelIdn2(i,5)/VelThre(5))^Delta(5))    0;
%       0             0               0               0               0               sign(VelIdn2(i,6))*exp(-abs(VelIdn2(i,6)/VelThre(6))^Delta(6))]; 
% 
%    Wd2_N(6*(i-1)+1:6*i,61:66) = iStd2*Wfv;
%    Wd2_N(6*(i-1)+1:6*i,67:72) = iStd2*Wfc;    
%    Wd2_N(6*(i-1)+1:6*i,73:78) = iStd2*Wfn;        

%     %%%%%%%%%%%Method 4: only consider first 3 joints, last 3 joints are known
%     Wfv =[VelIdn2(i,1)    0       0   ;
%       0         VelIdn2(i,2)  0       ;
%       0         0       VelIdn2(i,3)  ;];
%  
% 
%     %%%%%%Method 1: classic coulomb 
%     Wfc =[sign(VelIdn2(i,1))  0               0               ;
%       0             sign(VelIdn2(i,2))    0               ;
%       0             0               sign(VelIdn2(i,3))    ]; 
%   
%    Z3=zeros(3);
%    Wd2_N(6*(i-1)+1:6*i,61:63) = [iStd2(1:3,1:3)*Wfv;Z3];
%    Wd2_N(6*(i-1)+1:6*i,64:66) = [iStd2(1:3,1:3)*Wfc;Z3];  
%    
%    Trq2_a(6*(i-1)+4,1) = Trq2_a(6*(i-1)+4,1) - (iStd2(4,4)*(Fv(4)*VelIdn2(i,4) + sign(VelIdn2(i,4))*Fc(4) ));
%    Trq2_a(6*(i-1)+5,1) = Trq2_a(6*(i-1)+5,1) - (iStd2(5,5)*(Fv(5)*VelIdn2(i,5) + sign(VelIdn2(i,5))*Fc(5) ));
%    Trq2_a(6*(i-1)+6,1) = Trq2_a(6*(i-1)+6,1) - (iStd2(6,6)*(Fv(6)*VelIdn2(i,6) + sign(VelIdn2(i,6))*Fc(6) ));
end

Wd2_B=Wd2_N*Basis'/(Basis*Basis');

Trq_a=[Trq1_a;Trq2_a];
Wd_B=[Wd1_B;Wd2_B];

%%
IdnParam=pinv(Wd_B)*Trq_a;

rParam_c=IdnParam(1:36);
fParam_c=IdnParam(37:end);

rParam_=[rParam_n rParam_c];

%%
%%%%%%%%%%To display identification error%%%%%%%%%%%
for i=1:Num1
    Trq1_c(6*(i-1)+1:6*i,1)=Std1*Wd1_B(6*(i-1)+1:6*i,:)*IdnParam;
    Trq2_c(6*(i-1)+1:6*i,1)=Std2*Wd2_B(6*(i-1)+1:6*i,:)*IdnParam;
    
%    Trq1_c(6*(i-1)+4,1) = Trq1_c(6*(i-1)+4,1) + ((Fv(4)*VelIdn1(i,4) + sign(VelIdn1(i,4))*Fc(4) ));
%    Trq1_c(6*(i-1)+5,1) = Trq1_c(6*(i-1)+5,1) + ((Fv(4)*VelIdn1(i,5) + sign(VelIdn1(i,5))*Fc(5) ));
%    Trq1_c(6*(i-1)+6,1) = Trq1_c(6*(i-1)+6,1) + ((Fv(4)*VelIdn1(i,6) + sign(VelIdn1(i,6))*Fc(6) ));
%    
%    Trq2_c(6*(i-1)+4,1) = Trq2_c(6*(i-1)+4,1) + ((Fv(4)*VelIdn2(i,4) + sign(VelIdn2(i,4))*Fc(4) ));
%    Trq2_c(6*(i-1)+5,1) = Trq2_c(6*(i-1)+5,1) + ((Fv(5)*VelIdn2(i,5) + sign(VelIdn2(i,5))*Fc(5) ));
%    Trq2_c(6*(i-1)+6,1) = Trq2_c(6*(i-1)+6,1) + ((Fv(6)*VelIdn2(i,6) + sign(VelIdn2(i,6))*Fc(6) ));
end

[Q,R,E] = qr(Wd_B);
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
for i=1:6
    TrqMax1(i)=max(abs(TrqIdn1(:,i)));
    JntMax1(i)=max(abs(JntIdn1(:,i)));
    VelMax1(i)=max(abs(VelIdn1(:,i)));
    AccMax1(i)=max(abs(AccIdn1(:,i)));
end

%%%%%%%%%%To plot actual and computed torque%%%%%%%%
for i=1:6
    figure(i);
    plot([0:1:Num1-1]*SmpT, TrqIdn1(1:end,i),'b');
    hold on;
    plot([0:1:Num1-1]*SmpT, Trq1_c(i:6:end),'r');
    hold on;
%     plot([0:1:Num1-1]*SmpT, JntIdn1(:,i)/JntMax1(i)*TrqMax1(i),'g');
%     hold on;
%     plot([0:1:Num1-1]*SmpT, VelIdn1(:,i)/VelMax1(i)*TrqMax1(i),'y');
%     hold on;
%     plot([0:1:Num1-1]*SmpT, AccIdn1(:,i)/AccMax1(i)*TrqMax1(i),'k');
    hold off;
    grid on;
    str=sprintf('Torque of Joint %d',i);
    title(str);
end

%%
for i=1:6
    TrqMax2(i)=max(abs(TrqIdn2(:,i)));
    JntMax2(i)=max(abs(JntIdn2(:,i)));
    VelMax2(i)=max(abs(VelIdn2(:,i)));
    AccMax2(i)=max(abs(AccIdn2(:,i)));
end

for i=1:6
    figure(i+6);
    plot([0:1:Num2-1]*SmpT, TrqIdn2(1:end,i),'b');
    hold on;
    plot([0:1:Num2-1]*SmpT, Trq2_c(i:6:end),'r');
    hold on;
%     plot([0:1:Num2-1]*SmpT, JntIdn2(:,i)/JntMax2(i)*TrqMax2(i),'g');
%     hold on;
%     plot([0:1:Num2-1]*SmpT, VelIdn2(:,i)/VelMax2(i)*TrqMax2(i),'y');
%     hold on;
%     plot([0:1:Num2-1]*SmpT, AccIdn2(:,i)/AccMax2(i)*TrqMax2(i),'k');
    hold off;
    grid on;
    str=sprintf('Torque of Joint %d',i);
    title(str);
end



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: StaticDyn.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 19/03/2014
%
%@Description: To verify static dynamic
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;
I2T = [0.73;0.73;0.5;0.4;0.4;0.39];
Gear = [-147;-153;153;-76.95;-80;-51];

% for Num=1:50
%     for Nj=1:6
%         xlsFile=sprintf('C:\\Users\\DAI Dan\\Desktop\\Learn\\Dynamic Control\\New Page\\Experiment\\20150306\\StaticDynamic\\%d-%d.csv',Nj,Num);
%         sheet=sprintf('%d-%d',Nj,Num);
%         Data=xlsRead(xlsFile,sheet)';
%         Cur(Nj+(Num-1)*6,:)=Data(3,5:end);
%         %Trq(Num,Nj)=mean(Cur)*I2T(Nj)*Gear(Nj);
%     end
% end

% sctCur=load('StaticCur.mat');
% Cur=sctCur.Cur;
% d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.05,0.1,1,75);
% Hd = design(d,'equiripple');
% 
% Nj=0;
% for i=1:300
%     if Nj==6
%         Nj=1;
%     else
%         Nj=Nj+1;
%     end
%     sCur(i,:)=filtfilt(Hd.Numerator,1,Cur(i,:));
%     sTrq(i)=mean(sCur(i,:))*I2T(Nj)*Gear(Nj);
% end
% 
% sTrq=reshape(sTrq,6,50);
% sTrq=sTrq';

sctTrq=load('StaticSTrq.mat');
Trq=sctTrq.sTrq;
for i=1:6
    var(i)=max(Trq(:,i))-min(Trq(:,i));
end
iStd=diag(1./var);
Std=diag(var);

sctParam=load('EfIdnCndNmlLfMix1.mat');
Param=sctParam.IdnParam;

JntFile='D:\Learn\Project_Matlab\Fanuc\StaticDynJnt.txt';
Jnt=importdata(JntFile);
Jnt=Jnt/180*pi;
Jnt(:,2)=Jnt(:,2)-pi/2;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
DH=[0       0       0       504;
    -pi/2   170     -pi/2    0;
    0       780     0       0;
    -pi/2   140    0       760;
    pi/2    0       0       0;
    -pi/2   0       0       0;
    0       0       0       125]';
Ld=[504 170 780 140 760]/1000;
gr=9.8;

Z6=[0 0 0 0 0 0];
Zm6=zeros(6);

%%%%%%%%%%%%%%%%%%%Identification%%%%%%%%%%%%%%%%
iNum=30;
for i=1:iNum
    iTrq_a(6*(i-1)+1:6*i,1) =iStd*Trq(i,:)';
    
    iWd =EulerWd_Min(Ld,Jnt(i,:),Z6,Z6,gr);
    iWd_N(6*(i-1)+1:6*i,1:60) = iStd*iWd;
end

Bd=EulerBasis_Static(Ld);
Basis=Bd;
   
iWd_B=iWd_N*Basis'/(Basis*Basis');
sP=pinv(iWd_B)*iTrq_a;
%%
%%%%%%%%Verification%%%%%%%%
vNum=20;
for i=1:vNum
    vTrq_a(6*(i-1)+1:6*i,1) =Trq(i+iNum,:)';
    
    vWd =EulerWd_Min(Ld,Jnt(i+iNum,:),Z6,Z6,gr);
    vWd_N(6*(i-1)+1:6*i,1:60) = iStd*vWd;
end
vWd_B=vWd_N*Basis'/(Basis*Basis');
for i=1:vNum
    vTrq_c(6*(i-1)+1:6*i,1)=Std*vWd_B(6*(i-1)+1:6*i,:)*sP;
end
vErr=vTrq_a-vTrq_c;
vErr=reshape(vErr,6,20)';
mvErr=mean(vErr,1);

%%

Num=50;
for i=1:Num
    Trq_a(6*(i-1)+1:6*i,1) =Trq(i,:)';
    
    Wd =EulerWd_Min(Ld,Jnt(i,:),Z6,Z6,gr);
    Wd_N(6*(i-1)+1:6*i,1:60) = Wd;
end
Bd=EulerBasis(Ld);
Basis=Bd;
   
Wd_B=Wd_N*Basis'/(Basis*Basis');
Trq_c=Wd_B*Param(1:36);

Err=Trq_a-Trq_c;
Err=reshape(Err,6,50)';
mErr=mean(Err,1);


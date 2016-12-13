%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: DataProcessing.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 03/03/2015
%
%@Function: DataProcessing
%@Description: 
%1. Current Zero-phase filter
%2. Vel/Acc computation based on feedbacked position
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear;
clc;

DriveFile = 'C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\Dynamic Debug\ActualData\20140613\DriveData.txt';

IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
SmpT = 31.25*65*1e-6;  % f=500Hz
I2T = [0.77;0.77;0.524;0.375;0.375;0.375];
K = [-145.7;140;-173.5;104.7;-100;-51.5];
EncRes = 32768*4;

RawData = importdata(DriveFile);
Nd =size(RawData,1);
Num=4;
%%
%d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.1,0.2,1,90);
%Hd = design(d,'cheby2');
d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.1,0.15,1,70);
Hd = design(d,'equiripple');
for i=1:6
    St(:,i) = RawData(:,Num*i-3)*1e-3;
    Trq(:,i)= RawData(:,Num*i-2)*I2T(i)*K(i);
    Vel(:,i)= RawData(:,Num*i-1)*2*pi/60/K(i);
    Pos(:,i)= (RawData(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi; 
    
    zfTrq(:,i)=filtfilt(Hd.Numerator,1,Trq(:,i));
    %fTrq(:,i)=filter(Hd,Trq(:,i));
    %sTrq(:,i)=smooth(Trq(:,i));
    
    sPos(:,i)=smooth(Pos(:,i));    
    
%     figure(i);
%     plot(St(:,i),Trq(:,i),'k');
%     hold on;
%     plot(St(:,i),zfTrq(:,i),'r');
%     hold off;
%     grid on;
end

%%
%%%%%%%%%%%%%%Velocity and Acc Computation Based on Frequency Method%%%%%%%%
Pos(end,:)=[];
Vel(end,:)=[];
fs=1/SmpT;
fftPos(:,1)=fft(Pos(:,1));
Ns=size(Pos(:,1),1);
fftPos(100:end-100,1)=0;
Ks=[0:Ns/2-1,0,-Ns/2+1:-1]';
jw=2j*pi*Ks*fs/Ns;
fftsVel(:,1)=jw.*fftPos(:,1);
fftsAcc(:,1)=-Ks.^2.*fftPos(:,1);
sVel(:,1)=ifft(fftsVel(:,1));
sAcc(:,1)=ifft(fftsAcc(:,1));
figure(1);
plot(St(1:end-1,1),Vel(:,1),'b');
hold on;
plot(St(1:end-1,1),sVel(:,1),'r');
hold off;
grid on;

figure(2);
plot(St(1:end-1,1),sAcc(:,1),'r');
grid on;
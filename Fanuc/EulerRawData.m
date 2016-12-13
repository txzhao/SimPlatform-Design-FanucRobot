%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerRawData.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 11/6/2014
%
%@Description:Raw Data Processing
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;
% %%
% %Planning data, pos,vel,acc,motor vel, motor acc, planned encoder value, feedback encoder value
% ConData = importdata('C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\ControllerData.txt');
% 
% % PosCmd = ConData(:,1:6);
% % VelCmd = ConData(:,7:12);
% % AccCmd = ConData(:,13:18);
% % MVelCmd = ConData(:,19:24);
% % MAccCmd = ConData(:,25:30);
% % EncCmd = ConData(:,31:36);
% % EncFbk = ConData(:,37:42);
% VelCmd = ConData(:,1:6);
% AccCmd = ConData(:,7:12);
% MVelCmd = ConData(:,13:18);
% MAccCmd = ConData(:,19:24);
% Nc = size(ConData,1);
% 
% 
% t=[0:1:Nc-1];
% plot(t,VelCmd(:,6));
% grid on;
% % for i=1:6
% %     figure(i);
% %     plot(t,VelCmd(:,i));
% %     grid on;
% % end
% %%
% % T1 V1 I1 P1 Acc1 T2 V2 I2 P2 Acc2...T6 V6 I6 P6 Acc6
% % T: sample time stamp
% % V: motor velocity,unit rpm
% % I: motor current for torque, unit A
% % P: position feedback via encoder, unit counts
% % Acc: numerical derivative of V
% 
% % RawData(:,1:Num) = importdata('C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140611\Axis1.txt');
% % RawData(:,Num+1:2*Num) = importdata('C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140611\Axis2.txt');
% % RawData(:,2*Num+1:3*Num) = importdata('C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140611\Axis3.txt');
% % RawData(:,3*Num+1:4*Num) = importdata('C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140611\Axis4.txt');
% % RawData(:,4*Num+1:5*Num) = importdata('C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140611\Axis5.txt');
% % RawData(:,5*Num+1:6*Num) = importdata('C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140611\Axis6.txt');
% RawData = importdata( 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\JA2.txt');
% Num=4;
% 
% Nd =size(RawData,1);
% td = [0:1:Nd-1];
% I2T = [0.77;0.77;0.524;0.375;0.375;0.375];
% R = [-145.7;140;-173.5;104.7;-100;-51.5];
% EncRes = 32768*4;
% IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
% SmpT = 31.25*65*1e-6;
% for i=1:6
%     St(:,i) = RawData(:,Num*i-3)*1e-3;
%     %Trq(:,i)=RawData(:,Num*i-2)*I2T(i)*R(i);
%     Trq(:,i)=RawData(:,Num*i-2);
%     STrq(:,i)=smooth(Trq(:,i));
%     Vel(:,i)=RawData(:,Num*i-1)*360/60/R(i);
%     Pos(:,i)=(RawData(:,Num*i)-IniEnc(i))/EncRes/R(i)*360; 
% %     Acc(:,i)=RawData(:,Num*i)/pi*180*sign(R(i));
% %     SAcc(:,i)=smooth(Acc(:,i));
%     SVel(:,i)=smooth(Vel(:,i));
% end
% for i=1:Nd-1
%     MyAcc(i+1,:) = (SVel(i+1,:) - SVel(i,:))./(St(i+1,:)-St(i,:));
%     MyVel(i+1,:) = (Pos(i+1,:) - Pos(i,:))./(St(i+1,:)-St(i,:));
% end
% MyAcc(1,:)=0;
% MyVel(1,:)=0;
% for i=1:6
%     MySAcc(:,i) = smooth(MyAcc(:,i));
%     MySVel(:,i) = smooth(MyVel(:,i));
% end
% 
% 
% %%
% % tc=[0:(Nd-1)/(Nc-1):Nd-1];
% for i=1:6
%     figure(i);
%     plot(td,MySAcc(:,i),'r');
% %     hold on;
% %     plot(td,STrq(:,i),'b');
%   
%     hold off;
%     grid on;
% end
% 
% %%
% OptPos = importdata('D:\Learn\Project_Matlab\Fanuc\OptPos.txt');
% OptVel = importdata('D:\Learn\Project_Matlab\Fanuc\OptVel.txt');
% OptAcc = importdata('D:\Learn\Project_Matlab\Fanuc\OptAcc.txt');
% OptNum = size(OptPos,1);
% 
% %%
% OptT=[0:1:OptNum-1]*4*1e-3;
% for i=1:6
%     figure(i);
%     plot(OptT,OptAcc(:,i)/D2R,'r');
%     grid on;
% end
% %%
% Xout = zeros(18*OptNum,1);
% for i=1:6:OptNum
%     Xout(18*(i-1)+1:18*(i-1)+6) = OptPos(i,:)';
%     Xout(18*(i-1)+7:18*(i-1)+12) = OptVel(i,:)';
%     Xout(18*(i-1)+13:18*i) = OptAcc(i,:)';
% end
% disp('Condition Number (After v5cubic interpolation):');
% disp(EulerCond(Xout));

%%
DriveFileL = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140725\JLS.txt';
DriveFileR = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140725\JRS.txt';
IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];    
SmpT = 31.25*35*1e-6;

I2T = [0.77;0.77;0.524;0.375;0.375;0.375];
K = [-145.7;140;-173.5;104.7;-100;-51.5];
EncRes = 32768*4;

RawDataL = importdata(DriveFileL);
Nd =size(RawDataL,1);
d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.02,0.1,1,90);

% Hdb = design(d,'butter');
% Hdc1 = design(d,'cheby1');
Hdc2 = design(d,'cheby2');
% Hdp = design(d,'ellip');
% Hde = design(d,'equiripple');
% Hdi = design(d,'ifir');
% Hdk = design(d,'kaiserwin');
% Hdm = design(d,'multistage');
Num=4;
for i=1:6
    StL(:,i) = RawDataL(:,Num*i-3)*1e-3;
    Trqo(:,i) = RawDataL(:,Num*i-2)*I2T(i)*K(i);
%     Trqs(:,i) = smooth(RawDataL(:,Num*i-2)*I2T(i)*K(i));
%     TrqLb(:,i)=filter(Hdb,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
%     TrqLc1(:,i)=filter(Hdc1,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
    TrqLc2(:,i)=filter(Hdc2,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
%     TrqLp(:,i)=filter(Hdp,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
%     TrqLe(:,i)=filter(Hde,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
%     TrqLi(:,i)=filter(Hdi,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
%     TrqLk(:,i)=filter(Hdk,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
%     TrqLm(:,i)=filter(Hdm,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
          
    Velo(:,i)=(RawDataL(:,Num*i-1)*2*pi/60/K(i));
    VelLc2(:,i)=filter(Hdc2,RawDataL(:,Num*i-1)*2*pi/60/K(i));
    Poso(:,i)=(RawDataL(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi;
    PosLc2(:,i)=filter(Hdc2,(RawDataL(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
end

for i=1:Nd-1
    AccLc2(i+1,:) = (VelLc2(i+1,:) - VelLc2(i,:))./(StL(i+1,:)-StL(i,:));
end
for i=1:6
    AccLs(:,i)=smooth(AccLc2(:,i));
    %AccLc2(:,i) = filter(Hdc2,AccLc2(:,i));    
end
AccLc2(1,:)=0;
%%
t=[0:1:Nd-1];
for i=1:6
    figure(i);
    plot(t,AccLs(:,i),'b');
    hold on;
    plot(t,AccLc2(:,i),'r');
    grid on;
end

%%
t=[0:1:Nd-1];
for i=1:6
    figure(i);
    plot(t,Trqo(:,i),'b');
    hold on;
%     plot(t,Trqs(:,i),'g');
%     hold on;
    plot(t,TrqLc2(:,i),'r');
    grid on;
end

%%
% fTrqo = fftshift(fft(Trqo));
% fTrqLc2 =fftshift(fft(TrqLc2));
% 
% Fs = 1/SmpT;
% dF = Fs/Nd;
% f = -Fs/2:dF:Fs/2-dF;
% figure(2);
% plot(f,abs(fTrqo)/Nd,'b');
% grid on;
% figure(3);
% plot(f,abs(fTrqLc2)/Nd,'r');
% grid on;


%%
t=[0:1:Nd-1];
for i=1:6
    figure(i);
    plot(t,Velo(:,i),'b');
    hold on;
%     plot(t,Trqs(:,i),'g');
%     hold on;
    plot(t,VelLc2(:,i),'r');
    grid on;
end
% 
% %%
% fVelo = fftshift(fft(Velo));
% fVelLc2 =fftshift(fft(VelLc2));
% 
% Fs = 1/SmpT;
% dF = Fs/Nd;
% f = -Fs/2:dF:Fs/2-dF;
% figure(2);
% plot(f,abs(fVelo)/Nd,'b');
% grid on;
% figure(3);
% plot(f,abs(fVelLc2)/Nd,'r');
% grid on;
% 


%%
t=[0:1:Nd-1];
for i=1:6
    figure(i);
    plot(t,Poso(:,i),'b');
    hold on;
    plot(t,PosLc2(:,i),'r');
    grid on;
end
% 
% %%
% fPoso = fftshift(fft(Poso));
% fPosLc2 =fftshift(fft(PosLc2));
% 
% Fs = 1/SmpT;
% dF = Fs/Nd;
% f = -Fs/2:dF:Fs/2-dF;
% figure(2);
% plot(f,abs(fPoso)/Nd,'b');
% grid on;
% figure(3);
% plot(f,abs(fPosLc2)/Nd,'r');
% grid on;

%%
v=[0:0.05:2];
%y=100*v.*log(v+1)+80;
y1=100*v+80;
y2=100*v.*0.8.^v +80;
figure(1);
plot(v,y1,'b');
hold on;
plot(v,y2,'r');
hold off;
grid on;

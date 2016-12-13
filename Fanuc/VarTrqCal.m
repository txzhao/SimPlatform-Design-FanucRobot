%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: VarTrqCal.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 04/03/2014
%
%@Description: To Calculate Variance of noise on Torque
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
IniEnc =[109824;-2846557;-2698244;19752;-4211310;-6879];
SmpT = 31.25*200*1e-6;
I2T = [0.73;0.73;0.5;0.4;0.4;0.39];
K = [-147;-153;153;-76.95;-80;-51];
IniJnt=[0;0;0;0;pi/2;0];
EncRes = 32768*4;
D2R = pi/180;
R2D = 180/pi;

File{1}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\OptTrj\VarTrj\VarAxis1.txt';
File{2}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\OptTrj\VarTrj\VarAxis2.txt';
File{3}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\OptTrj\VarTrj\VarAxis3.txt';
File{4}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\OptTrj\VarTrj\VarAxis4.txt';
File{5}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\OptTrj\VarTrj\VarAxis5.txt';
File{6}='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\OptTrj\VarTrj\VarAxis6.txt';

%%%%%%%Torque Vel Pos | Torque Vel Pos | ......
for i=1:6
    Axis{i}=importdata(File{i});
    Current{i}=Axis{i}(:,1:3:30);
    Torque{i}=Axis{i}(:,1:3:30)*I2T(i)*K(i);
    Vel{i}=Axis{i}(:,2:3:30)*2*pi/60/K(i);
    Joint{i}=(Axis{i}(:,3:3:30) - IniEnc(i))/EncRes/K(i)*2*pi + IniJnt(i);
end
%%
for i=1:6
    Ns(i)=size(Torque{i},1);
    CurMean{i}=mean(Current{i},2);
    CurVar{i}=var(Current{i},1,2);
    cVar(i)=sum(CurVar{i})/(10*Ns(i)-1);
    TrqMean{i}=mean(Torque{i},2);
    TrqVar{i}=var(Torque{i},1,2);
    tVar(i)=sum(TrqVar{i})/(10*Ns(i)-1);    
end
%%
for i=1:6
    figure(i);
   
    plot([0:1:Ns(i)-1]*SmpT,Current{i},'b');
    hold on;
    plot([0:1:Ns(i)-1]*SmpT,CurMean{i},'r');
    hold off;
    grid on;
    str=sprintf('%d Axis Torque',i);
    title(str);
end







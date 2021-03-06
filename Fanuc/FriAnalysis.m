%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: FriAnalysis.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 25/03/2014
%
%@Description: To analysis friction of joint 1,4,5,6
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;
%%
%%%%%%Joint 1%%%%%%%
File1='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Friction\j1\J1.txt';
Data1=importdata(File1);
Vel1=Data1(2:2:end)*2*pi/60;
Trq1=Data1(1:2:end);
figure(1);
plot(Vel1,Trq1,'.r');
grid on;
%%
%%%%%%Joint 5%%%%%%%
File4='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Friction\j4\J4.txt';
Data4=importdata(File4);
Vel4=Data4(2:2:end)*2*pi/60;
Trq4=Data4(1:2:end);
P4=polyfit(Vel4,Trq4,1);
cTrq4=P4(1)*Vel4+P4(2);
figure(4);
plot(Vel4,Trq4,'.r');
hold on;
plot(Vel4,cTrq4,'.g');
hold off;
grid on;

%%
%%%%%%Joint 5%%%%%%%
File5='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Friction\j5\J5.txt';
Data5=importdata(File5);
Vel5=Data5(2:2:end)*2*pi/60;
Trq5=Data5(1:2:end);
P5=polyfit(Vel5,Trq5,1);
cTrq5=P5(1)*Vel5+P5(2);
figure(5);
plot(Vel5,Trq5,'.r');
hold on;
plot(Vel5,cTrq5,'.g');
hold off;
grid on;
%%
%%%%%%Joint 6%%%%%%%
File6='C:\Users\DAI Dan\Desktop\Learn\Dynamic Control\New Page\Experiment\20150306\Friction\j6\J6.txt';
Data6=importdata(File6);
Vel6=Data6(2:2:end)*2*pi/60;
Trq6=Data6(1:2:end);
P6=polyfit(Vel6,Trq6,1);
cTrq6=P6(1)*Vel6+P6(2);
figure(6);
plot(Vel6,Trq6,'.r');
hold on;
plot(Vel6,cTrq6,'.g');
hold off;
grid on;
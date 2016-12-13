%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerDynIdenActDataCF.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 25/07/2014
%
%@Description: To identify the dynamic parameters using sampled data
%Key idea is to add a pair of sample points which have common acceleration but opposite velocity.
%Because of symmetry property of fricition funciton, this method will lead to cancellation of friciton.
%However, in practice, it is hardly to get one pair of sample which have excatly opposite velocity.
%One way to solve the problem is to add N pairs of samples each pair of which almost satisfies pre-describled condition
%The sum of multiple pairs will decrease the error in a statistical way. 
%After eliminating friciton force, we can identify the pure manipulator dynamic parameters.
%Then we emploit the identified dynamic model to re-model nolinear friction function using Tustin Model
%Finally, we have to demonstrate the accuracy of the model.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
% clear all;
% clc;
% format short g
% 
% RobotType ={ 'Kawasaki','Yaskawa','Fanuc','Staubli','Efort','Other'};
% SelectedType = RobotType{1};
% bMotor = false;
% 
% switch SelectedType
%     case 'Kawasaki'
% 
%     DriveFileL = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140725\JLS.txt';
%     DriveFileR = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140725\JRS.txt';
%     IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];    
%     SmpT = 31.25*35*1e-6;
% 
%     I2T = [0.77;0.77;0.524;0.375;0.375;0.375];
%     K = [-145.7;140;-173.5;104.7;-100;-51.5];
%     EncRes = 32768*4;
%     
%     % %% Lenght: m,  Angle: rad
%     DH=[
%     0       430     0       0       700     0        88;
%     0       0       -pi/2   0       pi      pi       0;
%     0       100     650     0       0       0        0;
%     0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;];
%     DH(1,:) = DH(1,:)/1000;
%     DH(3,:) = DH(3,:)/1000;
%     
%     Imz = [0.65;0.65;0.047;0.017;0.017;0.017]*1e-3; %Unit: kg*m^2
% 
%     %%%
%     
%     %MidL=[964,913,905,913,909,956];
%     MidL=[964,913,905,908,909,956];
%     MidR=[1020,1004,995,998,1049,1008];
%     Wid = 50;
%     Stp = 10;
%     Cnt = 75;
%     Len = 850;
%     
%     VelThre = [0.0005,0.0005,0.0005,0.0008,0.0008,0.002];
%     %VelThre = [0,0,0,0,0,0];
%     AccThre = [0.02,0.04,0.04,0.08,0.08,00.16];
%     
%     otherwise
% end
% 
% Num=4;
% RawDataL = importdata(DriveFileL);
% Nd =size(RawDataL,1);
% 
% 
% % d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.1,0.2,1,90);
% % d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.05,0.1,1,90);
% % Hd = design(d,'equiripple');
% % d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.01,0.1,1,90);
% d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.1,0.2,1,90);
% Hd = design(d,'cheby2');
% 
% 
% for i=1:6
%     StL(:,i) = RawDataL(:,Num*i-3)*1e-3;
%     TrqL(:,i)=filter(Hd,(RawDataL(:,Num*i-2)*I2T(i)*K(i)));
%     VelL(:,i)=filter(Hd,(RawDataL(:,Num*i-1)*2*pi/60/K(i)));
%     PosL(:,i)=filter(Hd,(RawDataL(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
% %     TrqL(:,i)=smooth((RawDataL(:,Num*i-2)*I2T(i)*K(i)));
% %     VelL(:,i)=smooth((RawDataL(:,Num*i-1)*2*pi/60/K(i)));
% %     PosL(:,i)=smooth((RawDataL(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
% end
% 
% 
% 
% for i=1:Nd-1
%     AccL(i+1,:) = (VelL(i+1,:) - VelL(i,:))./(StL(i+1,:)-StL(i,:));
% end
% for i=1:6
%     AccL(:,i) = smooth(AccL(:,i));
% end
% AccL(1,:)=0;
% 
% 
% 
% 
% RawDataR = importdata(DriveFileR);
% Nd =size(RawDataR,1);
% for i=1:6
%     StR(:,i) = RawDataR(:,Num*i-3)*1e-3;
%     TrqR(:,i)=filter(Hd,RawDataR(:,Num*i-2)*I2T(i)*K(i));
%     VelR(:,i)=filter(Hd,RawDataR(:,Num*i-1)*2*pi/60/K(i));
%     PosR(:,i)=filter(Hd,(RawDataR(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
% %     TrqR(:,i)=smooth((RawDataR(:,Num*i-2)*I2T(i)*K(i)));
% %     VelR(:,i)=smooth((RawDataR(:,Num*i-1)*2*pi/60/K(i)));
% %     PosR(:,i)=smooth((RawDataR(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
% end
% for i=1:Nd-1
%     AccR(i+1,:) = (VelR(i+1,:) - VelR(i,:))./(StR(i+1,:)-StR(i,:));
% end
% for i=1:6
%     AccR(:,i) = smooth(AccR(:,i));
% end
% AccR(1,:)=0;
% %%%
% % for i=1:6
% %     figure(i);
% %     plot([0:1:2*Nd-1],[TrqR(:,i);TrqL(:,i)],'r');
% % %     hold on;
% % %     plot([0:1:Nd-1],TrqR(:,i),'b');
% %     grid on;
% % end
% 
% % LpDly=52;
% % MidL=[964,913,905,906,909,956]+LpDly;
% % MidR=[1020,1004,993,993,1049,1008]+LpDly;
% LpDly=15;
% MidL=[964,913,905,906,909,956]+LpDly;
% MidR=[1020,1004,995,993,1049,1001]+LpDly;
% 
% %%%%Verification Set%%%%%%%%%%%%%%%%%
% for i=1:6
%     TrqVfyL(:,i) = TrqL(MidL(i)-Len+1:MidL(i)+Len,i);
%     PosVfyL(:,i) = PosL(MidL(i)-Len+1:MidL(i)+Len,i);
%     VelVfyL(:,i) = VelL(MidL(i)-Len+1:MidL(i)+Len,i);
%     AccVfyL(:,i) = AccL(MidL(i)-Len+1:MidL(i)+Len,i);
%     
%     TrqVfyR(:,i) = TrqR(MidR(i)-Len+1:MidR(i)+Len,i);
%     PosVfyR(:,i) = PosR(MidR(i)-Len+1:MidR(i)+Len,i);
%     VelVfyR(:,i) = VelR(MidR(i)-Len+1:MidR(i)+Len,i);
%     AccVfyR(:,i) = AccR(MidR(i)-Len+1:MidR(i)+Len,i);
%     
% end
% 
% 
% %%%Identification For Pure Robot Dynamic (Cancelled Friction)%%%%%%%%%%%%%
% Ft =[0;0;0;0;0;0];
% Ld = [DH(1,1) DH(1,2) DH(3,2) DH(3,3) DH(1,4) DH(3,4) DH(1,5) DH(1,6)];
% 
% %%%%Calculate all Wd's for later use%%%%%%%%%%%
% SmpNum = 2*Len;
% for i=1:SmpNum
%     
%         TrqL_a(6*(i-1)+1:6*i,1) =  TrqVfyL(i,:)';
%         WdL = EulerWd(Ld,PosVfyL(i,:),VelVfyL(i,:),AccVfyL(i,:));
%         WdL_N(6*(i-1)+1:6*i,1:60) = WdL;
%         WmL = EulerWm(Ld,abs(K'),PosVfyL(i,:),VelVfyL(i,:),AccVfyL(i,:));
%         
%         TrqR_a(6*(i-1)+1:6*i,1) =  TrqVfyR(i,:)';
%         WdR = EulerWd(Ld,PosVfyR(i,:),VelVfyR(i,:),AccVfyR(i,:));
%         WdR_N(6*(i-1)+1:6*i,1:60) = WdR;
%         WmR = EulerWm(Ld,abs(K'),PosVfyR(i,:),VelVfyR(i,:),AccVfyR(i,:));
%         
%         TrqML(6*(i-1)+1:6*i,1) = WmL*Imz;
%         TrqMR(6*(i-1)+1:6*i,1) = WmR*Imz;
%     
% end
% 
% FwdIdx = Len;
% BckIdx = Len+1;
% 
% for i=1:Cnt
%     FwdIdx = Len - (i-1)*Stp;
%     BakIdx = Len+1+(i-1)*Stp;
%     
%     WdL = zeros(6,60);
%     WdR = zeros(6,60);
%     TrqL = zeros(6,1);
%     TrqR = zeros(6,1);
%     
%     for j=1:Wid
%         WdL = WdL + WdL_N(6*(FwdIdx-j)+1:6*(FwdIdx-j+1),:) + WdL_N(6*(BakIdx+j-2)+1:6*(BakIdx+j-1),:);
%         WdR = WdR + WdR_N(6*(FwdIdx-j)+1:6*(FwdIdx-j+1),:) + WdR_N(6*(BakIdx+j-2)+1:6*(BakIdx+j-1),:);
%         TrqL = TrqL + TrqL_a(6*(FwdIdx-j)+1:6*(FwdIdx-j+1),:) + TrqL_a(6*(BakIdx+j-2)+1:6*(BakIdx+j-1),:);
%         TrqR = TrqR + TrqR_a(6*(FwdIdx-j)+1:6*(FwdIdx-j+1),:) + TrqR_a(6*(BakIdx+j-2)+1:6*(BakIdx+j-1),:);
%         TrqL = TrqL - (TrqML(6*(FwdIdx-j)+1:6*(FwdIdx-j+1),:) + TrqML(6*(BakIdx+j-2)+1:6*(BakIdx+j-1),:));
%         TrqR = TrqR - (TrqMR(6*(FwdIdx-j)+1:6*(FwdIdx-j+1),:) + TrqMR(6*(BakIdx+j-2)+1:6*(BakIdx+j-1),:));
%     end
%     
%     Wd_N(6*2*(i-1)+1:6*2*(i-1)+6,1:60) = WdL/Wid;
%     Wd_N(6*2*(i-1)+6+1:6*2*(i-1)+12,1:60) = WdR/Wid;
%     Trq_a(6*2*(i-1)+1:6*2*(i-1)+6,1) = TrqL/Wid;
%     Trq_a(6*2*(i-1)+6+1:6*2*(i-1)+12,1)= TrqR/Wid;    
% end
% 
% [Q,R,E] = qr(Wd_N);
% Tau = 6*2*Cnt*(2.2204e-16)*R(1,1);
% Num = size(find(diag(R)>Tau),1);
% Q1 = Q(:,1:Num);
% R1 = R(1:Num,1:Num);
% 
% W1 = Q1*R1;
% S = svd(W1);
% MaxS = max(S);
% MinS = min(S);
% CondNum = MaxS/MinS;
% 
% R2 = R(1:Num,Num+1:end);
% Wd_ = Q1*R1;
% 
% P_c = pinv(Wd_)*Trq_a;
% 
% Rt = R1\R2;
% Rt(find(abs(Rt)<Tau)) = 0;
% P2_c = ones(60-Num,1);
% P2_c(~any(Rt,1),:)=0;
% P1_c = P_c - R1\R2*P2_c;
% Param_c = E*[P1_c;P2_c];

%%
%%%%Friction Modelling%%%%%%%%%%
TrqL_c = WdL_N*Param_c + TrqML;
TrqR_c = WdR_N*Param_c + TrqMR;

FrcL = TrqL_a - TrqL_c;
FrcR = TrqR_a - TrqR_c;

Vel=[VelVfyL;VelVfyR];
Frc=[FrcL(1:6:end),FrcL(2:6:end),FrcL(3:6:end),FrcL(4:6:end),FrcL(5:6:end),FrcL(6:6:end);...
     FrcR(1:6:end),FrcR(2:6:end),FrcR(3:6:end),FrcR(4:6:end),FrcR(5:6:end),FrcR(6:6:end)];

for i=1:6
    MaxVp=max(Vel(:,i));
    Vp1 = (Vel(:,i)>(0.05*MaxVp));
    Vp2 = (Vel(:,i)<(0.95*MaxVp));
    Vp = Vp1 & Vp2;
    Idxp = find(Vp==1);
    VelPos = Vel(Idxp,i);
    FrcPos = Frc(Idxp,i);
    Mxp =[VelPos, ones(size(VelPos,1),1)];
    Lp(:,i) = (Mxp'*Mxp)\Mxp'*FrcPos;
    
    MaxVn=min(Vel(:,i));
    Vn1 = (Vel(:,i)<(0.05*MaxVn));
    Vn2 = (Vel(:,i)>(0.95*MaxVn));
    Vn = Vn1 & Vn2;
    Idxn = find(Vn==1);
    VelNeg = Vel(Idxn,i);
    FrcNeg = Frc(Idxn,i);
    Mxn =[VelNeg, ones(size(VelNeg,1),1)];
    Ln(:,i) = (Mxn'*Mxn)\Mxn'*FrcNeg;
%     VelPos = Vel(find(Vel(:,i)>0),i);
%     VelNeg = Vel(find(Vel(:,i)<0),i);
%     FrcPos = Frc(find(Vel(:,i)>0),i);
%     FrcNeg = Frc(find(Vel(:,i)<0),i);
%     Mxp =[VelPos, ones(size(VelPos,1),1)];
%     Mxn =[VelNeg, ones(size(VelNeg,1),1)];
%     Lp(:,i) = (Mxp'*Mxp)\Mxp'*FrcPos;
%     Ln(:,i) = (Mxn'*Mxn)\Mxn'*FrcNeg;
    %Lp(:,i) = polyfit(VelPos,FrcPos,1);
    %Ln(:,i) = polyfit(VelNeg,FrcNeg,1);
    clear VelPos VelNeg FrcPos FrcNeg Mxp Mxn Idxn Idxp Vp1 Vp2 Vn1 Vn2 Vp Vn
end 
 
 
Num = size(VelVfyL,1);
for i=1:6
    figure(i);
    plot(Vel(1:end,i),Frc(1:end,i),'s','MarkerSize',2,'MarkerEdgeColor','b');
    hold on;
    plot(Vel(:,i),(sign(Vel(:,i))+1)/2.*(Vel(:,i)*Lp(1,i) + Lp(2,i))...
        + (1-sign(Vel(:,i)))/2.*(Vel(:,i)*Ln(1,i)+Ln(2,i)),'r');
    hold off;
%     hold on;
%     plot((Vel(Num+1:end,i)),Frc(Num+1:end,i),'s','MarkerSize',2,'MarkerEdgeColor','r');
    grid on;    
end





% %%
% TrqL_c = WdL_N*Param_c + TrqML;
% TrqR_c = WdR_N*Param_c + TrqMR;
% 
% Nt = size(TrqL_c)/6;
% t=[0:1:Nt-1];
% 
% for i=1:6
%     figure(i+6);
% %     plot(t,TrqVfyL(:,i)/(I2T(i)*K(i)),'b');
% %     hold on;
% %     plot(t,TrqL_c(i:6:end)/(I2T(i)*K(i)),'r');
%     plot(t,TrqVfyL(:,i),'b');
%     hold on;
%     plot(t,TrqL_c(i:6:end),'r');
%     grid on;
% end
% %%
% for i=1:6
%     figure(i+12);
% %     plot(t,TrqVfyR(:,i)/(I2T(i)*K(i)),'b');
% %     hold on;
% %     plot(t,TrqR_c(i:6:end)/(I2T(i)*K(i)),'r');
%     plot(t,TrqVfyR(:,i),'b');
%     hold on;
%     plot(t,TrqR_c(i:6:end),'r');
%     grid on;
% end
% 

%%  Verification with other sets of samples
clear VfyData VfySt VfyTrq  VfyVel VfyPos VfyPos VfyAcc
clear VfySynTrq VfySynVel VfySynPos VfySynAcc
clear Wd_vfy_N TrqM_vfy VfyTrq_c VfyTrq_a Frc_vfy
SampleType={'3C1','3C2','2C1','2C2','3L1','3L2','LX','LY','LZ','J1',...
            'J2','J3','J4','J5','J6','JA1','JA2', 'J1-5','J2-5','J3-5',...
            'J4-5','J5-5','J6-5','J1-10','J2-10','J3-10','J4-10','J5-10','J6-10','J1-15',...
            'J2-15','J3-15','J4-15','J5-15','J6-15','Pos1','Pos2','Pos3','Pos4',};
SelectedSample = SampleType{17};
VelThre = [0.0005,0.0005,0.0005,0.0008,0.0008,0.002];
I2T = [0.77;0.77;0.524;0.375;0.375;0.375];
Idx = 1;

switch SelectedSample
    case '3C1'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\3C1.txt';
        SmpIdx = round([235.625;247.28;138.125;31.25*65*1e-2;223.438;355.406]/(31.25*65*1e-3));
        VfyNum = 1500;
    case '3C2'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\3C2.txt';
        SmpIdx = round([134.14;219.375;235.62;31.25*65*1e-2;231.56;296.56]/(31.25*65*1e-3));
        VfyNum = 1500;
    case '2C1'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\2C1.txt';
        SmpIdx = round([217.344;186.875;180.781;31.25*65*1e-2;162.5;203.125]/(31.25*65*1e-3));
        VfyNum = 1200;
    case '2C2'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\2C2.txt';
        SmpIdx = round([266.094;162.5;188.906;31.25*65*1e-2;199.063;223.594]/(31.25*65*1e-3));
        VfyNum = 1200;        
    case '3L1'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\3L1.txt';
        SmpIdx = round([211.253;197.03;164.37;31.25*65*1e-2;180.62;156.34]/(31.25*65*1e-3));
        VfyNum =900;
    case '3L2'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\3L2.txt';
        SmpIdx = round([215.313;235.625;176.719;31.25*65*1e-2;276.25;190.938]/(31.25*65*1e-3));
        VfyNum =900;
    case 'LX'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\LX.txt';
        SmpIdx = round([349.375;235.625;257.969;31.25*65*1e-2;257.69;296.563]/(31.25*65*1e-3));
        VfyNum =900;
    case 'LY'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\LY.txt';
        SmpIdx = round([355.469;280.813;327.031;31.25*65*1e-2;402.88;355.469]/(31.25*65*1e-3));
        VfyNum =900;
    case 'LZ'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\LZ.txt';
        SmpIdx = round([385.938;385.938;345.313;31.25*65*1e-2;339.219;266.094]/(31.25*65*1e-3));
        VfyNum =900;
    case 'J1'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J1.txt';
        SmpIdx = round([266.094;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2]/(31.25*65*1e-3));
        VfyNum =1850;
    case 'J2'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J2.txt';
        SmpIdx = round([31.25*65*1e-2;186.875;144.219;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2]/(31.25*65*1e-3));
        VfyNum =1850;
    case 'J3'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J3.txt';
        SmpIdx = round([31.25*65*1e-2;91.406;266.094;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2]/(31.25*65*1e-3));
        VfyNum =1850;
    case 'J4'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J4.txt';
        SmpIdx = round([31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;231.56;31.25*65*1e-2;31.25*65*1e-2]/(31.25*65*1e-3));
        VfyNum =1850;
    case 'J5'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J5.txt';
        SmpIdx = round([31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;255.938;199.063]/(31.25*65*1e-3));
        VfyNum =1850;
    case 'J6'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J6.txt';
        SmpIdx = round([31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;87.344;221.406]/(31.25*65*1e-3));
        VfyNum =1850;
    case 'JA1'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\JA1.txt';
        SmpIdx = round([174.188;121.875;105.625;91.406;83.281;148.281]/(31.25*65*1e-3));
        VfyNum =1800;
    case 'JA2'
        IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\JA2.txt'; 
        SmpIdx = round([266.094;278.281;170.625;316.875;231.563;239.688]/(31.25*65*1e-3));
        VfyNum =1800;
    case 'J1-5'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J1-5.txt'; 
        SmpIdx = round([400/(31.25*800*1e-3);1;1;1;1;1]);
        VfyNum =1900;
    case 'J2-5'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J2-5.txt';
        SmpIdx = round([1;318.75/(31.25*600*1e-3);1;1;1;1]);
        VfyNum =1900;
    case 'J3-5'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J3-5.txt';
        SmpIdx = round([1;1;295.313/(31.25*450*1e-3);1;1;1]);
        VfyNum =1900;
    case 'J4-5'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J4-5.txt';
        SmpIdx = round([1;1;1;304.668/(31.25*650*1e-3);1;1]);
        VfyNum =1900;
    case 'J5-5'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J5-5.txt';
        SmpIdx = round([1;1;1;1;390.625/(31.25*500*1e-3);328.125/(31.25*500*1e-3)]);
        VfyNum =1900;
    case 'J6-5'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J6-5.txt';
        SmpIdx = round([1;1;1;1;1;225/(31.25*800*1e-3)]);
        VfyNum =1900;
    case 'J1-10'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J1.txt'; 
        SmpIdx = round([162.5/(31.25*200*1e-3);1;1;1;1;1]);
        VfyNum =1900;
    case 'J2-10'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J2.txt';
        SmpIdx = round([1;206.52/(31.25*200*1e-3);1;1;1;1]);
        VfyNum =1900;
    case 'J3-10'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J3.txt';
        SmpIdx = round([1;1;234.375/(31.25*150*1e-3);1;1;1]);
        VfyNum =1900;
    case 'J4-10'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J4.txt';
        SmpIdx = round([1;1;1;208.125/(31.25*180*1e-3);1;1]);
        VfyNum =1900;
    case 'J5-10'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J5.txt';
        SmpIdx = round([1;1;1;1;234.375/(31.25*150*1e-3);304.688/(31.25*150*1e-3)]);
        VfyNum =1900;
    case 'J6-10'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J6.txt';
        SmpIdx = round([1;1;1;1;1;330/(31.25*220*1e-3)]);
        VfyNum =1900;
     case 'J1-15'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J1.txt'; 
        SmpIdx = round([325/(31.25*200*1e-3);1;1;1;1;1]);
        VfyNum =1900;
    case 'J2-15'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J2.txt';
        SmpIdx = round([1;258.75/(31.25*180*1e-3);1;1;1;1]);
        VfyNum =1900;
    case 'J3-15'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J3.txt';
        SmpIdx = round([1;1;304.688/(31.25*130*1e-3);1;1;1]);
        VfyNum =1900;
    case 'J4-15'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J4.txt';
        SmpIdx = round([1;1;1;303.75/(31.25*180*1e-3);1;1]);
        VfyNum =1900;
    case 'J5-15'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J5.txt';
        SmpIdx = round([1;1;1;1;365.625/(31.25*150*1e-3);290.625/(31.25*150*1e-3)]);
        VfyNum =1900;
    case 'J6-15'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J6.txt';
        SmpIdx = round([1;1;1;1;1;170.625/(31.25*210*1e-3)]);
        VfyNum =1900;
    case 'Pos1'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Pos1.txt';
        SmpIdx = round([1;1;1;1;1;1]);
        VfyNum =1900;
    case 'Pos2'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Pos2.txt';
        SmpIdx = round([1;1;1;1;1;1]);
        VfyNum =1900;
    case 'Pos3'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Pos3.txt';
        SmpIdx = round([1;1;1;1;1;1]);
        VfyNum =1900;
    case 'Pos4'
        IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Pos4.txt';
        SmpIdx = round([1;1;1;1;1;1]);
        VfyNum =1900;
    
    otherwise
        disp('Unkonwn Sample Type!!!');
end

Num=4;
VfyData = importdata(VfyFile);
Nv =size(VfyData,1);
for i=1:6
    VfySt(:,i) = VfyData(:,Num*i-3)*1e-3;
%     VfyTrq(:,i)=smooth(VfyData(:,Num*i-2)*I2T(i)*K(i));
%     VfyVel(:,i)=smooth(VfyData(:,Num*i-1)*2*pi/60/K(i));
%     VfyPos(:,i)=smooth((VfyData(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
    VfyTrq(:,i)=filter(Hd,VfyData(:,Num*i-2)*I2T(i)*K(i));
    VfyVel(:,i)=filter(Hd,VfyData(:,Num*i-1)*2*pi/60/K(i));
    VfyPos(:,i)=filter(Hd,(VfyData(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
end
%%%
% for i=1:6
%     figure(i+6);
%     plot([0:1:Nv-1],VfyTrq(:,i),'r');
%     grid on;
% end

%%
clear VfyData VfySt VfyTrq  VfyVel VfyPos VfyPos VfyAcc
clear VfySynTrq VfySynVel VfySynPos VfySynAcc
clear Wd_vfy_N TrqM_vfy VfyTrq_c VfyTrq_a

SampleType ={'V5-J1','V10-J1','V15-J1','V20-J1','V25-J1','V30-J1','V35-J1','V40-J1','V45-J1','V50-J1',...
             'V55-J1','V60-J1','V65-J1','V70-J1','V75-J1','V80-J1','V85-J1','V90-J1','V95-J1','V100-J1',...
             'V5-J2','V10-J2','V15-J2','V20-J2','V25-J2','V30-J2','V35-J2','V40-J2','V45-J2','V50-J2',...
             'V55-J2','V60-J2','V65-J2','V70-J2','V75-J2','V80-J2','V85-J2','V90-J2','V95-J2','V100-J2',...
             'V5-J3','V10-J3','V15-J3','V20-J3','V25-J3','V30-J3','V35-J3','V40-J3','V45-J3','V50-J3',...
             'V55-J3','V60-J3','V65-J3','V70-J3','V75-J3','V80-J3','V85-J3','V90-J3','V95-J3','V100-J3',...
             'V5-J4','V10-J4','V15-J4','V20-J4','V25-J4','V30-J4','V35-J4','V40-J4','V45-J4','V50-J4',...
             'V55-J4','V60-J4','V65-J4','V70-J4','V75-J4','V80-J4','V85-J4','V90-J4','V95-J4','V100-J4',...
             'V5-J5','V10-J5','V15-J5','V20-J5','V25-J5','V30-J5','V35-J5','V40-J5','V45-J5','V50-J5',...
             'V55-J5','V60-J5','V65-J5','V70-J5','V75-J5','V80-J5','V85-J5','V90-J5','V95-J5','V100-J5',...
             'V5-J6','V10-J6','V15-J6','V20-J6','V25-J6','V30-J6','V35-J6','V40-J6','V45-J6','V50-J6',...
             'V55-J6','V60-J6','V65-J6','V70-J6','V75-J6','V80-J6','V85-J6','V90-J6','V95-J6','V100-J6',};
SelectedSample = SampleType{120};
Idx=6;
IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
VfyNum =1900;
SmpIdx = [1;1;1;1;1;1];
PosCoef=[0.8;0.8;0.45;0.88;0.7;0.88];
NegCoef=[0.8;0.8;0.45;0.8;0.9;0.92];

switch SelectedSample
    case 'V5-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V5-J1.txt';
    case 'V10-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V10-J1.txt';
    case 'V15-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V15-J1.txt';
    case 'V20-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V20-J1.txt';
    case 'V25-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V25-J1.txt';
    case 'V30-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V30-J1.txt';
    case 'V35-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V35-J1.txt';
    case 'V40-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V40-J1.txt';
    case 'V45-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V45-J1.txt';
    case 'V50-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V50-J1.txt';
    case 'V55-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V55-J1.txt';
    case 'V60-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V60-J1.txt';
    case 'V65-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V65-J1.txt';
    case 'V70-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V70-J1.txt';
    case 'V75-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V75-J1.txt';
    case 'V80-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V80-J1.txt';
    case 'V85-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V85-J1.txt';
    case 'V90-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V90-J1.txt';
    case 'V95-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V95-J1.txt';
    case 'V100-J1'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V100-J1.txt';
        case 'V5-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V5-J2.txt';
    case 'V10-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V10-J2.txt';
    case 'V15-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V15-J2.txt';
    case 'V20-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V20-J2.txt';
    case 'V25-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V25-J2.txt';
    case 'V30-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V30-J2.txt';
    case 'V35-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V35-J2.txt';
    case 'V40-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V40-J2.txt';
    case 'V45-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V45-J2.txt';
    case 'V50-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V50-J2.txt';
    case 'V55-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V55-J2.txt';
    case 'V60-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V60-J2.txt';
    case 'V65-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V65-J2.txt';
    case 'V70-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V70-J2.txt';
    case 'V75-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V75-J2.txt';
    case 'V80-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V80-J2.txt';
    case 'V85-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V85-J2.txt';
    case 'V90-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V90-J2.txt';
    case 'V95-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V95-J2.txt';
    case 'V100-J2'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V100-J2.txt';
            case 'V5-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V5-J3.txt';
    case 'V10-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V10-J3.txt';
    case 'V15-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V15-J3.txt';
    case 'V20-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V20-J3.txt';
    case 'V25-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V25-J3.txt';
    case 'V30-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V30-J3.txt';
    case 'V35-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V35-J3.txt';
    case 'V40-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V40-J3.txt';
    case 'V45-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V45-J3.txt';
    case 'V50-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V50-J3.txt';
    case 'V55-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V55-J3.txt';
    case 'V60-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V60-J3.txt';
    case 'V65-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V65-J3.txt';
    case 'V70-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V70-J3.txt';
    case 'V75-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V75-J3.txt';
    case 'V80-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V80-J3.txt';
    case 'V85-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V85-J3.txt';
    case 'V90-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V90-J3.txt';
    case 'V95-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V95-J3.txt';
    case 'V100-J3'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V100-J3.txt';
            case 'V5-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V5-J4.txt';
    case 'V10-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V10-J4.txt';
    case 'V15-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V15-J4.txt';
    case 'V20-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V20-J4.txt';
    case 'V25-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V25-J4.txt';
    case 'V30-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V30-J4.txt';
    case 'V35-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V35-J4.txt';
    case 'V40-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V40-J4.txt';
    case 'V45-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V45-J4.txt';
    case 'V50-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V50-J4.txt';
    case 'V55-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V55-J4.txt';
    case 'V60-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V60-J4.txt';
    case 'V65-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V65-J4.txt';
    case 'V70-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V70-J4.txt';
    case 'V75-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V75-J4.txt';
    case 'V80-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V80-J4.txt';
    case 'V85-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V85-J4.txt';
    case 'V90-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V90-J4.txt';
    case 'V95-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V95-J4.txt';
    case 'V100-J4'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V100-J4.txt';
            case 'V5-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V5-J5.txt';
    case 'V10-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V10-J5.txt';
    case 'V15-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V15-J5.txt';
    case 'V20-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V20-J5.txt';
    case 'V25-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V25-J5.txt';
    case 'V30-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V30-J5.txt';
    case 'V35-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V35-J5.txt';
    case 'V40-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V40-J5.txt';
    case 'V45-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V45-J5.txt';
    case 'V50-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V50-J5.txt';
    case 'V55-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V55-J5.txt';
    case 'V60-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V60-J5.txt';
    case 'V65-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V65-J5.txt';
    case 'V70-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V70-J5.txt';
    case 'V75-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V75-J5.txt';
    case 'V80-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V80-J5.txt';
    case 'V85-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V85-J5.txt';
    case 'V90-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V90-J5.txt';
    case 'V95-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V95-J5.txt';
    case 'V100-J5'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V100-J5.txt';
            case 'V5-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V5-J6.txt';
    case 'V10-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V10-J6.txt';
    case 'V15-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V15-J6.txt';
    case 'V20-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V20-J6.txt';
    case 'V25-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V25-J6.txt';
    case 'V30-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V30-J6.txt';
    case 'V35-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V35-J6.txt';
    case 'V40-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V40-J6.txt';
    case 'V45-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V45-J6.txt';
    case 'V50-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V50-J6.txt';
    case 'V55-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V55-J6.txt';
    case 'V60-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V60-J6.txt';
    case 'V65-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V65-J6.txt';
    case 'V70-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V70-J6.txt';
    case 'V75-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V75-J6.txt';
    case 'V80-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V80-J6.txt';
    case 'V85-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V85-J6.txt';
    case 'V90-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V90-J6.txt';
    case 'V95-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V95-J6.txt';
    case 'V100-J6'
        VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\V100-J6.txt';
    otherwise
end
IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];

% NoiseFile =  'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140721\Noise.txt';
% NoiseData = importdata(NoiseFile);
% for i=1:6
%     NoiseTrq(:,i)=smooth(NoiseData(:,3*i-2)*I2T(i)*K(i));
%     NoiseVel(:,i)=smooth(NoiseData(:,3*i-1)*2*pi/60/K(i));
%     NoisePos(:,i)=smooth((NoiseData(:,3*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
% end


VfyData = importdata(VfyFile);
Nfy = size(VfyData,1);
VfySt_ = VfyData(:,1)*1e-3;
VfySt = repmat(VfySt_,1,6);
VfyTrq_ =smooth(VfyData(:,2)*I2T(Idx)*K(Idx));
VfyVel_ =smooth(VfyData(:,3)*2*pi/60/K(Idx));
VfyPos_ =smooth((VfyData(:,4)-IniEnc(Idx))/EncRes/K(Idx)*2*pi);
VfyTrq = zeros(Nfy,6);
VfyVel = zeros(Nfy,6);
VfyPos = zeros(Nfy,6);
VfyPos(:,5) = pi/2;
VfyTrq(:,Idx) = VfyTrq_;
VfyVel(:,Idx) = VfyVel_;
VfyPos(:,Idx) = VfyPos_;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Nv =size(VfyData,1);
for i=1:Nv-1
    VfyAcc(i+1,:) = (VfyVel(i+1,:) - VfyVel(i,:))./(VfySt(i+1,:)-VfySt(i,:));
end
for i=1:6
    VfyAcc(:,i) = smooth(VfyAcc(:,i));
end
VfyAcc(1,:)=0;

%%% Synchronization

for i=1:6
    VfySynTrq(:,i) = VfyTrq(SmpIdx(i)+LpDly:(SmpIdx(i)+VfyNum-1+LpDly),i);
    VfySynPos(:,i) = VfyPos(SmpIdx(i)+LpDly:(SmpIdx(i)+VfyNum-1+LpDly),i);
    VfySynVel(:,i) = VfyVel(SmpIdx(i)+LpDly:(SmpIdx(i)+VfyNum-1+LpDly),i);
    VfySynAcc(:,i) = VfyAcc(SmpIdx(i)+LpDly:(SmpIdx(i)+VfyNum-1+LpDly),i);    
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Wfs_vfy = zeros(6);
for i=1:VfyNum
    if i==1
        VfySynPos(1,:)=[0,0,0,0,pi/2,0];
        VfySynVel(1,:)=0;
        VfySynAcc(1,:)=0;
    end
    
    VfyTrq_a(6*(i-1)+1:6*i,1) =   VfySynTrq(i,:)';
    Wd_vfy = EulerWd(Ld, VfySynPos(i,:), VfySynVel(i,:), VfySynAcc(i,:));
    Wd_vfy_N(6*(i-1)+1:6*i,1:60) = Wd_vfy;
    
    Wm_vfy = EulerWm(Ld,abs(K'), VfySynPos(i,:), VfySynVel(i,:), VfySynAcc(i,:));    
    TrqM_vfy(6*(i-1)+1:6*i,1) = Wm_vfy*Imz;
    
    for j=1:6
        
        if (abs(VfySynVel(i,j))>VelThre(j))
        Frc_vfy(6*(i-1)+j,1) =  (sign(VfySynVel(i,j))+1)/2*(VfySynVel(i,j)*Lp(1,j) + Lp(2,j))...
        + (1-sign(VfySynVel(i,j)))/2*(VfySynVel(i,j)*Ln(1,j)+  Ln(2,j));
        else
        Frc_vfy(6*(i-1)+j,1) =  (sign(VfySynVel(i,j))+1)/2*(VfySynVel(i,j)*Lp(1,j))...
        + (1-sign(VfySynVel(i,j)))/2*(VfySynVel(i,j)*Ln(1,j));
        end
    end
    
end

VfyTrq_c = Wd_vfy_N*Param_c + TrqM_vfy + Frc_vfy;

% Frc_c = VfyTrq_a - VfyTrq_c;
% 
% Frc=[Frc_c(1:6:end),Frc_c(2:6:end),Frc_c(3:6:end),Frc_c(4:6:end),Frc_c(5:6:end),Frc_c(6:6:end)];
% 
% for i=1:6
%     figure(i);
%     plot(VfySynVel(:,i),Frc(:,i),'s','MarkerSize',2,'MarkerFaceColor','r');
%     grid on;    
% end


% %% %Plot Comparison
% %VfyTrq_c = Wd_vfy_N*Param_c + TrqM_vfy ;
% Nt = size(VfyTrq_c)/6;
% t=[0:1:Nt-1];
% for i=1:6
%     figure(i);
%     
%     plot(t,VfySynTrq(:,i),'b');
%     hold on;
%     plot(t,smooth(VfyTrq_c(i:6:end)),'r');
%     hold off;
%     grid on;
% end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Nt = size(VfyTrq_c)/6;
t=[0:1:Nt-1];

figure(1);
plot(t,VfySynTrq(:,Idx),'b');
hold on;
plot(t,smooth(VfyTrq_c(Idx:6:end)),'r');
hold off;
grid on;









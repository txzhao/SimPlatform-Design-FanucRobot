%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerDynIden.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 12/6/2014
%
%@Description: To identify the dynamic parameters using sampled data
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
clc;
format short g

RobotType ={ 'Kawasaki','Yaskawa','Fanuc','Staubli','Efort','Other'};
SelectedType = RobotType{1};
bFriction = true;
bMotor = false;
IdnNum = 350;
IdnStep = 5;

switch SelectedType
    case 'Kawasaki'
    % High Speed Data
    DriveFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\DriveData.txt';
    IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
    SmpT = 31.25*65*1e-6;
    StartIdx = round([270.156;282.344;164.531;318.906;233.594;239.688]/(31.25*65*1e-3));
%     
    % Low Speed Data
%     DriveFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\DriveData.txt';
%     IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%     SmpT = 31.25*600*1e-6;
%     StartIdx = round([243.75;206.25;243.75;187.5;168.75;243.75]/(31.25*600*1e-3));
    
%     % Increased Acc, Vel, Pos
%     DriveFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Inc.txt';
%     IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%     SmpT = 31.25*850*1e-6;
%     StartIdx = round([292.188;262.625;212.5;292.188;165.625;292.188]/(31.25*850*1e-3));

    
    ControlFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140611\ControlData.txt';
    I2T = [0.77;0.77;0.524;0.375;0.375;0.375];
    K = [-145.7;140;-173.5;104.7;-100;-51.5];
    EncRes = 32768*4;
    
    % %% Lenght: m,  Angle: rad
    DH=[
    0       430     0       0       700     0        88;
    0       0       -pi/2   0       pi      pi       0;
    0       100     650     0       0       0        0;
    0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;];
    DH(1,:) = DH(1,:)/1000;
    DH(3,:) = DH(3,:)/1000;
    if ~bMotor
        Imz = [0.65;0.65;0.047;0.017;0.017;0.017]*1e-3; %Unit: kg*m^2
    end
    %%%
    
    VelThre = [0.0005,0.0005,0.0005,0.0008,0.0008,0.002];
    %VelThre = [0,0,0,0,0,0];
    AccThre = [0.02,0.04,0.04,0.08,0.08,00.16];
    
    otherwise
end
ConData = importdata(ControlFile);
D2R = pi/180;
PosCmd = ConData(:,1:6)*D2R;
VelCmd = ConData(:,7:12)*D2R;
AccCmd = ConData(:,13:18)*D2R;
MVelCmd = ConData(:,19:24)*D2R;
MAccCmd = ConData(:,25:30)*D2R;
EncCmd = ConData(:,31:36);
EncFbk = ConData(:,37:42);
Nc = size(ConData,1);

Num=4;
RawData = importdata(DriveFile);
Nd =size(RawData,1);
d=fdesign.lowpass('Fp,Fst,Ap,Ast',0.1,0.2,1,90);
Hd = design(d,'cheby2');
for i=1:6
    St(:,i) = RawData(:,Num*i-3)*1e-3;
%     Trq(:,i)=smooth(RawData(:,Num*i-2)*I2T(i)*K(i));
%     Vel(:,i)=smooth(RawData(:,Num*i-1)*2*pi/60/K(i));
%     Pos(:,i)=smooth((RawData(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
    Trq(:,i)=filter(Hd,RawData(:,Num*i-2)*I2T(i)*K(i));
    Vel(:,i)=filter(Hd,RawData(:,Num*i-1)*2*pi/60/K(i));
    Pos(:,i)=filter(Hd,(RawData(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
end
%%% add 15 to cancel delay caused by filter
StartIdx = StartIdx +15;
for i=1:Nd-1
    Acc(i+1,:) = (Vel(i+1,:) - Vel(i,:))./(St(i+1,:)-St(i,:));
end
for i=1:6
    Acc(:,i) = smooth(Acc(:,i));
end
Acc(1,:)=0;
%%
%%% Synchronization
for i=1:6
    TrqIdn(:,i) = Trq(StartIdx(i):IdnStep:(StartIdx(i)+IdnStep*(IdnNum-1)),i);
    PosIdn(:,i) = Pos(StartIdx(i):IdnStep:(StartIdx(i)+IdnStep*(IdnNum-1)),i);
    VelIdn(:,i) = Vel(StartIdx(i):IdnStep:(StartIdx(i)+IdnStep*(IdnNum-1)),i);
    AccIdn(:,i) = Acc(StartIdx(i):IdnStep:(StartIdx(i)+IdnStep*(IdnNum-1)),i);
    
%     TrqVfy(:,i) = Trq(StartIdx(i)+10:IdnStep:(StartIdx(i)+10+IdnStep*(IdnNum-1)),i);
%     PosVfy(:,i) = Pos(StartIdx(i)+10:IdnStep:(StartIdx(i)+10+IdnStep*(IdnNum-1)),i);
%     VelVfy(:,i) = Vel(StartIdx(i)+10:IdnStep:(StartIdx(i)+10+IdnStep*(IdnNum-1)),i);
%     AccVfy(:,i) = Acc(StartIdx(i)+10:IdnStep:(StartIdx(i)+10+IdnStep*(IdnNum-1)),i);
    TrqVfy(:,i) = Trq(StartIdx(i):(StartIdx(i)+IdnStep*(IdnNum-1)),i);
    PosVfy(:,i) = Pos(StartIdx(i):(StartIdx(i)+IdnStep*(IdnNum-1)),i);
    VelVfy(:,i) = Vel(StartIdx(i):(StartIdx(i)+IdnStep*(IdnNum-1)),i);
    AccVfy(:,i) = Acc(StartIdx(i):(StartIdx(i)+IdnStep*(IdnNum-1)),i);
end


%%%%Identification
Ft =[0;0;0;0;0;0];
Ld = [DH(1,1) DH(1,2) DH(3,2) DH(3,3) DH(1,4) DH(3,4) DH(1,5) DH(1,6)];
if bFriction
    if bMotor
        ParamNum=(1+3+6+4+1)*6;
    else
        ParamNum=(1+3+6+4)*6;
    end
else
    if bMotor
        ParamNum=(1+3+6+1)*6;
    else
        ParamNum = (1+3+6)*6;
    end
end

for i=1:IdnNum
%     if (abs(VelIdn(i,1))>VelThre(1) && abs(VelIdn(i,2))>VelThre(2) && abs(VelIdn(i,3))>VelThre(3) && ...
%        abs(VelIdn(i,4))>VelThre(4) && abs(VelIdn(i,5))>VelThre(5) && abs(VelIdn(i,6))>VelThre(6) )
%         
        Trq_a(6*(i-1)+1:6*i,1) =  TrqIdn(i,:)';
        Wd = EulerWd(Ld,PosIdn(i,:),VelIdn(i,:),AccIdn(i,:));
        Wd_N(6*(i-1)+1:6*i,1:60) = Wd;


        Wm = EulerWm(Ld,abs(K'),PosIdn(i,:),VelIdn(i,:),AccIdn(i,:));

        if bFriction

%             Wfv =[VelIdn(i,1)    0       0       0       0       0;
%               0         VelIdn(i,2)  0       0       0       0;
%               0         0       VelIdn(i,3)  0       0       0;
%               0         0       0       VelIdn(i,4)  0       0;
%               0         0       0       0       VelIdn(i,5)  0;
%               0         0       0       0       0       VelIdn(i,6)];


%             Wfs =[sign(VelIdn(i,1))  0               0               0               0               0;
%               0             sign(VelIdn(i,2))    0               0               0               0;
%               0             0               sign(VelIdn(i,3))    0               0               0;
%               0             0               0               sign(VelIdn(i,4))    0               0;
%               0             0               0               0               sign(VelIdn(i,5))    0;
%               0             0               0               0               0               sign(VelIdn(i,6))]; 
          
%             Wfs = zeros(6,6);      
%             for j=1:6
%                  if abs(VelIdn(i,j))>VelThre(j) 
%                     Wfs(j,j) = sign(VelIdn(i,j));
%                 else
%                     Wfs(j,j)=0;
%                 end
%             end
            
            %%%%%%%%%%%%%%Non-Symmertry Friction Model%%%%%%%%%%
            Wfvp=zeros(6,6);
            Wfvn=zeros(6,6);
            Wfsp=zeros(6,6);
            Wfsn=zeros(6,6);
            for j=1:6
                if VelIdn(i,j)>=0
                    Wfvp(j,j) = VelIdn(i,j);
                    Wfvn(j,j) = 0;
                    if abs(VelIdn(i,j))>VelThre(j) 
                        Wfsp(j,j) = sign(VelIdn(i,j));
                    else
                        Wfsp(j,j)=0;
                    end
                else
                    Wfvp(j,j) = 0;
                    Wfvn(j,j) = VelIdn(i,j);
                    if abs(VelIdn(i,j))>VelThre(j) 
                        Wfsn(j,j) = sign(VelIdn(i,j));
                    else
                        Wfsn(j,j)=0;
                    end
                end
                
            end
            
        end
        TrqM(6*(i-1)+1:6*i,1) = Wm*Imz;
        Wd_N(6*(i-1)+1:6*i,61:66) = Wfvp;
        Wd_N(6*(i-1)+1:6*i,67:72) = Wfsp;
        Wd_N(6*(i-1)+1:6*i,73:78) = Wfvn;
        Wd_N(6*(i-1)+1:6*i,79:84) = Wfsn;
        

%         if bMotor
%             if bFriction
%             Wd_N(6*(i-1)+1:6*i,61:66) = Wm;
%             Wd_N(6*(i-1)+1:6*i,67:72) = Wfv;
%             Wd_N(6*(i-1)+1:6*i,73:78) = Wfs;    
%             else
%             Wd_N(6*(i-1)+1:6*i,61:66) = Wm;    
%             end
%         else
%             TrqM(6*(i-1)+1:6*i,1) = Wm*Imz;
%             %TrqM(6*(i-1)+1:6*i,1) = 0;
%             if bFriction
%             Wd_N(6*(i-1)+1:6*i,61:66) = Wfv;
%             Wd_N(6*(i-1)+1:6*i,67:72) = Wfs;      
%             end
%         end

%     else
%          i=i-1;
%          IdnNum = IdnNum -1;
%     end  
     
    
end
[Q,R,E] = qr(Wd_N);
Tau = 6*IdnNum*(2.2204e-16)*R(1,1);
Num = size(find(diag(R)>Tau),1);
Q1 = Q(:,1:Num);
R1 = R(1:Num,1:Num);

W1 = Q1*R1;
S = svd(W1);
MaxS = max(S);
MinS = min(S);
CondNum = MaxS/MinS;

R2 = R(1:Num,Num+1:end);
Wd_ = Q1*R1;

if bMotor
    P_c = pinv(Wd_)*Trq_a;
else
    P_c = pinv(Wd_)*(Trq_a-TrqM);
end
Rt = R1\R2;
Rt(find(abs(Rt)<Tau)) = 0;
P2_c = zeros(ParamNum-Num,1);
%P2_c = ones(ParamNum-Num,1);
%P2_c(~any(Rt,1),:)=0;
P1_c = P_c - R1\R2*P2_c;
Param_c = E*[P1_c;P2_c];

if bMotor
    Trq_c = Wd_N*Param_c;
else
    Trq_c = Wd_N*Param_c + TrqM;
end

ErrIdn_c = abs(Trq_a - Trq_c);

ErrIdn_c1 = ErrIdn_c(1:6:end);
ErrIdn_c2 = ErrIdn_c(2:6:end);
ErrIdn_c3 = ErrIdn_c(3:6:end);
ErrIdn_c4 = ErrIdn_c(4:6:end);
ErrIdn_c5 = ErrIdn_c(5:6:end);
ErrIdn_c6 = ErrIdn_c(6:6:end);
for i=1:6
    MaxTrqIdn(i) = max(abs(TrqIdn(:,i)));
end

disp('Identification Set:');
disp('Condition Num |Max Sigular|   Min Sigular');
disp([CondNum,MaxS,MinS]);
disp('       AbsMax   |   AbsMean  |  RltMax   |   RltMean');
disp([max(ErrIdn_c1),mean(ErrIdn_c1),max(ErrIdn_c1)/MaxTrqIdn(1),mean(ErrIdn_c1)/MaxTrqIdn(1)]);
disp([max(ErrIdn_c2),mean(ErrIdn_c2),max(ErrIdn_c2)/MaxTrqIdn(2),mean(ErrIdn_c2)/MaxTrqIdn(2)]);
disp([max(ErrIdn_c3),mean(ErrIdn_c3),max(ErrIdn_c3)/MaxTrqIdn(3),mean(ErrIdn_c3)/MaxTrqIdn(3)]);
disp([max(ErrIdn_c4),mean(ErrIdn_c4),max(ErrIdn_c4)/MaxTrqIdn(4),mean(ErrIdn_c4)/MaxTrqIdn(4)]);
disp([max(ErrIdn_c5),mean(ErrIdn_c5),max(ErrIdn_c5)/MaxTrqIdn(5),mean(ErrIdn_c5)/MaxTrqIdn(5)]);
disp([max(ErrIdn_c6),mean(ErrIdn_c6),max(ErrIdn_c6)/MaxTrqIdn(6),mean(ErrIdn_c6)/MaxTrqIdn(6)]);
% 
% %%%%%%%Verification%%%%%%%%%%%%%%%%%%%%%
Nv =  size(PosVfy,1);
for i=1:Nv
    
    Trq_av(6*(i-1)+1:6*i,1) =  TrqVfy(i,:)';
    Wdv = EulerWd(Ld,PosVfy(i,:),VelVfy(i,:),AccVfy(i,:));
    Wmv = EulerWm(Ld,abs(K'),PosVfy(i,:),VelVfy(i,:),AccVfy(i,:));    

    Wdv_N(6*(i-1)+1:6*i,1:60) = Wdv;
    
%     if bFriction
%         Wfvv =[VelVfy(i,1)    0       0       0       0       0;
%           0         VelVfy(i,2)  0       0       0       0;
%           0         0       VelVfy(i,3)  0       0       0;
%           0         0       0       VelVfy(i,4)  0       0;
%           0         0       0       0       VelVfy(i,5)  0;
%           0         0       0       0       0       VelVfy(i,6)];
%          
%         Wfsv = zeros(6,6);      
%         for j=1:6
%              if abs(VelVfy(i,j))>VelThre(j) 
%                 Wfsv(j,j) = sign(VelVfy(i,j));
%             else
%                 Wfsv(j,j)=0;
%             end
%         end

        Wfvvp=zeros(6,6);
        Wfvvn=zeros(6,6);
        Wfsvp=zeros(6,6);
        Wfsvn=zeros(6,6);
        for j=1:6
            if VelVfy(i,j)>=0
                Wfvvp(j,j) = VelVfy(i,j);
                Wfvvn(j,j) = 0;
                if abs(VelVfy(i,j))>VelThre(j) 
                    Wfsvp(j,j) = sign(VelVfy(i,j));
                else
                    Wfsvp(j,j)=0;
                end
            else
                Wfvvp(j,j) = 0;
                Wfvvn(j,j) = VelVfy(i,j);
                if abs(VelVfy(i,j))>VelThre(j) 
                    Wfsvn(j,j) = sign(VelVfy(i,j));
                else
                    Wfsvn(j,j)=0;
                end
            end

        end
        
 
    TrqMv(6*(i-1)+1:6*i,1) = Wmv*Imz;
    Wdv_N(6*(i-1)+1:6*i,61:66) = Wfvvp;
    Wdv_N(6*(i-1)+1:6*i,67:72) = Wfsvp;
    Wdv_N(6*(i-1)+1:6*i,73:78) = Wfvvn;
    Wdv_N(6*(i-1)+1:6*i,79:84) = Wfsvn; 

    
%     if bMotor
%         if bFriction
%         Wdv_N(6*(i-1)+1:6*i,61:66) = Wmv;
%         Wdv_N(6*(i-1)+1:6*i,67:72) = Wfvv;
%         Wdv_N(6*(i-1)+1:6*i,73:78) = Wfsv;    
%         else
%         Wdv_N(6*(i-1)+1:6*i,61:66) = Wmv;    
%         end
%     else
%         TrqMv(6*(i-1)+1:6*i,1) = Wmv*Imz;
%         TrqMv(6*(i-1)+1:6*i,1) =0;
%         if bFriction
%         Wdv_N(6*(i-1)+1:6*i,61:66) = Wfvv;
%         Wdv_N(6*(i-1)+1:6*i,67:72) = Wfsv;      
%         end
%     end
end
%%
%Trq_c = (Wdv_N(:,1:84)*Param_c(1:84) + TrqMv);
Dyn_c = (Wdv_N(:,1:60)*Param_c(1:60) ) + TrqMv;
Frc_c = (Wdv_N(:,61:84)*Param_c(61:84) );

Dyn =[TrqVfy(:,1)-Frc_c(1:6:end,1),TrqVfy(:,2)-Frc_c(2:6:end,1),TrqVfy(:,3)-Frc_c(3:6:end,1),...
      TrqVfy(:,4)-Frc_c(4:6:end,1),TrqVfy(:,5)-Frc_c(5:6:end,1),TrqVfy(:,6)-Frc_c(6:6:end,1)];
Dyn_c =[Dyn_c(1:6:end,1),Dyn_c(2:6:end,1),Dyn_c(3:6:end,1),...
       Dyn_c(4:6:end,1),Dyn_c(5:6:end,1),Dyn_c(6:6:end,1)];
Nt=length(Dyn(:,1));
t=[0:1:Nt-1];
for i=1:6
    figure(i);
%     plot(VelVfy(:,i),Frc(:,i),'s','MarkerSize',2,'MarkerFaceColor','b');
%     hold on;
%      plot(VelVfy(:,i),Param_c(60+i)*VelVfy(:,i)+Param_c(66+i)*sign(VelVfy(:,i)),'r');
    plot(t,smooth(Dyn_c(:,i)),'r');
    hold on;
    plot(t,TrqVfy(:,i),'b');
%     plot(t,PosVfy(:,i)/pi*180);
%     plot(t,smooth(Dyn_c(:,i)),'r');
%     hold on;
%     plot(t,Dyn(:,i),'b');
    grid on;
end
%%
% if bMotor
%     Trq_cv = Wdv_N*Param_c;
% else
%     Trq_cv = Wdv_N*Param_c + TrqMv;
% end
% ErrVfy_c = abs(Trq_av - Trq_cv);
% 
% ErrVfy_c1 = ErrVfy_c(1:6:end);
% ErrVfy_c2 = ErrVfy_c(2:6:end);
% ErrVfy_c3 = ErrVfy_c(3:6:end);
% ErrVfy_c4 = ErrVfy_c(4:6:end);
% ErrVfy_c5 = ErrVfy_c(5:6:end);
% ErrVfy_c6 = ErrVfy_c(6:6:end);
% for i=1:6
%     MaxTrqVfy(i) = max(abs(TrqVfy(:,i)));
% end
% 
% [Max_c(1),Idx_c(1)]=max(ErrVfy_c1);
% [Max_c(2),Idx_c(2)]=max(ErrVfy_c2);
% [Max_c(3),Idx_c(3)]=max(ErrVfy_c3);
% [Max_c(4),Idx_c(4)]=max(ErrVfy_c4);
% [Max_c(5),Idx_c(5)]=max(ErrVfy_c5);
% [Max_c(6),Idx_c(6)]=max(ErrVfy_c6);
% 
% disp('Verification Set:');
% disp('       AbsMax   |   AbsMean  |  RltMax   |   RltMean');
% disp([max(ErrVfy_c1),mean(ErrVfy_c1),max(ErrVfy_c1)/MaxTrqVfy(1),mean(ErrVfy_c1)/MaxTrqVfy(1)]);
% disp([max(ErrVfy_c2),mean(ErrVfy_c2),max(ErrVfy_c2)/MaxTrqVfy(2),mean(ErrVfy_c2)/MaxTrqVfy(2)]);
% disp([max(ErrVfy_c3),mean(ErrVfy_c3),max(ErrVfy_c3)/MaxTrqVfy(3),mean(ErrVfy_c3)/MaxTrqVfy(3)]);
% disp([max(ErrVfy_c4),mean(ErrVfy_c4),max(ErrVfy_c4)/MaxTrqVfy(4),mean(ErrVfy_c4)/MaxTrqVfy(4)]);
% disp([max(ErrVfy_c5),mean(ErrVfy_c5),max(ErrVfy_c5)/MaxTrqVfy(5),mean(ErrVfy_c5)/MaxTrqVfy(5)]);
% disp([max(ErrVfy_c6),mean(ErrVfy_c6),max(ErrVfy_c6)/MaxTrqVfy(6),mean(ErrVfy_c6)/MaxTrqVfy(6)]);
% 
% %%
% %%%%Plot Comparison
% Nt = size(Trq_cv)/6;
% t=[0:1:Nt-1];
% for i=1:6
%     figure(i);
%     
%     plot(t,TrqVfy(:,i),'b');
%     hold on;
%     plot(t,Trq_cv(i:6:end),'r');
% %     hold on;
% %     plot(Idx_c(i)-1,TrqVfy(Idx_c(i),i),'s','MarkerSize',10,'MarkerFaceColor','g',  'MarkerEdgeColor','k');
%     
%     hold off;
%     grid on;
% end

% %%  Verification with other sets of samples
% clear VfyData VfySt VfyTrq  VfyVel VfyPos VfyPos VfyAcc
% clear VfySynTrq VfySynVel VfySynPos VfySynAcc
% clear Wd_vfy_N TrqM_vfy VfyTrq_c VfyTrq_a
% 
% SampleType={'3C1','3C2','2C1','2C2','3L1','3L2','LX','LY','LZ','J1',...
%             'J2','J3','J4','J5','J6','JA1','JA2', 'J1-5','J2-5','J3-5',...
%             'J4-5','J5-5','J6-5','J1-10','J2-10','J3-10','J4-10','J5-10','J6-10','J1-15',...
%             'J2-15','J3-15','J4-15','J5-15','J6-15','Pos1','Pos2','Pos3','Pos4',};
% SelectedSample = SampleType{36};
% I2T = [0.77;0.77;0.524;0.375;0.375;0.375];
% Idx = 1;
% 
% switch SelectedSample
%     case '3C1'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\3C1.txt';
%         SmpIdx = round([235.625;247.28;138.125;31.25*65*1e-2;223.438;355.406]/(31.25*65*1e-3));
%         VfyNum = 1500;
%     case '3C2'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\3C2.txt';
%         SmpIdx = round([134.14;219.375;235.62;31.25*65*1e-2;231.56;296.56]/(31.25*65*1e-3));
%         VfyNum = 1500;
%     case '2C1'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\2C1.txt';
%         SmpIdx = round([217.344;186.875;180.781;31.25*65*1e-2;162.5;203.125]/(31.25*65*1e-3));
%         VfyNum = 1200;
%     case '2C2'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\2C2.txt';
%         SmpIdx = round([266.094;162.5;188.906;31.25*65*1e-2;199.063;223.594]/(31.25*65*1e-3));
%         VfyNum = 1200;        
%     case '3L1'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\3L1.txt';
%         SmpIdx = round([211.253;197.03;164.37;31.25*65*1e-2;180.62;156.34]/(31.25*65*1e-3));
%         VfyNum =900;
%     case '3L2'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\3L2.txt';
%         SmpIdx = round([215.313;235.625;176.719;31.25*65*1e-2;276.25;190.938]/(31.25*65*1e-3));
%         VfyNum =900;
%     case 'LX'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\LX.txt';
%         SmpIdx = round([349.375;235.625;257.969;31.25*65*1e-2;257.69;296.563]/(31.25*65*1e-3));
%         VfyNum =900;
%     case 'LY'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\LY.txt';
%         SmpIdx = round([355.469;280.813;327.031;31.25*65*1e-2;402.88;355.469]/(31.25*65*1e-3));
%         VfyNum =900;
%     case 'LZ'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\LZ.txt';
%         SmpIdx = round([385.938;385.938;345.313;31.25*65*1e-2;339.219;266.094]/(31.25*65*1e-3));
%         VfyNum =900;
%     case 'J1'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J1.txt';
%         SmpIdx = round([266.094;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2]/(31.25*65*1e-3));
%         VfyNum =1850;
%     case 'J2'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J2.txt';
%         SmpIdx = round([31.25*65*1e-2;186.875;144.219;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2]/(31.25*65*1e-3));
%         VfyNum =1850;
%     case 'J3'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J3.txt';
%         SmpIdx = round([31.25*65*1e-2;91.406;266.094;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2]/(31.25*65*1e-3));
%         VfyNum =1850;
%     case 'J4'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J4.txt';
%         SmpIdx = round([31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;231.56;31.25*65*1e-2;31.25*65*1e-2]/(31.25*65*1e-3));
%         VfyNum =1850;
%     case 'J5'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J5.txt';
%         SmpIdx = round([31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;255.938;199.063]/(31.25*65*1e-3));
%         VfyNum =1850;
%     case 'J6'
%         IniEnc =[-160924;78898;4682241;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\J6.txt';
%         SmpIdx = round([31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;31.25*65*1e-2;87.344;221.406]/(31.25*65*1e-3));
%         VfyNum =1850;
%     case 'JA1'
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\JA1.txt';
%         SmpIdx = round([174.188;121.875;105.625;91.406;83.281;148.281]/(31.25*65*1e-3));
%         VfyNum =1500;
%     case 'JA2'
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140613\JA2.txt'; 
%         SmpIdx = round([266.094;278.281;170.625;316.875;231.563;239.688]/(31.25*65*1e-3));
%         VfyNum =1500;
%     case 'J1-5'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J1-5.txt'; 
%         SmpIdx = round([400/(31.25*800*1e-3);1;1;1;1;1]);
%         VfyNum =1900;
%     case 'J2-5'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J2-5.txt';
%         SmpIdx = round([1;318.75/(31.25*600*1e-3);1;1;1;1]);
%         VfyNum =1900;
%     case 'J3-5'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J3-5.txt';
%         SmpIdx = round([1;1;295.313/(31.25*450*1e-3);1;1;1]);
%         VfyNum =1900;
%     case 'J4-5'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J4-5.txt';
%         SmpIdx = round([1;1;1;304.668/(31.25*650*1e-3);1;1]);
%         VfyNum =1900;
%     case 'J5-5'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J5-5.txt';
%         SmpIdx = round([1;1;1;1;390.625/(31.25*500*1e-3);328.125/(31.25*500*1e-3)]);
%         VfyNum =1900;
%     case 'J6-5'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140701\J6-5.txt';
%         SmpIdx = round([1;1;1;1;1;225/(31.25*800*1e-3)]);
%         VfyNum =1900;
%     case 'J1-10'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J1.txt'; 
%         SmpIdx = round([162.5/(31.25*200*1e-3);1;1;1;1;1]);
%         VfyNum =1900;
%     case 'J2-10'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J2.txt';
%         SmpIdx = round([1;206.52/(31.25*200*1e-3);1;1;1;1]);
%         VfyNum =1900;
%     case 'J3-10'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J3.txt';
%         SmpIdx = round([1;1;234.375/(31.25*150*1e-3);1;1;1]);
%         VfyNum =1900;
%     case 'J4-10'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J4.txt';
%         SmpIdx = round([1;1;1;208.125/(31.25*180*1e-3);1;1]);
%         VfyNum =1900;
%     case 'J5-10'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J5.txt';
%         SmpIdx = round([1;1;1;1;234.375/(31.25*150*1e-3);304.688/(31.25*150*1e-3)]);
%         VfyNum =1900;
%     case 'J6-10'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V10-J6.txt';
%         SmpIdx = round([1;1;1;1;1;330/(31.25*220*1e-3)]);
%         VfyNum =1900;
%      case 'J1-15'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J1.txt'; 
%         SmpIdx = round([325/(31.25*200*1e-3);1;1;1;1;1]);
%         VfyNum =1900;
%     case 'J2-15'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J2.txt';
%         SmpIdx = round([1;258.75/(31.25*180*1e-3);1;1;1;1]);
%         VfyNum =1900;
%     case 'J3-15'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J3.txt';
%         SmpIdx = round([1;1;304.688/(31.25*130*1e-3);1;1;1]);
%         VfyNum =1900;
%     case 'J4-15'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J4.txt';
%         SmpIdx = round([1;1;1;303.75/(31.25*180*1e-3);1;1]);
%         VfyNum =1900;
%     case 'J5-15'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J5.txt';
%         SmpIdx = round([1;1;1;1;365.625/(31.25*150*1e-3);290.625/(31.25*150*1e-3)]);
%         VfyNum =1900;
%     case 'J6-15'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140716\V15-J6.txt';
%         SmpIdx = round([1;1;1;1;1;170.625/(31.25*210*1e-3)]);
%         VfyNum =1900;
%     case 'Pos1'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Pos1.txt';
%         SmpIdx = round([1;1;1;1;1;1]);
%         VfyNum =1900;
%     case 'Pos2'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Pos2.txt';
%         SmpIdx = round([1;1;1;1;1;1]);
%         VfyNum =1900;
%     case 'Pos3'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Pos3.txt';
%         SmpIdx = round([1;1;1;1;1;1]);
%         VfyNum =1900;
%     case 'Pos4'
%         IniEnc =[-160924;39399190;43999106;82745;695941;-2462336];
%         VfyFile = 'C:\Users\DAI Dan\Desktop\Dynamic Debug\ActualData\20140703\Pos4.txt';
%         SmpIdx = round([1;1;1;1;1;1]);
%         VfyNum =1900;
%     
%     otherwise
%         disp('Unkonwn Sample Type!!!');
% end
%    
% Num=4;
% VfyData = importdata(VfyFile);
% Nv =size(VfyData,1);
% for i=1:6
%     VfySt(:,i) = VfyData(:,Num*i-3)*1e-3;
%     VfyTrq(:,i)=smooth(VfyData(:,Num*i-2)*I2T(i)*K(i));
%     VfyVel(:,i)=smooth(VfyData(:,Num*i-1)*2*pi/60/K(i));
%     VfyPos(:,i)=smooth((VfyData(:,Num*i)-IniEnc(i))/EncRes/K(i)*2*pi); 
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
SelectedSample = SampleType{61};
Idx=4;
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
    VfySynTrq(:,i) = VfyTrq(SmpIdx(i):(SmpIdx(i)+VfyNum-1),i);
    VfySynPos(:,i) = VfyPos(SmpIdx(i)+10:(SmpIdx(i)+10+VfyNum-1),i);
    VfySynVel(:,i) = VfyVel(SmpIdx(i)+10:(SmpIdx(i)+10+VfyNum-1),i);
    VfySynAcc(:,i) = VfyAcc(SmpIdx(i)+10:(SmpIdx(i)+10+VfyNum-1),i);    
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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

    
    Wd_vfy_N(6*(i-1)+1:6*i,61:66) = Wm_vfy;
    
    if bFriction
        
        
%         Wfv_vfy =[VfySynVel(i,1)    0       0       0       0       0;
%                   0         VfySynVel(i,2)  0       0       0       0;
%                   0         0       VfySynVel(i,3)  0       0       0;
%                   0         0       0       VfySynVel(i,4)  0       0;
%                   0         0       0       0       VfySynVel(i,5)  0;
%                   0         0       0       0       0       VfySynVel(i,6)];
%               
%         
%         Wfs_vfy = zeros(6,6);      
%         for j=1:6
%              if abs(VfySynVel(i,j))>VelThre(j) 
%                 Wfs_vfy(j,j) = sign(VfySynVel(i,j));
%             else
%                 Wfs_vfy(j,j)=0;
%             end
%         end
       
        Wfvp_vfy=zeros(6,6);
        Wfvn_vfy=zeros(6,6);
        Wfsp_vfy=zeros(6,6);
        Wfsn_vfy=zeros(6,6);
        for j=1:6
            if VfySynVel(i,j)>=0
                Wfvp_vfy(j,j) = VfySynVel(i,j)*PosCoef(j)^VfySynVel(i,j);
                Wfvn_vfy(j,j) = 0;
                if abs(VfySynVel(i,j))>VelThre(j) 
                    Wfsp_vfy(j,j) = sign(VfySynVel(i,j));
                else
                    Wfsp_vfy(j,j)=0;
                end
            else
                Wfvp_vfy(j,j) = 0;
                Wfvn_vfy(j,j) = VfySynVel(i,j)*NegCoef(j)^abs(VfySynVel(i,j));
                if abs(VfySynVel(i,j))>VelThre(j) 
                    Wfsn_vfy(j,j) = sign(VfySynVel(i,j));
                else
                    Wfsn_vfy(j,j)=0;
                end
            end

        end
        
    
    TrqM_vfy(6*(i-1)+1:6*i,1) = Wm_vfy*Imz;
    Wd_vfy_N(6*(i-1)+1:6*i,61:66) = Wfvp_vfy;
    Wd_vfy_N(6*(i-1)+1:6*i,67:72) = Wfsp_vfy; 
    Wd_vfy_N(6*(i-1)+1:6*i,73:78) = Wfvn_vfy;
    Wd_vfy_N(6*(i-1)+1:6*i,79:84) = Wfsn_vfy; 
         
           
        
    end
    
%      if bMotor
%         if bFriction
%         Wd_vfy_N(6*(i-1)+1:6*i,61:66) = Wm_vfy;
%         Wd_vfy_N(6*(i-1)+1:6*i,67:72) = Wfv_vfy;
%         Wd_vfy_N(6*(i-1)+1:6*i,73:78) = Wfs_vfy;    
%         else
%         Wd_vfy_N(6*(i-1)+1:6*i,61:66) = Wm_vfy;    
%         end
%     else
%         TrqM_vfy(6*(i-1)+1:6*i,1) = Wm_vfy*Imz;
%         if bFriction
%         Wd_vfy_N(6*(i-1)+1:6*i,61:66) = Wfv_vfy;
%         Wd_vfy_N(6*(i-1)+1:6*i,67:72) = Wfs_vfy;      
%         end
%     end
    
end
if bMotor
    VfyTrq_c = Wd_vfy_N*Param_c;
else
    VfyTrq_c = Wd_vfy_N(:,1:84)*Param_c(1:84) + TrqM_vfy;
end
% Frc_c = Wd_vfy_N(:,61:72)*Param_c(61:72);
% 
% ErrVfy_c = abs(VfyTrq_a - VfyTrq_c);
% 
% ErrVfy_c1 = ErrVfy_c(1:6:end);
% ErrVfy_c2 = ErrVfy_c(2:6:end);
% ErrVfy_c3 = ErrVfy_c(3:6:end);
% ErrVfy_c4 = ErrVfy_c(4:6:end);
% ErrVfy_c5 = ErrVfy_c(5:6:end);
% ErrVfy_c6 = ErrVfy_c(6:6:end);
% for i=1:6
%     MaxTrqVfy(i) = max(abs(VfySynTrq(:,i)));
% end
% 
% [Max_c(1),Idx_c(1)]=max(ErrVfy_c1);
% [Max_c(2),Idx_c(2)]=max(ErrVfy_c2);
% [Max_c(3),Idx_c(3)]=max(ErrVfy_c3);
% [Max_c(4),Idx_c(4)]=max(ErrVfy_c4);
% [Max_c(5),Idx_c(5)]=max(ErrVfy_c5);
% [Max_c(6),Idx_c(6)]=max(ErrVfy_c6);
% 
% disp('Verification Set:');
% disp('       AbsMax   |   AbsMean  |  RltMax   |   RltMean');
% disp([max(ErrVfy_c1),mean(ErrVfy_c1),max(ErrVfy_c1)/MaxTrqVfy(1),mean(ErrVfy_c1)/MaxTrqVfy(1)]);
% disp([max(ErrVfy_c2),mean(ErrVfy_c2),max(ErrVfy_c2)/MaxTrqVfy(2),mean(ErrVfy_c2)/MaxTrqVfy(2)]);
% disp([max(ErrVfy_c3),mean(ErrVfy_c3),max(ErrVfy_c3)/MaxTrqVfy(3),mean(ErrVfy_c3)/MaxTrqVfy(3)]);
% disp([max(ErrVfy_c4),mean(ErrVfy_c4),max(ErrVfy_c4)/MaxTrqVfy(4),mean(ErrVfy_c4)/MaxTrqVfy(4)]);
% disp([max(ErrVfy_c5),mean(ErrVfy_c5),max(ErrVfy_c5)/MaxTrqVfy(5),mean(ErrVfy_c5)/MaxTrqVfy(5)]);
% disp([max(ErrVfy_c6),mean(ErrVfy_c6),max(ErrVfy_c6)/MaxTrqVfy(6),mean(ErrVfy_c6)/MaxTrqVfy(6)]);

%%%%% Plot Comparison
% Nt = size(VfyTrq_c)/6;
% t=[0:1:Nt-1];
% for i=1:6
%     figure(i);
%     
%     plot(t,VfySynTrq(:,i),'b');
%     hold on;
%     plot(t,smooth(VfyTrq_c(i:6:end)),'r');
%     %plot(t,smooth(Frc_c(i:6:end)),'r');
%     %hold on;
%     %plot(Idx_c(i)-1,TrqVfy(Idx_c(i),i),'s','MarkerSize',10,'MarkerFaceColor','g',  'MarkerEdgeColor','k');
%     
%     hold off;
%     grid on;
% end


Nt = size(VfyTrq_c)/6;
t=[0:1:Nt-1];

figure(1);

plot(t,VfySynTrq(:,Idx),'b');
hold on;
plot(t,smooth(VfyTrq_c(Idx:6:end)),'r');
hold on;
%plot(Idx_c(i)-1,TrqVfy(Idx_c(i),i),'s','MarkerSize',10,'MarkerFaceColor','g',  'MarkerEdgeColor','k');

hold off;
grid on;






%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerCostFunM.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 25/6/2014
%
%@Function: EulerCostFunMA
%@Description: Cost function for finding optimal trajectory, considering motor. Only input acceleration, to obtain
%Vel and Pos by integral of acc
%@Input:
%X: [Acc1...AccN]
%@Output:
%Cost: cost
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Cost=EulerCostFunMA(X)

Scl = eye(60);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

N = size(X,1)/6;
Pos = zeros(N,6);
Vel = zeros(N,6);
Acc = zeros(N,6);
for i=1:N
    Acc(i,:) = X(6*(i-1)+1:6*i)';
end

DeltaT = 24*1e-3/2;
Vel(1,:)=[0,0,0,0,0,0];
for i=2:N
    Vel(i,:) = Vel(i-1,:) + (Acc(i-1,:) + Acc(i,:))/2*DeltaT;
end
Pos(1,:)=[0,0,0,0,pi/2,0];
for i=2:N
    Pos(i,:) = Pos(i-1,:) + (Vel(i-1,:) + Vel(i,:))/2*DeltaT;
end

Ld =[266 300 150 870 0 170 1016 174]/1000;
K = [1 1 1 1 1 1];
Wd_N = zeros(6*N,60+12);
Lamada1 = 2/5;
Lamada2 = 2/5;
Lamada3 = 1/5;
for i=1:N
    Wd_N((i-1)*6+1:6*i,1:60) = EulerWd(Ld,Pos(i,:),Vel(i,:),Acc(i,:))*Scl;
    %Wd_N((i-1)*6+1:6*i,61:66) = EulerWm(Ld,K,Pos(i,:),Vel(i,:),Acc(i,:));
%     Wd_N((i-1)*6+1:6*i,67:72) =[Vel(i,1)    0       0       0       0       0;
%       0         Vel(i,2)  0       0       0       0;
%       0         0       Vel(i,3)  0       0       0;
%       0         0       0       Vel(i,4)  0       0;
%       0         0       0       0       Vel(i,5)  0;
%       0         0       0       0       0       Vel(i,6)];
%     Wd_N((i-1)*6+1:6*i,73:78) =[sign(Vel(i,1))  0               0               0               0               0;
%       0             sign(Vel(i,2))    0               0               0               0;
%       0             0               sign(Vel(i,3))    0               0               0;
%       0             0               0               sign(Vel(i,4))    0               0;
%       0             0               0               0               sign(Vel(i,5))    0;
%       0             0               0               0               0               sign(Vel(i,6))];
   Wd_N((i-1)*6+1:6*i,61:66) =[Vel(i,1)    0       0       0       0       0;
      0         Vel(i,2)  0       0       0       0;
      0         0       Vel(i,3)  0       0       0;
      0         0       0       Vel(i,4)  0       0;
      0         0       0       0       Vel(i,5)  0;
      0         0       0       0       0       Vel(i,6)];
    Wd_N((i-1)*6+1:6*i,67:72) =[sign(Vel(i,1))  0               0               0               0               0;
      0             sign(Vel(i,2))    0               0               0               0;
      0             0               sign(Vel(i,3))    0               0               0;
      0             0               0               sign(Vel(i,4))    0               0;
      0             0               0               0               sign(Vel(i,5))    0;
      0             0               0               0               0               sign(Vel(i,6))]; 
end

[Q,R,P] = qr(Wd_N);
Tau = 6*N*(2.2204e-16)*R(1,1);
Num = size(find(diag(R)>Tau),1);
Q1 = Q(:,1:Num);
R1 = R(1:Num,1:Num);
W1 = Q1*R1;
S = svd(W1);
MaxS = max(S);
MinS = min(S);

W1_ = W1;
W1_(find(abs(W1_<1e-4))) = 0;
MinW = min(abs(W1_(find(W1_~=0))));
MaxW = max(max(abs(W1_)));

%Cost = Lamada1*MaxS/MinS + Lamada2/MinS + Lamada3*MaxW/MinW;
Cost = Lamada1*MaxS/MinS + Lamada2/MinS ;
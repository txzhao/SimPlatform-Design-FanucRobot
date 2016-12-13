%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: EulerCondM.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 25/6/2014
%
%@Function: EulerCondM
%@Description: Output Condition Number given specific trajectory
% Not consider motor effect
%@Input:
%X: [Pos1; Vel1; Acc1; Pos2; Vel2; Acc2;...;PosN; VelN; AccN]
%@Output:
%Cost: cost
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Cnd=EulerCond(X)

Scl = eye(60);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

N = round(size(X,1)/18);
Pos = zeros(N,6);
Vel = zeros(N,6);
Acc = zeros(N,6);
for i=1:N
    Pos(i,:) = X(18*(i-1)+1:18*(i-1)+6)';
    Vel(i,:) = X(18*(i-1)+7:18*(i-1)+12)';
    Acc(i,:) = X(18*(i-1)+13:18*i)';
end

Ld =[266 300 150 870 0 170 1016 174]/1000;
K = [1 1 1 1 1 1];
Wd_N = zeros(6*N,60+12);
Lamada1 = 2/5;
Lamada2 = 2/5;
Lamada3 = 1/5;
for i=1:N
    Wd_N((i-1)*6+1:6*i,1:60) = EulerWd(Ld,Pos(i,:),Vel(i,:),Acc(i,:))*Scl;
    
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

Cnd = MaxS/MinS;
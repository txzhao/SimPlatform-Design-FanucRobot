%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: inv_kin.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 21/01/2014
%
%@Function: inv_kin
%@Description: Inverse Kinematic Calculation
%@Input:
%gd: desired g
%Ksi: Ksi parameter of manipulator
%@Output:
%theta: solution
%Num: the number of solutions
function [theta,Num] = inv_kin(gd,Ksi)
theta = zeros(6,4);% at most 4 pairs of solution
Num=0;

Min1 = -165; Max1 = 165;
Min2 = -100; Max2 = 100;
Min3 = -165 ; Max3 = 165;
Min4 = -200; Max4 = 200;
Min5 = -140; Max5 = 140;
Min6 = -360; Max6 = 360;

%%%%%%%%%%%%%%%%%
v1 = Ksi(1:3,1);
w1 = Ksi(4:6,1);
q1 = cross(w1,v1);

v2 = Ksi(1:3,2);
w2 = Ksi(4:6,2);
q2 = cross(w2,v2);

v3 = Ksi(1:3,3);
w3 = Ksi(4:6,3);
q3 = cross(w3,v3);

v4 = Ksi(1:3,4);
w4 = Ksi(4:6,4);
q4 = cross(w4,v4);

v5 = Ksi(1:3,5);
w5 = Ksi(4:6,5);
q5 = cross(w5,v5);

v6 = Ksi(1:3,6);
w6 = Ksi(4:6,6);
q6 = cross(w6,v6);

q7 = q6 + 10*w6;

gst0 = expg(Ksi(:,7),1);


% %% Calculate pw %%%%%%%%
wt=[w6,w5];
qt=q5-q6;
t =inv(wt'*wt)*wt'*qt;
pw = q6 + t(1)*w6;

%%%%%%%%%%%%%%%%%
pw = [pw;1];
q1 = [q1;1];
q2 = [q2;1];
q3 = [q3;1];
q4 = [q4;1];
q5 = [q5;1];
q6 = [q6;1];
q7 = [q7;1];
%%%%%%%%%%%%%%%%%
% gd*inv(gst0)   
g1 = gd/gst0;       

% select pw on w4, w5, w6
p1  = g1*pw;

theta_1 = atan2(p1(1)*w2(1)+p1(2)*w2(2),p1(1)*w2(2)-p1(2)*w2(1))-asin(pw(2)/norm(p1(1:2))); % have and only have one solution
%theta_1 = atan2(p1(1)*w2(1)+p1(2)*w2(2),p1(1)*w2(2)-p1(2)*w2(1));
if isInRange(theta_1,Min1,Max1)==0
    %disp('Cannot find appropriate theta_1');
    return;
end

% select q2 on w2, subproblem3
p2 = double(expg(-Ksi(:,1),theta_1)*p1);

d =  p2 - q2;
[theta_3,Num_3] = subPro3(Ksi(:,3),pw,q2,d); % at most 2 solutions
if any(isInRange(theta_3,Min3,Max3)==1)==0
    %disp('Cannot find appropriate theta_3');
    return;
end

% 

for c3 =1:Num_3
    if isInRange(theta_3(c3),Min3,Max3)==1        
        p3 = double(expg(Ksi(:,3),theta_3(c3))*pw);
        [theta_2,Num_2] = subPro1(Ksi(:,2),p3,p2); % only one solution
        if isInRange(theta_2,Min2,Max2)==0
            %disp('Cannot find appropriate theta_2');
            return;
        end
        
        if Num_2==1
            g2 =double( expg(-Ksi(:,3),theta_3(c3))*expg(-Ksi(:,2),theta_2)*expg(-Ksi(:,1),theta_1)*g1);

            %select q7 on w6 and not on w5
            p4 = g2*q7;
            [theta_4,theta_5,Num_45] = subPro2(Ksi(:,4),Ksi(:,5),q7,p4); % at most 2 pairs of solution
            if any(isInRange(theta_5,Min5,Max5)==1)==0
                %disp('Cannot find appropriate theta_5');
                return;
            end

            for c45=1:Num_45
                if isInRange(theta_5(c45),Min5,Max5)==1
                    g3 = double(expg(-Ksi(:,5),theta_5(c45))*expg(-Ksi(:,4),theta_4(c45))*g2);
                    %selcet q3
                    p5=g3*q3;
                    [theta_6,Num_6] = subPro1(Ksi(:,6),q3,p5); % only one solution
                    
                    if Num_6==1
                        Num = Num +1;
                        theta(:,Num) = [theta_1,theta_2,theta_3(c3),theta_4(c45),theta_5(c45),theta_6]';
                    end
                    
                end
            end
        end
    end

end
 
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function isIn = isInRange(x,xmin,xmax)
    x = x/pi*180;
    isIn = (x>=xmin & x <=xmax);
end
 

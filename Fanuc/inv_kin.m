function [theta,Num] = inv_kin(gd,L)
theta = zeros(6,4);% at most 4 pairs of solution
Num=0;

Min1 = -165; Max1 = 165;
Min2 = -150; Max2 = 60;
Min3 = -210 ; Max3 = 90;
Min4 = -180; Max4 = 180;
Min5 = -140; Max5 = 140;
Min6 = -180; Max6 = 180;

L1 = L(1);
L2 = L(2);
L3 = L(3);
L4 = L(4);
L5 = L(5);
L6 = L(6);
L7 = L(7);
L8 = L(8);
L9 = L(9);

s_origin = [0;0;0];
w_x = [1;0;0];
w_y = [0;1;0];
w_z = [0;0;1];

w1 = w_z;
q1 = s_origin;
kx1 = [-cross(w1,q1);w1];

w2 = w_y;
q2 = [L2;0;L1];
kx2 = [-cross(w2,q2);w2];

w3 = w_y;
q3 = [L2;0;L1+L3];
kx3 = [-cross(w3,q3);w3];

pw = [L2+L5;0;L1+L3+L4];

w4 = w_x;
q4 = pw;
kx4 = [-cross(w4,q4);w4];

w5 = w_y;
q5 = pw;
kx5 = [-cross(w5,q5);w5];

w6 = w_x;
q6 = pw;
kx6 = [-cross(w6,q6);w6];

q7 = [L2+L5+L6;0;L1+L3+L4];

q1 = [q1;1];
q2 = [q2;1];
q3 = [q3;1];
q4 = [q4;1];
q5 = [q5;1];
q6 = [q6;1];
q7 = [q7;1];
pw = [pw;1];


gst0 = [1,0,0,L2+L5+L6+L7; 0,1,0,L8;0,0,1,L1+L3+L4+L9;0,0,0,1];
    
if all(size(gd) == [4,4])
   g1 = gd/gst0;       % gd*inv(gst0)
elseif all(size(gd) == [4,1])
   p0 = gst0(1:3,4);
   pd = gd(1:3);
   w = cross(p0,pd);
   w = w/norm(w);
   ang = acos( (p0'*pd)/(norm(p0)*norm(pd)) );
        
   R = double(expRot(w,ang));
   q = pd - R*p0;
   
   g1 = [R q; zeros(1,3) 1];
end

% select pw = [L2+L5;0;L1+L3+L4]
p1  = g1*pw;
theta_1 = atan2(p1(2),p1(1)); % only one solution
if isInRange(theta_1,Min1,Max1)==0
    %disp('Cannot find appropriate theta_1');
    return;
end

% select q2 = [L2;0;L1], subproblem3
p2 = double(expWre(-kx1,theta_1)*p1);
d =  p2 - q2;
[theta_3,Num_3] = subPro3(kx3,pw,q2,d); % at most 2 solutions
if any(isInRange(theta_3,Min3,Max3)==1)==0
    %disp('Cannot find appropriate theta_3');
    return;
end

% 

for c3 =1:Num_3
    if isInRange(theta_3(c3),Min3,Max3)==1        
        p3 = double(expWre(kx3,theta_3(c3))*pw);
        theta_2 = subPro1(kx2,p3,p2); % only one solution
        if isInRange(theta_2,Min2,Max2)==0
            %disp('Cannot find appropriate theta_2');
            return;
        end

        g2 =double( expWre(-kx3,theta_3(c3))*expWre(-kx2,theta_2)*expWre(-kx1,theta_1)*g1);

        %select q7
        p4 = g2*q7;
        [theta_4,theta_5,Num_45] = subPro2(kx4,kx5,q7,p4); % at most 2 pairs of solution
        
        if any(isInRange(theta_5,Min5,Max5)==1)==0
            %disp('Cannot find appropriate theta_5');
            return;
        end
        
        for c45=1:Num_45
            if isInRange(theta_5(c45),Min5,Max5)==1
                g3 = double(expWre(-kx5,theta_5(c45))*expWre(-kx4,theta_4(c45))*g2);
                %selcet q3
                p5=g3*q3;
                theta_6 = subPro1(kx6,q3,p5); % only one solution

                Num = Num +1;
                theta(:,Num) = [theta_1,theta_2,theta_3(c3),theta_4(c45),theta_5(c45),theta_6]';
            end
        end
    end

end
% check range
%disp(theta*180/pi);  
 
end

function isIn = isInRange(x,xmin,xmax)
    x = x/pi*180;
    isIn = (x>=xmin & x <=xmax);
end
 

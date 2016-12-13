% Input: Rotation Matrix
% Output: Rotated Aixs and angle
function [w,theta] = logr(R)
% Ref: Li PPT-1-17
t = trace(R);

if t==3
    w = [0;0;0];
    theta = 0;
elseif t==-1 
    theta = pi;
    if R(1,1)==1
        w = [1;0;0];
    elseif R(2,2)==1
        w = [0;1;0];
    else
        w = [0;0;1];
    end
else
    theta = acos((t-1)/2);
    if theta<eps
        w = [0;0;0];
        theta = 0;
    else
        w = [R(3,2)-R(2,3);R(1,3)-R(3,1);R(2,1)-R(1,2)]/(2*sin(theta));
    end
    
end
function [xi,theta] = logg(g)
R = g(1:3,1:3);
P = g(1:3,4);

[w,theta] = logr(R);
if theta<eps
    theta = norm(P);
    if theta<eps
        v = [0;0;0];
    else
        v = P/theta;
    end
else
    % ??? How do you derive it ??
    invA = eye(3)/theta - hat(w)/2 + hat(w)^2*(2*sin(theta)-theta*(1+cos(theta)))/(2*theta*sin(theta));
    v=invA*P;
    %A=(eye(3)-R)*hat(w)+w*w'*theta;  
    %v = inv(A)*P;
end
xi = [v;w];
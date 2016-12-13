function g = expg(xi,theta)
v = xi(1:3);
w = xi(4:6);
n = norm(w);

if n<eps
    R = eye(3);
    P = v*theta;
else
    theta = theta*n;
    w = w/n;
    v = v/n;
    R = expr(w,theta);
    P = (eye(3)-R)*hat(w)*v + w*w'*theta*v;
end

g = [R,             P;
     zeros(1,3),    1];
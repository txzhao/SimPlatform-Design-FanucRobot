function R = expr(w,theta)
n = norm(w);

if n<eps
    R = eye(3);
else
    %theta = theta*n;
    %w = w/n;
    R = eye(3) + hat(w)/n*sin(n*theta) + hat(w)^2/n^2*(1-cos(n*theta));
end
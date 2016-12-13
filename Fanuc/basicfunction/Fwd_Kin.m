function g = Fwd_Kin(xi,theta)
n = size(xi,2);

g = eye(4);
for i=1:n
    g = g * expg(xi(:,i),theta(i));
end
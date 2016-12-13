function adx = ad(xi)
w = xi(4:6);
v = xi(1:3);

adx = [hat(w),      hat(v);
       zeros(3,3),  hat(w)];

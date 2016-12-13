function adx = ads(xi)
w = xi(4:6);
v = xi(1:3);

adx = [skew(w),      skew(v);
       zeros(3,3),  skew(w)];

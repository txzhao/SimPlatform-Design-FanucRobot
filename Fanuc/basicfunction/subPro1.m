function [theta,Num] = subPro1(kx, p, q)
    theta=0;

    velociy = kx(1:3);
    w = kx(4:6); % rotation axis
    r = -cross(velociy,w);
    
    u = p(1:3) - r;
    v = q(1:3) - r;
    
    
    up = u - w*(w'*u);
    vp = v - w*(w'*v);

    MyZero=1e-5;
    Dnorm=abs(norm(up)-norm(vp));
    Ddot = abs(w'*u-w'*v);
    if Dnorm< MyZero && Ddot<MyZero
    
        theta = atan2(w'*(cross(up,vp)),up'*vp);
        Num=1;
    else
        Num=0;
    end
end
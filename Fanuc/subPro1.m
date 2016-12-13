function theta = subPro1(kx, p, q)


    velociy = kx(1:3);
    w = kx(4:6); % rotation axis
    r = -cross(velociy,w);
    
    u = p(1:3) - r;
    v = q(1:3) - r;
    
    
    up = u - w*(w'*u);
    vp = v - w*(w'*u);

%     if norm(up) == 0
%         error('SubPro1: up = 0, Infinite number of solutions!');
%     end

    theta = atan2(w'*(cross(up,vp)),up'*vp);
	
end
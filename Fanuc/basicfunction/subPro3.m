function [theta,Nsol] = subPro3(kx, p ,q, d )
    theta = zeros(2,1);
    p = p(1:3);     % col vector
    q = q(1:3);     % col vector
    d = d(1:3);     % col vector.

    velociy = kx(1:3);  
    w = kx(4:6);        % rotation axis
    r = -cross(velociy,w);
    
    u = p - r;
    v = q - r;
    
    up = u - w*(w'*u);
    vp = v - w*(w'*v);

    dp2 = d'*d - (w'*(p-q))^2;
    
    theta0 = atan2(w'*(cross(up,vp)),up'*vp);
    
    CheckCos=(up'*up + vp'*vp - dp2)/(2*norm(up)*norm(vp));
    if CheckCos<=1 && CheckCos>=-1
        phi = acos( CheckCos );

        theta(1) = theta0 - phi;
        theta(2) = theta0 + phi;


        if phi ~= 0
            Nsol = 2;
        else
    %         theta = theta0;
            Nsol = 1;
        end
    else
        Nsol = 0;
    end
        
end

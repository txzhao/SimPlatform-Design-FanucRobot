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

    phi = acos( (up'*up + vp'*vp - dp2)/(2*norm(up)*norm(vp)) );
    
    theta(1) = theta0 - phi;
    theta(2) = theta0 + phi;
    
%     check1 = (sol1 >= -45/180*pi) && (sol1 <= 115/180*pi);
%     check2 = (sol2 >= -45/180*pi) && (sol2 <= 115/180*pi);
%     
%     if check1 && check2
%         
%         if abs(sol1) > abs(sol2)
%             theta = sol2;
%         else
%             theta = sol1;
%         end
%         
%     elseif check1
%         theta = sol1;
%     elseif check2
%         theta = sol2;
%     end 
%     Nsol = check1+check2;

    if phi ~= 0
        Nsol = 2;
    else
%         theta = theta0;
        Nsol = 1;
    end
        
end

function iAd = intAd(xi,theta)
v = xi(1:3);
w = xi(4:6);
n = norm(w);

if n<eps
    iR = eye(3);
    iP = hat(v)*theta/2;
else
    theta = theta*n;
    w = w/n;
    v = v/n;
    
    % integral of R
    iR = eye(3) + hat(w)*(1-cos(theta))/theta + hat(w)^2*(1-sin(theta)/theta);
    
    % integral of hat(P)*R
    % it's the sum of 3 parts
    wv = hat(hat(w)*v);
    PA = wv*iR;
    PB = iR*wv;
    PC = eye(3) + hat(w)*(sin(theta)-cos(theta)*theta)/(theta^2) + hat(w)^2*( 1/2 - (sin(theta)*theta+cos(theta)-1)/(theta^2) );
    PC = hat(w*w'*v*theta)*PC;
    iP = PA-PB+PC;
end

iAd = [ iR,           iP;
        zeros(3,3),   iR];
    
    
    
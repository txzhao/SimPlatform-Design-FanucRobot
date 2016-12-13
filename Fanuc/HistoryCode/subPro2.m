function [theta1, theta2, Nsol] = subPro2(kx1, kx2, p ,q )

    theta1 = zeros(2,1);
    theta2= zeros(2,1);
    % ============================================= %    
    % Twist 2 is the one that rotation happens first
    % ============================================= %
    
    velociy1 = kx1(1:3); 
    w1 = kx1(4:6); % rotation axis for twist1
    r1 = -cross(velociy1,w1); % one point in w1 axis
    
    velociy2 = kx2(1:3);
    w2 = kx2(4:6); % rotation axis for twist2
    r2 = -cross(velociy2,w2); % one point in w2 axis

    %find the common point of two axis
    r = findCommon(w1,w2,r1,r2);
    
    u = p(1:3) - r;
    v = q(1:3) - r;
    
    alpha = ((w1'*w2)*w2'*u - w1'*v)/((w1'*w2)*(w1'*w2)-1);
    beta  = ((w1'*w2)*w1'*v - w2'*u)/((w1'*w2)*(w1'*w2)-1);
    
    ySqu = (u'*u - alpha*alpha - beta*beta - 2*beta*alpha*w1'*w2)/((cross(w1,w2))'*(cross(w1,w2)));
 
    if ySqu > 0
        Nsol = 2;
    elseif ySqu == 0
        Nsol = 1;
    else
        Nsol = 0;
    end

    if ySqu>=0
    for i =1:2
        
        y = (2*i-3)*sqrt(ySqu); % could have two solutions in this step

        z = alpha*w1 + beta*w2 - y*cross(w1,w2);

        c = z + r; % the common point in the rotation if there are solutions

        theta2(i) = subPro1(kx2,p,c);
        theta1(i) = subPro1(kx1,c,q);
    end
    end
    
    
end


function r = findCommon(w1,w2,r1,r2)
    
    A = [w1(1) -w2(1) ; w1(2) -w2(2)];
    vec = [r2(1)-r1(1) r2(2)-r1(2)]';
    
    if (det(A)==0) % if the first two set of para are parallel
        A = [w1(1) -w2(1) ; w1(3) -w2(3)];
        vec = [r2(1)-r1(1) r2(3)-r1(3)]';
    end
    
    if (det(A)==0)
        A = [w1(2) -w2(2) ; w1(3) -w2(3)];
        vec = [r2(2)-r1(2) r2(3)-r1(3)]';
    end
    
    cof = A\vec; % get the inverse
    
    r = r1 + w1*cof(1);
    
end
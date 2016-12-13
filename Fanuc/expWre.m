% exponential of the wrench 

function g = expWre(kx,theta) 

     if(length(kx) ~=6)
        error('Length of kx must be 6');
     end   
    
    v = kx(1:3);
    w = kx(4:6); 
    
    if(w(1)==0 && w(2)==0 && w(3)==0)
        R = eye(3);
        p = v*theta;
    else
        R = expRot(w,theta);
        p = (eye(3) - R)*cross(w,v)+w*w'*v*theta;
    end
    g = [R,p;zeros(1,3),1];

end

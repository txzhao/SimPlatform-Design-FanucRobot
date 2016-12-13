% exponential of the skew matrix

function R = expRot(w,theta)

%     if(norm(w)~=1)
%         error('Norm of w must be 1');
%     end
    
    wh = skew(w);
    R = eye(3)+wh*sin(theta)+wh*wh*(1-cos(theta));
    
end




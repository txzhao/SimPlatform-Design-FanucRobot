function wh = skew(w)

    if(length(w) ~=3)
        error('Length of w must be 3');
    end
    
%     wh = diag(sym('wh',[1,3]));
%     %wh=zeros(3);
%     wh(1,1) = 0;
%     wh(2,2) = 0;
%     wh(3,3) = 0;
%     
%     
%     wh(1,2) = -w(3);
%     wh(1,3) = w(2);
%     wh(2,1) = w(3);
%     wh(2,3) = -w(1);
%     wh(3,1) = -w(2);
%     wh(3,2) = w(1);
    wh = [0     -w(3)   w(2);
          w(3)  0       -w(1);
          -w(2) w(1)    0];
end
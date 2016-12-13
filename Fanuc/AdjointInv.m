function Adg_inv = AdjointInv(g)

    if( any(size(g) ~= [4 4]) )
        error('The size of g must be 4x4');
    end
    
    RT = g(1:3,1:3).';
    p = g(1:3,4);
    ze = zeros(3);
    Adg_inv = [RT, -RT*skew(p);
               ze,  RT];
    %Adg_inv(4:6,4:6) = RT;
    
end
function Adg = Adj(g)
% Adjoint transformation matrix Adg of transform g
R = g(1:3,1:3);
P = g(1:3,4);
P_hat = hat(P);

Adg = [ R,              P_hat*R;
        zeros(3,3),     R];
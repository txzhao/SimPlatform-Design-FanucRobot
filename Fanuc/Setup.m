% close all;
% clear all;
clc;


%%
% L1~L6: length of link
% A1~A6: angle of joint
% L7~L9: relative coordinate based on frame attached on the 6th joint,
% default values are 0
syms L1 L2 L3 L4 L5 L6  
syms A1 A2 A3 A4 A5 A6
syms L7 L8 L9
syms EL1 EL2
 


s_origin = [0;0;0];
w_x = [1;0;0];
w_y = [0;1;0];
w_z = [0;0;1];
L = [L1 L2 L3 L4 L5 L6 L7 L8 L9];
A = [A1 A2 A3 A4 A5 A6];

w1 = w_z;
q1 = s_origin;
kx1 = [-cross(w1,q1);w1];

w2 = w_y;
q2 = [L2;0;L1];
kx2 = [-cross(w2,q2);w2];

w3 = w_y;
q3 = [L2;0;L1+L3];
kx3 = [-cross(w3,q3);w3];

pw = [L2+L5;0;L1+L3+L4];

w4 = w_x;
q4 = pw;
kx4 = [-cross(w4,q4);w4];

w5 = w_y;
q5 = pw;
kx5 = [-cross(w5,q5);w5];

w6 = w_x;
q6 = pw;
kx6 = [-cross(w6,q6);w6];

g1 = expWre(kx1,A1);
g2 = expWre(kx2,A2);
g3 = expWre(kx3,A3);
g4 = expWre(kx4,A4);
g5 = expWre(kx5,A5);
g6 = expWre(kx6,A6);

%% forward kinemactic for end effector 
% 
% gst0 = diag(sym('gst0_',[1 4]));
% gst0(1:3,1:3) = eye(3);
% gst0(1:3,4) = [L2+L5+L6+L7; L8; L1+L3+L4+L9];
% gst0(4,4) = 1;
% gst = g1*g2*g3*g4*g5*g6*gst0;
% gst = simplify(gst);
% fwd_kin = matlabFunction(gst,'file','fwd_kin','vars',{L,A});
% 
% %% forward kinematic for other joints, in order to draw dynamic figure
% gst10 = diag(sym('gst10_',[1 4]));
% gst10(1:3,1:3) = eye(3);
% gst10(1:3,4) = [L2; 0; L1];
% gst10(4,4) = 1;
% gst1 = g1*gst10;
% gst1 = simplify(gst1);
% fwd_kin1 = matlabFunction(gst1,'file','fwd_kin1','vars',{L,A});
% 
% gst20 = diag(sym('gst20_',[1 4]));
% gst20(1:3,1:3) = eye(3);
% gst20(1:3,4) = [L2; 0; L1+L3];
% gst20(4,4) = 1;
% gst2 = g1*g2*gst20;
% gst2 = simplify(gst2);
% fwd_kin2 = matlabFunction(gst2,'file','fwd_kin2','vars',{L,A});
% 
% gst30 = diag(sym('gst30_',[1 4]));
% gst30(1:3,1:3) = eye(3);
% gst30(1:3,4) = [L2; 0; L1+L3+L4];
% gst30(4,4) = 1;
% gst3 = g1*g2*g3*gst30;
% gst3 = simplify(gst3);
% fwd_kin3 = matlabFunction(gst3,'file','fwd_kin3','vars',{L,A});
% 
% gst40 = diag(sym('gst10_',[1 4]));
% gst40(1:3,1:3) = eye(3);
% gst40(1:3,4) = [L2+L5; 0; L1+L3+L4];
% gst40(4,4) = 1;
% gst4 = g1*g2*g3*g4*gst40;
% gst4 = simplify(gst4);
% fwd_kin4 = matlabFunction(gst4,'file','fwd_kin4','vars',{L,A});
% 
% gst50 = diag(sym('gst50_',[1 4]));
% gst50(1:3,1:3) = eye(3);
% gst50(1:3,4) = [L2+L5+L6; 0; L1+L3+L4];
% gst50(4,4) = 1;
% gst5 = g1*g2*g3*g4*g5*gst50;
% gst5 = simplify(gst5);
% fwd_kin5 = matlabFunction(gst5,'file','fwd_kin5','vars',{L,A});


%% Derive Spatial Jocobian



% Adg1_1 = Adjoint(g1);
% Adg1_2 = simplify(Adg1_1*Adjoint(g2));
% Adg1_3 = simplify(Adg1_2*Adjoint(g3));
% Adg1_4 = simplify(Adg1_3*Adjoint(g4));
% Adg1_5 = simplify(Adg1_4*Adjoint(g5));
% 
% kx1_p = kx1;
% kx2_p = simplify(Adg1_1*kx2);
% kx3_p = simplify(Adg1_2*kx3);
% kx4_p = simplify(Adg1_3*kx4);
% kx5_p = simplify(Adg1_4*kx5);
% kx6_p = simplify(Adg1_5*kx6);
% 
% spat_Jacobian_ = simplify([kx1_p kx2_p kx3_p kx4_p kx5_p kx6_p]);

%spat_Jacobian = matlabFunction(spat_Jacobian_,'file','spat_Jacobian','vars',{L,A});

% 
% %% Derive Body Jocobian
% 
% gst0 = diag(sym('gst0_',[1 4]));
% gst0(1:3,1:3) = eye(3);
% gst0(1:3,4) = [L2+L5+L6+L7; L8; L1+L3+L4+L9];
% gst0(4,4) = 1;
% 
% AdInvgst0 = AdjointInv(gst0);
% AdInvg6_6 = simplify(AdInvgst0*AdjointInv(g6));
% AdInvg5_6 = simplify(AdInvg6_6*AdjointInv(g5));
% AdInvg4_6 = simplify(AdInvg5_6*AdjointInv(g4));
% AdInvg3_6 = simplify(AdInvg4_6*AdjointInv(g3));
% AdInvg2_6 = simplify(AdInvg3_6*AdjointInv(g2));
% AdInvg1_6 = simplify(AdInvg2_6*AdjointInv(g1));
% 
% 
% kx1_j = simplify(AdInvg1_6*kx1);
% kx2_j = simplify(AdInvg2_6*kx2);
% kx3_j = simplify(AdInvg3_6*kx3);
% kx4_j = simplify(AdInvg4_6*kx4);
% kx5_j = simplify(AdInvg5_6*kx5);
% kx6_j = simplify(AdInvg6_6*kx6);
% 
% 
% body_Jacobian = simplify([kx1_j kx2_j kx3_j kx4_j kx5_j kx6_j]);
% 
% body_Jacobian = matlabFunction(body_Jacobian,'file','body_Jacobian','vars',{L,A});

%% inverse of spatial jacobian
% inv_spat_J_ = inv(spat_Jacobian_);
% inv_spat_J  = matlabFunction(inv_spat_J_,'file','inv_spat_J','vars',{L,A});

%% derivative of inv(spatial jacobian) respect to different theta
% d_inv_SJ_1_ = diff(inv_spat_J_,A1);
% d_inv_SJ_2_ = diff(inv_spat_J_,A2);
% d_inv_SJ_3_ = diff(inv_spat_J_,A3);
% d_inv_SJ_4_ = diff(inv_spat_J_,A4);
% d_inv_SJ_5_ = diff(inv_spat_J_,A5);
% d_inv_SJ_6_ = diff(inv_spat_J_,A6);
% 
% d_inv_SJ_1  = matlabFunction(d_inv_SJ_1_,'file','d_inv_SJ_1','vars',{L,A});
% d_inv_SJ_2  = matlabFunction(d_inv_SJ_2_,'file','d_inv_SJ_2','vars',{L,A});
% d_inv_SJ_3  = matlabFunction(d_inv_SJ_3_,'file','d_inv_SJ_3','vars',{L,A});
% d_inv_SJ_4  = matlabFunction(d_inv_SJ_4_,'file','d_inv_SJ_4','vars',{L,A});
% d_inv_SJ_5  = matlabFunction(d_inv_SJ_5_,'file','d_inv_SJ_5','vars',{L,A});
% d_inv_SJ_6  = matlabFunction(d_inv_SJ_6_,'file','d_inv_SJ_6','vars',{L,A});



%% Derive Body Jacobian for Dynamic
syms Cx1 Cx2 Cx3 Cx4 Cx5 Cx6
syms Cy1 Cy2 Cy3 Cy4 Cy5 Cy6
syms Cz1 Cz2 Cz3 Cz4 Cz5 Cz6

Cen = [Cx1 Cx2 Cx3 Cx4 Cx5 Cx6 Cy1 Cy2 Cy3 Cy4 Cy5 Cy6 Cz1 Cz2 Cz3 Cz4 Cz5 Cz6];

q1_d = [Cx1;Cy1;Cz1];
q2_d = [Cx2;Cy2;Cz2];
q3_d = [Cx3;Cy3;Cz3];
q4_d = [Cx4;Cy4;Cz4];
q5_d = [Cx5;Cy5;Cz5];
q6_d = [Cx6;Cy6;Cz6];

kx1_d = kx1;
kx2_d = kx2;
kx3_d = kx3;
kx4_d = kx4;
kx5_d = kx5;
kx6_d = kx6;
g1_d = g1;
g2_d = g2;
g3_d = g3;
g4_d = g4;
g5_d = g5;
g6_d = g6;

gst10_d = diag(sym('gst10_d_',[1 4]));
gst10_d(1:3,1:3) = eye(3);
gst10_d(1:3,4) = q1_d;
gst10_d(4,4) = 1;

gst20_d = diag(sym('gst20_d_',[1 4]));
gst20_d(1:3,1:3) = eye(3);
gst20_d(1:3,4) = q2_d;
gst20_d(4,4) = 1;

gst30_d = diag(sym('gst30_d_',[1 4]));
gst30_d(1:3,1:3) = eye(3);
gst30_d(1:3,4) = q3_d;
gst30_d(4,4) = 1;

gst40_d = diag(sym('gst40_d_',[1 4]));
gst40_d(1:3,1:3) = eye(3);
gst40_d(1:3,4) = q4_d;
gst40_d(4,4) = 1;

gst50_d = diag(sym('gst50_d_',[1 4]));
gst50_d(1:3,1:3) = eye(3);
gst50_d(1:3,4) = q5_d;
gst50_d(4,4) = 1;

gst60_d = diag(sym('gst60_d_',[1 4]));
gst60_d(1:3,1:3) = eye(3);
gst60_d(1:3,4) = q6_d;
gst60_d(4,4) = 1;


AdInvgst0 = AdjointInv(gst60_d);
AdInvg6_6 =  (AdInvgst0*AdjointInv(g6_d));
AdInvg5_6 =  (AdInvg6_6*AdjointInv(g5_d));
AdInvg4_6 =  (AdInvg5_6*AdjointInv(g4_d));
AdInvg3_6 =  (AdInvg4_6*AdjointInv(g3_d));
AdInvg2_6 =  (AdInvg3_6*AdjointInv(g2_d));
AdInvg1_6 =  (AdInvg2_6*AdjointInv(g1_d));


kx1_j =  (AdInvg1_6*kx1_d);
kx2_j =  (AdInvg2_6*kx2_d);
kx3_j =  (AdInvg3_6*kx3_d);
kx4_j =  (AdInvg4_6*kx4_d);
kx5_j =  (AdInvg5_6*kx5_d);
kx6_j =  (AdInvg6_6*kx6_d);

body_Jacobian_d6_ = [kx1_j kx2_j kx3_j kx4_j kx5_j kx6_j];
body_Jacobian_d6 = matlabFunction(body_Jacobian_d6_,'file','body_Jacobian_d6','vars',{L,A,Cen});
disp('Finish jacobian 6');

AdInvgst0 = AdjointInv(gst50_d);
AdInvg5_5 =  (AdInvgst0*AdjointInv(g5_d));
AdInvg4_5 =  (AdInvg5_5*AdjointInv(g4_d));
AdInvg3_5 =  (AdInvg4_5*AdjointInv(g3_d));
AdInvg2_5 =  (AdInvg3_5*AdjointInv(g2_d));
AdInvg1_5 =  (AdInvg2_5*AdjointInv(g1_d));

kx1_j =  (AdInvg1_5*kx1_d);
kx2_j =  (AdInvg2_5*kx2_d);
kx3_j =  (AdInvg3_5*kx3_d);
kx4_j =  (AdInvg4_5*kx4_d);
kx5_j =  (AdInvg5_5*kx5_d);
kx6_j = [0;0;0;0;0;0];

body_Jacobian_d5_ = [kx1_j kx2_j kx3_j kx4_j kx5_j kx6_j];
body_Jacobian_d5 = matlabFunction(body_Jacobian_d5_,'file','body_Jacobian_d5','vars',{L,A,Cen});
disp('Finish jacobian 5');

AdInvgst0 = AdjointInv(gst40_d);
AdInvg4_4 =  (AdInvgst0*AdjointInv(g4_d));
AdInvg3_4 =  (AdInvg4_4*AdjointInv(g3_d));
AdInvg2_4 =  (AdInvg3_4*AdjointInv(g2_d));
AdInvg1_4 =  (AdInvg2_4*AdjointInv(g1_d));

kx1_j =  (AdInvg1_4*kx1_d);
kx2_j =  (AdInvg2_4*kx2_d);
kx3_j =  (AdInvg3_4*kx3_d);
kx4_j =  (AdInvg4_4*kx4_d);
kx5_j = [0;0;0;0;0;0];
kx6_j = [0;0;0;0;0;0];

body_Jacobian_d4_ = [kx1_j kx2_j kx3_j kx4_j kx5_j kx6_j];
body_Jacobian_d4 = matlabFunction(body_Jacobian_d4_,'file','body_Jacobian_d4','vars',{L,A,Cen});
disp('Finish jacobian 4');

AdInvgst0 = AdjointInv(gst30_d);
AdInvg3_3 =  (AdInvgst0*AdjointInv(g3_d));
AdInvg2_3 =  (AdInvg3_3*AdjointInv(g2_d));
AdInvg1_3 =  (AdInvg2_3*AdjointInv(g1_d));

kx1_j =  (AdInvg1_3*kx1_d);
kx2_j =  (AdInvg2_3*kx2_d);
kx3_j =  (AdInvg3_3*kx3_d);
kx4_j = [0;0;0;0;0;0];
kx5_j = [0;0;0;0;0;0];
kx6_j = [0;0;0;0;0;0];

body_Jacobian_d3_ = [kx1_j kx2_j kx3_j kx4_j kx5_j kx6_j];
body_Jacobian_d3 = matlabFunction(body_Jacobian_d3_,'file','body_Jacobian_d3','vars',{L,A,Cen});
disp('Finish jacobian 3');

AdInvgst0 = AdjointInv(gst20_d);
AdInvg2_2 =  (AdInvgst0*AdjointInv(g2_d));
AdInvg1_2 =  (AdInvg2_2*AdjointInv(g1_d));

kx1_j =  (AdInvg1_2*kx1_d);
kx2_j =  (AdInvg2_2*kx2_d);
kx3_j = [0;0;0;0;0;0];
kx4_j = [0;0;0;0;0;0];
kx5_j = [0;0;0;0;0;0];
kx6_j = [0;0;0;0;0;0];

body_Jacobian_d2_ = [kx1_j kx2_j kx3_j kx4_j kx5_j kx6_j];
body_Jacobian_d2 = matlabFunction(body_Jacobian_d2_,'file','body_Jacobian_d2','vars',{L,A,Cen});
disp('Finish jacobian 2');

AdInvgst0 = AdjointInv(gst10_d);
AdInvg1_1 =  (AdInvgst0 *AdjointInv(g1_d));

kx1_j =  (AdInvg1_1*kx1_d);
kx2_j = [0;0;0;0;0;0];
kx3_j = [0;0;0;0;0;0];
kx4_j = [0;0;0;0;0;0];
kx5_j = [0;0;0;0;0;0];
kx6_j = [0;0;0;0;0;0];

body_Jacobian_d1_ = [kx1_j kx2_j kx3_j kx4_j kx5_j kx6_j];
body_Jacobian_d1 = matlabFunction(body_Jacobian_d1_,'file','body_Jacobian_d1','vars',{L,A,Cen});
disp('Finish jacobian 1');

%% derive M(theta)
syms Ma1 Ma2 Ma3 Ma4 Ma5 Ma6 
syms I1_11 I1_12 I1_13 I1_21 I1_22 I1_23 I1_31 I1_32 I1_33 
syms I2_11 I2_12 I2_13 I2_21 I2_22 I2_23 I2_31 I2_32 I2_33 
syms I3_11 I3_12 I3_13 I3_21 I3_22 I3_23 I3_31 I3_32 I3_33 
syms I4_11 I4_12 I4_13 I4_21 I4_22 I4_23 I4_31 I4_32 I4_33 
syms I5_11 I5_12 I5_13 I5_21 I5_22 I5_23 I5_31 I5_32 I5_33 
syms I6_11 I6_12 I6_13 I6_21 I6_22 I6_23 I6_31 I6_32 I6_33 

M1=[Ma1 0   0   0       0      0;
    0   Ma1 0   0       0      0;
    0   0   Ma1 0       0      0;
    0   0   0   I1_11 I1_12  I1_13;
    0   0   0   I1_21 I1_22  I1_23;
    0   0   0   I1_31 I1_32  I1_33;];
M2=[Ma2 0   0   0       0      0;
    0   Ma2 0   0       0      0;
    0   0   Ma2 0       0      0;
    0   0   0   I2_11 I2_12  I2_13;
    0   0   0   I2_21 I2_22  I2_23;
    0   0   0   I2_31 I2_32  I2_33;];
M3=[Ma3 0   0   0       0      0;
    0   Ma3 0   0       0      0;
    0   0   Ma3 0       0      0;
    0   0   0   I3_11 I3_12  I3_13;
    0   0   0   I3_21 I3_22  I3_23;
    0   0   0   I3_31 I3_32  I3_33;];
M4=[Ma4 0   0   0       0      0;
    0   Ma4 0   0       0      0;
    0   0   Ma4 0       0      0;
    0   0   0   I4_11 I4_12  I4_13;
    0   0   0   I4_21 I4_22  I4_23;
    0   0   0   I4_31 I4_32  I4_33;];
M5=[Ma5 0   0   0       0      0;
    0   Ma5 0   0       0      0;
    0   0   Ma5 0       0      0;
    0   0   0   I5_11 I5_12  I5_13;
    0   0   0   I5_21 I5_22  I5_23;
    0   0   0   I5_31 I5_32  I5_33;];
M6=[Ma6 0   0   0       0      0;
    0   Ma6 0   0       0      0;
    0   0   Ma6 0       0      0;
    0   0   0   I6_11 I6_12  I6_13;
    0   0   0   I6_21 I6_22  I6_23;
    0   0   0   I6_31 I6_32  I6_33;];

%Using .' instead of ' to avoid conjugate transpose     
M_d_ = (body_Jacobian_d1_).'* M1 * body_Jacobian_d1_;
M_d_ = M_d_ +  (body_Jacobian_d2_).'* M2 * body_Jacobian_d2_;
M_d_ = M_d_ +  (body_Jacobian_d3_).'* M3 * body_Jacobian_d3_;
M_d_ = M_d_ +  (body_Jacobian_d4_).'* M4 * body_Jacobian_d4_;
M_d_ = M_d_ +  (body_Jacobian_d5_).'* M5 * body_Jacobian_d5_;
M_d_ = M_d_ +  (body_Jacobian_d6_).'* M6 * body_Jacobian_d6_;

Ma = [Ma1 Ma2 Ma3 Ma4 Ma5 Ma6];
Ie1 = [I1_11 I1_21 I1_31 I1_12 I1_22 I1_32 I1_13 I1_23 I1_33];
Ie2 = [I2_11 I2_21 I2_31 I2_12 I2_22 I2_32 I2_13 I2_23 I2_33];
Ie3 = [I3_11 I3_21 I3_31 I3_12 I3_22 I3_32 I3_13 I3_23 I3_33];
Ie4 = [I4_11 I4_21 I4_31 I4_12 I4_22 I4_32 I4_13 I4_23 I4_33];
Ie5 = [I5_11 I5_21 I5_31 I5_12 I5_22 I5_32 I5_13 I5_23 I5_33];
Ie6 = [I6_11 I6_21 I6_31 I6_12 I6_22 I6_32 I6_13 I6_23 I6_33];
M_d = matlabFunction(M_d_,'file','M_d','vars',{L,A,Cen,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6});
 
%% derive partial M /partial Ai

M_dp1_ = diff(M_d_,A1);
M_dp2_ = diff(M_d_,A2);
M_dp3_ = diff(M_d_,A3);
M_dp4_ = diff(M_d_,A4);
M_dp5_ = diff(M_d_,A5);
M_dp6_ = diff(M_d_,A6);
% 
disp('Beigin creating function...')
M_dp1 = matlabFunction(M_dp1_,'file','M_dp1','vars',{L,A,Cen,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6});
disp('Finish 1');
M_dp2 = matlabFunction(M_dp2_,'file','M_dp2','vars',{L,A,Cen,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6});
disp('Finish 2');
M_dp3 = matlabFunction(M_dp3_,'file','M_dp3','vars',{L,A,Cen,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6});
disp('Finish 3');
M_dp4 = matlabFunction(M_dp4_,'file','M_dp4','vars',{L,A,Cen,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6});
disp('Finish 4');
M_dp5 = matlabFunction(M_dp5_,'file','M_dp5','vars',{L,A,Cen,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6});
disp('Finish 5');
M_dp6 = matlabFunction(M_dp6_,'file','M_dp6','vars',{L,A,Cen,Ma,Ie1,Ie2,Ie3,Ie4,Ie5,Ie6});
disp('Finish 6');

% %%
% % syms Wa1 Wa2 Wa3 Wa4 Wa5 Wa6
% % Omega = [Wa1 Wa2 Wa3 Wa4 Wa5 Wa6];
% % M_dp = cell(1,6);
% % Wa   = cell(1,6);
% % M_dp{1} = diff(M_d,A1);
% % M_dp{2} = diff(M_d,A2);
% % M_dp{3} = diff(M_d,A3);
% % M_dp{4} = diff(M_d,A4);
% % M_dp{5} = diff(M_d,A5);
% % M_dp{6} = diff(M_d,A6);
% % Wa{1} = Wa1;
% % Wa{2} = Wa2;
% % Wa{3} = Wa3;
% % Wa{4} = Wa4;
% % Wa{5} = Wa5;
% % Wa{6} = Wa6;
% % 
% % C = cell(6,6);
% % 
% % for i=1:6
% %     for j=1:6
% %         for k=1:6
% %             if k==1
% %                 C{i,j} =0.5*(M_dp{k}(i,j)+M_dp{j}(i,k)-M_dp{i}(k,j))*Wa{k};
% %             else
% %                 C{i,j} =C{i,j}+ 0.5*(M_dp{k}(i,j)+M_dp{j}(i,k)-M_dp{i}(k,j))*Wa{k};
% %             end
% %         end
% %     end
% % 
% % end
% % 
% % C_d =[C{1,1} C{1,2} C{1,3} C{1,4} C{1,5} C{1,6};
% %     C{2,1} C{2,2} C{2,3} C{2,4} C{2,5} C{2,6};
% %     C{3,1} C{3,2} C{3,3} C{3,4} C{3,5} C{3,6};
% %     C{4,1} C{4,2} C{4,3} C{4,4} C{4,5} C{4,6};
% %     C{5,1} C{5,2} C{5,3} C{5,4} C{5,5} C{5,6};
% %     C{6,1} C{6,2} C{6,3} C{6,4} C{6,5} C{6,6}];
% %  
% % C_d = matlabFunction(C_d,'file','C_d','vars',{L,A,Ma,Ie,Omega});
% 
%% derive potential energy V = m_i*g*h_i
% syms g
% gst1_d = g1_d*gst10_d;
% gst2_d = g1_d*g2_d*gst20_d;
% gst3_d = g1_d*g2_d*g3_d*gst30_d;
% gst4_d = g1_d*g2_d*g3_d*g4_d*gst40_d;
% gst5_d = g1_d*g2_d*g3_d*g4_d*g5_d*gst50_d;
% gst6_d = g1_d*g2_d*g3_d*g4_d*g5_d*g6_d*gst60_d;
% 
% h1_d = gst1_d(3,4);
% h2_d = gst2_d(3,4);
% h3_d = gst3_d(3,4);
% h4_d = gst4_d(3,4);
% h5_d = gst5_d(3,4);
% h6_d = gst6_d(3,4);
% 
% V_d = (Ma1*h1_d+Ma2*h2_d+Ma3*h3_d+Ma4*h4_d+Ma5*h5_d+Ma6*h6_d)*g;
% N1_d = diff(V_d,A1);
% N2_d = diff(V_d,A2);
% N3_d = diff(V_d,A3);
% N4_d = diff(V_d,A4);
% N5_d = diff(V_d,A5);
% N6_d = diff(V_d,A6);
% 
% N_d_ =[N1_d;N2_d;N3_d;N4_d;N5_d;N6_d];
% 
% N_d =  matlabFunction(N_d_,'file','N_d','vars',{L,A,Cen,Ma,g});

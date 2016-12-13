function ShowConfig(L,A)

ExL1 = 266;
ExL2 = 227;

bq = [0;0;0;1];
b2q1 = [-L(2);ExL1;ExL2-L(1);1];
b2q2 = [0;ExL1;ExL2-L(1);1];
b2q3 = [0;ExL1;0;1];
b3q1 = [0;ExL1;0;1];
 
%tic;
q(:,1)=bq;
q(:,2)= fwd_kin1(L,A)*b2q1;
q(:,3)= fwd_kin1(L,A)*b2q2;
q(:,4)= fwd_kin1(L,A)*b2q3;
q(:,5)= fwd_kin2(L,A)*b3q1;
q(:,6)= fwd_kin2(L,A)*bq;
q(:,7)= fwd_kin3(L,A)*bq;
q(:,8)= fwd_kin4(L,A)*bq;
q(:,9)= fwd_kin5(L,A)*bq;
q(:,10)= fwd_kin(L,A)*bq;
%toc;

p(:,1) = q(1:3,1);
p(:,2) = [0;0;ExL2];
p(:,3) = q(1:3,2);
p(:,4) = q(1:3,3);
p(:,5) = q(1:3,4);
p(:,6) = q(1:3,5);
p(:,7) = q(1:3,6);
p(:,8) = q(1:3,7);
p(:,9) = q(1:3,8);
p(:,10) = q(1:3,9);
p(:,11) = q(1:3,10);
%disp(p(:,11));

plot3(p(1,:),p(2,:),p(3,:),'-','linewidth',3);
hold on;
plot3(p(1,2),p(2,2),p(3,3),'r.','markersize',20);
hold on;
plot3(p(1,5:6),p(2,5:6),p(3,5:6),'r.','markersize',20);
hold on;
plot3(p(1,8:10),p(2,8:10),p(3,8:10),'r.','markersize',20);
hold on;
plot3(p(1,11),p(2,11),p(3,11),'g.','markersize',20);
view(120,45);
grid on
axis equal
axis([-800 1500 -800 800 0 1600])
xlabel('x')
ylabel('y')
zlabel('z')



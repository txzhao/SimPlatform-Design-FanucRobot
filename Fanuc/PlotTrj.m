%%%%%%%%Plotting after simulation%%%%%%%%%%%%%%
% figure(1);
% plot3(RefEndPos.signals.values(:,1),RefEndPos.signals.values(:,2),RefEndPos.signals.values(:,3),'b');
% hold on;
% plot3(EncEndPos.signals.values(:,1),EncEndPos.signals.values(:,2),EncEndPos.signals.values(:,3),'r');
% hold off;
% grid on;
% xlabel('X');
% ylabel('Y');
% zlabel('Z');
% legend('Reference Trajectory','Actual Implemented Trajectory','Location','NorthEast');
% title('Dynamic Control: 3D Trajectory Comparison');
% 
% figure(2);
% plot(RefEndPos.signals.values(:,1),RefEndPos.signals.values(:,2),'b');
% hold on;
% plot(EncEndPos.signals.values(:,1),EncEndPos.signals.values(:,2),'r');
% hold off;
% grid on;
% legend('Reference Trajectory','Actual Implemented Trajectory','Location','NorthEast');
% title('Dynamic Control: X-Y Plane Trajectory Comparison');
% 
% figure(3);
% plot(RefEndPos.signals.values(:,1),RefEndPos.signals.values(:,3),'b');
% hold on;
% plot(EncEndPos.signals.values(:,1),EncEndPos.signals.values(:,3),'r');
% hold off;
% grid on;
% legend('Reference Trajectory','Actual Implemented Trajectory','Location','NorthEast');
% title('Dynamic Control: X-Z Plane Trajectory Comparison');
% 
% figure(4);
% plot(RefEndPos.signals.values(:,2),RefEndPos.signals.values(:,3),'b');
% hold on;
% plot(EncEndPos.signals.values(:,2),EncEndPos.signals.values(:,3),'r');
% hold off;
% grid on;
% legend('Reference Trajectory','Actual Implemented Trajectory','Location','NorthEast');
% title('Dynamic Control: Y-Z Plane Trajectory Comparison');


%%%%%%%Plotting Step Responsing%%%%%%%%%%%%%%%%%%%
Ts=1/8000;
Axis=1;
%Loop='Vel';
Loop='Pos';
Num=size(RefPulse.signals.values,1);
t=[0:1:Num-1]*Ts;
figure(2);
plot(t,RefPulse.signals.values(:,1)/pi*180);
hold on;
switch Axis
    case 1
        switch Loop
            case 'Pos'
                Response=EncJVAJ1.signals.values(:,1);
            case 'Vel'
                Response=EncJVAJ1.signals.values(:,2)*Ts;
        end
    case 2
        switch Loop
            case 'Pos'
                Response=EncJVAJ2.signals.values(:,1);
            case 'Vel'
                Response=EncJVAJ2.signals.values(:,2)*Ts;
        end
    case 3
        switch Loop
            case 'Pos'
                Response=EncJVAJ3.signals.values(:,1);
            case 'Vel'
                Response=EncJVAJ3.signals.values(:,2)*Ts;
        end
    case 4
         switch Loop
            case 'Pos'
                Response=EncJVAJ4.signals.values(:,1);
            case 'Vel'
                Response=EncJVAJ4.signals.values(:,2)*Ts;
        end
    case 5
         switch Loop
            case 'Pos'
                Response=EncJVAJ5.signals.values(:,1);
            case 'Vel'
                Response=EncJVAJ5.signals.values(:,2)*Ts;
        end
    case 6
         switch Loop
            case 'Pos'
                Response=EncJVAJ6.signals.values(:,1);
            case 'Vel'
                Response=EncJVAJ6.signals.values(:,2)*Ts;
        end
end
plot(t,Response,'r');
hold off;
grid on;
title('Step Response');

% %%%%%%%%%%%%%%%%Performance Comparison Between FW+FB and FB%%%%%%%%%%
% J1_FW_=load('J1_FW.mat');
% J2_FW_=load('J2_FW.mat');
% J3_FW_=load('J3_FW.mat');
% J4_FW_=load('J4_FW.mat');
% J5_FW_=load('J5_FW.mat');
% J6_FW_=load('J6_FW.mat');
% J1_FW = J1_FW_.EncJVAJ1.signals.values;
% J2_FW = J2_FW_.EncJVAJ2.signals.values;
% J3_FW = J3_FW_.EncJVAJ3.signals.values;
% J4_FW = J4_FW_.EncJVAJ4.signals.values;
% J5_FW = J5_FW_.EncJVAJ5.signals.values;
% J6_FW = J6_FW_.EncJVAJ6.signals.values;
% 
% J1_=load('J1.mat');
% J2_=load('J2.mat');
% J3_=load('J3.mat');
% J4_=load('J4.mat');
% J5_=load('J5.mat');
% J6_=load('J6.mat');
% J1 = J1_.EncJVAJ1.signals.values;
% J2 = J2_.EncJVAJ2.signals.values;
% J3 = J3_.EncJVAJ3.signals.values;
% J4 = J4_.EncJVAJ4.signals.values;
% J5 = J5_.EncJVAJ5.signals.values;
% J6 = J6_.EncJVAJ6.signals.values;
% 
% J1_Ref_=load('J1_Ref.mat');
% J2_Ref_=load('J2_Ref.mat');
% J3_Ref_=load('J3_Ref.mat');
% J4_Ref_=load('J4_Ref.mat');
% J5_Ref_=load('J5_Ref.mat');
% J6_Ref_=load('J6_Ref.mat');
% J1_Ref = J1_Ref_.RefJVAJ1.signals.values;
% J2_Ref = J2_Ref_.RefJVAJ2.signals.values;
% J3_Ref = J3_Ref_.RefJVAJ3.signals.values;
% J4_Ref = J4_Ref_.RefJVAJ4.signals.values;
% J5_Ref = J5_Ref_.RefJVAJ5.signals.values;
% J6_Ref = J6_Ref_.RefJVAJ6.signals.values;
% 
% num=size(J1,1);
% Ts=1/8000;
% t=[0:1:num-1]*Ts;
% k=3;
% 
% figure(1);
% plot(t,J1_Ref(:,k),'b');
% hold on;
% plot(t,J1_FW(:,k),'r');
% hold on;
% plot(t,J1(:,k),'y');
% hold off;
% grid on;
% title('Joint 1');
% 
% figure(2);
% plot(t,J2_Ref(:,k),'b');
% hold on;
% plot(t,J2_FW(:,k),'r');
% hold on;
% plot(t,J2(:,k),'y');
% hold off;
% grid on;
% title('Joint 2');
% 
% figure(3);
% plot(t,J3_Ref(:,k),'b');
% hold on;
% plot(t,J3_FW(:,k),'r');
% hold on;
% plot(t,J3(:,k),'y');
% hold off;
% grid on;
% title('Joint 3');
% 
% figure(4);
% plot(t,J4_Ref(:,k),'b');
% hold on;
% plot(t,J4_FW(:,k),'r');
% hold on;
% plot(t,J4(:,k),'y');
% hold off;
% grid on;
% title('Joint 4');
% 
% figure(5);
% plot(t,J5_Ref(:,k),'b');
% hold on;
% plot(t,J5_FW(:,k),'r');
% hold on;
% plot(t,J5(:,k),'y');
% hold off;
% grid on;
% title('Joint 5');
% 
% figure(6);
% plot(t,J6_Ref(:,k),'b');
% hold on;
% plot(t,J6_FW(:,k),'r');
% hold on;
% plot(t,J6(:,k),'y');
% hold off;
% grid on;
% title('Joint 6');
function Tuning(Axis,VelPulseEnable,PosPulseEnable,RefPosVelPulse,RefPosPulse,RefVelPulse,EncJVAJ1,EncJVAJ2,...
EncJVAJ3,EncJVAJ4,EncJVAJ5,EncJVAJ6,EncRes,LinePTs2Rpm,Gear)
%%%%%%%Plotting Step Responsing%%%%%%%%%%%%%%%%%%%
Ts=1/4000;
if VelPulseEnable
    Loop='Vel';
end
if PosPulseEnable
    Loop='Pos';
end

switch Loop
    case 'Pos'
    Num=size(RefPosVelPulse.signals.values,1);
    t=[0:1:Num-1]*Ts;
    case 'Vel'
    Num=size(RefVelPulse.signals.values,1);
    t=[0:1:Num-1]*Ts;
end

switch Axis
    case 1
        switch Loop
            case 'Pos'
                Input_pp=RefPosPulse.signals.values(:,1)/Gear(Axis)/EncRes*360 +a1;
                Input_pv=RefPosVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_pp=(EncJVAJ1.signals.values(:,1));
                Response_pv=EncJVAJ1.signals.values(:,2)/(360)*60*Gear(Axis);
            case 'Vel'
                Input_vv=RefVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_vv=EncJVAJ1.signals.values(:,2)/(360)*60*Gear(Axis);
        end
    case 2
        switch Loop
            case 'Pos'
                Input_pp=RefPosPulse.signals.values(:,1)/Gear(Axis)/EncRes*360 +a2;
                Input_pv=RefPosVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_pp=(EncJVAJ2.signals.values(:,1));
                Response_pv=EncJVAJ2.signals.values(:,2)/(360)*60*Gear(Axis);
            case 'Vel'
                Input_vv=RefVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_vv=EncJVAJ2.signals.values(:,2)/(360)*60*Gear(Axis);
        end
    case 3
        switch Loop
            case 'Pos'
                Input_pp=RefPosPulse.signals.values(:,1)/Gear(Axis)/EncRes*360 +a3 ;
                Input_pv=RefPosVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_pp=(EncJVAJ3.signals.values(:,1));
                Response_pv=EncJVAJ3.signals.values(:,2)/(360)*60*Gear(Axis);
            case 'Vel'
                Input_vv=RefVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_vv=EncJVAJ3.signals.values(:,2)/(360)*60*Gear(Axis);

        end
    case 4
         switch Loop
            case 'Pos'
                Input_pp=RefPosPulse.signals.values(:,1)/Gear(Axis)/EncRes*360 +a4;
                Input_pv=RefPosVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_pp=(EncJVAJ4.signals.values(:,1));
                Response_pv=EncJVAJ4.signals.values(:,2)/(360)*60*Gear(Axis);
            case 'Vel'
                Input_vv=RefVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_vv=EncJVAJ4.signals.values(:,2)/(360)*60*Gear(Axis);
        end
    case 5
         switch Loop
            case 'Pos'
                Input_pp=RefPosPulse.signals.values(:,1)/Gear(Axis)/EncRes*360 +a5;
                Input_pv=RefPosVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_pp=(EncJVAJ5.signals.values(:,1));
                Response_pv=EncJVAJ5.signals.values(:,2)/(360)*60*Gear(Axis);
            case 'Vel'
                Input_vv=RefVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_vv=EncJVAJ5.signals.values(:,2)/(360)*60*Gear(Axis);
        end
    case 6
         switch Loop
            case 'Pos'
                Input_pp=RefPosPulse.signals.values(:,1)/Gear(Axis)/EncRes*360 +a6;
                Input_pv=RefPosVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_pp=(EncJVAJ6.signals.values(:,1));
                Response_pv=EncJVAJ6.signals.values(:,2)/(360)*60*Gear(Axis);
            case 'Vel'
                Input_vv=RefVelPulse.signals.values(:,1)*LinePTs2Rpm;
                Response_vv=EncJVAJ6.signals.values(:,2)/(360)*60*Gear(Axis);
        end
end


switch Loop
    case 'Pos'
        figure(1);
        %%%%%%%Unit: Degree
        plot(t,Input_pp,'b');
        hold on;
        plot(t,Response_pp,'r');
        hold off;
        grid on;
        title('Position Step Response (Degree)');
        xlabel('Time(s)');
        ylabel('Angle(degree)');
        legend('Input','Response');
        figure(2);
        %%%%%%%%%Unit: Rpm
        plot(t,Input_pv,'b');
        hold on;
        plot(t,Response_pv,'r');
        hold off;
        grid on;
        title('Position Velocity Step Response (Rpm)');
        xlabel('Time(s)');
        ylabel('Omega(Rpm)');
        legend('Input','Response');
        figure(3);
        %%%%%%%Unit: Line
        plot(t,Input_pp-Response_pp,'b');
        grid on;
        title('Position Error (Degree)');
        xlabel('Time(s)');
        ylabel('Angle(degree)');
    case 'Vel'
        figure(1);
        %%%%%%%%%%%Unit: Rpm
        plot(t,Input_vv,'b');
        hold on;
        plot(t,Response_vv,'r');
        hold off;
        grid on;
        title('Velocity Step Response (Rpm)');
        xlabel('Time(s)');
        ylabel('Omega(Rpm)');
        legend('Input','Response');
        figure(2)
        plot(t,Input_vv-Response_vv,'b');
        grid on;
        title('Velocity Error (Rpm)');
        xlabel('Time(s)');
        ylabel('Omega(Rpm)');
end
end
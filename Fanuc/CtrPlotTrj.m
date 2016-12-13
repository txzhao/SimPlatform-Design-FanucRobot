if DynTrjMode==2
    Tuning(VelLpAxisNum,1,0,RefPosVelPulse,RefPosPulse,RefVelPulse,EncJVAJ1,EncJVAJ2,...
    EncJVAJ3,EncJVAJ4,EncJVAJ5,EncJVAJ6,EncRes,LinePTs2Rpm,Gear);
elseif DynTrjMode==3
    Tuning(PosLpAxisNum,0,1,RefPosVelPulse,RefPosPulse,RefVelPulse,EncJVAJ1,EncJVAJ2,...
    EncJVAJ3,EncJVAJ4,EncJVAJ5,EncJVAJ6,EncRes,LinePTs2Rpm,Gear);
elseif DynTrjMode==1
    EndPosDisplay(EndPosX,EndPosY,EndPosZ);
end
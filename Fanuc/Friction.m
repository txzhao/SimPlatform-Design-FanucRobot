%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%@Copyright(c),Googol Shenzhen Tech. Ltd
%@File Name: Friction.m
%@Author: Dai Dan
%@Version: 1.0
%@Date: 16/7/2014
%
%@Function: Friction
%@Description: Generate nolinear friction force(Stiction + Stribeck + Columb + Viscous)
%@Input:
%Fv: Viscous friction coefficient
%Fs: Columb friction coefficient
%Fb: Breaking away friction
%Cv: Stribeck coefficient
%Vt: Velocity threshold for generating continuous friction
%v: Relative velocity
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function Ff = Friction(Fv,Fs,Fb,Cv,Vt,v)
if abs(v)>=Vt
    Ff = (Fs + (Fb - Fs)*exp(-Cv*abs(v)))*sign(v) + Fv*v;
else
    Ff = v/Vt * ((Fs + (Fb - Fs)*exp(-Cv*Vt)) + Fv*Vt);
end
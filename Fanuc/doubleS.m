function [Flag,Ta,Tv,Td,Tj1,Tj2,q,v,a,j]=doubleS(qo,qf,vo,vf,ao,af,vm,am,jm)
Ta=0;Tv=0;Td=0;Tj1=0;Tj2=0;
Flag = true;
positive = true;

if qf-qo<0
    qo = -qo;
    qf = -qf;
    vo = -vo;
    vf = -vf;
    ao = -ao;
    af = -af;
    positive = false;
end

Tjs = min(am/jm,sqrt(abs(vf-vo)/jm));
dq = qf - qo;
if Tjs < am/jm
    if dq> Tjs*(vo+vf)

    else
        Flag = false;
        return;
    end
else
    if dq > 0.5*(vo+vf)*(Tjs+abs(vo-vf)/jm)
    else
        Flag = false;
        return;
    end

end

if (vm-vo)*jm<am^2
    Tj1 = sqrt((vm-vo)/jm);
    Ta = 2*Tj1;
else
    Tj1 = am/jm;
    Ta = Tj1 + (vm-vo)/am;
end

if (vm-vf)*jm<am^2
    Tj2 = sqrt((vm-vf)/jm);
    Td = 2*Tj2;
else
    Tj2 = am/jm;
    Td = Tj2 + (vm-vf)/am;
end

Tv = (qf-qo)/vm - Ta/2*(1+vo/vm)-Td/2*(1+vf/vm);

if Tv<0
    Tj1 = am/jm;
    Tj2 = am/jm;
    Delta = am^4/jm^2 + 2*(vo^2+vf^2) + am*(4*(qf-qo)- 2*am/jm*(vo+vf));
    Ta = (am^2/jm - 2*vo + sqrt(Delta))/ (2*am);
    Td = (am^2/jm - 2*vf + sqrt(Delta))/ (2*am);
    Tv=0;
end

while (Ta<2*Tj1 && 0<Ta) || (Td<2*Tj2 && 0<Td)
    am = am*0.9;
    Tj1 = am/jm;
    Tj2 = am/jm;
    Delta = am^4/jm^2 + 2*(vo^2+vf^2) + am*(4*(qf-qo)- 2*am/jm*(vo+vf));
    Ta = (am^2/jm - 2*vo + sqrt(Delta))/ (2*am);
    Td = (am^2/jm - 2*vf + sqrt(Delta))/ (2*am);
    Tv=0;
end

if Ta<0
    Ta=0;
    Tj1=0;
    Td = 2*(qf-qo)/(vf+vo);
    Tj2 = jm*(qf-qo)-sqrt(jm*(jm*(qf-qo)^2)+(vf+vo)^2*(vf-vo));
    Tj2 = Tj2/(jm*(vf+vo));
else if Td<0
    Td=0;
    Tj2=0;
    Ta = 2*(qf-qo)/(vf+vo);
    Tj1 = jm*(qf-qo)-sqrt(jm*(jm*(qf-qo)^2-(vf+vo)^2*(vf-vo)));
    Tj1 = Tj1/(jm*(vf+vo));   
    end
end

T = Ta+Tv+Td;
dt = 0.1;
t = [0:dt:T];
t1 = t(1:floor(Tj1/dt)+1);
t2 = t(floor(Tj1/dt)+2:floor((Ta-Tj1)/dt)+1);
t3 = t(floor((Ta-Tj1)/dt)+2:floor(Ta/dt)+1);
t4 = t(floor(Ta/dt)+2:floor((Ta+Tv)/dt)+1);
t5 = t(floor((Ta+Tv)/dt)+2:floor((T-Td+Tj2)/dt)+1);
t6 = t(floor((T-Td+Tj2)/dt)+2:floor((T-Tj2)/dt)+1);
t7 = t(floor((T-Tj2)/dt)+2:floor(T/dt)+1);

alima=jm*Tj1;
alimd = -jm*Tj2;
vlim = vf-(Td-Tj2)*alimd;

q1 = qo + vo*t1 + jm/6*t1.^3;
v1 = vo + jm/2*t1.^2;
a1 = jm*t1;
j1 = jm*ones(size(t1));


q2 = qo + vo*t2 + alima/6*(3*t2.^2-3*Tj1*t2+Tj1^2);
v2 = vo+alima*(t2-Tj1/2);
a2 = alima*ones(size(t2));
j2 = zeros(size(t2));

q3 = qo + (vlim+vo)*Ta/2-vlim*(Ta-t3)+jm*(Ta-t3).^3/6;
v3 = vlim - jm*(Ta-t3).^2/2;
a3 = jm*(Ta-t3);
j3 = -jm*ones(size(t3));

q4 = qo + (vlim+vo)*Ta/2 + vlim*(t4-Ta);
v4 = vlim*ones(size(t4));
a4 = zeros(size(t4));
j4 = zeros(size(t4));

q5 = qf - (vlim+vf)*Td/2 + vlim*(t5-T+Td)-jm*(t5-T+Td).^3/6;
v5 = vlim - jm*(t5-T+Td).^3/2;
a5 = -jm*(t5-T+Td);
j5 = -jm*ones(size(t5));


q6 = qf-(vlim+vf)*Td/2+vlim*(t6-T+Td)+alimd/6*(3*(t6-T+Td).^2-3*Tj2*(t6-T+Td)+Tj2^2);
v6 = vlim + alimd*(t6-T+Td-Tj2/2);
a6 = alimd*ones(size(t6));
j6 = zeros(size(t6));

q7 = qf-vf*(T-t7)-jm*(T-t7).^3/6;
v7 = vf + jm*(T-t7).^2/2;
a7 = -jm*(T-t7);
j7 = jm*ones(size(t7));

q=[q1 q2 q3 q4 q5 q6 q7]';
v=[v1 v2 v3 v4 v5 v6 v7]';
a=[a1 a2 a3 a4 a5 a6 a7]';
j=[j1 j2 j3 j4 j5 j6 j7]';

if positive
    
else
    q=-q;
    v=-v;
    a=-a;
    j=-j;
end

return;


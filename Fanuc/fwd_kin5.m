function gst5 = fwd_kin5(in1,in2)
%FWD_KIN5
%    GST5 = FWD_KIN5(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 5.5.
%    24-Apr-2013 12:50:49

A1 = in2(:,1);
A2 = in2(:,2);
A3 = in2(:,3);
A4 = in2(:,4);
A5 = in2(:,5);
L1 = in1(:,1);
L2 = in1(:,2);
L3 = in1(:,3);
L4 = in1(:,4);
L5 = in1(:,5);
L6 = in1(:,6);
t93 = cos(A1);
t94 = cos(A2);
t95 = sin(A3);
t96 = cos(A3);
t97 = sin(A2);
t98 = sin(A4);
t99 = t93.*t94.*t95;
t100 = t93.*t96.*t97;
t101 = t100+t99;
t102 = cos(A4);
t103 = sin(A1);
t104 = sin(A5);
t105 = t93.*t94.*t96;
t106 = t105-t93.*t95.*t97;
t107 = cos(A5);
t108 = t101.*t102;
t109 = t103.*t98;
t110 = t108+t109;
t111 = t103.*t94.*t95;
t112 = t103.*t96.*t97;
t113 = t111+t112;
t114 = t103.*t94.*t96;
t115 = t114-t103.*t95.*t97;
t116 = t102.*t113;
t117 = t116-t93.*t98;
t118 = t94.*t95;
t119 = t96.*t97;
t120 = t118+t119;
t121 = t94.*t96;
t122 = t121-t95.*t97;
gst5 = reshape([t106.*t107-t104.*t110,-t104.*t117+t107.*t115,-t107.*t120-t102.*t104.*t122,0.0,-t102.*t103+t101.*t98,t102.*t93+t113.*t98,t98.*cos(A2+A3),0.0,t104.*t106+t107.*t110,t104.*t115+t107.*t117,-t104.*t120+t102.*t107.*t122,0.0,L2.*t93+L3.*t93.*t97-L6.*t103.*t104.*t98+L4.*t93.*t94.*t95+L4.*t93.*t96.*t97+L5.*t93.*t94.*t96-L5.*t93.*t95.*t97+L6.*t107.*t93.*t94.*t96-L6.*t107.*t93.*t95.*t97-L6.*t102.*t104.*t93.*t94.*t95-L6.*t102.*t104.*t93.*t96.*t97,L2.*t103+L3.*t103.*t97+L4.*t103.*t94.*t95+L4.*t103.*t96.*t97+L5.*t103.*t94.*t96-L5.*t103.*t95.*t97+L6.*t104.*t93.*t98+L6.*t103.*t107.*t94.*t96-L6.*t103.*t107.*t95.*t97-L6.*t102.*t103.*t104.*t94.*t95-L6.*t102.*t103.*t104.*t96.*t97,L1+L3.*t94+L4.*t94.*t96-L4.*t95.*t97-L5.*t94.*t95-L5.*t96.*t97-L6.*t107.*t94.*t95-L6.*t107.*t96.*t97-L6.*t102.*t104.*t94.*t96+L6.*t102.*t104.*t95.*t97,1.0],[4, 4]);
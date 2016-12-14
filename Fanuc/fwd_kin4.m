function gst4 = fwd_kin4(in1,in2)
%FWD_KIN4
%    GST4 = FWD_KIN4(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 5.5.
%    24-Apr-2013 12:50:38

A1 = in2(:,1);
A2 = in2(:,2);
A3 = in2(:,3);
A4 = in2(:,4);
L1 = in1(:,1);
L2 = in1(:,2);
L3 = in1(:,3);
L4 = in1(:,4);
L5 = in1(:,5);
t71 = cos(A1);
t72 = cos(A4);
t73 = cos(A2);
t74 = sin(A3);
t75 = t71.*t73.*t74;
t76 = cos(A3);
t77 = sin(A2);
t78 = t71.*t76.*t77;
t79 = t75+t78;
t80 = sin(A1);
t81 = sin(A4);
t82 = A2+A3;
t83 = cos(t82);
t84 = t73.*t74.*t80;
t85 = t76.*t77.*t80;
t86 = t84+t85;
t87 = sin(t82);
t88 = L4.*t87;
t89 = L3.*t77;
t90 = L5.*t83;
t91 = L2+t88+t89+t90;
gst4 = reshape([t71.*t83,t80.*t83,-t87,0.0,-t72.*t80+t79.*t81,t71.*t72+t81.*t86,t81.*t83,0.0,t72.*t79+t80.*t81,-t71.*t81+t72.*t86,t72.*t83,0.0,t71.*t91,t80.*t91,L1+L3.*t73+L4.*t83-L5.*t87,1.0],[4, 4]);
function EulerMd_ = EulerMd(in1,in2,in3,in4,in5,in6,in7,in8,in9,in10)
%EULERMD
%    EULERMD_ = EULERMD(IN1,IN2,IN3,IN4,IN5,IN6,IN7,IN8,IN9,IN10)

%    This function was generated by the Symbolic Math Toolbox version 5.5.
%    15-Aug-2014 16:04:03

Cx1 = in3(:,1);
Cx2 = in3(:,2);
Cx3 = in3(:,3);
Cx4 = in3(:,4);
Cx5 = in3(:,5);
Cx6 = in3(:,6);
Cy1 = in3(:,7);
Cy2 = in3(:,8);
Cy3 = in3(:,9);
Cy4 = in3(:,10);
Cy5 = in3(:,11);
Cy6 = in3(:,12);
Cz2 = in3(:,14);
Cz3 = in3(:,15);
Cz4 = in3(:,16);
Cz5 = in3(:,17);
Cz6 = in3(:,18);
I1_33 = in4(:,9);
I2_11 = in5(:,1);
I2_12 = in5(:,4);
I2_21 = in5(:,2);
I2_13 = in5(:,7);
I2_22 = in5(:,5);
I2_31 = in5(:,3);
I2_23 = in5(:,8);
I2_32 = in5(:,6);
I2_33 = in5(:,9);
I3_11 = in6(:,1);
I3_12 = in6(:,4);
I3_21 = in6(:,2);
I3_13 = in6(:,7);
I3_22 = in6(:,5);
I3_31 = in6(:,3);
I3_23 = in6(:,8);
I3_32 = in6(:,6);
I3_33 = in6(:,9);
I4_11 = in7(:,1);
I4_12 = in7(:,4);
I4_21 = in7(:,2);
I4_13 = in7(:,7);
I4_22 = in7(:,5);
I4_31 = in7(:,3);
I4_23 = in7(:,8);
I4_32 = in7(:,6);
I4_33 = in7(:,9);
I5_11 = in8(:,1);
I5_12 = in8(:,4);
I5_21 = in8(:,2);
I5_13 = in8(:,7);
I5_22 = in8(:,5);
I5_31 = in8(:,3);
I5_23 = in8(:,8);
I5_32 = in8(:,6);
I5_33 = in8(:,9);
I6_11 = in9(:,1);
I6_12 = in9(:,4);
I6_21 = in9(:,2);
I6_13 = in9(:,7);
I6_22 = in9(:,5);
I6_31 = in9(:,3);
I6_23 = in9(:,8);
I6_32 = in9(:,6);
I6_33 = in9(:,9);
Ld1 = in1(:,1);
Ld2 = in1(:,2);
Ld3 = in1(:,3);
Ld4 = in1(:,4);
Ld5 = in1(:,5);
Ld6 = in1(:,6);
Ld7 = in1(:,7);
Ma1 = in2(:,1);
Ma2 = in2(:,2);
Ma3 = in2(:,3);
Ma4 = in2(:,4);
Ma5 = in2(:,5);
Ma6 = in2(:,6);
pos2 = in10(:,2);
pos3 = in10(:,3);
pos4 = in10(:,4);
pos5 = in10(:,5);
pos6 = in10(:,6);
t2 = pos2+pos3;
t3 = sin(t2);
t4 = sin(pos5);
t5 = t3.*t4;
t6 = cos(t2);
t7 = cos(pos4);
t8 = cos(pos5);
t22 = t6.*t7.*t8;
t9 = -t22+t5;
t10 = Cy5-Ld5;
t11 = -Cx5+Ld3+Ld7;
t12 = sin(pos4);
t13 = sin(pos2);
t14 = Ld4.*t13;
t15 = Ld3+t14;
t16 = -Cz5+Ld1+Ld2+Ld4+Ld6;
t17 = t3.*t8;
t18 = t4.*t6.*t7;
t19 = t17+t18;
t20 = -Cz6+Ld1+Ld2+Ld4+Ld6;
t21 = Cy6-Ld5;
t23 = -Cx6+Ld3+Ld7;
t24 = sin(pos6);
t25 = cos(pos6);
t26 = t12.*t15;
t27 = Ld5.*t7;
t28 = Ld6.*t12;
t29 = t27+t28;
t30 = t29.*t3;
t31 = t26+t30;
t32 = t15.*t7;
t33 = Ld5.*t12;
t41 = Ld6.*t7;
t34 = t33-t41;
t35 = Ld7.*t6.*t7;
t42 = t3.*t34;
t36 = t32+t35-t42;
t37 = t31.*t8;
t38 = Ld5.*t4.*t6;
t39 = Ld7.*t12.*t6.*t8;
t40 = t37+t38+t39;
t43 = t32-t42;
t44 = t31.*t4;
t45 = Ld7.*t12.*t4.*t6;
t47 = Ld5.*t6.*t8;
t46 = t44+t45-t47;
t48 = Cx4-Ld3;
t49 = t24.*t9;
t51 = t12.*t25.*t6;
t50 = t49-t51;
t52 = t20.^2;
t53 = Ma6.*t52;
t54 = t25.*t9;
t55 = t12.*t24.*t6;
t56 = t54+t55;
t57 = Ma6.*t21.*t23;
t58 = t25.*t40;
t59 = t24.*t36;
t60 = t58+t59;
t61 = -Cz2+Ld1+Ld2;
t62 = t10.^2;
t63 = Ma5.*t62;
t64 = Cx3-Ld3;
t65 = t21.^2;
t66 = Ma6.*t65;
t67 = t23.^2;
t68 = Ma6.*t67;
t69 = Ma6.*t20.*t21;
t70 = t25.*t36;
t71 = -Cz3+Ld1+Ld2+Ld4;
t72 = Ma3.*t64.*t71;
t73 = Cy3.^2;
t74 = Ma3.*t73;
t75 = -Cz4+Ld1+Ld2+Ld4+Ld6;
t76 = Cy4-Ld5;
t77 = t24.*t40;
t78 = -t70+t77;
t79 = cos(pos2);
t80 = Cx2-Ld3;
t81 = Ma2.*t61.*t80;
t82 = Cy2.^2;
t83 = Ma2.*t82;
t84 = Ma5.*t10.*t16;
t85 = Ma5.*t10.*t11;
t86 = t16.^2;
t87 = Ma5.*t86;
t88 = t11.^2;
t89 = Ma5.*t88;
t90 = Ma4.*t48.*t75;
t91 = t76.^2;
t92 = Ma4.*t91;
t93 = t75.^2;
t94 = Ma4.*t93;
t95 = t48.^2;
t96 = Ma4.*t95;
t97 = Ma4.*t75.*t76;
t98 = Ld5.*Ma4.*t6;
t99 = Ma4.*t12.*t6.*t75;
t100 = Ma4.*t6.*t7.*t76;
t101 = t100+t98+t99;
t102 = I5_32+t84;
t103 = t102.*t9;
t104 = I5_12+t85;
t105 = t104.*t19;
t106 = Ma5.*t16.*t46;
t107 = Ma5.*t11.*t40;
t108 = I5_22+t87+t89;
t202 = t108.*t12.*t6;
t109 = t103+t105+t106+t107-t202;
t110 = cos(pos3);
t111 = Ld4.*t110;
t112 = Ld6+t111;
t113 = Ma5.*t46;
t114 = Ma5.*t10.*t9;
t201 = Ma5.*t12.*t16.*t6;
t115 = t113+t114-t201;
t116 = I6_22+t53+t68;
t117 = t116.*t50;
t118 = I6_32+t69;
t119 = t118.*t56;
t120 = I6_12+t57;
t121 = t120.*t19;
t122 = Ma6.*t20.*t46;
t123 = Ma6.*t23.*t60;
t124 = t117+t119+t121+t122+t123;
t125 = I6_33+t66+t68;
t126 = t125.*t56;
t190 = Ma6.*t20.*t23;
t127 = I6_13-t190;
t128 = t127.*t19;
t129 = I6_23+t69;
t130 = t129.*t50;
t131 = Ma6.*t21.*t46;
t215 = Ma4.*t48.*t76;
t132 = I4_12-t215;
t133 = I4_22+t94+t96;
t134 = t12.*t133.*t6;
t135 = Ma4.*t31.*t48;
t136 = I4_32+t97;
t137 = t136.*t6.*t7;
t138 = Ld5.*Ma4.*t6.*t75;
t216 = t132.*t3;
t139 = t134+t135+t137+t138-t216;
t140 = t112.*t8;
t141 = Ld7.*t4.*t7;
t142 = sin(pos3);
t243 = Ld4.*t142.*t4.*t7;
t143 = t140+t141-t243;
t144 = Ma6.*t46;
t145 = Ma6.*t20.*t50;
t146 = Ma6.*t21.*t56;
t147 = t144+t145+t146;
t148 = I4_13+t90;
t149 = I4_33+t92+t96;
t150 = t149.*t6.*t7;
t151 = Ma4.*t43.*t48;
t152 = I4_23+t97;
t153 = t12.*t152.*t6;
t154 = Ld5.*Ma4.*t6.*t76;
t221 = t148.*t3;
t155 = t150+t151+t153+t154-t221;
t156 = Ma6.*t78;
t157 = Ma6.*t19.*t20;
t220 = Ma6.*t23.*t56;
t158 = t156+t157-t220;
t159 = Ma5.*t40;
t160 = Ma5.*t10.*t19;
t218 = Ma5.*t11.*t12.*t6;
t161 = t159+t160-t218;
t162 = t112.*t4;
t163 = Ld4.*t142.*t7.*t8;
t165 = Ld7.*t7.*t8;
t164 = t162+t163-t165;
t171 = Ld4.*t142;
t166 = Ld7-t171;
t167 = Ma6.*t60;
t168 = Ma6.*t23.*t50;
t169 = Ma6.*t19.*t21;
t170 = t167+t168+t169;
t172 = Ma5.*t36;
t173 = Ma5.*t11.*t9;
t224 = Ma5.*t16.*t19;
t174 = t172+t173-t224;
t184 = Ma5.*t11.*t16;
t175 = I5_31-t184;
t176 = t175.*t9;
t177 = I5_11+t63+t87;
t178 = t177.*t19;
t179 = I5_21+t85;
t180 = Ma5.*t10.*t40;
t225 = t12.*t179.*t6;
t226 = Ma5.*t16.*t36;
t181 = t176+t178+t180-t225-t226;
t182 = I5_33+t63+t89;
t183 = t182.*t9;
t185 = Ma5.*t10.*t46;
t186 = Ma5.*t11.*t36;
t187 = I5_23+t84;
t188 = I6_11+t53+t66;
t189 = t188.*t19;
t191 = I6_21+t57;
t192 = t191.*t50;
t193 = Ma6.*t21.*t60;
t194 = Ma4.*t31;
t195 = Ma4.*t3.*t76;
t196 = Ma4.*t12.*t48.*t6;
t197 = t194+t195+t196;
t198 = Ma4.*t43;
t199 = Ma4.*t48.*t6.*t7;
t200 = t198+t199-Ma4.*t3.*t75;
t203 = t25.*t7;
t242 = t12.*t24.*t8;
t204 = t203-t242;
t205 = Cy3.*Ma3.*t71;
t206 = I3_32+t205;
t207 = t206.*t6;
t208 = Ld6.*t8;
t209 = t141+t208;
t210 = t24.*t7;
t211 = t12.*t25.*t8;
t212 = t210+t211;
t240 = Ma6.*t23.*t78;
t213 = t126+t128+t130+t131-t240;
t214 = t212.*t213;
t217 = t139.*t7;
t222 = Ld6.*t4;
t219 = t165-t222;
t241 = Cy3.*Ma3.*t64;
t223 = I3_12-t241;
t227 = I5_13-t184;
t228 = t19.*t227;
t236 = t12.*t187.*t6;
t229 = t183+t185+t186+t228-t236;
t230 = t12.*t229.*t8;
t231 = I6_31-t190;
t232 = t231.*t56;
t233 = Ma6.*t20.*t78;
t234 = t189+t192+t193+t232+t233;
t235 = I4_11+t92+t94;
t237 = Ma4.*t43.*t75;
t238 = I4_31+t90;
t239 = t238.*t6.*t7;
t244 = t164.*t25;
t245 = t12.*t166.*t24;
t246 = t244+t245;
t247 = Cy2.*Ma2.*t61;
t248 = t164.*t24;
t250 = t12.*t166.*t25;
t249 = t248-t250;
t251 = I4_21-t215;
t252 = t12.*t136;
t253 = Ma4.*t112.*t75;
t254 = Ld4.*Ma4.*t142.*t48.*t7;
t319 = t133.*t7;
t255 = t252+t253+t254-t319;
t256 = t116.*t204;
t257 = t12.*t120.*t4;
t258 = Ma6.*t23.*t246;
t320 = t118.*t212;
t321 = Ma6.*t143.*t20;
t259 = t256+t257+t258-t320-t321;
t260 = Ma4.*t112;
t261 = Ma4.*t12.*t76;
t331 = Ma4.*t7.*t75;
t262 = t260+t261-t331;
t263 = Ma6.*t249;
t264 = Ma6.*t212.*t23;
t265 = Ma6.*t12.*t20.*t4;
t266 = t263+t264+t265;
t267 = t80.^2;
t268 = Ma2.*t267;
t269 = t64.^2;
t270 = Ma3.*t269;
t271 = t125.*t212;
t272 = Ma6.*t143.*t21;
t273 = Ma6.*t23.*t249;
t326 = t129.*t204;
t327 = t12.*t127.*t4;
t274 = t271+t272+t273-t326-t327;
t275 = Ma6.*t246;
t276 = Ma6.*t204.*t23;
t277 = Ma6.*t12.*t21.*t4;
t278 = t275+t276+t277;
t279 = t12.*t149;
t280 = Ma4.*t112.*t76;
t281 = t108.*t7;
t282 = t104.*t12.*t4;
t283 = Ma5.*t11.*t164;
t334 = Ma5.*t143.*t16;
t335 = t102.*t12.*t8;
t284 = t281+t282+t283-t334-t335;
t285 = Ma5.*t143;
t286 = Ma5.*t10.*t12.*t8;
t332 = Ma5.*t16.*t7;
t287 = t285+t286-t332;
t288 = t61.^2;
t289 = Ma2.*t288;
t290 = Ma6.*t143;
t291 = Ma6.*t21.*t212;
t337 = Ma6.*t20.*t204;
t292 = t290+t291-t337;
t293 = t71.^2;
t294 = Ma3.*t293;
t295 = Ma5.*t164;
t296 = Ma5.*t11.*t7;
t297 = Ma5.*t10.*t12.*t4;
t298 = t295+t296+t297;
t299 = t191.*t204;
t300 = Ma6.*t20.*t249;
t301 = Ma6.*t21.*t246;
t302 = t12.*t188.*t4;
t338 = t212.*t231;
t303 = t299+t300+t301+t302-t338;
t304 = Ma5.*t12.*t16.*t4;
t305 = Ma5.*t11.*t12.*t8;
t342 = Ma5.*t12.*t166;
t306 = t304+t305-t342;
t307 = t187.*t7;
t308 = t12.*t227.*t4;
t309 = Ma5.*t11.*t12.*t166;
t340 = Ma5.*t10.*t143;
t341 = t12.*t182.*t8;
t310 = t307+t308+t309-t340-t341;
t311 = t179.*t7;
t312 = Ma5.*t10.*t164;
t313 = t12.*t177.*t4;
t343 = t12.*t175.*t8;
t344 = Ma5.*t12.*t16.*t166;
t314 = t311+t312+t313-t343-t344;
t315 = Ma4.*t48.*t7;
t316 = t315-Ld4.*Ma4.*t142.*t7;
t317 = Ma4.*t12.*t48;
t318 = t317-Ld4.*Ma4.*t12.*t142;
t322 = t204.*t259;
t323 = t219.*t24;
t324 = Ld7.*t12.*t25;
t325 = t323+t324;
t328 = t212.*t274;
t329 = t219.*t25;
t349 = Ld7.*t12.*t24;
t330 = t329-t349;
t350 = t152.*t7;
t333 = t12.*(t279+t280-t350-Ld4.*Ma4.*t12.*t142.*t48);
t336 = t284.*t7;
t339 = t12.*t303.*t4;
t345 = t12.*t314.*t4;
t346 = t251.*t7;
t347 = Ld4.*Ma4.*t12.*t142.*t75;
t348 = Ld4.*Ma4.*t142.*t7.*t76;
t351 = Ma6.*t20.*t209;
t352 = Ma6.*t23.*t330;
t353 = -t256-t257+t320+t351+t352;
t354 = Ma6.*t23.*t325;
t381 = Ma6.*t209.*t21;
t355 = -t271+t326+t327+t354-t381;
t356 = Ld6.*Ma4.*t75;
t357 = t252-t319+t356;
t358 = t264+t265-Ma6.*t325;
t359 = Ma5.*t16.*t209;
t360 = Ma5.*t11.*t219;
t361 = -t281-t282+t335+t359+t360;
t362 = t276+t277-Ma6.*t330;
t363 = Ld6.*Ma4;
t364 = t261-t331+t363;
t365 = Ma5.*t209;
t366 = t286-t332+t365;
t367 = Ld6.*Ma4.*t76;
t368 = t279-t350+t367;
t369 = Ma6.*t209;
t370 = t291-t337+t369;
t371 = t296+t297-Ma5.*t219;
t372 = Ma6.*t20.*t325;
t373 = Ma6.*t21.*t330;
t374 = -t299-t302+t338+t372+t373;
t375 = Ld7.*Ma5.*t11.*t12;
t386 = Ma5.*t10.*t209;
t376 = t307+t308-t341+t375-t386;
t387 = Ld7.*Ma5.*t12;
t377 = t304+t305-t387;
t378 = Ma5.*t10.*t219;
t379 = Ld7.*Ma5.*t12.*t16;
t380 = -t311-t313+t343+t378+t379;
t382 = -t323-t324;
t383 = -t329+t349;
t384 = t12.*t368;
t385 = -t165+t222;
t395 = t24.*t385;
t388 = t324-t395;
t389 = t25.*t385;
t390 = t349+t389;
t391 = Ma6.*t21.*t390;
t400 = Ma6.*t20.*t388;
t392 = t299+t302-t338+t391-t400;
t393 = Ma5.*t10.*t385;
t394 = t311+t313-t343-t379+t393;
t396 = Ma6.*t23.*t390;
t397 = t256+t257-t320-t351+t396;
t398 = Ma6.*t23.*t388;
t399 = -t271+t326+t327-t381+t398;
t401 = t102.*t4;
t402 = t104.*t8;
t403 = t401+t402;
t404 = t120.*t8;
t405 = t116.*t24.*t4;
t406 = t118.*t25.*t4;
t407 = t404+t405+t406;
t408 = t127.*t8;
t409 = t125.*t25.*t4;
t410 = t129.*t24.*t4;
t411 = t408+t409+t410;
t412 = Ma6.*t20.*t24.*t4;
t413 = Ma6.*t21.*t25.*t4;
t414 = t412+t413;
t415 = Ma6.*t20.*t8;
t435 = Ma6.*t23.*t25.*t4;
t416 = t415-t435;
t417 = Ma6.*t21.*t8;
t418 = Ma6.*t23.*t24.*t4;
t419 = t417+t418;
t420 = t175.*t4;
t421 = t177.*t8;
t422 = t420+t421;
t423 = t188.*t8;
t424 = t231.*t25.*t4;
t425 = t191.*t24.*t4;
t426 = t423+t424+t425;
t427 = t227.*t8;
t428 = t182.*t4;
t429 = t427+t428;
t430 = Ma5.*t11.*t4;
t438 = Ma5.*t16.*t8;
t431 = t430-t438;
t432 = t403.*t7;
t433 = t132.*t7;
t434 = t204.*t407;
t436 = t12.*t4.*t422;
t437 = t12.*t4.*t426;
t439 = t125.*t24;
t440 = Ma6.*t20.*t25;
t446 = Ma6.*t21.*t24;
t441 = t440-t446;
t442 = t118.*t24;
t447 = t116.*t25;
t443 = t442-t447;
t444 = t191.*t25;
t452 = t129.*t25;
t453 = t439-t452;
t445 = t212.*t453;
t451 = t231.*t24;
t454 = t444-t451;
t448 = t12.*t4.*t454;
t449 = t12.*t179.*t4;
t450 = Ma5.*t11.*t385;
t455 = t120.*t204;
EulerMd_ = reshape([I1_33-t3.*(-t3.*(I3_11+t294+t74)+t6.*(I3_31+t72)+Ma3.*t15.*t71)+t6.*(t6.*(I3_33+t270+t74)-t3.*(I3_13+t72)+Ma3.*t15.*t64)+Ld3.*(Ld3.*Ma2-Ma2.*t13.*t61+Ma2.*t79.*t80)+t56.*(t126+t128+t130+t131+Ma6.*t23.*(t70-t24.*t40))+t181.*t19+t197.*t31+t174.*t36+t161.*t40+t115.*t46+t147.*t46+t124.*t50+t200.*t43+t170.*t60+t158.*t78+Cx1.^2.*Ma1+Cy1.^2.*Ma1+t9.*(t183+t185+t186+t19.*(I5_13-Ma5.*t11.*t16)-t12.*t187.*t6)-t3.*(t237+t239-t235.*t3+t12.*t6.*(I4_21-Ma4.*t48.*t76)-Ma4.*t31.*t76)+t15.*(Ma3.*t15-Ma3.*t3.*t71+Ma3.*t6.*t64)+t19.*(t189+t192+t193+t56.*(I6_31-Ma6.*t20.*t23)-Ma6.*t20.*(t70-t24.*t40))-t13.*(-t13.*(I2_11+t289+t83)+t79.*(I2_31+t81)+Ld3.*Ma2.*t61)+t79.*(t79.*(I2_33+t268+t83)-t13.*(I2_13+t81)+Ld3.*Ma2.*t80)+Ld5.*t101.*t6-t109.*t12.*t6+t12.*t139.*t6+t155.*t6.*t7,-t3.*(I3_21-t241+Cy3.*Ld4.*Ma3.*t142)-t19.*t303-t19.*t314+t31.*t316+t306.*t36-t298.*t40+t287.*t46+t292.*t46-t318.*t43-t259.*t50+t274.*t56-t278.*t60-t266.*t78-t310.*t9+t6.*(I3_23+t205-Cy3.*Ld4.*Ma3.*t110)-t3.*(t346+t347+t348-t12.*t238)-t13.*(I2_21-Cy2.*Ma2.*t80)+t79.*(I2_23+t247)-t6.*t7.*(t279+t280-t152.*t7-Ld4.*Ma4.*t12.*t142.*t48)-Ld5.*t262.*t6-t12.*t255.*t6+t12.*t284.*t6,t19.*t374+t19.*t380+t36.*t377-t371.*t40+t366.*t46+t370.*t46+t353.*t50-t355.*t56-t362.*t60-t358.*t78-t376.*t9-t3.*(I3_21-t241)-t3.*(t346-t12.*t238)+t6.*(I3_23+t205)-Ld5.*t364.*t6-t12.*t357.*t6-t12.*t361.*t6-t368.*t6.*t7-Ma4.*t12.*t43.*t48+Ma4.*t31.*t48.*t7,t237-t235.*t3-t19.*t422-t19.*t426-t36.*t431-t414.*t46-t407.*t50-t411.*t56-t419.*t60-t416.*t78-t429.*t9-Ma4.*t31.*t76+t12.*t132.*t6+t12.*t403.*t6+t148.*t6.*t7-Ma5.*t10.*t4.*t46-Ma5.*t10.*t40.*t8,-t106-t107+t202-t179.*t19-t441.*t46+t443.*t50-t187.*t9-t19.*(t444-t231.*t24)+t56.*(t439-t129.*t25)-Ma6.*t23.*t25.*t60-Ma6.*t23.*t24.*t78,-t189-t193-t233-t120.*t50-t127.*t56,t207+t214+t217+t230-t101.*t112+t115.*t143-t12.*t155+t143.*t147-t161.*t164-t124.*t204-t158.*t249-t170.*t246-t223.*t3-t109.*t7-t13.*(I2_12-Cy2.*Ma2.*t80)+t79.*(I2_32+t247)-t12.*t166.*t174-t12.*t181.*t4-t12.*t234.*t4+Ld4.*t12.*t142.*t200-Ld4.*t142.*t197.*t7-Cy3.*Ld4.*Ma3.*t142.*t3-Cy3.*Ld4.*Ma3.*t110.*t6,I2_22+I3_22+t268+t270+t289+t294+t322+t328+t333+t336+t339+t345+t112.*t262+t143.*t287+t143.*t292+t164.*t298+t249.*t266+t246.*t278-t255.*t7-Ld4.*t142.*(Ma3.*t64-Ld4.*Ma3.*t142)-Ld4.*t110.*(Ma3.*t71-Ld4.*Ma3.*t110)-t12.*t166.*t306-t12.*t310.*t8-Ld4.*t12.*t142.*t318-Ld4.*t142.*t316.*t7-Ld4.*Ma3.*t142.*t64-Ld4.*Ma3.*t110.*t71,I3_22+t270+t294+t384+t112.*t364+t143.*t366+t143.*t370+t164.*t371-t204.*t353-t212.*t355+t249.*t358+t246.*t362-t357.*t7-t361.*t7-t12.*t166.*t377-t12.*t374.*t4-t12.*t380.*t4-t12.*t376.*t8-Ld4.*Ma3.*t142.*t64-Ld4.*Ma3.*t110.*t71-Ld4.*Ma4.*t12.^2.*t142.*t48-Ld4.*Ma4.*t142.*t48.*t7.^2,t347+t348+t432+t433+t434+t436+t437-t12.*t148-t143.*t414-t212.*t411+t246.*t419+t249.*t416+t12.*t166.*t431-t12.*t429.*t8-Ma5.*t10.*t143.*t4+Ma5.*t10.*t164.*t8,t281+t283-t334+t445+t448+t449-t143.*t441-t204.*t443-t12.*t187.*t8+Ma6.*t23.*t24.*t249+Ma6.*t23.*t246.*t25,t300+t301+t302+t455-t127.*t212,t207+t214+t217+t230-Ld6.*t101-t12.*t155+t115.*t209-t124.*t204+t147.*t209+t161.*t219+t158.*t325+t170.*t330-t223.*t3-t109.*t7-Ld7.*t12.*t174-t12.*t181.*t4-t12.*t234.*t4,I3_22+t270+t294+t322+t328+t333+t336+t339+t345+Ld6.*t262+t209.*t287+t209.*t292-t219.*t298-t266.*t325-t278.*t330-t255.*t7-Ld7.*t12.*t306-t12.*t310.*t8-Ld4.*Ma3.*t142.*t64-Ld4.*Ma3.*t110.*t71,I3_22+t270+t294+t384+Ld6.*t364+t382.*(t264+t265+Ma6.*t382)+t383.*(t276+t277+Ma6.*t383)+t385.*(t296+t297+Ma5.*t385)-t204.*t353-t212.*t355+t209.*t366+t209.*t370-t357.*t7-t361.*t7-Ld7.*t12.*t377+t12.*t392.*t4+t12.*t394.*t4-t12.*t376.*t8,t432+t433+t434+t436+t437-t12.*t148-t209.*t414-t212.*t411-t388.*t416+t390.*t419+Ld7.*t12.*t431-t12.*t429.*t8-Ma5.*t10.*t209.*t4+Ma5.*t10.*t385.*t8,t281-t359+t445+t448+t449+t450-t204.*t443-t209.*t441-t12.*t187.*t8-Ma6.*t23.*t24.*t388+Ma6.*t23.*t25.*t390,t302+t391-t400+t455-t127.*t212,t237+t239-t235.*t3-t229.*t4-t181.*t8-t234.*t8-Ma4.*t31.*t76-t124.*t24.*t4-t213.*t25.*t4+t12.*t251.*t6,t346+t347+t348-t12.*t238+t310.*t4+t303.*t8+t314.*t8+t24.*t259.*t4-t25.*t274.*t4,t346-t12.*t238+t376.*t4+t392.*t8+t394.*t8+t24.*t397.*t4+t25.*t399.*t4,I4_11+t92+t94+t4.*t429+t422.*t8+t426.*t8+t24.*t4.*t407+t25.*t4.*t411,t187.*t4+t179.*t8+t8.*(t444-t451)-t24.*t4.*t443-t25.*t4.*t453,t423+t120.*t24.*t4+t127.*t25.*t4,-t103-t105-t106-t107+t202-t124.*t25+t213.*t24,t281+t282+t283-t334-t335+t25.*t259+t24.*t274,t281+t282-t335-t359+t450-t24.*t399+t25.*t397,t401+t402-t24.*t411+t25.*t407,I5_22+t87+t89-t25.*t443+t24.*(t439-t452),-t127.*t24+t120.*t25,-t189-t192-t193-t232-t233,t303,t392,t426,t454,t188],[6, 6]);

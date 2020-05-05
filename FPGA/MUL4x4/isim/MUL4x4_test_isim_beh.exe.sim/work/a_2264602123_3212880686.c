/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Damian Bigajczyk/Desktop/WorkSpace/FPGA/MUL4x4/MUL4x4.vhd";
extern char *IEEE_P_2592010699;



static void work_a_2264602123_3212880686_p_0(char *t0)
{
    char t13[16];
    char t15[16];
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t11;
    char *t12;
    char *t14;
    char *t16;
    char *t17;
    int t18;
    unsigned int t19;
    unsigned char t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;

LAB0:    xsi_set_current_line(27, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = (0 - 3);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB3;

LAB4:
LAB7:    t26 = (t0 + 9454);
    t28 = (t0 + 5728);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    memcpy(t32, t26, 8U);
    xsi_driver_first_trans_fast(t28);

LAB2:    t33 = (t0 + 5584);
    *((int *)t33) = 1;

LAB1:    return;
LAB3:    t9 = (t0 + 9450);
    t11 = (t0 + 1032U);
    t12 = *((char **)t11);
    t14 = ((IEEE_P_2592010699) + 4024);
    t16 = (t15 + 0U);
    t17 = (t16 + 0U);
    *((int *)t17) = 0;
    t17 = (t16 + 4U);
    *((int *)t17) = 3;
    t17 = (t16 + 8U);
    *((int *)t17) = 1;
    t18 = (3 - 0);
    t19 = (t18 * 1);
    t19 = (t19 + 1);
    t17 = (t16 + 12U);
    *((unsigned int *)t17) = t19;
    t17 = (t0 + 9196U);
    t11 = xsi_base_array_concat(t11, t13, t14, (char)97, t9, t15, (char)97, t12, t17, (char)101);
    t19 = (4U + 4U);
    t20 = (8U != t19);
    if (t20 == 1)
        goto LAB5;

LAB6:    t21 = (t0 + 5728);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t11, 8U);
    xsi_driver_first_trans_fast(t21);
    goto LAB2;

LAB5:    xsi_size_not_matching(8U, t19, 0);
    goto LAB6;

LAB8:    goto LAB2;

}

static void work_a_2264602123_3212880686_p_1(char *t0)
{
    char t13[16];
    char t15[16];
    char t21[16];
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t11;
    char *t12;
    char *t14;
    char *t16;
    char *t17;
    int t18;
    unsigned int t19;
    char *t20;
    char *t22;
    unsigned int t23;
    unsigned char t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;

LAB0:    xsi_set_current_line(28, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = (1 - 3);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB3;

LAB4:
LAB7:    t30 = (t0 + 9465);
    t32 = (t0 + 5792);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    memcpy(t36, t30, 8U);
    xsi_driver_first_trans_fast(t32);

LAB2:    t37 = (t0 + 5600);
    *((int *)t37) = 1;

LAB1:    return;
LAB3:    t9 = (t0 + 9462);
    t11 = (t0 + 1032U);
    t12 = *((char **)t11);
    t14 = ((IEEE_P_2592010699) + 4024);
    t16 = (t15 + 0U);
    t17 = (t16 + 0U);
    *((int *)t17) = 0;
    t17 = (t16 + 4U);
    *((int *)t17) = 2;
    t17 = (t16 + 8U);
    *((int *)t17) = 1;
    t18 = (2 - 0);
    t19 = (t18 * 1);
    t19 = (t19 + 1);
    t17 = (t16 + 12U);
    *((unsigned int *)t17) = t19;
    t17 = (t0 + 9196U);
    t11 = xsi_base_array_concat(t11, t13, t14, (char)97, t9, t15, (char)97, t12, t17, (char)101);
    t22 = ((IEEE_P_2592010699) + 4024);
    t20 = xsi_base_array_concat(t20, t21, t22, (char)97, t11, t13, (char)99, (unsigned char)2, (char)101);
    t19 = (3U + 4U);
    t23 = (t19 + 1U);
    t24 = (8U != t23);
    if (t24 == 1)
        goto LAB5;

LAB6:    t25 = (t0 + 5792);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t20, 8U);
    xsi_driver_first_trans_fast(t25);
    goto LAB2;

LAB5:    xsi_size_not_matching(8U, t23, 0);
    goto LAB6;

LAB8:    goto LAB2;

}

static void work_a_2264602123_3212880686_p_2(char *t0)
{
    char t13[16];
    char t15[16];
    char t23[16];
    char t25[16];
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t11;
    char *t12;
    char *t14;
    char *t16;
    char *t17;
    int t18;
    unsigned int t19;
    char *t20;
    char *t22;
    char *t24;
    char *t26;
    char *t27;
    int t28;
    unsigned int t29;
    unsigned char t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;

LAB0:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = (2 - 3);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB3;

LAB4:
LAB7:    t35 = (t0 + 9477);
    t37 = (t0 + 5856);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    memcpy(t41, t35, 8U);
    xsi_driver_first_trans_fast(t37);

LAB2:    t42 = (t0 + 5616);
    *((int *)t42) = 1;

LAB1:    return;
LAB3:    t9 = (t0 + 9473);
    t11 = (t0 + 1032U);
    t12 = *((char **)t11);
    t14 = ((IEEE_P_2592010699) + 4024);
    t16 = (t15 + 0U);
    t17 = (t16 + 0U);
    *((int *)t17) = 0;
    t17 = (t16 + 4U);
    *((int *)t17) = 1;
    t17 = (t16 + 8U);
    *((int *)t17) = 1;
    t18 = (1 - 0);
    t19 = (t18 * 1);
    t19 = (t19 + 1);
    t17 = (t16 + 12U);
    *((unsigned int *)t17) = t19;
    t17 = (t0 + 9196U);
    t11 = xsi_base_array_concat(t11, t13, t14, (char)97, t9, t15, (char)97, t12, t17, (char)101);
    t20 = (t0 + 9475);
    t24 = ((IEEE_P_2592010699) + 4024);
    t26 = (t25 + 0U);
    t27 = (t26 + 0U);
    *((int *)t27) = 0;
    t27 = (t26 + 4U);
    *((int *)t27) = 1;
    t27 = (t26 + 8U);
    *((int *)t27) = 1;
    t28 = (1 - 0);
    t19 = (t28 * 1);
    t19 = (t19 + 1);
    t27 = (t26 + 12U);
    *((unsigned int *)t27) = t19;
    t22 = xsi_base_array_concat(t22, t23, t24, (char)97, t11, t13, (char)97, t20, t25, (char)101);
    t19 = (2U + 4U);
    t29 = (t19 + 2U);
    t30 = (8U != t29);
    if (t30 == 1)
        goto LAB5;

LAB6:    t27 = (t0 + 5856);
    t31 = (t27 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    memcpy(t34, t22, 8U);
    xsi_driver_first_trans_fast(t27);
    goto LAB2;

LAB5:    xsi_size_not_matching(8U, t29, 0);
    goto LAB6;

LAB8:    goto LAB2;

}

static void work_a_2264602123_3212880686_p_3(char *t0)
{
    char t11[16];
    char t17[16];
    char t19[16];
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    char *t18;
    char *t20;
    char *t21;
    int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned char t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;

LAB0:    xsi_set_current_line(30, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = (3 - 3);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB3;

LAB4:
LAB7:    t30 = (t0 + 9488);
    t32 = (t0 + 5920);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    memcpy(t36, t30, 8U);
    xsi_driver_first_trans_fast(t32);

LAB2:    t37 = (t0 + 5632);
    *((int *)t37) = 1;

LAB1:    return;
LAB3:    t9 = (t0 + 1032U);
    t10 = *((char **)t9);
    t12 = ((IEEE_P_2592010699) + 4024);
    t13 = (t0 + 9196U);
    t9 = xsi_base_array_concat(t9, t11, t12, (char)99, (unsigned char)2, (char)97, t10, t13, (char)101);
    t14 = (t0 + 9485);
    t18 = ((IEEE_P_2592010699) + 4024);
    t20 = (t19 + 0U);
    t21 = (t20 + 0U);
    *((int *)t21) = 0;
    t21 = (t20 + 4U);
    *((int *)t21) = 2;
    t21 = (t20 + 8U);
    *((int *)t21) = 1;
    t22 = (2 - 0);
    t23 = (t22 * 1);
    t23 = (t23 + 1);
    t21 = (t20 + 12U);
    *((unsigned int *)t21) = t23;
    t16 = xsi_base_array_concat(t16, t17, t18, (char)97, t9, t11, (char)97, t14, t19, (char)101);
    t23 = (1U + 4U);
    t24 = (t23 + 3U);
    t25 = (8U != t24);
    if (t25 == 1)
        goto LAB5;

LAB6:    t21 = (t0 + 5920);
    t26 = (t21 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    memcpy(t29, t16, 8U);
    xsi_driver_first_trans_fast(t21);
    goto LAB2;

LAB5:    xsi_size_not_matching(8U, t24, 0);
    goto LAB6;

LAB8:    goto LAB2;

}

static void work_a_2264602123_3212880686_p_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(35, ng0);

LAB3:    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t1 = (t0 + 5984);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 5648);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_2264602123_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2264602123_3212880686_p_0,(void *)work_a_2264602123_3212880686_p_1,(void *)work_a_2264602123_3212880686_p_2,(void *)work_a_2264602123_3212880686_p_3,(void *)work_a_2264602123_3212880686_p_4};
	xsi_register_didat("work_a_2264602123_3212880686", "isim/MUL4x4_test_isim_beh.exe.sim/work/a_2264602123_3212880686.didat");
	xsi_register_executes(pe);
}

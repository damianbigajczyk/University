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
static const char *ng0 = "C:/Users/Damian Bigajczyk/Desktop/WorkSpace/FPGA/Sterownik_wywietlacza_LED/Sterownik_wyswietlacza_LED.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );


static void work_a_1967724282_3212880686_p_0(char *t0)
{
    char t14[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;

LAB0:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4432);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(40, ng0);
    t1 = (t0 + 2152U);
    t5 = *((char **)t1);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    if (t7 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 1952U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB8;

LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(41, ng0);
    t1 = (t0 + 8174);
    t9 = (t0 + 4512);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 2U);
    xsi_driver_first_trans_fast(t9);
    goto LAB6;

LAB8:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 2632U);
    t5 = *((char **)t2);
    t2 = (t0 + 8104U);
    t8 = (t0 + 8176);
    t10 = (t14 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 0;
    t11 = (t10 + 4U);
    *((int *)t11) = 1;
    t11 = (t10 + 8U);
    *((int *)t11) = 1;
    t15 = (1 - 0);
    t16 = (t15 * 1);
    t16 = (t16 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t16;
    t4 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t5, t2, t8, t14);
    if (t4 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 8104U);
    t5 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t14, t2, t1, 1);
    t8 = (t14 + 12U);
    t16 = *((unsigned int *)t8);
    t21 = (1U * t16);
    t3 = (2U != t21);
    if (t3 == 1)
        goto LAB13;

LAB14:    t9 = (t0 + 4512);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t5, 2U);
    xsi_driver_first_trans_fast(t9);

LAB11:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 8104U);
    t5 = (t0 + 8180);
    t9 = (t14 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 1;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t15 = (1 - 0);
    t16 = (t15 * 1);
    t16 = (t16 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t16;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t14);
    if (t3 != 0)
        goto LAB15;

LAB17:    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 8104U);
    t5 = (t0 + 8186);
    t9 = (t14 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 1;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t15 = (1 - 0);
    t16 = (t15 * 1);
    t16 = (t16 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t16;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t14);
    if (t3 != 0)
        goto LAB18;

LAB19:    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 8104U);
    t5 = (t0 + 8192);
    t9 = (t14 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 1;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t15 = (1 - 0);
    t16 = (t15 * 1);
    t16 = (t16 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t16;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t14);
    if (t3 != 0)
        goto LAB20;

LAB21:    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 8104U);
    t5 = (t0 + 8198);
    t9 = (t14 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 1;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t15 = (1 - 0);
    t16 = (t15 * 1);
    t16 = (t16 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t16;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t14);
    if (t3 != 0)
        goto LAB22;

LAB23:
LAB16:    goto LAB6;

LAB10:    xsi_set_current_line(44, ng0);
    t11 = (t0 + 8178);
    t13 = (t0 + 4512);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t11, 2U);
    xsi_driver_first_trans_fast(t13);
    goto LAB11;

LAB13:    xsi_size_not_matching(2U, t21, 0);
    goto LAB14;

LAB15:    xsi_set_current_line(50, ng0);
    t10 = (t0 + 1032U);
    t11 = *((char **)t10);
    t10 = (t0 + 4576);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t11, 4U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(51, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t15 = (0 - 3);
    t16 = (t15 * -1);
    t21 = (1U * t16);
    t22 = (0 + t21);
    t1 = (t2 + t22);
    t3 = *((unsigned char *)t1);
    t5 = (t0 + 4640);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t3;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(52, ng0);
    t1 = (t0 + 8182);
    t5 = (t0 + 4704);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB16;

LAB18:    xsi_set_current_line(54, ng0);
    t10 = (t0 + 1192U);
    t11 = *((char **)t10);
    t10 = (t0 + 4576);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t11, 4U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t15 = (1 - 3);
    t16 = (t15 * -1);
    t21 = (1U * t16);
    t22 = (0 + t21);
    t1 = (t2 + t22);
    t3 = *((unsigned char *)t1);
    t5 = (t0 + 4640);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t3;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(56, ng0);
    t1 = (t0 + 8188);
    t5 = (t0 + 4704);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB16;

LAB20:    xsi_set_current_line(58, ng0);
    t10 = (t0 + 1352U);
    t11 = *((char **)t10);
    t10 = (t0 + 4576);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t11, 4U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(59, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t15 = (2 - 3);
    t16 = (t15 * -1);
    t21 = (1U * t16);
    t22 = (0 + t21);
    t1 = (t2 + t22);
    t3 = *((unsigned char *)t1);
    t5 = (t0 + 4640);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t3;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(60, ng0);
    t1 = (t0 + 8194);
    t5 = (t0 + 4704);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB16;

LAB22:    xsi_set_current_line(62, ng0);
    t10 = (t0 + 1512U);
    t11 = *((char **)t10);
    t10 = (t0 + 4576);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t11, 4U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(63, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t15 = (3 - 3);
    t16 = (t15 * -1);
    t21 = (1U * t16);
    t22 = (0 + t21);
    t1 = (t2 + t22);
    t3 = *((unsigned char *)t1);
    t5 = (t0 + 4640);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t3;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(64, ng0);
    t1 = (t0 + 8200);
    t5 = (t0 + 4704);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB16;

}


extern void work_a_1967724282_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1967724282_3212880686_p_0};
	xsi_register_didat("work_a_1967724282_3212880686", "isim/TEST_isim_beh.exe.sim/work/a_1967724282_3212880686.didat");
	xsi_register_executes(pe);
}

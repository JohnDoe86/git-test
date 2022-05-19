/* Copyright (c) 2020 Synopsys, Inc. All rights reserved worldwide. */

/*
 * Rule 11.9 (Required):
 * The macro NULL shall be the only permitted form of integer null pointer constant.
 */

// 空指针只允许用NULL形式，不能用0替代
// NULL形式看测试用例里面可以写作 (void *)0,取指针地址 

#include <stdint.h>

//#defect
int32_t *p1_ = 0; /* Non-compliant */  

int32_t *p2_ = (void *)0; /* Compliant */ //#nodefect

int32_t *p1;
#define MY_NULL_1 0
void Rule11_9_example_1(void)
{
    //#defect
    if (p1 == MY_NULL_1) /* Non-compliant */  //字符替换，指针p1 == 数字0
    {
    }
}

int32_t *p2;
#define MY_NULL_2 (void *)0
void Rule11_9_example_2(void)
{
    if (p2 == MY_NULL_2) /* Compliant */ //#nodefect //字符替换 指针p2 == 无类型的指针
    {
    }
}

extern void f(uint8_t *p);
/* Compliant for any conforming definition of NULL, such as:
* 0
* ( void * ) 0
* ( ( ( 0 ) ) )
* ( ( ( 1 - 1 ) ) )
*/
#define NULL (((1 - 1)))   //NULL宏被赋给0
void Rule11_9_example_3(void)
{
    f(NULL); //#nodefect //函数参数为int整形指针， 
}

/* end of standard.c */

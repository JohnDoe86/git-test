/* Copyright (c) 2020 Synopsys, Inc. All rights reserved worldwide. */

/*
 * Rule 11.9 (Required):
 * The macro NULL shall be the only permitted form of integer null pointer constant.
 */

#include <stddef.h>
#include <stdlib.h>

void Rule11_9_example_1(void)
{
    void *buf = (void *)0; //#nodefect  //void *形式的指针 Good
}

void Rule11_9_example_2(void)
{
    int *a = NULL;
    (1 == 1) ? a : NULL; //#nodefect    //NULL形式的指针Good
}

void Rule11_9_example_3(void)
{
    int *a = NULL;
    (1 == 1) ? NULL : a; //#nodefect  //NULL赋值和三木运算返回
}

void Rule11_9_example_4(void)
{
    int *a = NULL;
    //#defect
    (1 == 1) ? 0 : a;    //正确使用NULL，但是三目运算返回的是0形式
}

typedef signed char err_t;
#define ERR_OK 0
err_t Rule11_9_example_5()
{
    return ERR_OK; //#nodefect  //作为0值返回正确的情况
}

void Rule11_9_example_6(void)
{
    int *a = (((1 - 1))); //#nodefect  //fp
}

#define NULL_VAL 0
typedef _Bool bool;

// struct/union with pointer field
union c_un
{
    long *pt1;
    bool *pt2;
};

struct m_str
{
    int *pt1;
    union
    {
        double *pt2;
        bool *pt3;
    };
};

// struct/union with pointer/non-pointer fields
union m_un1
{
    int mem1;
    int *mem2;
};

// struct/union with non-pointer field
union m_un2
{
    long mem1;
    double mem2;
};

void Rule11_9_example_7(void)
{
    union c_un cu1 = {0};       //#nodefect  //0的多种含义, 可以表示地址为0x0？
    union c_un cu2 = {1};       //#nodefect  //int 类型转换为 long*
    union c_un *unPtr[3] = {0}; //#nodefect  //在C语言中，0相当于NULL
    struct m_str cs = {0};      //#nodefect

    union m_un1 c_un1 = {0};      //#nodefect  //int同类型赋值
    union m_un1 c_un2 = {1};      //#nodefect
    union m_un1 cu_arr1[3] = {0}; //#nodefect  

    union m_un2 c_un3 = {0};      //#nodefect  //短类型赋值长类型
    union m_un2 c_un4 = {1};      //#nodefect
    union m_un2 cu_arr2[3] = {0}; //#nodefect

    union c_un *c_un5 = {0};      //#defect //0赋值指针地址，不好
    union c_un *c_un6 = NULL_VAL; //#defect //同上

    union m_un1 *p_un1 = {0};      //#defect //同上
    union m_un1 *p_un2 = NULL_VAL; //#defect //同上

    union m_un2 *p_un3 = {0};      //#defect //同上
    union m_un2 *p_un4 = NULL_VAL; //#defect //同上
}



int *Rule11_9_example_8(void)
{
    //#defect
    return 0;  //0常量赋值到指针地址
}

void foo(int *a);

void Rule11_9_example_9(void)
{
    //#defect
    foo(0);       //0转指针
    foo((void *)0); //#nodefect  //可以接受的类型
    foo(1 - 1);     //#nodefect  //保持怀疑//fn
}

void Rule11_9_example_10(void)
{
    int *a = NULL;
    (a == (void *)0);  //NULL (void *)0 可以的吧
}

void Rule11_9_example_11(void)
{
    int *a = malloc(sizeof(int) * 10);
    if (a != NULL)  //nodefect //NULL与指针a比较
    {
        *a = 5;
    }
}

void Rule11_9_example_12(void)
{
    char *a = malloc(sizeof(char) * 10);
    //#defect
    if (a != 0)  //用到了0，意图0当作NULL与a指针比较
    {
        *a = 5;
    }
}

void Rule11_9_example_13(void)
{
    int *a = NULL;
    //#defect
    a == 0;
    a == NULL; //#nodefect  //显而易见
}

#include <stdint.h>

extern void Rule11_9_example_14(uint8_t *p);

void Rule11_9_example_15(void)
{
    Rule11_9_example_14(NULL); //#nodefect //函数指针参数用的NULL
}

static void *Rule11_9_example_16(void)
{
    int *ptr = NULL; //#nodefect    #NULL作为函数返回
    return NULL;     //#nodefect
}

void Rule11_9_example_17(void)
{
    int *ptrArr1[] = {NULL, NULL, NULL}; //#nodefect //NULL作为指针数组元素

    // initializing ptrArr2[2] with implicit 0 in the tail of the array.
    int *ptrArr2[3] = {(void *)NULL, NULL}; //#defect  //未赋值的元素默认为0，
}

#define null_val NULL //后面的NULL替换前面的
#define null 0LL      //long long 类型的0

typedef long* PINT32;  //long* 别名PINT32
typedef int* PINT;     //int* 别名PINT
typedef _Bool bool;    //_Bool C99标准

void Rule11_9_example_18(int *arg)
{
    if(arg != NULL)  //NULL与指针比较
    {
        *arg = 1;
    }
}

void Rule11_9_example_19(long *parm)
{
    if(parm != NULL)    //NULL与指针比较
    {
        *parm = 1L;
    }
}

struct cStu {
    int *pt1;
    bool *pt2;
};

enum myEnum
{
    ce1 = 1,
    ce2 = 0,
    ce3 = 2
};

/*
 * Compliant test cases:
 */

/*
 * Assign NULL to global pointer.
 */
int *cglobalVar1 = null_val; //#nodefect
bool *cglobalVar2 = NULL; //#nodefect
char *cglobalVar3 = (void *)NULL_VAL; //#nodefect
long *cglobalVar4 = (long *)(NULL_VAL); //#nodefect
int *cglobalVar5[3] = {0}; //#nodefect  //怀疑，这里用也是fp
int *cglobalVar6[2] = {(int *)(NULL_VAL), (int *)(NULL_VAL)}; //#nodefect

/*
 * Return NULL to pointer.
 */
int *Rule11_9_example_20(void)
{
    return NULL; //#nodefect  //NULL做函数的返回值
}  

/*
 * Return NULL to pointer pointing to another pointer.
 */
int **Rule11_9_example_21(void)   
{
    return null_val; //#nodefect     //NULL做函数的返回值
}

/*
 * Assign NULL to function integr pointer argument.
 */
void Rule11_9_example_22(void)
{
    Rule11_9_example_18(NULL);  //#nodefect   //NULL做函数的参数，函数在187行
}

/*
 * Assign NULL to integr pointer variable(static, const, volatile and so on).
 */
void Rule11_9_example_23(void)    //NULL赋值给各种类型的指针
{
    int *ptr = NULL; //#nodefect
    PINT pVal = NULL; //#nodefect
    bool *pBool = NULL; //#nodefect
    long *const pInt1 = NULL; //#nodefect
    const long *const pInt2 = NULL; //#nodefect
    long *pInt3 = null_val; //#nodefect
    long long *pInt4 = (long long *)NULL_VAL; //#nodefect
    unsigned char *pUChr = (unsigned char *)(0); //#nodefect

    signed char *pChr = null_val; //#nodefect
    if(pChr == ((void *)NULL_VAL)) //#nodefect
    {

    }

    int num = (pInt3 == null_val) ? 0 : 1; //#nodefect
}

/*
 * Assign NULL to struct member with pointer type.
 */
void Rule11_9_example_24(void)
{
    struct cStu cs;         //指针赋值给结构体成员 并做比较
    cs.pt1 = NULL; //#nodefect
    cs.pt2 = null_val; //#nodefect

    while(cs.pt2 != ((void *)NULL_VAL)) //#nodefect
    {

    }

    cs.pt1 = (NULL_VAL, NULL); //#nodefect
}

/*
 * Assign NULL to enum and array member with pointer type.
 */
void Rule11_9_example_25(void)    
{
    enum myEnum *cePtr = NULL;   //#nodefect  //NULL赋值给指针
    PINT cArr1[2] = {(void *)NULL_VAL, null_val}; //#nodefect
    int *cArr2[3] = {NULL, NULL, NULL}; //#nodefect
    int *cArr3[2] = {(int *)(NULL_VAL), (int *)(NULL_VAL)}; //#nodefect
    int *cArr4[2][2] = {NULL, NULL, NULL, NULL}; //#nodefect
    int *cArr5[5] = {0}; //#nodefect   //怀疑 //fn
    PINT cArr6[3] = {0, 0, 0}; //#nodefect  //怀疑  //fn
    int *cArr7[3] = {NULL_VAL, NULL_VAL}; //#nodefect //怀疑 //fn
    int *cArr8[2][2][3] = {0, 0, 0}; //#nodefect  //怀疑 //fn
}

/*
 * Explicit cast from NULL to pointer.
 */
int *Rule11_9_example_26(void)
{
    int *cast_data = (int *)(null_val); //#nodefect  //显式转换
    unsigned int *pCast = (unsigned int *)NULL_VAL; //#nodefect  //显式转换
    return (int *)(NULL); //#nodefect //显式转换
}

/*
 * Nested macros of NULL used as null pointer constant.
 */
#define NUM1 0x01
typedef struct arr_state_st
{
    char *arr_dat[16];
    int arr_dat_flag[16];
    int top;
} ARR_ST;

#define arr_clear_dat(p,i) \
    do { \
        if (((p)->arr_dat[i] != NULL) && \      //关注这一行的意思，define之后为空，默认0
        (p)->arr_dat_flag[i] & NUM1) \
        {  \
        } \
    } while(0)

void Rule11_9_example_27(void)
{
    ARR_ST *es;     //野指针，既不是0也不是NULL，所以是nodefect
    int i;
    i = es->top;

    arr_clear_dat(es, i); //#nodefect
}

#define VOID void*
#define FUN(type) type
#define CondMacro1(type, p) ((type *)(1 ? p : (FUN(int) *)0))
#define CondMacro2(type, p) ((type *)(1 ? p : (VOID)0))

void Rule11_9_example_28(void)
{
    int *ptr = NULL; //#nodefect
    ptr = CondMacro1(int, ptr); //#nodefect
    ptr = CondMacro2(int, ptr); //#nodefect   //带参数的宏
}

void Rule11_9_example_29(void)
{
    static const char *cList1[]=
    {
        "12",
        "34",
        (char *) NULL //#nodefect    //NULL做指针变量
    };

    static const char *cList2[]=
    {
        "12",
        "34",
        NULL //#nodefect
    };
}

/*
 * Assign literal 0LL or 0 to global integr pointer variable.
 */
int *nglobalVar1 = NULL_VAL; //#defect    //0
bool *nglobalVar2 = null; //#defect       //0ll
char *nglobalVar3 = null; //#defect       //0ll
PINT32 nglobalVar4 = 0; //#defect         //o ---> pointer
int32_t *ngArr[3] = {(void *)null}; //#defect

/*
 * Return literal 0LL to int pointer.   //返回值为0LL或者0
 */
int *Rule11_9_example_30(void)
{
    return null; //#defect
}

/*
 * Return literal 0 to pointer pointing to another pointer.
 */
int **Rule11_9_example_31(void)
{
    return NULL_VAL; //#defect   //返回值为0LL或者0， 二级指针
}

/*
 * Assign literal 0LL or 0 to function integr pointer argument.
 */
void Rule11_9_example_32(void)
{
    Rule11_9_example_18(null); //#defect    //函数参数是指针，0--->pointer
    Rule11_9_example_19(NULL_VAL); //#defect    //同上
}

/*
 * Assign literal 0LL or 0 to integr pointer variable(static,
 * const, volatile and so on).
 */
void Rule11_9_example_33(void)
{
    int32_t *iVal1 = null; //#defect
    static int *iVal3 = NULL_VAL; //#defect
    volatile int *pInt1 = null; //#defect
    bool *pBool = NULL_VAL; //#defect
    signed char *pInt2 = null; //#defect
    const long *pInt3 = NULL_VAL; //#defect
    int * const pInt4 = null; //#defect
    PINT32 pInt5 = null; //#defect
    long long *pInt6 = 0; //#defect
}  //以上全是0 或者 0LL 转换到指针的情况

/*
 * Assign literal 0LL or 0 to struct member with intger pointer type.
 */
void Rule11_9_example_34(void)
{
    struct cStu ns;
    ns.pt1 = NULL_VAL; //#defect
    ns.pt2 = null; //#defect
    ns.pt1 = (ns.pt1 == null) ? NULL_VAL : nglobalVar1; //#defect
    ns.pt2 = ((void *)0LL, 0); //#defect
    ns.pt1 = (0, null, 0); //#defect
}   
    //cStu成员全是指针变量，以上都是在用0指向指针

/*
 * Assign literal 0LL or 0 to enum and array member with pointer type.
 */
void Rule11_9_example_35(void)
{
    enum myEnum *nePtr = NULL_VAL; //#defect
    PINT32 nArr1[2] = {(void *)null, 0}; //#defect
    int32_t *nArr2[5] = {(void *)0, 0}; //#defect
    int *nArr3[3] = {(void *)0}; //#defect
    PINT32 nArr4[3] = {(void *)0, 0, 0}; //#defect
    int *nArrr5[2][2] = {(void *)0, 0, 0}; //#defect
    int *nArrr6[2][2][2] = {(void *)0, 0, (void *)NULL_VAL, 0}; //#defect
}   //使用0去赋值指针变量，默认没有赋值的指针变量元素也是0.

/*
 * Assign literal 0LL or 0 to compare with pointer type.
 */
void Rule11_9_example_36(void)
{
    //
    int *pInt = NULL;  //#nodefect
    if(pInt == NULL_VAL) //#defect   //0与指针比较
    {

    }

    bool b1 = 1;
    bool b2 = 0;

    pInt = b1 ? null : nglobalVar1; //#defect
    pInt = b2 ? nglobalVar1 : NULL_VAL; //#defect
    //三目运算作为返回第一、第二参数的情况
}

/* end of test.c */

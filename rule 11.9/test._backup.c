/* Copyright (c) 2020 Synopsys, Inc. All rights reserved worldwide. */

/*
 * Rule 11.9 (Required):
 * The macro NULL shall be the only permitted form of integer null pointer constant.
 */

#include <stddef.h>
#include <stdlib.h>

void Rule11_9_example_1(void)
{
    void *buf = (void *)0; //#nodefect#TS1
}

void Rule11_9_example_2(void)
{
    int *a = NULL;       //#nodefect#TS1
    (1 == 1) ? a : NULL; //#nodefect#TS3
}

void Rule11_9_example_3(void)
{
    int *a = NULL;       //#nodefect#TS1
    (1 == 1) ? NULL : a; //#nodefect#TS4
}

void Rule11_9_example_4(void)
{
    int *a = NULL;    //#nodefect#TS1
    (1 == 1) ? 0 : a; //#defect#TS4
}

typedef signed char err_t;
#define ERR_OK 0
err_t Rule11_9_example_5()
{
    return ERR_OK; //#nodefect#TS1
}

void Rule11_9_example_6(void)
{
    int *a = (((1 - 1))); //#fpdefect#SATW-4406#TS1
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
    union c_un cu1 = {0};       //#nodefect#TS1
    union c_un cu2 = {1};       //#nodefect#TS1
    union c_un *unPtr[3] = {0}; //#nodefect#TS1
    struct m_str cs = {0};      //#nodefect#TS1

    union m_un1 c_un1 = {0};      //#nodefect#TS1
    union m_un1 c_un2 = {1};      //#nodefect#TS1
    union m_un1 cu_arr1[3] = {0}; //#nodefect#TS1

    union m_un2 c_un3 = {0};      //#nodefect#TS1
    union m_un2 c_un4 = {1};      //#nodefect#TS1
    union m_un2 cu_arr2[3] = {0}; //#nodefect#TS1

    union c_un *c_un5 = {0};      //#defect#TS1
    union c_un *c_un6 = NULL_VAL; //#defect#TS1

    union m_un1 *p_un1 = {0};      //#defect#TS1
    union m_un1 *p_un2 = NULL_VAL; //#defect#TS1

    union m_un2 *p_un3 = {0};      //#defect#TS1
    union m_un2 *p_un4 = NULL_VAL; //#defect#TS1
}

int *Rule11_9_example_8(void)
{
    //#defect#TS1
    return 0;
}

void foo(int *a);

void Rule11_9_example_9(void)
{
    //#defect#TS1
    foo(0);
    foo((void *)0); //#nodefect#TS1
    foo(1 - 1);     //#fpdefect#SATW-4406#TS1
}

void Rule11_9_example_10(void)
{
    int *a = NULL;    //#nodefect#TS1
    (a == (void *)0); //#nodefect#TS2
}

void Rule11_9_example_11(void)
{
    int *a = malloc(sizeof(int) * 10);
    if (a != NULL) //#nodefect#TS2
    {
        *a = 5;
    }
}

void Rule11_9_example_12(void)
{
    char *a = malloc(sizeof(char) * 10);
    //#defect#TS2
    if (a != 0)
    {
        *a = 5;
    }
}

void Rule11_9_example_13(void)
{
    int *a = NULL; //#nodefect#TS1
    a == 0;        //#defect#TS2
    a == NULL;     //#nodefect#TS2
}

#include <stdint.h>

extern void Rule11_9_example_14(uint8_t *p);

void Rule11_9_example_15(void)
{
    Rule11_9_example_14(NULL); //#nodefect#TS1
}

static void *Rule11_9_example_16(void)
{
    int *ptr = NULL; //#nodefect#TS1
    return NULL;     //#nodefect#TS1
}

void Rule11_9_example_17(void)
{
    int *ptrArr1[] = {NULL, NULL, NULL}; //#nodefect#TS1

    // initializing ptrArr2[2] with implicit 0 in the tail of the array.
    int *ptrArr2[3] = {(void *)NULL, NULL}; //#defect#TS1
}

#define null_val NULL
#define null 0LL

typedef long *PINT32;
typedef int *PINT;
typedef _Bool bool;

void Rule11_9_example_18(int *arg)
{
    if (arg != NULL) //#defect#TS2
    {
        *arg = 1;
    }
}

void Rule11_9_example_19(long *parm)
{
    if (parm != NULL) //#defect#TS2
    {
        *parm = 1L;
    }
}

/*
 * Compliant test cases:
 */

/*
 * Assign NULL to global pointer.
 */
int *cglobalVar1 = null_val;                                  //#nodefect#TS1
bool *cglobalVar2 = NULL;                                     //#nodefect#TS1
char *cglobalVar3 = (void *)NULL_VAL;                         //#nodefect#TS1
long *cglobalVar4 = (long *)(NULL_VAL);                       //#nodefect#TS1
int *cglobalVar5[3] = {0};                                    //#fpdefect#SATW-4406#TS1
int *cglobalVar6[2] = {(int *)(NULL_VAL), (int *)(NULL_VAL)}; //#nodefect#TS1

/*
 * Return NULL to pointer.
 */
int *Rule11_9_example_20(void)
{
    return NULL; //#nodefect#TS1
}

/*
 * Return NULL to pointer pointing to another pointer.
 */
int **Rule11_9_example_21(void)
{
    return null_val; //#nodefect#TS1
}

/*
 * Assign NULL to function integr pointer argument.
 */
void Rule11_9_example_22(void)
{
    Rule11_9_example_18(NULL); //#nodefect#TS1
}

/*
 * Assign NULL to integr pointer variable(static, const, volatile and so on).
 */
void Rule11_9_example_23(void)
{
    int *ptr = NULL;                             //#nodefect#TS1
    PINT pVal = NULL;                            //#nodefect#TS1
    bool *pBool = NULL;                          //#nodefect#TS1
    long *const pInt1 = NULL;                    //#nodefect#TS1
    const long *const pInt2 = NULL;              //#nodefect#TS1
    long *pInt3 = null_val;                      //#nodefect#TS1
    long long *pInt4 = (long long *)NULL_VAL;    //#nodefect#TS1
    unsigned char *pUChr = (unsigned char *)(0); //#nodefect#TS1

    signed char *pChr = null_val;   //#nodefect#TS1
    if (pChr == ((void *)NULL_VAL)) //#nodefect#TS2
    {
    }

    int num = (pInt3 == null_val) ? 0 : 1; //#nodefect#TS2
}

struct cStu
{
    int *pt1;
    bool *pt2;
};

/*
 * Assign NULL to struct member with pointer type.
 */
void Rule11_9_example_24(void)
{
    struct cStu cs;
    cs.pt1 = NULL;     //#nodefect#TS1
    cs.pt2 = null_val; //#nodefect#TS1

    while (cs.pt2 != ((void *)NULL_VAL)) //#nodefect#TS2
    {
    }

    cs.pt1 = (NULL_VAL, NULL); //#nodefect#TS1
}

/*
 * Assign literal 0LL or 0 to struct member with intger pointer type.
 */
void Rule11_9_example_34(void)
{
    struct cStu ns;
    ns.pt1 = NULL_VAL;                                  //#defect#TS1
    ns.pt2 = null;                                      //#defect#TS1
    ns.pt1 = (ns.pt1 == null) ? NULL_VAL : nglobalVar1; //#defect#TS4
    ns.pt2 = ((void *)0LL, 0);                          //#defect#TS1
    ns.pt1 = (0, null, 0);                              //#defect#TS1
}

enum myEnum
{
    ce1 = 1,
    ce2 = 0,
    ce3 = 2
};

/*
 * Assign NULL to enum and array member with pointer type.
 */
void Rule11_9_example_25(void)
{
    enum myEnum *cePtr = NULL;                              //#nodefect#TS1
    PINT cArr1[2] = {(void *)NULL_VAL, null_val};           //#nodefect#TS1
    int *cArr2[3] = {NULL, NULL, NULL};                     //#nodefect#TS1
    int *cArr3[2] = {(int *)(NULL_VAL), (int *)(NULL_VAL)}; //#nodefect#TS1
    int *cArr4[2][2] = {NULL, NULL, NULL, NULL};            //#nodefect#TS1
    int *cArr5[5] = {0};                                    //#fpdefect#SATW-4406#TS1
    PINT cArr6[3] = {0, 0, 0};                              //#fpdefect#SATW-4406#TS1
    int *cArr7[3] = {NULL_VAL, NULL_VAL};                   //#fpdefect#SATW-4406#TS1
    int *cArr8[2][2][3] = {0, 0, 0};                        //#fpdefect#SATW-4406#TS1
}

/*
 * Assign literal 0LL or 0 to enum and array member with pointer type.
 */
void Rule11_9_example_35(void)
{
    enum myEnum *nePtr = NULL_VAL;                              //#defect#TS1
    PINT32 nArr1[2] = {(void *)null, 0};                        //#defect#TS1
    int32_t *nArr2[5] = {(void *)0, 0};                         //#defect#TS1
    int *nArr3[3] = {(void *)0};                                //#defect#TS1
    PINT32 nArr4[3] = {(void *)0, 0, 0};                        //#defect#TS1
    int *nArrr5[2][2] = {(void *)0, 0, 0};                      //#defect#TS1
    int *nArrr6[2][2][2] = {(void *)0, 0, (void *)NULL_VAL, 0}; //#defect#TS1
}

/*
 * Explicit cast from NULL to pointer.
 */
int *Rule11_9_example_26(void)
{
    int *cast_data = (int *)(null_val);             //#nodefect#TS1
    unsigned int *pCast = (unsigned int *)NULL_VAL; //#nodefect#TS1
    return (int *)(NULL);                           //#nodefect#TS1
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

#define arr_clear_dat(p, i)              \
    do                                   \
    {                                    \
        if (((p)->arr_dat[i] != NULL) && \
            (p)->arr_dat_flag[i] & NUM1) \
        {                                \
        }                                \
    } while (0)

void Rule11_9_example_27(void)
{
    ARR_ST *es;
    int i;
    i = es->top;

    arr_clear_dat(es, i); //#nodefect#TS1
}

#define VOID void *
#define FUN(type) type
#define CondMacro1(type, p) ((type *)(1 ? p : (FUN(int) *)0))
#define CondMacro2(type, p) ((type *)(1 ? p : (VOID)0))

void Rule11_9_example_28(void)
{
    int *ptr = NULL;            //#nodefect#TS1
    ptr = CondMacro1(int, ptr); //#nodefect#TS1
    ptr = CondMacro2(int, ptr); //#nodefect#TS1
}

void Rule11_9_example_29(void)
{
    static const char *cList1[] =
        {
            "12",
            "34",
            (char *)NULL //#nodefect#TS1
        };

    static const char *cList2[] =
        {
            "12",
            "34",
            NULL //#nodefect#TS1
        };
}

/*
 * Assign literal 0LL or 0 to global integr pointer variable.
 */
int *nglobalVar1 = NULL_VAL;        //#defect#TS1
bool *nglobalVar2 = null;           //#defect#TS1
char *nglobalVar3 = null;           //#defect#TS1
PINT32 nglobalVar4 = 0;             //#defect#TS1
int32_t *ngArr[3] = {(void *)null}; //#defect#TS1

/*
 * Return literal 0LL to int pointer.
 */
int *Rule11_9_example_30(void)
{
    return null; //#defect#TS1
}

/*
 * Return literal 0 to pointer pointing to another pointer.
 */
int **Rule11_9_example_31(void)
{
    return NULL_VAL; //#defect#TS1
}

/*
 * Assign literal 0LL or 0 to function integr pointer argument.
 */
void Rule11_9_example_32(void)
{
    Rule11_9_example_18(null);     //#defect#TS1
    Rule11_9_example_19(NULL_VAL); //#defect#TS1
}

/*
 * Assign literal 0LL or 0 to integr pointer variable(static,
 * const, volatile and so on).
 */
void Rule11_9_example_33(void)
{
    int32_t *iVal1 = null;        //#defect#TS1
    static int *iVal3 = NULL_VAL; //#defect#TS1
    volatile int *pInt1 = null;   //#defect#TS1
    bool *pBool = NULL_VAL;       //#defect#TS1
    signed char *pInt2 = null;    //#defect#TS1
    const long *pInt3 = NULL_VAL; //#defect#TS1
    int *const pInt4 = null;      //#defect#TS1
    PINT32 pInt5 = null;          //#defect#TS1
    long long *pInt6 = 0;         //#defect#TS1
}

/*
 * Assign literal 0LL or 0 to compare with pointer type.
 */
void Rule11_9_example_36(void)
{
    int *pInt = NULL;     //#nodefect#TS1
    if (pInt == NULL_VAL) //#defect#TS2
    {
    }

    bool b1 = 1;
    bool b2 = 0;

    pInt = b1 ? null : nglobalVar1;     //#defect#TS4
    pInt = b2 ? nglobalVar1 : NULL_VAL; //#defect#TS3
}

/* end of test.c */

/* Copyright (c) 2020 Synopsys, Inc. All rights reserved worldwide. */

/*
 * Rule 7.1 (Required):
 * Octal constants shall not be used.
 */

#include <sysheader.h>
#include <stdint.h>

void Rule7_1_example_1(void)
{
    int x = 077; //#defect#TS2
}

void Rule7_1_example_2(void)
{
    int x = 63; //#nodefect#TS2
}

extern uint16_t code3[10];

void Rule7_1_example_3(void)
{
    code3[1] = 109; //#nodefect#TS2
}

extern uint16_t code4[10];

void Rule7_1_example_4(void)
{
    code4[2] = 100; //#nodefect#TS2
}

extern uint16_t code5[10];

void Rule7_1_example_5(void)
{
    code5[3] = 052; //#defect#TS1
}

typedef enum _DiskStatusCode_t //#nodefect#E1
{
    DiskCommandPass = 0,
    DiskNotReady,
    DiskNotPresent,
    DiskParametersError,
    DiskMiscompareError,
    DiskChanged,
    DiskUknowError,
} DiskStatusCode_t; //#nodefect#E1

void Rule7_1_example_6(void)
{
    char s[] = "\077"; //#nodefect#TS3
}

void Rule7_1_example_7(void)
{
    int x = '\077'; //#nodefect#TS3
}

void Rule7_1_example_8(void)
{
    int x = 0; //#nodefect#E1
}

extern uint16_t code9[10];

void Rule7_1_example_9(void)
{
    code9[4] = 071; //#defect#TS2
}

void Rule7_1_example_10()
{
    int i = SYSCONST; //#nodefect#TS2
}

/* end of test.c */

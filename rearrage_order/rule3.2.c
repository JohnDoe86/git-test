/* Copyright (c) 2020 Synopsys, Inc. All rights reserved worldwide. */

/*
 * Rule 3.2 (Required):
 * Line-splicing shall not be used in // comments.
 */

#include <stdint.h>
#include <stdbool.h>

//#defect#TS1
// This comment \
has a line splice

extern int b;

void Rule3_2_example_1(void)
{
    //#defect#TS1
    unsigned int x = 0; // comment \
    if ( b )
    {
        ++x; /* This is always executed */
    }
}

void Rule3_2_example_2()
{
    // developer intended to add a comment but commented the next line as well
    bool b = true;
    //#defect#TS1
    uint16_t x = 0; // comment \
    if (b)
    {
        x++;
    }
}

//#defect#TS1
// \
Issue warning

/* Comment may have multiple splicing. We only want to emit one warning. */
//#defect#TS1
// \ // \ // \ // \
\
\
comment

//#defect#TS1
// /*\
*/

//#nodefect#TS2
// \ // no warning

//#nodefect#TS2
// // \ // \ // \ \\ //

//#nodefect#TS2
// This comment
// has no line splice

/* These testcases are technically invalid MISRA C-2012 code
   since nested comments are not allowed. */

//#nodefect#TS3
/* // \
*/


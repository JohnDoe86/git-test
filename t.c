#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef void (*fp16) (int16_t n);
typedef fp16 (*pfp16)(void);

void Rule11_1_example_15(void)
{
	pfp16 pfp1;
	(void*)(pfp1);
}

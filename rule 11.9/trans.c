#include <stdio.h>
#include <stdint-gcc.h>

extern void f(uint8_t *p);
/* Compliant for any conforming definition of NULL, such as:
* 0
* ( void * ) 0
* ( ( ( 0 ) ) )
* ( ( ( 1 - 1 ) ) )
*/
#define NULL (((1 - 1)))
void Rule11_9_example_3(void)
{
    f(NULL); //#nodefect
    //等价于
    f((((1-1))));
}

void Rule11_9_example_4(void)
{
    f((((1 - 1))));
    f((((1-1))));
}
/* end of standard.c */
int main() {
    printf("Hello, World!\n");
    Rule11_9_example_3();
    Rule11_9_example_4();
    return 0;
}

#include <stdio.h>

union c_un
{
    long *pt1;
    bool *pt2;
};

int main() {
    printf("Hello, World!\n");
    union c_un cu2 = {1};
    return 0;
}

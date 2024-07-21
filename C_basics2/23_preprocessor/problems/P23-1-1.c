#include <stdio.h>

#define ADD_THREE(X, Y, Z)      ((X) + (Y) + (Z))
#define MUL_THREE(X, Y, Z)      ((X) * (Y) * (Z))

int main(void)
{
    printf("3 + 4 + 5 = %d \n", ADD_THREE(3, 4, 5));
    printf("3 * 4 * 5 = %d \n", MUL_THREE(3, 4, 5));

    return 0;
}
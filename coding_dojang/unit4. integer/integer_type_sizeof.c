#include <stdio.h>

int main()
{
    // char: 1, short: 2, int: 4, long: 8, long long: 8
    printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
        sizeof(char),
        sizeof(short),
        sizeof(int),
        sizeof(long),
        sizeof(long long));
    
    return 0;
}
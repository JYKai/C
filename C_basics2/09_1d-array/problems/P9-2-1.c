#include <stdio.h>

int main(void)
{
    char arr[100];
    int count = 0;

    scanf("%s", arr);
    
    while (arr[count] != 0) { count++; }
    printf("%d\n", count);
    return 0;
}
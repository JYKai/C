#include <stdio.h>

int main(void)
{
    int cur = 2;
    int is = 0;

    do
    {
       is = 1;
       while (is < 10)
       {
           printf("%d x %d = %d \n", cur, is, cur * is);
           is++;
       }
       cur++;
    } while (cur < 10);
    
    return 0;
}
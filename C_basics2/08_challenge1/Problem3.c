#include <stdio.h>

int maxNum(int num1, int num2)
{
    if (num1 > num2) { return num1; }
    else if (num1 < num2) { return num2; }
    else { return num1; }
}

int main(void)
{
    int num1, num2, larger, gcd;
    int i;
    scanf("%d %d", &num1, &num2);

    larger = maxNum(num1, num2);
    gcd = 1;
    for (i = 2; i <= larger; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i;
        }
    }
    printf("두 정수 %d, %d의 최대공약수 = %d \n", num1, num2, gcd);
    
    return 0;
}
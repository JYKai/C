// 문자열을 출력하는 puts, fputs 함수

#include <stdio.h>

int main(void)
{
    char str[80] = "apple juice";
    char *ps = "banana";

    puts(str);              // apple juice
    fputs(ps, stdout);      // bananamilk
    puts("milk");

    return 0;
}
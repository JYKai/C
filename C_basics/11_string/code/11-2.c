// 포인터로 문자열을 사용하는 방법

#include <stdio.h>

int main(void)
{
    char *dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert); // 오늘 후식은 apple입니다.
    dessert = "banana";
    printf("내일 후식은 %s입니다.\n", dessert); // 내일 후식은 banana입니다.

    return 0;
}
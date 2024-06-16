// 문자열 상수가 주소란 증거

#include <stdio.h>

int main(void)
{
    printf("apple이 지정된 시작 주소 값 : %p\n", "apple");  // apple이 지정된 시작 주소 값 : 0x100d1bf1f
    printf("두 번째 문자의 주소 값 : %p\n", "apple" + 1);   // 두 번째 문자의 주소 값 : 0x100d1bf20
    printf("첫 번째 문자 : %c\n", *"apple");              // 첫 번째 문자 : a
    printf("두 번째 문자 : %c\n", *("apple" + 1));        // 두 번째 문자 : p
    printf("배열로 표현한 세 번째 문자 : %c\n", "apple"[2]);  // 배열로 표현한 세 번째 문자 : p

    return 0;
}
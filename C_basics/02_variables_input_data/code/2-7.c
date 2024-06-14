// char 배열에 문자열 복사

#include <stdio.h>
#include <string.h>

int main(void)
{
    char fruit[20] = "strawberry";

    printf("%s\n", fruit); // strawberry
    strcpy(fruit, "banana"); 
    printf("%s\n", fruit); // banana

    return 0;
}
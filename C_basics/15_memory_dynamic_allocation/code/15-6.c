// 명령행 인수를 출력하는 프로그램

#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    for (i = 0; i < argc; i++) { printf("%s\n", argv[i]); }

    return 0;
}
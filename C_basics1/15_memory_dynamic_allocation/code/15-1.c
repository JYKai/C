// 동적 할당한 저장 공간을 사용하는 프로그램

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;    // 동적 할당 영역을 연결할 포인터 선언
    double *pd;

    pi = (int *)malloc(sizeof(int));        // 메모리 동적 할당 후 포인터 연결
    if (pi == NULL)                         // 동적 할당에 실패하면 NULL 포인터 반환
    {
        printf("# 메모리가 부족합니다.\n");
        exit(1);                            // 프로그램 종료
    }
    pd = (double *)malloc(sizeof(double));

    *pi = 10;
    *pd = 3.4;

    printf("정수형으로 사용 : %d\n", *pi);
    printf("실수형으로 사용 : %.1lf\n", *pd);

    free(pi);
    free(pd);

    return 0;
}
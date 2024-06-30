# 다차원 배열과 포인터의 관계

## 2차원 배열이름의 포인터 형
2차원 배열이름을 대상으로 증가 및 감소연산을 할 경우, 연산결과는 각 행의 첫 번째 요소의 주소 값이 된다.
- 2차원 배열이름의 포인터 형은 가로의 길이에 따라서도 달라진다.

</br>

## 2차원 배열이름의 특성과 주의사항

### 주의! '배열 포인터'와 '포인터 배열'을 혼동하지 말자.
```c
int * whoA [4];     // 포인터 배열
int (*whoB) [4];    // 배열 포인터
```
- whoA : 배열 선언
    - int형 포인터 배열
- whoB : 포인터 변수 선언
    - 가로길이가 4인 int형 2차원 배열을 가리키는 용도의 포인터 변수

```c
#include <stdio.h>

int main(void)
{
    int num1 = 10, num2 = 20, num3 = 30, num4 = 40;
    int arr2d[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int i, j;

    int * whoA[4] = { &num1, &num2, &num3, &num4};      // 포인터 배열
    int (*whoB)[4] = arr2d;                             // 배열 포인터

    printf("%d %d %d %d \n", *whoA[0], *whoA[1], *whoA[2], *whoA[3]);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", whoB[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```
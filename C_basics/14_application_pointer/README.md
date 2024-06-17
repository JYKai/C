# 응용 포인터

## 이중 포인터와 배열 포인터

### 이중 포인터 개념
포인터도 메모리에 저장 공간을 갖는 하나의 변수이다. 따라서, 주소 연산으로 포인터의 주소도 구할 수 있다.  
포인터의 주소를 저장한 이중 포인터에 간접 참조 연산을 수행하면 가리키는 대상의 포인터를 쓸 수 있다.
```c
// 포인터와 이중 포인터의 관계

#include <stdio.h>

int main(void)
{
    int a = 10;
    int *pi;
    int **ppi;

    pi = &a;
    ppi = &pi;

    printf("-----------------------------------\n");
    printf("변수    변숫값    &연산    *연산   **연산\n");
    printf("-----------------------------------\n");
    printf("  a%10d%10u\n", a, &a);
    printf(" pi%10u%10u%10d\n", pi, &pi, *pi);
    printf("ppi%10u%10u%10u%10u\n", ppi, &ppi, *ppi, **ppi);
    printf("-----------------------------------\n");

    return 0;
}
```
- 이중 포인터는 별(*) 두 개를 붙여서 선언한다. = ```int **ppi```
    - (int *) = 가리키는 자료형 -> 첫 번째 별은 ppi가 가리키는 자료형이 포인터임을 뜻한다.
    - (*ppi) = ppi는 포인터 -> 두 번째 별은 ppi 자신이 포인터임을 뜻한다.

**이중 포인터의 형태**  
포인터에서 형태를 얘기할 때는 두 가지를 명확히 구분해야 한다.
- 포인터가 가리키는 것의 형태
    - (ex) int형 변수의 주소를 저장하는 포인터는 가리키는 자료형이 int형이고 자신의 형태는 (int *)형이 된다.
- 포인터 자신의 형태

이중 포인터도 가리키는 포인터의 형태에 맞춰 선언해야 한다.
- 이중 포인터에 저장할 주소가 어떤 포인터형의 주소인지를 먼저 파악한다.

**주소와 포인터의 차이**  
포인터는 변수이므로 주소 연산자를 사용하여 그 주소를 구할 수 있지만 상수인 주소에는 주소 연산자를 사용할 수 없다.

**다중 포인터**  
이중 포인터도 변수이므로 주소 연산자를 사용하면 그 주소를 구할 수 있다.
``` double ***ppp; ```


### 이중 포인터 활용 1 : 포인터 값을 바꾸는 함수의 매개변수
이중 포인터는 포인터의 값을 바꾸는 함수의 매개변수에 사용한다.
```c
// 이중 포인터를 사용한 포인터 교환

#include <stdio.h>

void swap_ptr(char **ppa, char **ppb);

int main(void)
{
    char *pa = "success";
    char *pb = "failure";

    printf("pa -> %s, pb -> %s\n", pa, pb);
    swap_ptr(&pa, &pb);
    printf("pa -> %s, pb -> %s\n", pa, pb);

    return 0;
}

void swap_ptr(char **ppa, char **ppb)
{
    char *pt;

    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}
```
- 두 변수의 값을 바꾸는 함수는 변수의 주소를 인수로 주고 함수가 그 주소를 간접 참조하여 변수의 값을 바꾼다.
    - 변수가 포인터인 경우 함수의 인수로 포인터의 주소를 줘야 하고 결국 그 값을 받는 매개변수로 이중 포인터가 필요하다.


### 이중 포인터 활용 2 : 포인터 배열을 매개변수로 받는 함수
이중 포인터는 포인터 배열을 매개변수로 받는 함수에도 사용할 수 있다.
- 포인터 배열의 배열명은 이중 포인터에 저장한다.
```c
// 포인터 배열의 값을 출력하는 함수

#include <stdio.h>

void print_str(char **pps, int cnt);

int main(void)
{
    char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"};
    int count;

    count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
    print_str(ptr_ary, count);

    return 0;
}

void print_str(char **pps, int cnt)
{
    int i;

    for (i = 0; i < cnt; i++) { printf("%s\n", pps[i]); }
}
```


### 배열 요소의 주소와 배열의 주소
```int ary[5]```
- ary 자체가 주소로 쓰일 때는 첫 번째 요소를 가리키므로 가리키는 대상의 크기는 4가 된다.
- 배열의 주소 &ary는 배열 전체를 가리키므로 가리키는 대상과 크기는 20이 된다.

**구분을 위한 규칙**  
1. 배열은 전체가 하나의 논리적인 변수이다.
- 배열도 일반 변수처럼 크기와 형태에 대한 정보를 가진다.
- 배열은 다양한 선언이 가능하므로 선언 방법에 따라 크기와 형태가 다를 수 있다.
- 배열은 논리적인 변수이므로 일반 변수처럼 대입 연산자 왼쪽에 사용하는 것은 불가능하다.

2. 배열의 주소에 정수를 더하면 배열 전체의 크기를 곱해서 더한다.
- 배열의 정수 연산
    - ```ary + 1 -> 5241932 + (1 * sizeof(ary[0])) -> 5241932 + (1 * 4) -> 5241936```
- 배열의 주소에 정수 연산
    - ```&ary + 1 -> 5241932 + (1 * sizeof(ary)) -> 5241932 + (1 * 20) -> 5241952```
    - 배열의 주소는 주로 2차원 이상의 배열에서 사용한다.


### 2차원 배열과 배열 포인터
배열 포인터는 배열을 가리키는 포인터로 2차원 배열의 이름을 저장할 수 있다.
```c
// 배열 포인터로 2차원 배열의 값 출력

#include <stdio.h>

int main(void)
{
    int ary[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    int (*pa)[4];   // int형 변수 4개의 배열을 가리키는 배열 포인터
    int i, j;

    pa = ary;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```
- ```int (*pa)[4];```
    - int, [4] : 가리키는 것은 int 4개의 1차원 배열
    - (*pa) : pa는 포인터
    - 일반 변수명 앞에 별(*)을 붙여 포인터임을 표시하고 괄호로 묶는다.
- 선언된 배열 포인터는 일반 포인터처럼 메모리에 저장 공간이 확보되므로 그 이후부터는 이름으로 사용한다.
```c
// 2차원 배열의 값을 출력하는 함수

#include <stdio.h>

void print_ary(int (*pa)[4]);

int main(void)
{
    int ary[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    
    print_ary(ary);

    return 0;
}

void print_ary(int (*pa)[4])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
}
```
- 2차원 배열명을 인수로 주면 함수에는 첫 번째 부분배열의 주소가 전달된다. 이 값을 저장하기 위해서 매개변수로 배열 포인터를 선언해야 한다.

</br>

## 함수 포인터와 void 포인터

### 함수 포인터의 개념
함수 포인터를 사용하기 위해 가장 중요한 것은 함수명의 의미를 파악하는 것이다.
- 함수명은 함수 정의가 있는 메모리의 시작 위치이다.
- 함수명이 주소이므로 포인터에 저장하면 함수를 다양한 방식으로 홀출할 수 있다.
```c
// 함수 포인터를 사용한 함수 호출

#include <stdio.h>

int sum(int, int);

int main(void)
{
    int (*fp)(int, int);
    int res;

    fp = sum;
    res = fp(10, 20);
    printf("result : %d\n", res);

    return 0;
}

int sum(int a, int b)
{
    return (a + b);
}
```
- 프로그램을 컴파일하면 함수도 실행 파일의 한 부분을 차지하므로 프로그램을 실행하면 함수도 메모리에 올려진다.
- 메모리에 올려진 함수를 실행시키기 위해서는 그 위치를 알아야 하는데 컴파일 후에 함수명이 함수가 올려진 메모리 주소로 바뀌므로 함수를 호출할 때 함수명을 사용한다.
- 함수의 형태 : ```int sum(int, int);```
- 포인터의 형태 : ```int (*fp)(int, int);```
    - 반드시 변수명을 별표와 함께 괄호로 묶어야 한다. 괄호가 없으면 주소를 반환하는 함수의 선언이 되므로 주의해야 한다.


### 함수 포인터의 활용
함수 포인터는 함수의 형태만 같으면 기능과 상관없이 모든 함수에 사용할 수 있다.
- 형태가 같은 다양한 기능의 함수를 선택적으로 호출할 때 사용한다.
```c
// 함수 포인터로 원하는 함수를 호출하는 프로그램

#include <stdio.h>

void func(int (*fp)(int, int));         // 함수 포인터를 매개변수로 갖는 함수
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);

int main(void)
{
    int sel;                            // 선택된 메뉴 번호를 저장할 변수

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("01 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요 : ");
    scanf("%d", &sel);

    switch (sel)
    {
    case 1: func(sum); break;
    case 2: func(mul); break;
    case 3: func(max); break;
    }

    return 0;
}

void func(int (*fp)(int, int))
{
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("결괏값은 : %d\n", res);
}

int sum(int a, int b) { return (a + b); }
int mul(int a, int b) { return (a * b); }
int max(int a, int b)
{
    if (a > b) { return a; }
    else { return b; }
}
```

**어떤 경우에 함수 포인터를 사용해야 하나?**  
- 만약 func 함수만 따로 만드는 경우 만드는 시점에서 연산 방법을 결정할 수 없다면 일단 함수 포인터를 쓰고 나중에 func 함수를 호출하는 곳에서 연산 방법을 함수로 구현할 수 있다.
- 하나의 프로그램이 여러 개의 파일로 분리되어 있는 경우 다른 파일에 있는 정적 함수(static function)를 호출하는 방법으로 함수 포인터를 사용할 수 있다.


### void 포인터
가리키는 자료형이 다른 주소를 저장하는 경우라면 void 포인터를 사용한다.
```c
// void 포인터의 사용

#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.5;
    void *vp;

    vp = &a;
    printf("a : %d\n", *(int *)vp);

    vp = &b;
    printf("b : %.1lf\n", *(double *)vp);

    return 0;
}
```
- void 포인터는 가리키는 자료형이 정해져 있지 않으므로 어떤 주소든 저장할 수 있다.
    - 간접 참조 연산이나 정수를 더하는 포인터 연산이 불가능하다.
- 자료형에 맞게 void 포인터를 형 변환한 뒤, 각각 가리키는 변수를 출력하기 위해 간접 참조 연산을 수행한다.
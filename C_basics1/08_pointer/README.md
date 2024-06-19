# 포인터

## 포인터의 기본 개념

### 메모리의 주소
프로그램이 사용하는 메모리의 위치를 주소 값으로 식별할 수 있으며, 주소 값은 바이트 단위로 구분된다.
- 값은 0부터 시작하고 바이트 단위로 1씩 증가하므로 2바이트 이상의 크기를 갖는 변수는 여러 개의 주소 값에 걸쳐 할당된다.

### 주소 연산자 : &
주소 : 변수가 할당된 메모리 공간의 시작 주소를 의미한다.
- 주소는 주소 연산자 &를 사용해서 구한다.
```c
// 변수의 메모리 주소 확인

#include <stdio.h>

int main(void)
{
    int a;
    double b;
    char c;

    printf("int형 변수의 주소 : %u\n", &a); // 주소 연산자로 주소 계산
    printf("double형 변수의 주소 : %u\n", &b);
    printf("char형 변수의 주소 : %u\n", &c);

    return 0;
}
```
- & : 변수가 메모리 어디에 할당되었는지 확인할 수 있는 단항 연산자, 변수만을 피연산자로 사용하여 시작 주소를 구한다.

**메모리 주소의 출력 변환 문자**  
- 주소는 보통 16진수로 표기한다.
- 주소를 출력할 때는 전용 변환 문자인 %p를 사용하는 것이 좋다.
    - %p는 주소값의 데이터 크기에 따라 자릿수를 맞춰 16진수 대문자로 출력한다.
- 주소 값을 10진수로 출력하며, 주소는 음수가 없으므로 %u 변환 문자를 사용한다.


### 포인터와 간접 참조 연산자 : *
포인터 : 변수의 메모리 주소를 저장하는 변수이며, 선언할 때 변수 앞에 *만 붙여주면 된다.
```c
// 포인터의 선언과 사용

#include <stdio.h>

int main(void)
{
    int a;
    int *pa;

    pa = &a;
    *pa = 10; // 포인터로 변수 a에 10 대입

    printf("포인터로 a 값 출력 : %d\n", *pa);
    printf("변수명으로 a 값 출력 : %d\n", a);

    return 0;
}
```
- ```int *pa;```
    - int : 주소 위치에 있는 변수의 자료형
    - '*' : 포인터 선언 시 변수명 앞에 붙임
    - 포인터의 자료형은 변수의 자료형을 적는다.
- ```pa = &a;```
    - 포인터가 어떤 변수의 주소를 저장한 경우 '가리킨다'라고 하며, 둘의 관계를 pa -> a 처럼 화살표로 간단히 표현한다.
- ```*pa = 10;```
    - 포인터가 가리키는 변수를 사용할 때는 포인터에 특별한 연산자를 사용하는데, 이를 **간접 참조 연산자(*)** 또는 포인터 연산자라고 한다.
    - *pa는 변수 a의 쓰임과 마찬가지로 대입 연산자(=)의 왼쪽에 올 때는 pa가 가리키는 변수의 저장 공간(l-value)으로 사용되고, 오른쪽에 올 때는 pa가 가리키는 변수의 값(r-value)으로 사용된다.
    - 연산하거나 출력할 때도 값을 사용한다.
    - ```scanf``` 함수를 사용할 때, 이미 주소값이 저장되어 있는 pa를 사용하면 된다.


### 여러 가지 포인터 사용해보기
```c
// 포인터를 사용한 두 정수의 합과 평균 계산

#include <stdio.h>

int main(void)
{
    int a = 10, b = 15, total;      // 변수 선언과 초기화
    double avg;                     // 평균을 저장할 변수
    int *pa, *pb;                   // 포인터 동시 선언
    int *pt = &total;               // 포인터 선언과 초기화
    double *pg = &avg;              // double형 포인터 선언과 초기화

    pa = &a;                        // 포인터 pa에 변수 a의 주소 대입
    pb = &b;                        // 포인터 pb에 변수 b의 주소 대입

    *pt = *pa + *pb;                // a 값과 b 값을 더해 total에 저장
    *pg = *pt / 2.0;                // total 값을 2로 나눈 값을 avg에 저장

    printf("두 정수의 값 : %d, %d\n", *pa, *pb);
    printf("두 정수의 합 : %d\n", *pt);
    printf("두 정수의 평균 : %.1lf\n", *pg);

    return 0;
}
```
- ```int *pa, *pb;```
    - 연속으로 포인터를 선언할 수 있다.
    - ```int *pa, pb;```
        - *pa는 포인로 선언되지만, pb는 일반 int형 변수로 선언된다.

### const를 사용한 포인터
const 예약어를 포인터에 사용하면 이는 가리키는 변수의 값을 바꿀 수 없다는 의미로, 변수에 사용하는 것과는 다른 의미를 가진다.
```c
// 포인터에 const 사용

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    const int *pa = &a;                 // 포인터 pa는 변수 a를 가리킨다.

    printf("변수 a의 값 : %d\n", *pa);    // 포인터를 간접 참조하여 a 출력
    pa = &b;                            // 포인터가 변수 b를 가리키게 한다.
    printf("변수 b의 값 : %d\n", *pa);    // 포인터를 간접 참조하여 b 출력
    pa = &a;                            // 포인터가 변수 a를 가리키게 한다.
    a = 20;
    printf("변수 a의 값 : %d\n", *pa);    // 포인터로 간접 참조하여 바뀐 값 출력

    return 0;
}
```
- ```const int *pa = &a;``` , ```pa = &b;```
    - const가 일반 변수처럼 포인터 값을 고정시킨다면 pa는 다른 변수의 주소를 저장할 수 없어야 한다. 하지만, 그것과는 무관하게 동작한다.
    - 포인터에 사용된 const의 의미는 pa가 가리키는 변수 a는 pa를 간접 참조하여 바꿀 수 없다는 것이다.

**포인터에 const를 사용하는 이유**  
포인터에 const를 사용하는 대표적인 예는 문자열 상수를 인수로 받는 함수이다.
- 문자열 상수는 값이 바뀌면 안 되는 저장 공간이므로 함수의 매개변수를 통해서 값을 바꿀 수 없도록 매개변수로 선언된 포인터에 const를 사용한다.

</br>

## 포인터 이해하기

### 주소와 포인터의 차이
- 주소 : 변수에 할당된 메모리 저장 공간의 시작 주소 값 자체
    - 포인터처럼 간접 참조 연산자를 쓸 수 있지만 상수이므로 대입 연산자 왼쪽에 올 수 없다.
- 포인터 : 그 값을 저장하는 또 다른 메모리 공간
특정 변수의 주소 값은 바뀌지 않지만 포인터는 다른 주소를 대입하여 그 값을 바꿀 수 있다. 즉, 주소는 '상수'이고, 포인터는 '변수'이다.

### 주소와 포인터의 크기
포인터의 크기는 저장할 주소의 크기에 따라 결정된다.
- 포인터의 크기는 컴파일러에 따라 다를 수 있으나 모든 주소와 포인터는 **가리키는 자료형과 상관없이** 그 크기가 같다는 것에는 변함이 없다.
```c
// 주소와 포인터의 크기

#include <stdio.h>

int main(void)
{
    char ch;
    int in;
    double db;

    char *pc = &ch;
    int *pi = &in;
    double *pd = &db;

    printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
    printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
    printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

    printf("char * 포인터의 크기 : %d\n", sizeof(pc));
    printf("int * 포인터의 크기 : %d\n", sizeof(pi));
    printf("double * 포인터의 크기 : %d\n", sizeof(pd));

    printf("char * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pc));
    printf("int * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pi));
    printf("double * 포인터가 가리키는 변수의 크기 : %d\n", sizeof(*pd));

    return 0;
}
```


### 포인터의 대입 규칙
1. 포인터는 가리키는 변수의 형태가 같을 때만 대입해야 한다.
```c
// 허용되지 않는 포인터의 대입

#include <stdio.h>

int main(void)
{
    int a = 10;
    int *p = &a;
    double *pd;

    pd = p;
    printf("%lf\n", *pd); // 0.000000

    return 0;
}
```
- 컴파일러는 p에 저장된 값을 int형 변수의 주소로 생각하고, pd에 저장된 값을 double형 변수의 주소로 생각한다.
    - pd에 p를 대입한 후에 간접 참조 연산을 수행하면 변수 a에 할당된 영역 이후의 할당되지 않은 영역까지 사용하게 된다.

2. 형 변환을 사용한 포인터의 대입은 언제나 가능하다.
```c
double a = 3.1;
double *pd = &a;
int *pi;
pi = (int *)pd;     // pd 값을 형 변환하여 pi에 대입
```

**포인터에 100번지를 직접 대입하는 것은 가능한가?**  
형 변환 연산자를 사용하면 컴파일 경고나 에러 없이 원하는 정수 값을 포인터에 대입하여 사용할 수 있다.
```c
int *p;
p = (int *) 100;    // 100을 int형 변수의 주소로 형 변환하여 p에 대입
*p = 10;            // 100번지부터 103번지까지 4바이트의 공간에 10 대입
```
- 100번지부터 103번지까지가 어떤 용도로 사용되는 영역인지 알 수 없으므로 프로그램을 실행할 때 문제를 일으킬 가능성이 크다.
- 포인터는 항상 정상적으로 할당받은 메모리 공간의 주소를 저장해서 사용해야 한다.
- 포인터를 초기화하지 않는 건 더 위험하다. 간접 참조 연산을 수행하면 알 수 없는 곳으로 찾아가 데이터를 바꿀 수 있다.


### 포인터를 사용하는 이유
임베디드 프로그래밍을 할 때 메모리에 직접 접근하는 경우나 동적 할당한 메모리를 사용하는 경우에는 포인터가 반드시 필요하다.

**두 변수의 값을 바꾸며 포인터 이해하기**  
```c
// 포인터를 사용한 두 변수의 값 교환

#include <stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
    int a = 10, b = 20;

    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);

    return 0;
}

void swap(int *pa, int *pb)
{
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
```
- swap 함수는 포인터를 통해 main 함수의 변수 a, b를 공유하므로 두 변수를 직접 바꾸는 일이 가능해진다.


**포인터 없이 두 변수의 값을 바꾸는 함수는 불가능한가?**  
함수 안에 선언된 변수명은 사용 범위가 함수 내부로 제한되므로 main 함수에 있는 변수 a, b는 다른 함수인 swap 함수에서 그 이름을 사용할 수 없다.
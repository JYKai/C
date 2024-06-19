# 전처리와 분할 컴파일

## 전처리 지시자

### 파일을 포함하는 #include
```#include```는 지정한 파일의 내용을 읽어와 지시자가 있는 위치에 붙여놓는다.
```c
// 사용자 정의 헤더 파일 - student.h
typedef struct
{
    int num;        // 학번
    char name[20];  // 이름
} Student;
```
```c
// 소스 파일 - main.c
#include <stdio.h>
#include "student.h"

int main(void)
{
    Student a = {315, "홍길동"};

    printf("학번 : %d, 이름 : %s\n", a.num, a.name);
    return 0;
}
```
- 꺽쇠괄호(<>)를 사용하면 복사할 파일을 컴파일러가 설정한 include 디렉터리에서 찾는다.
- 큰따옴표("")를 사용하면 소스 파일이 저장된 디렉터리에서 먼저 찾는다.

보통 하나의 프로그램은 독립적으로 컴파일 가능한 파일 단위인 모듈(module)로 나누어 분할 컴파일한다.


### 매크로명을 만드는 #define
```#define```은 매크로명을 정의하는 전처리 지시자로 사용법은 아래와 같다.
- ```#define 매크로명 치환될_부분```
    - 관례상 대문자로 매크로명을 정의한다.
```c
#include <stdio.h>
#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")

int main(void)
{
    double radius, area;

    printf("반지름을 입력하세요(10이하) : ");
    scanf("%lf", &radius);

    area = PI * radius * radius;
    if (area > LIMIT) { ERR_PRN; }
    else { printf("원의 면적 : %.1lf (%s)\n", area, MSG); }

    return 0;
}
```
- 상수대신 사용되는 매크로명을 매크로 상수라고 한다.
- 매크로명을 정의할 때 치환될 부분이 길어 여러 줄을 써야 한다면 백슬래시(\)로 연결한다.
```c
#define INTRO "Perfect C Language \
& Basic Data Structure"
``
- 매크로명을 사용하면 디버깅과 유지보수가 힘드므로 필요한 경우만 제한적으로 사용한다.


### #define을 사용한 매크로 함수
```#define 매크로_함수명(인수) 치환될_부분```  

```c
#include <stdio.h>
#define SUM(a, b) ((a) + (b))
#define MUL(a, b) ((a) * (b))

int main(void)
{
    int a = 10, b = 20;
    int x = 30, y = 40;
    int res;

    printf("a + b = %d\n", SUM(a, b));
    printf("x + y = %d\n", SUM(x, y));

    res = 30 / MUL(2, 5);
    printf("res = %d\n", res);

    return 0;
}
```
- 매크로 함수는 치환된 후의 부작용을 줄이기 위해 치환될 부분에 괄호를 써서 정의한다.
- 함수처럼 쓰이지만 치환된 후 발생할 문제를 예측하기 어렵다. 많은 기능을 구현하기 힘들다.
- 호출한 함수로 이동할 때 필요한 준비작업이 없으므로 함수 호출보다 상대적으로 실행 속도가 빠르다.


### 이미 정의된 매크로
| 이미 정의된 매크로 | 기능 |
| :--- | ---- | 
| `__FILE__`  | 전체 디렉터리 경로에 포함된 파일명 |
| `__FUNCTION__`    | 매크로명이 사용된 함수 이름 |
| `__LINE__`    | 매크로명이 사용된 행 번호 |
| `__DATE__`    | 컴파일을 시작한 날짜 |
| `__TIME__`    | 컴파일을 시작한 시간 |

```c
// 이미 정의된 매크로 기능

#include <stdio.h>

void func(void);

int main(void)
{
    printf("컴파일 날짜와 시간 : %s, %s\n\n", __DATE__, __TIME__);
    printf("파일명 : %s\n", __FILE__);
    printf("함수명 : %s\n", __FUNCTION__);
    printf("행번호 : %d\n", __LINE__);

#line 100 "macro.c"     // 행 번호를 100부터 시작, 파일명은 macro.c로 표시
    func();             // 여기부터 행 번호는 100으로 시작

    return 0;
}

void func(void)
{
    printf("\n");
    printf("파일명 : %s\n", __FILE__);
    printf("함수명 : %s\n", __FUNCTION__);
    printf("행번호 : %d\n", __LINE__);
}
```
- 매크로를 사용해 실행 중에 갑자기 종료되는 경우 함수명이나 행 번호를 출력하여 어디까지 진행되었는지 확인하는 용도로 사용할 수 있다.


### 매크로 연산자 #과##
#은 매크로 함수의 인수를 문자열로 치환하고 ##는 두 인수를 붙여서 치환한다.
```c
// #과 ##을 사용한 매크로 함수

#include <stdio.h>
#define PRINT_EXPR(x) printf(#x " = %d\n", x)
#define NAME_CAT(x, y) (x ## y)

int main(void)
{
    int a1, a2;

    NAME_CAT(a, 1) = 10;        // (a1) = 10;
    NAME_CAT(a, 2) = 20;        // (a2) = 20;
    PRINT_EXPR(a1 + a2);        // printf("a1 + a2" " = %d\n", a1 + a2);
    PRINT_EXPR(a2 - a1);        // printf("a2 - a1" " = %d\n", a2 - a1);

    return 0;
}
```
- 컴파일러는 여러 개의 문자열을 연속으로 사용하면 하나의 문자열로 연결해 처리하므로 치환된 문자열은 이어지는 문자열과 합쳐지게 된다.
- ##연산자는 2개의 토큰을 붙여서 하나로 만드는 연산자이다.


### 조건부 컴파일 지시자
조건부 컴파일은 소스 코드를 조건에 따라 선택적으로 컴파일한다.
- #if, #else, #elif, #ifdef, #ifndef, #endif
```c
// #if, #ifdef, #else, #endif를 사용한 조건부 컴파일

#include <stdio.h>
#define VER 7
#define BIT16

int main(void)
{
    int max;

#if VER >= 6
    printf("버전 %d입니다.\n", VER);
#endif

#ifdef BIT16
    max = 32776;
#else
    max = 2147483647;
#endif

    printf("int형 변수의 최댓값 : %d\n", max);

    return 0;
}
```
- #if문의 조건식이 참이면 #if와 #endif 사이의 모든 문장을 컴파일한다.
    - 컴파일할 문장이 두 문장 이상이더라도 중괄호를 쓰지 않는다.
- 조건식에 특정 매크로명이 정의되어 있는지 검사할 때는 #ifdef를 사용한다.
    - #ifdef와 #ifndef는 매크로명의 정의 여부만 확인할 수 있으므로 다른 연산자와 함께 조건식을 만들 때는 define이나 !define 연산자를 사용해야 한다.
    ```c
    #if (defined(BIT16) && (VER >= 6))
        컴파일할 문장
    #endif
    ```
- 조건식을 만족하지 않는 경우 컴파일 자체를 중단할 때는 #error 지시자를 사용한다.
```c
#if VER >= 6
    printf("버전 %d입니다.\n", VER);
#else
#error 컴파일러 버전은 6.0 이상이어야 합니다.       // 메세지를 보여주고 컴파일 종료
#endif
```
- 조건부 컴파일은 프로그램의 호환성을 좋게 한다.
- 조건부 컴파일 기능을 사용하여 컴파일할 코드를 구별하면 서로 다른 컴파일러에서 컴파일이 가능한 코드를 만들 수 있다.

### #pragma 지시자
```#pragma``` 지시자는 컴파일러의 컴파일 방법을 세부적으로 제어할 때 사용한다.
- 사용법은 지시명을 통해 컴파일러의 어떤 기능을 제어할 것인지 알려준다.
- pack은 구조체의 패딩 바이트 크기를 결정하며, warning은 경고 메세지를 관리한다.
```c
// #pragma 를 사용한 바이트 얼라인먼트 변경

#include <stdio.h>
#pragma pack(push, 1)       // 바이트 얼라인먼트를 1로 바꿈
typedef struct
{
    char ch;
    int in;
} Sample1;

#pragma pack(pop)           // 바꾸기 전의 바이트 얼라인먼트 적용
typedef struct
{
    char ch;
    int in;
} Sample2;

int main(void)
{
    printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));  // Sample1 구조체의 크기 : 5바이트
    printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));  // Sample2 구조체의 크기 : 8바이트

    return 0;
}

```
- ```#pragma pack(push, 1)```
    - 단위 크기를 1로 설정하여 구조체 멤버가 메모리의 모든 위치에 할당할 수 있도록 한다.
    - 이후에 어떤 구조체를 정의하더라도 패딩 바이트를 포함하지 않으며 구조체의 크기는 멤버의 크기를 모두 더한 크기가 된다.
    - push는 바이트 얼라인먼트를 바꿀 때 현재의 규칙을 기억한다.
    - pop을 사용하여 이전의 규칙을 복원할 수 있다.
- pragma에는 pack, warning 외에도 많은 지시명을 사용할 수 있다. 메뉴얼을 참고하자.

</br>

## 분할 컴파일
- 각 파일을 독립적으로 컴파일할 수 있도록 필요한 선언을 포함해야 한다.

## 분할 컴파일에서 extern과 static의 용도
- 다른 파일에 선언된 전역 변수를 사용할 때는 extern 선언을 한다.  
- 다른 파일에서 전역 변수를 공유하지 못하게 할 때는 static을 사용한다.

## 헤더 파일의 필요성과 중복 문제 해결 방법
분할 컴파일할 때는 사용자 정의 헤더 파일이 필요하다.
- 이름이 같은 구조체 선언이 둘 이상 있을 수 있다면 멤버의 형태가 다르고 구조체의 이름이 같은 경우 구조체의 이름이 같은 경우 구조체 변수의 형태를 결정할 수 없게 된다.
- 헤더 파일의 중복 포함 문제를 해결하기 위해 조건부 컴파일 전처리 명령어를 사용한다.
    - 헤더 파일의 처음에 특정 매크로명을 정의하여 같은 헤더 파일이 두 번 이상 포함될 때는 조건검사를 통해 헤더 파일이 중복 포함되지 않도록 만든다. == ```ifndef _POINT_H_``` -> ```define _POINT_H_```
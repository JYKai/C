# 매크로와 선행처리기 (Preprocessor)

## 선행처리기와 매크로

### 선행처리는 컴파일 이전의 처리를 의미한다.
선행처리 명령문은 # 문자로 시작을 하며, 컴파일러가 아닌 선행처리기에 의해서 처리되는 문장이기 때문에 명령문의 끝에 세미콜론을 붙이지 않는다.

</br>

## 대표적인 선행처리 명령문

### #define: Object-like macro
#define = '지시자'
- 이어서 등장하는 매크로를 마지막에 등장하는 매크로 몸체로 치환하라.
```c
#define NAME "김지윤"
#define AGE 30
#define PRINT_ADDR puts("주소: 인천광역시 \n");
```

### #define: Function-like macro
매개변수가 존재하는 매크로는 동작방식이 함수와 유사하여 '함수와 유사한 매크로'라 하며, '매크로 함수'라 부르기도 한다.
```c
#define SQUARE(X) X*X
```

### 잘못된 매크로 정의
```c
SQUARE(3+2)
```
- 3 + 2 * 3 + 2 = 11 이 되어 버린다.
    - ``` SQUARE((3 + 2))``` 와 같이 전달해야 한다.

### 매크로 몸체에 괄호를 마구마구 칩시다.
매크로 함수를 정의할 때에는 매크로의 몸체부분을 구성하는 X와 같은 전달인자 하나하나에 괄호를 해야함은 물론이고, 반드시 전체를 괄호로 한번 더 묶어줘야 한다는 사실을 기억하자.
```c
#define SQUARE(X) ((X) * (X))
```

### 매크로를 두 줄에 걸쳐서 정의하려면?
기본적으로 매크로는 한 줄에 정의하는 것이 원칙이다. 두 줄 이상에 걸쳐서 정의할 때는 ```\```문자를 활용해서 줄이 바뀌었음을 명시해야 한다.

### 매크로 정의 시, 먼저 정의된 매크로도 사용이 가능하다.
먼저 정의된 매크로는 뒤에서 매크로를 정의할 때 사용 가능하다.
```c
#include <stdio.h>

#define PI 3.14
#define PRODUCT(X, Y) ((X) * (Y))
#define CIRCLE_AREA(R) (PRODUCT((R), (R)) * PI)

int main(void)
{
    double rad = 2.1;
    printf("반지름 %g인 원의 넓이 : %g \n", rad, CIRCLE_AREA(rad));
    return 0;
}
```

### 매크로 함수의 장점
- 매크로 함수는 일반 함수에 비해 실행속도가 빠르다.
    - 함수의 빈번한 호출은 실행속도의 저하로 이어진다. 매크로 함수는 선행처리기에 의해서 매크로 함수의 몸체부분이 매크로 함수의 호출 문장을 대신하기 때문에 실행속도상 이점이 있다.
- 자료형에 따라서 별도로 함수를 정의하지 않아도 된다.

### 매크로 함수의 단점
- 정의하기가 정말로 까다롭다.
- 디버깅하기가 쉽지 않다.
    - 매크로를 잘못 정의할 경우, 에러 메세지는 선행처리 이전의 소스파일을 기준으로 출력되지 않고, 선행처리 이후의 소스파일을 기준으로 출력이 된다.

### 그래서 이러한 함수들을 매크로로 정의하지요.
- 작은 크기의 함수
- 호출의 빈도수가 높은 함수

</br>

## 조건부 컴파일(Contiditonal Compilation)을 위한 매크로

### #if... #endfif: 참이라면
```c
#include <stdio.h>

#define ADD 1
#define MIN 0

int main(void)
{
    int num1, num2;
    printf("두 개의 정수 입력 : ");
    scanf("%d %d", &num1, &num2);

#if ADD
    printf("%d + %d = %d \n", num1, num2, num1 + num2);
#endif

#if MIN
    printf("%d - %d = %d \n", num1, num2, num1 - num2);
#endif

    return 0;
}
```

### #ifdef... #endif: 정의되었다면
```c
#include <stdio.h>

// #define ADD 1
#define MIN 0

int main(void)
{
    int num1, num2;
    printf("두 개의 정수 입력 : ");
    scanf("%d %d", &num1, &num2);

#ifdef ADD
    printf("%d + %d = %d \n", num1, num2, num1 + num2);
#endif

#ifdef MIN
    printf("%d - %d = %d \n", num1, num2, num1 - num2);
#endif

    return 0;
}
```
- 매크로의 값은 중요하지 않기 때문에 생략해서 정의해도 된다.
    - 값이 생략되어 저장되면 소스코드에 있는 ADD와 MIN은 선행처리 과정에서 공백으로 대체가 된다(그냥 소멸된다는 뜻).

### #ifndef... #endif: 정의되지 않았다면
이 매크로는 헤더파일의 중복포함을 막기 위해 주로 사용된다.

### #else의 삽입: #if, #ifdef, #ifndef에 해당

### #elif의 삽입: #if에만 해당

</br>

## 매개변수의 결합과 문자열화

### 문자열 내애서는 매크로의 매개변수 치환이 발생하지 않는다.

### 문자열 내애서 매크로의 매개변수 치환이 발생하게 만들기: #연산자
#연산자는 치환의 결과를 문자열로 구성하는 연산자이다.
- 문자열은 나란히 선언하면 하나의 문자열로 간주가 된다.
```c
#include <stdio.h>

#define STRING_JOB(A, B)    #A "의 직업은 " #B "입니다."

int main(void)
{
    printf("%s \n", STRING_JOB(이동춘, 나무꾼));
    printf("%s \n", STRING_JOB(한상순, 사냥꾼));
    return 0;
}
```

### 특별한 매크로 연산자 없이 단순히 연결하는 것은 불가능하다.

### 필요한 형태대로 단순하게 결합하기: 매크로 ##연산자
이 연산자는 매크로 함수의 전달인자를 다른 대상(전달인자, 숫자, 문자, 문자열등)과 이어줄 때 사용한다.
```c
#define CON(UPP, LOW)   UPP ## 00 ## LOW

int num = CON(22, 77); // 220077
```
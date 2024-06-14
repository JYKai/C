# 변수와 데이터 입력

## 변수

### 변수 선언 방법
데이터의 종류에 맞는 자료형과 변수명을 나란히 사용하면 된다.
```c
// 변수의 선언과 사용

#include <stdio.h>

int main(void)
{
    int a;
    int b, c;
    double da;
    char ch;

    a = 10;
    b = a;
    c = a + 20;
    da = 3.5;
    ch = 'A';

    printf("변수 a의 값 : %d\n", a);
    printf("변수 b의 값 : %d\n", b);
    printf("변수 c의 값 : %d\n", c);
    printf("변수 da의 값 : %.1lf\n", da);
    printf("변수 ch의 값 : %c\n", ch);

    return 0;
}
```
- 변수의 자료형이 같으면 동시에 둘 이상의 변수를 선언할 수 있다.
- 저장 공간으로 사용하는 변수 = l-value(left value)
- 값으로 사용하는 변수 = r-value(right value)

### 정수 자료형
```c
// char형 변수의 사용

#include <stdio.h>

int main(void)
{
    char ch1 = 'A';
    char ch2 = 65;

    printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch1);
    printf("아스키 코드 값이 %d인 문자 : %c\n", ch2, ch2);

    return 0;
}
```
- char형 변수를 출력할 때 %c를 사용하면 변수에 저장된 값을 아스키 코드 값으로 해석하여 출력한다.

```c
// 여러 가지 정수형 변수

#include <stdio.h>

int main(void)
{
    short sh = 32767;
    int in = 2147483647;
    long ln = 2147483647;
    long long lln = 123451234512345;

    printf("short형 변수 출력 : %d\n", sh);
    printf("int형 변수 출력 : %d\n", in);
    printf("long형 변수 출력 : %ld\n", ln);
    printf("long long형 변수 출력 : %lld\n", lln);

    return 0;
}
```
- long형은 소문자 l을 붙여서 %ld로 출력하고, long long형은 소문자 ll을 붙여허 %lld로 출력한다.
- 특별한 경우가 아니라면 정수형은 int를 사용한다.
    - int형은 연산의 기본 단위로 컴퓨터에서 가장 빠르게 연산된다.
    - short형은 int형보다 크기가 작아 메모리를 적게 사용하지만, 연산 과정에서는 int형으로 변환되므로 실행 속도가 느려질 수 있다.
- long형은 큰 값을 저장할 때 사용한다.

> Q. 자료형의 크기가 궁금하다면?
> - ```sizeof``` 연산자로 확인할 수 있다.
>     - 자료형의 크기를 바이트 단위로 계산해준다.

### unsigned 정수 자료형
정수형은 보통 양수와 음수를 모두 저장하지만, 양수만을 저장하면 두 배 더 넓은 범위의 값을 저장할 수 있다.  
음수가 없는 데이터를 저장할 때는 unsigned를 사용한다.
```c
// unsigned를 잘못 사용한 경우

#include <stdio.h>

int main(void)
{
    unsigned int a;

    a = 4294967295;
    printf("%d\n", a); // -1
    a = -1;
    printf("%u\n", a); // 4294967295

    return 0;
}
```
- %d : 부호까지 생각해서 10진수로 출력하는 변환 문자
    - ```printf("%d\n", a)```
         - 4294967295의 메모리 내에 저장된 형태는 11111111 11111111 11111111 11111111 이다.
         - 부호있는 변환 문자를 사용했으므로 가장 왼쪽 비트를 부호 비트로 간주하고 -1을 출력한다.
- %u : 부호 없는 10진수로 출력하는 변환 문자
    - 부호 비트를 고려하지 않으므로 모든 비트를 10진수로 바꿔 4294967295를 출력한다.
- unsigned 자료형은 항상 양수만 저장하고 %u로 출력하기를 권한다.


### 실수 자료형
실수 데이터를 구현하는 방법이 정수와 다르므로 별도의 자료형을 사용한다.
- float, double, long double
```c
// 유효 숫자 확인

#include <stdio.h>

int main(void)
{
    float ft = 1.234567890123456789;  // 1.23456788063049316406
    double db = 1.234567890123456789; // 1.23456789012345669043

    printf("float형 변수의 값 : %.20f\n", ft);
    printf("double형 변수의 값 : %.20lf\n", db);

    return 0;
}
```
- 컴퓨터에서 실수를 표현하는 방식이 오차를 가지고 있다.
    - float형은 유효 숫자 7자리
    - double형은 유효 숫자 15자리
- 실수형은 유효 숫자가 많은 double 형을 기본으로 사용한다.


### 문자열 저장
``` char 배열명[문자열길이 + 1] = 문자열 ``` 형식으로 저장한다.
- 문자열의 길이보다 배열의 크기를 하나 더 크게 잡는 이유는 문자열 끝에 \0(널 문자, null character)을 자동으로 추가하기 때문이다.
```c
// char 배열에 문자열 저장

#include <stdio.h>

int main(void)
{
    char fruit[20] = "strawberry";

    printf("딸기 : %s\n", fruit);
    printf("딸기쨈 : %s %s\n", fruit, "jam");

    return 0;
}
```
- char 배열은 문자열을 저장하는 변수의 역할을 하며 %s로 출력한다.

> 배열에는 대입 연산자(=)를 사용할 수 없다.
- 대입 연산은 대상 자료형의 크기가 일정해야 하는데 선언에 따라 크기가 달라지는 char 배열은 대입 연산을 사용할 수 없다.
- 배열명은 주소 상수이므로 변수만 가능한 대입 연산자 왼쪽에 쓸 수 있다.
```c
fruit = "banana"; // 배열은 선언된 이후에 대입 연산자로 문자열을 입력할 수 없다.
```
- char형 배열에 초기화 이외에 문자열을 저장할 때는 ```strcpy``` 함수를 사용한다.
```c
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
```

### const를 사용한 변수
변수는 저장 공간이므로 언제든지 그 값을 변경할 수 있다. 하지만, const를 사용한 변수는 초기화된 값을 바꿀 수 없다.
```c
#include <stdio.h>

int main(void)
{
    int income = 0;
    double tax;
    const double tax_rate = 0.12;

    income = 456;
    tax = income * tax_rate;
    printf("세금은 : %.1lf입니다.\n", tax);

    return 0;
}
```
- ```const 자료형 변수명 = 값;```
    - const를 사용하면 이후에는 값을 바꿀 수 없으므로 반드시 선언과 동시에 초기화해야 한다. 그렇지 않으면 변수의 쓰리게 값이 계속 사용된다.
    - const를 사용하면 변수가 상수처럼 쓰이지만, C 문법이 제공하는 변수의 특성을 모두 가지는 엄현한 변수이다.

### 예약어와 식별자
예약어(reserved word 또는 key word)는 컴파일러와 사용 방법이 약속된 단어이고 식별자(identifier)는 필요에 따라 만들어 사용하는 단어이다.
```c
int age;
```
- int : 예약어
- age : 식별자

**식별자 규칙**  
- 알파벳 대문자 A ~ Z, 소문자 a ~ z, 숫자 0 ~ 9, _(밑줄)로 생성한다,.
- 숫자로 시작할 수 없다.
- 대문자와 소문자는 서로 다른 식별자로 인식한다.
- 예약어는 식별자로 사용할 수 없다.

</br>

## 데이터 입력
키보드에서 타이핑하는 모든 내용은 문자로 인식된다. 따라서 입력 데이터를 연산이 가능한 정수나 실수로 사용하기 위해서는 변환과정이 필요하며 ```scanf``` 함수를 사용하여 변환한다.
- ```scanf``` : 입력 문자들을 스캔하여 원하는 형태의 데이터로 변환해준다.

### scanf 함수의 사용법
키보드에서 입력한 값을 변수에 저장할 때 사용한다.
```c
scanf("%d", &a);
```
- 변수의 형태에 맞는 변환 문자를 사용하고, 입력할 변수 앞에 & 기호를 붙이면 된다.
```c
// scanf 함수를 사용한 키보드 입력

#include <stdio.h>

int main(void)
{
    int a;

    scanf("%d", &a);
    printf("입력된 값 : %d\n", a);

    return 0;
}
```

**```scanf``` 함수 사용의 유의점**  
1. ```scanf``` 함수에서 변수명을 지정할 때는 &를 붙여줘야 한다.
- & 기호는 변수의 주소를 구하는 연산자
2. ```scanf``` 함수에서 사용한 변환 문자와 맞는 형태의 데이터를 입력해야 한다.
- 변환 문자와 다른 예상치 못한 데이터가 입력되면 실행이 중단된다.
- 입력에 실패하면 변수 a에 있던 쓰레기 값이 그대로 출력된다.

**```scanf``` 함수의 응용**  
```c
scanf("%d%lf", &a, &b);
```
- 여러 개 변환 문자를 나열하여 한 번에 2개 이상의 변수에 값을 입력할 수 있다.
- 변환 문자들은 큰따옴표 안에 이어서 나열하며 변수 사이는 콤마로 구분한다.
```c
// scanf 함수를 사용한 연속 입력

#include <stdio.h>

int main(void)
{
    int age;
    double height;

    printf("나이와 키를 입력하세요 : ");
    scanf("%d%lf", &age, &height);
    printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age, height);

    return 0;
}
```

### 문자와 문자열 입력
char형 변수에 문자를 입력할 때는 키보드로 입력하는 모든 문자가 대상이 된다. 스페이스나 엔터도 하나의 문자로 전달된다.
- 문자열을 입력할 때는 배열명에 & 기호를 붙이지 않는다.
- 스페이스나 엔터, 탭 등을 만나면 바로 전까지만 저장된다. 따라서, 공백 없이 연속으로 입력해야 한다.
```c
// 문자와 문자열 입력

#include <stdio.h>

int main(void)
{
    char grade;
    char name[20];

    printf("학점 입력 : ");
    scanf("%c", &grade);
    printf("이름 입력 : ");
    scanf("%s", name);
    printf("%s의 학점은 %c입니다.\n", name, grade);

    return 0;
}
```
- 학점을 입력할 때 enter만 누른다면 제어 문자 \n이 grade 변수에 저장된다.
- 이름을 입력할 때 '김', '지윤'을 분리해서 입력하면 배열이는 '김'만 입력된다.

**비정상 종료되는 경우**  
- char 배열의 크기보다 큰 문자열을 입력하면 프로그램이 비정상적으로 종료될 수 있다.
- ```scanf_s``` : 배열의 크기까지만 문자열을 입력하도록 제한하는 함수 in VC++ 컴파일러

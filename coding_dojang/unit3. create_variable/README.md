# 변수 만들기

## 변수 선언
변수 이름은 원하는 대로 지으면 되지만 다음과 같은 규칙을 지켜야 한다.

- 영문 문자와 숫자를 사용할 수 있다.
- 대소문자를 구분한다.
- 문자부터 시작해야 하며 숫자부터 시작하면 안 된다.
- _(밑줄 문자)로 시작할 수 있다.
- C 언어의 키워드(int, short, long, float, void, if, for, while, switch 등)는 사용할 수 없다.

변수를 선언할 때는 반드시 맨 뒤에 ; (세미콜론)을 붙여주어야 한다.

C 언어의 문법은 무조건 위에서 아래로 해석되기 때문에 변수를 사용하려면 사용하는 부분보다 위에 변수를 선언해줘야 한다.

</br>

## 변수를 만들고 값 저장하기
```c
#include <stdio.h>

int main(void)
{
    int num1; // 정수형 변수 선언
    int num2;
    int num3;

    num1 = 10; // 변수에 값 할당(저장)
    num2 = 20;
    num3 = 30;

    printf("%d %d %d\n", num1, num2, num3);

    return 0;
}
```
- 변수에 값을 저장하는 과정을 "변수에 값을 할당한다"라고 부른다.
    - ```num1 = 10;```은 num1과 10이 같다는 뜻이 아니라 num1에 10을 할당(저장)한다는 뜻이 된다.
- ```printf("%d %d %d\n", num1, num2, num3); ```
    - %d는 10진수(decimal)를 출력할 때 사용하는 서식 지정자이다.

</br>

## 변수 여러 개를 한 번에 선언하기
```c
#include <stdio.h>

int main(void)
{
    int num1, num2, num3;

    num1 = 10;
    num2 = 20;
    num3 = 30;

    printf("%d %d %d\n", num1, num2, num3);

    return 0;
}
```

</br>

## 변수를 선언하면서 초기화하기
```c
#include <stdio.h>

int main(void)
{
    int num1 = 10;
    int num2 = 20, num3 = 30;

    printf("%d %d %d\n", num1, num2, num3);

    return 0;
}
```
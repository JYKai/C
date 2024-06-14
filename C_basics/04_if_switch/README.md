# 선택문(if, switch ~ case)

## if문

### if문의 기본 형식
```c
// if문의 기본 형식

#include <stdio.h>

int main(void)
{
    int a = 20;
    int b = 0;

    if (a > b) { b = a; }

    printf("a : %d, b : %d\n", a, b);

    return 0;
}
```
- if문은 중괄호({})를 사용하고 들여쓰기하여 실행문을 명확히 구분하는 것이 좋다.


### if ~ else문
```c
// if ~ else문 사용

#include <stdio.h>

int main(void)
{
    int a = 10;

    if (a >= 0)
    {
        a = 1;
    }
    else
    {
        a = -1;
    } 

    printf("a = %d\n", a);
    return 0;
}
```
- if ~ else문의 else에는 조건을 사용하지 않는다.
- 실행할 문장이 두 문장 이상이면 반드시 중괄호로 묶어야한다.


### if ~ else if ~ else문
```c
// if ~ else if ~ else문 사용

#include <stdio.h>

int main(void)
{
    int a = 0, b = 0;

    if (a > 0)
    {
        b = 1;
    }
    else if (a == 0)
    {
        b = 2;
    }
    else
    {
        b = 3;
    }

    printf("b = %d\n", b);
    return 0;
}
```
- 조건식을 차례로 검사하므로 이전 조건의 결과가 반영된다.
- 순서가 중요하지 않은 경우 참이 될 가능성이 많은 조건식을 먼저 사용하면 조건식을 검사하는 횟수를 줄일 수 있다.

</br>

## if문 활용과 switch ~ case문

### if문 중첩
```c
// 중첩된 if문

#include <stdio.h>

int main(void)
{
    int a = 20, b = 10;

    if (a > 10)
    {
        if (b >= 0)
        {
            b = 1;
        }
        else
        {
            b = -1;
        }
    }

    printf("b = %d\n", b);
    return 0;
}
```
- if ~ else문은 실행문이 많고 형태가 복잡하더라도 전체를 한 문장으로 취급한다.

**if문을 중첩해서 쓰는 이유**  
- 선행조건이 있으면 불필요한 조건 검사를 하지 않는다.
- 선행조건이 없어도 실행 효율을 위해 의도적으로 중첩해 사용할 수 있다.


### else 결합 문제
if문이 실행할 문장이 한 문장이더라도 중괄호를 반드시 써야하는 경우가 있다.
```c
// 중첩 if문에서 중괄호가 반드시 필요한 경우

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;

    if (a < 0)
    {
        if (b > 0)
        {
            printf("ok");
        }

    }
    else
    {
        printf("ok");
    }

    return 0;
}
```
- 컴파일러는 if문이 중첩된 경우 else를 가장 가까운 if와 연결한다. (Dagling else Problem)


### switch ~ case문
여러 개의 상수 중에서 조건에 해당하는 하나를 골라 실행하는 것
- 조건식은 정수식만 사용한다.
    - 정수식은 정수형 상수나 변수를 쓸 수 있고 수식을 사용할 때는 결괏값이 정수여야 한다.
    - case에 사용하는 상수식 역시 정수만 가능하다.
- 기본적으로 case는 break를 포함한다.
    - break는 해당 블록을 탈출하는 데 사용한다.

```c
// switch ~ case문의 사용

#include <stdio.h>

int main(void)
{
    int rank, m = 0;
    printf("rank를 입력하세요(정수): ");
    scanf("%d", &rank);

    switch (rank)
    {
        case 1:
            m = 300;
            break;
        case 2:
            m = 200;
            break;
        case 3:
            m = 100;
            break;
        default:
            m = 10;
            break;
    }

    printf("m : %d\n", m);
    return 0;
}
```
- case와 default는 건너뛸 위치를 표시하는 레이블의 역할을 한다.
- break는 필요에 따라 생략할 수 있다.
    - break가 없다면 블록의 끝까지 모든 문장을 실행하게 된다.
    - break를 생략할 때는 자세한 설명과 함께 제한적으로 사용해야 한다.
- switch ~ case문은 정수값에 따라 실행 문장을 선택하기에 좋은 구조며 범위를 검사하는 경우에는 적합하지 않다.
- switch ~ case문은 조건에 따라 case의 상수를 모두 비교한 후에 일치하는 상수가 없는 경우 마지막으로 default로 이동한다. 따라서, default는 switch의 블록 안 어디에 있어도 결과는 같다. 일반적으로 마지막에 넣어 예외 상황을 처리할 때 사용한다.
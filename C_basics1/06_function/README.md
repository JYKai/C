# 함수

## 함수의 작성과 사용

### 함수 정의
함수를 실제 코드로 만드는 것이며 기능을 구현한다.
- 함수명: 함수의 기능에 맞는 이름은 무엇인가?
    - 기능을 충분히 예상할 수 있도록 적절한 이름을 선택하며, 변수 선언 규칙에 따라 만든다.
- 매개변수: 함수가 기능을 수행하는 데 필요한 데이터는 무엇인가?
    - 함수가 처리할 데이터를 저장하는 변수로 함수명 옆의 괄호 안에 선언한다.
- 반환형: 함수가 수행된 후의 결과는 무엇인가?
    - 함수가 기능을 수행한 후에 호출한 곳으로 돌려줄 값의 자료형을 적는다.
```c
반환형 함수명(매개변수1, 매개변수2) <---- 함수 원형
{
    // 함수가 수행하는 명령. 결괏값을 돌려보냄
}
```

```c
// 2개의 함수로 만든 프로그램

#include <stdio.h>

int sum(int x, int y);

int main(void)
{
    int a = 10, b = 20;
    int result;

    result = sum(a, b);
    printf("result = %d\n", result);

    return 0;
}

int sum(int x, int y)
{
    int temp;
    temp = x + y;
    return temp;
}
```
- 함수를 정의할 때는 다른 함수 안에서 정의할 수 없다.
- 함수를 만들 때는 함수 원형을 가장 먼저 작성한다. = 함수 선언 ```int sum(int x, int y);```
    - 선언을 미리 해야 컴파일러가 반환값의 형태를 확인하고, 저장 공간을 준비할 수 있다.
    - 함수의 호출 형식에 문제가 없는지 검사한다.
- 컴파일러는 변수명의 사용 범위를 선언한 블록 내부로 제한하므로, 둘 이상의 함수에서 같은 이름의 변수를 선언해도 중복 에러가 발생하지 않는다.
- 컴파일러는 함수를 호출할 때 반환값을 저장할 공간을 미리 준비해둔다. 이 공간은 컴파일러가 별도로 확보하는 공간이며 식별할 수 있는 이름이 없으므로 계속 사용할 수 없다.
    - 저장된 반환값을 대입 연산으로 다른 변수에 복사하거나 수식에 바로 사용하는 것은 가능하다.

</br>

## 여러 가지 함수 유형

### 매개변수가 없는 함수
```c
// 매개변수가 없는 함수

#include <stdio.h>

int get_num(void);

int main(void)
{
    int result;

    result = get_num();
    printf("반환값 : %d\n", result);
    return 0;
}

int get_num(void)
{
    int num;
    printf("양수 입력 : ");
    scanf("%d", &num);
    while (num < 0)
    {
        printf("양수를 입력하세요!\n");
        printf("양수 입력 : ");
        scanf("%d", &num);
    }
    
    return num;
}
```
- ```int get_num(void)```
    - 괄호 안에 void를 넣어 매개변수가 없음을 표시한다. 괄호만 사용해도 괜찮지만, 매개변수가 없다는 것을 명시적으로 보여줄 수 있도록 void를 넣어주는 것이 좋다.
    - void는 함수 정의나 선언에서 사용하며 호출할 때는 사용하지 않는다.


### 반환값이 없는 함수
데이터를 받아서 단지 화면에 출력하는 함수라면 특별히 반환값이 필요 없다.
```c
// 반환값이 없는 함수

#include <stdio.h>

void print_char(char ch, int count);

int main(void)
{
    print_char('@', 5);

    return 0;
}

void print_char(char ch, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%c", ch);
    }

    return;
}
```
- 문자와 숫자를 받아야 하므로 매개변수는 있으나 반환형은 void를 사용한다.
- 반환값이 없으므로 return문은 값없이 단독으로 사용한다.
    - return으로 돌려줄 값이 없다면 자연스럽게 혼자 쓰인다. 생략도 가능하다.
- 반환형이 void일 경우 컴파일러는 반환값을 저장할 공간을 준비하지 않는다. 따라서, return 문에 반환값을 넣어주면 에러가 발생한다.


### 매개변수와 반환값이 모두 없는 함수
```c
// 반환값과 매개변수가 모두 없는 함수

#include <stdio.h>

void print_line(void);

int main(void)
{
    print_line();
    printf("학번    이름    전공    학점\n");
    print_line();

    return 0;
}

void print_line(void)
{
    int i;
    for (i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n");
}
```


### 재귀호출 함수
자기 자신을 호출하는 함수
```c
// 재귀호출 함수

#include <stdio.h>

void fruit(void);

int main(void)
{
    fruit();

    return 0;
}

void fruit(void)
{
    printf("apple\n");
    fruit();
}
```
- 함수는 끝나지 않고 apple을 계속 출력한다.
- 함수는 호출만으로 일정 크기의 메모리를 사용하므로 무한 호출하면 프로그램 하나가 쓸 수 있는 메모리(해당 프로세스에 할당된 스택 메모리)를 모두 사용하여 강제 종료된다.
- 재귀호출 함수는 반복 고리를 끊을 수 있는 조건식을 반드시 포함해야한다.
```c
// 3번 실행되는 재귀호출 함수

#include <stdio.h>

void fruit(int count);

int main(void)
{
    fruit(1);

    return 0;
}

void fruit(int count)
{
    printf("apple\n");
    if (count == 3) { return; }
    fruit(count + 1);
}
```
- 재귀호출 함수는 경우에 따라 복잡한 반복문을 간단히 표현할 수 있으나 코드 읽기가 쉽지 않고 반복 호출되면서 메모리를 사용하므로 제한적으로 쓰는 것이 좋다.
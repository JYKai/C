# 연산자

## 산술 연산자, 관계 연산자, 논리 연산자

### 산술 연산자와 대입 연산자

**산술 연산자**  
더하기(+), 빼기(-), 곱하기(*), 나누기(/), 나머지(%)의 연산을 의미한다.

**대입 연산자**  
'='를 대입 연산자라 하며 오른쪽 수식의 결과를 왼쪽 변수에 저장하는 역할을 한다.

**나누기 연산자와 나머지 연산자**  
나누기는 '/' 연산자를 사용한다. 
- 정수로 연산할 때는 몫을 구하고, 실수로 연산할 때는 소수점까지 구한다.
```c
// 몫과 나머지를 구하는 연산

#include <stdio.h>

int main(void)
{
    double apple;
    int banana;
    int orange;

    apple = 5.0 / 2.0;
    banana = 5 / 2;
    orange = 5 % 2;

    printf("apple : %.1lf\n", apple);
    printf("banana : %d\n", banana);
    printf("orange : %d\n", orange);

    return 0;
}
```
- 나눗셈 연산은 결괏값이 정수 또는 실수가 될 수 있으므로 그 값을 저장하는 변수도 그에 맞게 사용해야 한다.
- 실수 연산에는 나머지의 개념이 없으므로 나머지 연산자의 피연산자로 반드시 정수만을 사용해야 한다.


### 증감 연산자
```c
// 증감 연산자의 연산

#include <stdio.h>

int main(void)
{
    int a = 10, b = 10;

    ++a; // 변수의 값을 1 만큼 증가
    --b; // 변수의 값을 1 만큼 감소

    printf("%d\n", a); // 11
    printf("%d\n", b); // 9

    return 0;
}
```

**전위 표기와 후위 표기**  
- 전위 표기(prefix) : 증감 연산자가 피연산자 앞에 놓인 경우
    - 값이 증감하고 나서 연산에 사용
- 후위 표기(postfix) : 증감 연산자가 피연산자 뒤에 놓인 경우
    - 연산에 사용하고 나서 값이 증감

```c
// 전위 표기와 후위 표기를 사용한 증감 연산

#include <stdio.h>

int main(void)
{
    int a = 5, b = 5;
    int pre, post;

    pre = (++a) * 3;
    post = (b++) * 3;

    printf("초깃값 a = %d, b = %d\n", a, b); // 초깃값 a = 6, b = 6
    printf("전위형: (++a) * 3 = %d, 후위형: (b++) * 3 = %d\n", pre, post); // 전위형: (++a) * 3 = 18, 후위형: (b++) * 3 = 15

    return 0;
}
```

> ```(++a) + a + (++a)``` 
- 하나의 수식에서 같은 변수를 두 번 이상 사용할 때는 그 변수에 증감 연산자를 사용하면 안된다.


### 관계 연산자
관계 연산자에는 < 또는 > 등의 대소 관계 연산자와 ==(같다) 또는 !=(같지 않다)와 같은 동등 관계 연산자가 있다.
- 연산의 결괏값은 1 또는 0이다. 컴파일러는 참과 거짓을 1과 0으로 판단하므로 관계식을 실행 조건 검사에 사용할 수 있다.


### 논리 연산자
참과 거짓을 판단하는 데 사용하며 &&(AND), ||(OR), !(NOT) 셋뿐이다.
- && : 논리곱(AND) 연산자로 2개의 피연산자가 모두 참일 때만 연산 결과가 참이 된다.
- || : 논리합(OR) 연산자로 둘 중 하나라도 참이면 참이 된다.
- ! : 논리부정(NOT) 연산자이며 피연산자를 하나 사용하여 그 참과 거짓을 바꿀 때 사용한다.

```
a = 30 일때,
(a > 10) && (a < 20) 은 거짓이지만 10 < a < 20은 참이다. 수식을 만들 때 늘 유의하자.
```

**숏 서킷 룰(short circuit rule)**  
&&와 || 연산자는 숏 서킷 룰이 적용된다.  
숏 서킷 룰이란 좌항만으로 &&와 ||연산 결과를 판별하는 기능이다.
- && 연산자는 좌항이 거짓이면 우항과 관계없이 결과는 거짓이다.
- || 연산자는 좌항이 참이면 우항과 관계없이 결과가 참이다. 즉, 좌항이 참이면 우항은 아예 실행이 되지 않는다.
- ```(a < 0) && (++b > 20)```의 식이 있다면, ++b가 실행이 되지 않을 수 도 있다.


### 연산의 결괏값을 처리하는 방법
연산을 실행한 다음 연산의 결괏값은 변수에 저장하지 않으면 버려진다. 따라서 연산 결과를 곧바로 사용하거나 대입 연산을 통해 다른 변수에 저장해야 한다.

</br>

## 그 외 유용한 연산자

### 형 변환 연산자
형 변환 연산자는 피연산자가 1개이며 피연산자의 값을 원하는 형태로 바꾼다.  
형 변환 연산자를 사용해서 피연산자의 형태를 바꿀 때는 피연산자의 값을 복사하여 일시적으로 형태를 바꾸므로 연산 후 메모리에 있는 피연산자의 형태나 값은 변하지 않는다.
- ```(자료형)피연산자```
    - ```(double)10 -> 10.0```, ```(int)10.7 -> 10```
```c
// 형 변환 연산자가 필요한 경우

#include <stdio.h>

int main(void)
{
    int a = 20, b = 3;
    double res;

    res = ((double)a) / ((double)b);
    printf("a = %d, b = %d\n", a, b);     // a = 20, b = 3
    printf("a / b의 결과 : %.1lf\n", res); // a / b의 결과 : 6.7

    a = (int)res;
    printf("(int) %.1lf의 결과 : %d\n", res, a); // (int) 6.7의 결과 : 6

    return 0;
}
```
- 처음부터 a와 b를 double형으로 선언하면 편할 수 있지만, double형은 저장 공간이 크고 연산 속도가 느리며 무엇보다도 오차가 발생하므로 int형을 기본적으로 사용하고 실수 연산 결과가 필요할 때만 형 변환을 사용하는 편이 좋다.
- 추가적으로, 실수에서 정수 부분만을 추릴 때도 유용하게 사용된다. 소숫점 이하는 반올림이 아닌 버림으로 처리된다.

**자동 형 변환**  
컴퓨터는 데이터의 형태에 따라 다른 연산 방법을 사용하므로 피연산자가 2개 이상이라면 피연산자의 형태는 같아야 한다.  
따라서 컴파일러는 컴파일 과정에서 피연산자의 형태가 다르면 형태를 일치시키는 작업을 수행하여 이를 자동 형 변환이라고 한다.  
자동 형 변환은 형태가 다른 데이터를 자유롭게 연산할 수 있도록 도와주지만 예상치 못한 값의 변형이 생길 수 있으므로 가능하면 피연산자의 형태를 같게 사용하는 것이 좋다.


### sizeof 연산자
피연산자를 하나만 사용할 수 있으며 피연산자의 크기를 바이트 단위로 계산해서 알려준다.
- 대상은 변수, 상수, 수식, 자료형 등이 될 수 있다.
- 데이터 크기를 확인하거나 메모리를 동적으로 할당하는 작업 등에 유용하게 사용된다.
```c
// sizeof 연산자의 사용 예

#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.4;

    printf("int형 변수의 크기 : %d\n", sizeof(a));
    printf("double형 변수의 크기 : %d\n", sizeof(b));
    printf("정수형 상수의 크기 : %d\n", sizeof(10));
    printf("수식의 결괏값의 크기 : %d\n", sizeof(1.5 + 3.4));
    printf("char 자료형의 크기 : %d\n", sizeof(char));

    return 0;
}
```
- "A"와 같은 문자열의 크기를 확인할 수 있다. 이때, 문자열 끝에는 널 문자 \0이 삽입되므로 값은 2가 된다.
- 배열의 크기를 확인하는 용도로도 사용할 수 있다.

**sizeof 연산자와 괄호**  
sizeof는 연산자이므로 기본적으로 피연산자에 괄호를 사용할 필요가 없다. 하지만, 연산과정에서 의도치 않은 실수가 발생할 수 있으므로 편의상 피연산자에 괄호를 사용하도록 한다.


### 복합대입 연산자
연산 결과를 피연산자에 저장할 필요가 있다면 추가로 대입 연산을 수행해야하며 이때 복합대입 연산사를 사용하면 간단해진다.
- +=, -=. *=, /=, %= 이렇게 다섯 가지가 있다.
```c
// 복합대입 연산자

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    int res = 2;

    a += 20;
    res *= b + 10;

    printf("a = %d, b = %d\n", a, b); // a = 30, b = 20
    printf("res = %d\n", res); // res = 60

    return 0;
}
```

### 콤마 연산자
한 번에 여러 개의 수식을 차례로 나열해야 할 때 사용한다.  
왼쪽부터 오른쪽으로 차례로 연산을 수행하며 가장 오른쪽의 피연산자가 최종 결괏값이 된다.
```c
// 콤마 연산자

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    int res;

    res = (++a, ++b);
    
    printf("a: %d, b: %d\n", a, b); // a: 11, b: 21
    printf("res: %d\n", res); // res: 21

    return 0;
}
```
- 콤마 연산자는 대입 연산자보다 우선순위가 낮은 유일한 연산자이다. 대입 연산자와 함께 사용할 때는 반드시 괄호가 필요하다.
- ```res = (++a, ++b);```
    - 괄호가 빠져 있다면 res = ++a 연산 후에 ++b의 연산이 수행된다. 결과적으로 res에는 증가된 a값이 저장되고, b에는 1만큼 커진 값이 저장된다. = ```res = ++a; ++b;```
- 제어문에서 조건식을 나열하는 괄호 안과 같이 세미콜론 사용이 불가능한 구조에서 사용한다.

### 조건 연산자
유일한 삼항 연산자로 ?와 : 기호를 함께 사용한다.  
첫 번째 피연산자가 참이면 두 번째 피연산자가 결괏값이 되고, 거짓이면 세 번째 피연산자가 결괏값이 된다.
```c
// 조건 연산자

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20, res;

    res = (a > b) ? a : b;
    printf("큰 값 : %d\n", res); // 큰 값 : 20

    return 0;
}
```
- 조건 연산자는 코드를 간략히 만들어주는 효과가 있으며 매크로 함수에 사용하면 좋으나 가독성을 떨어뜨릴 가능성이 있으므로 필요한 곳에만 사용하는 것이 좋다.

### 비트 연산자
데이터를 비트 단위로 연산한다.  
논리 연산을 수행하는 &, |, ^ 같은 비트 논리 연산자와 비트를 좌우로 움직이는 >>, <<같은 비트 이동 연산자가 있다.
- 데이터를 비트로 정확히 표현할 수 있는 **정수**에만 사용할 수 있다.
```c
// 비트 연산식의 결과

#include <stdio.h>

int main(void)
{
    int a = 10; // 비트열 00000000 00000000 00000000 00001010
    int b = 12; // 비트열 00000000 00000000 00000000 00001100

    printf("a & b : %d\n", a & b);  // a & b : 8
    printf("a ^ b : %d\n", a ^ b);  // a ^ b : 6
    printf("a | b : %d\n", a | b);  // a | b : 14
    printf("~a : %d\n", ~a);        // ~a : -11
    printf("a << 1 : %d\n", a << 1); // a << 1 : 20
    printf("a >> 2 : %d\n", a >> 2); // a >> 2 : 2

    return 0;
}
```

**비트별 논리곱 연산자**  
```printf("a & b : %d\n", a & b);``` : 피연산자 a와 b를 각각 비트별로 논리곱 연산(&)을 수행한다.
- a & b = 8 -> 비트열 00000000 00000000 00000000 00001000
- 변수 a에 저장되어 있는 비트들과 b에 저장되어 있는 비트들을 각 위치별로 하나씩 피연산자라고 생각하고 논리곱 연산을 수행한다.
    - 두 비트가 모두 1인 경우에만 1로 계산

**비트별 배타적 논리합 연산자**  
```printf("a ^ b : %d\n", a ^ b);``` : 두 피연산자의 진리값이 서로 다를 때만 참이 된다.
- 둘 다 참이거나 둘 다 거짓이면 거짓이고, 하나만 참이고 다른 하나가 거짓인 경우에만 참이 된다.
- a ^ b = 6 -> 비트열 00000000 00000000 00000000 00000110

**비트별 논리합 연산자**  
```printf("a | b : %d\n", a | b);```
- a | b = 14 -> 비트열 00000000 00000000 00000000 00001110
- 두 비트 중에서 하나라도 참이면 1로 계산한다.

**비트별 부정 연산자**  
```printf("~a : %d\n", ~a);```
- 피연산자가 하나며 피연산자의 비트를 반전시킨다.
- 비트열 11111111 11111111 11111111 11110101 = -11

**비트 이동 연산자**  
<<은 비트들을 왼쪽으로 이동하고 >>은 오른쪽으로 이동한다.  
```printf("a << 1 : %d\n", a << 1);```
- a의 비트들을 모두 왼쪽으로 한 비트씩 이동시킨다. 왼쪽으로 밀려나는 비트들은 사라지고 오른쪽의 남은 비트는 0으로 채워진다.
- 비트열 00000000 00000000 00000000 00001010 -> 비트열 00000000 00000000 00000000 00010100
    - 값을 왼쪽으로 한 비트씩 이동할 때마다 2가 곱해진다.
```printf("a >> 2 : %d\n", a >> 2);```  
- 오른쪽 비트 이동 연산(>>)을 수행하면 2로 나눈 몫이 된다. 이때, 오른쪽으로 밀려나는 비트는 사라지며 왼쪽의 남은 비트는 부호 비트로 채운다.
    - 값이 양수이면 비트 이동 연산 후 왼쪽의 남은 비트는 양수로 채워지며, 음수일 경우에는 음수로 채워진다. 즉, 부호의 변화는 발생하지 않는다.

### 연산자 우선순위와 연산 방향
하나의 수식에서 2개 이상의 연산자가 함께 쓰일 때는 연산자의 우선순위에 따라 연산된다.
- 단항 연산자 > 이항 연산자 > 삼항 연산자 순서로 연산된다.
- 산술 연산자 > (비트 이송 연산자) > 관계 연산자 > 논리 연산자 순서로 연산된다.
```c
// 연산자 우선순위와 연산 방향

#include <stdio.h>

int main(void)
{
    int a = 10, b = 5;
    int res;

    res = a / b * 2; // 우선순위가 같으므로 왼쪽부터 차례로 연산
    printf("res = %d\n", res);
    res = ++a * 3; // a의 값을 1증가시키고 3을 곱한다.
    printf("res = %d\n", res);
    res = a > b && a != 5; // a > b의 결과와 a != 5의 결과를 && 연산
    printf("res = %d\n", res);
    res = a % 3 == 0; // a % 3의 값이 0과 같은지 확인
    printf("res = %d\n", res);

    return 0;
}
```
- 여러 연산자를 함께 사용할 때 의심되거나 분석이 까다롭다고 느껴진다면 괄호를 사용하자.
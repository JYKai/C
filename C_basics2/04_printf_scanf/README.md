# printf 함수와 scanf 함수 정리하기

## printf 함수 이야기

### printf 함수는 문자열을 출력하는 함수이다.
C언어는 큰 따옴표를 사용해서 문자열을 표현한다.
- 큰 따옴표로 묶인 문자열을 전달하면서 printf 함수를 호출하면, 전달된 문자를 출력한다.

### 특수문자의 출력이 필요한 이유
큰 따옴표는 문자열의 시작과 끝으로 해석이 되니, 큰 따옴표 자체의 출력을 원하는 경우에는 큰 따옴표 앞에 \문자를 붙여주기로 하자.
```c
printf("앞집 강아지가 말했다. \"멍~! 멍~!\" 정말 귀엽다.");
```

### printf 함수의 서식지정
printf는 print formatted 라는 뜻이며, 이는 '출력양식이 만들어진 상태에서 출력을 진행한다'는 뜻이다.
- %d : 데이터를 10진수 정수의 형태로 출력
- %X : 데이터를 16진수로 출력하되, 알파벳은 대문자로 출력(%x -> 소문자)

### 정수의 출력을 위한 서식문자들: %d, %u, %o, %x
- %o, %x : 8진수, 16진수의 출력에 사용되며 양의 정수만 출력이 가능하다.
    - 음의 정수를 출력하려면 %d
```c
#include <stdio.h>

int main(void)
{
    int num1 = 7, num2 = 13;
    printf("%o %#o \n", num1, num2);    // 7 015 
    printf("%x %#x \n", num1, num2);    // 7 0xd

    return 0;
}
```
- 16진수로 출력할 경우 출력된 내용이 16진수 정보임을 알리기 위해서 가급적 서식문자에 #을 포함시켜서 출력하는 것이 좋다.

### 실수의 출력을 위한 서식문자들: %f, %e, %g
```c
#include <stdio.h>

int main(void)
{  
    double d1 = 1.23e-3;
    double d2 = 1.23e-6;
    
    printf("%f \n", 0.1234);        // 0.123400 
    printf("%e \n", 0.1234);        // 1.234000e-01 
    printf("%f \n", 0.12345678);    // 0.123457 
    printf("%e \n", 0.12345678);    // 1.234568e-01 

    printf("%g \n", d1);            // 0.00123 
    printf("%g \n", d2);            // 1.23e-06 

    return 0;
}
```
- %g는 소수점 이하의 자릿수가 늘어나면 e표기법으로 출력을 한다.

### %s를 이용한 문자열의 출력
%s는 string의 s를 뜻하며, 문자열의 출력을 지시하기 위한 서식문자에 사용된다.

### 필드 폭을 지정하여 정돈된 출력 보이기
서식문자에는 출력의 필드 폭을 지정하는 옵션을 추가할 수 있다.
- %8d : 필드 폭을 8칸 확보하고, 오른쪽 정렬해서 출력을 진행한다.
- %-8d : 필드 폭을 8칸 확보하고, 왼쪽 정렬해서 출력을 진행한다.

</br>

## scanf 함수 이야기

### 정수 기반의 입력형태 정의하기
printf 함수와 마찬가지로 서식문자를 사용해서 출력한다.
- %d, %o, %x

### 실수 기반의 입력형태 정의하기
printf 함수에서는 서식문자 %f, %e 그리고 %g의 의미가 각각 달랐다. 그러나 scanf 함수에서는 'float형 데이터를 입력 받겠다'는 동일한 의미를 담고 있다.
- %lf : double
- %Lf : long double
```c
#include <stdio.h>

int main(void)
{
    float num1;
    double num2;
    long double num3;

    printf("실수 입력1(e 표기법으로): ");
    scanf("%f", &num1);
    printf("입력된 실수 %f \n", num1);

    printf("실수 입력2(e 표기법으로): ");
    scanf("%lf", &num1);
    printf("입력된 실수 %f \n", num1);

    printf("실수 입력3(e 표기법으로): ");
    scanf("%Lf", &num1);
    printf("입력된 실수 %Lf \n", num1);

    return 0;
}
```
- 실수의 입력과정에서 e 표기법을 사용해도 된다.
- float, double, long double의 데이터 출력에 사용되는 서식문자는 %f, %f, %LF 이다.
- float, double, long double의 데이터 입력에 사용되는 서식문자는 %f, %lf, %LF 이다.
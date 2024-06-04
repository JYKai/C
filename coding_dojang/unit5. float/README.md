# 실수 자료형 사용하기

## 실수형 변수 선언하기

```c
#include <stdio.h>

int main()
{
    float num1 = 0.1f;               // 단정밀도 부동소수점 변수를 선언하고 값을 할당
                                     // float는 숫자 뒤에 f를 붙임

    double num2 = 3867.215820;       // 배정밀도 부동소수점 변수를 선언하고 값을 할당
                                     // double은 숫자 뒤에 아무것도 붙이지 않음

    long double num3 = 9.327513l;    // 배정밀도 부동소수점 변수를 선언하고 값을 할당
                                     // long double은 숫자 뒤에 l을 붙임

    // float와 double은 %f로 출력, long double은 %Lf로 출력
    printf("%f %f %Lf\n", num1, num2, num3);    // 0.100000 3867.215820 9.327513

    return 0;
}
```
- 여기서 float는 숫자 뒤에 f, F를 붙여주고, long double은 l, L을 붙여인다. 
- double은 아무것도 붙이지 않는다.
- 1.f, .1f처럼 소수점 앞 또는 뒤의 0은 생략할 수 있다.

```c
#include <stdio.h>

int main()
{
    float num1 = 3.e5f;             // 지수 표기법으로 300000을 표기
                                    // float는 숫자 뒤에 f를 붙임
 
    double num2 = -1.3827e-2;       // 지수 표기법으로 -0.013827을 표기
                                    // double은 숫자 뒤에 아무것도 붙이지 않음

    long double num3 = 5.21e+9l;    // 지수 표기법으로 5210000000을 표기
                                    // long double은 숫자 뒤에 l을 붙임

    // float와 double은 %f로 출력, long double은 %Lf로 출력
    printf("%f %f %Lf\n", num1, num2, num3); // 300000.000000 -0.013827 5210000000.000000

    // 지수 표기법으로 출력할 때는 float와 double은 %e로 출력, long double은 %Le로 출력
    printf("%e %e %Le\n", num1, num2, num3); // 3.000000e+05 -1.382700e-02 5.210000e+09

    return 0;
}
```

</br>

## 자료형 크기 구하기
```c
#include <stdio.h>

int main()
{
    float num1 = 0.0f;
    double num2 = 0.0;
    long double num3 = 0.0l;

    printf("float: %d, double: %d, long double: %d\n",
        sizeof(num1),     // 4: sizeof로 float 변수의 자료형 크기를 구함
        sizeof(num2),     // 8: sizeof로 double 변수의 자료형 크기를 구함
        sizeof(num3)      // 8: sizeof로 long double 변수의 자료형 크기를 구함
    );

    return 0;
}
```

</br>

## 최솟값과 최댓값 표현하기
```c
#include <stdio.h>
#include <float.h>    // 실수 자료형의 양수 최솟값, 최댓값이 정의된 헤더 파일

int main()
{
    float num1 = FLT_MIN;           // float의 양수 최솟값
    float num2 = FLT_MAX;           // float의 양수 최댓값
    double num3 = DBL_MIN;          // double의 양수 최솟값
    double num4 = DBL_MAX;          // double의 양수 최댓값
    long double num5 = LDBL_MIN;    // long double의 양수 최솟값
    long double num6 = LDBL_MAX;    // long double의 양수 최댓값

    printf("%.40f %.2f\n", num1, num2);    // 0.0000000000000000000000000000000000000118
                                           // 340282346638528859811704183484516925440.00

    printf("%e %e\n", num3, num4);         // 2.225074e-308 1.797693e+308
    printf("%Le %Le\n", num5, num6);       // 2.225074e-308 1.797693e+308
 
    return 0;
}
```

</br>

## 오버플로우 & 언더플로우
```c
#include <stdio.h>
#include <float.h>    // 실수 자료형의 양수 최솟값, 최댓값이 정의된 헤더 파일

int main()
{
    float num1 = FLT_MIN;    // float의 양수 최솟값
    float num2 = FLT_MAX;    // float의 양수 최댓값

    // float의 양수 최솟값을 100000000.0으로 나누면 아주 작은 수가 되면서 언더플로우 발생
    num1 = num1 / 100000000.0f;

    // float의 양수 최댓값에 1000.0을 곱하면 저장할 수 있는 범위를 넘어서므로 오버플로우 발생
    num2 = num2 * 1000.0f;

    printf("%e %e\n", num1, num2);    // 0.000000e+00 inf: 실수의 언더플로우는 0
                                      // 오버플로우는 무한대가 됨

    return 0;
}
```
- FLT_MIN을 100000000.0과 같이 큰 수로 나누면 아주 작은 수가 되면서 언더플로우가 발생하는데 C 언어에서는 실수 언더플로우를 0 또는 쓰레기 값으로 처리한다.
- FLT_MAX에 1000.0을 곱하면 저장할 수 있는 범위를 넘어서기 때문에 오버플로우가 발생한다. 정수와는 달리 실수는 오버플로우가 발생했을 때 최솟값으로 되돌아가지 않고 무한대(infinity)가 되므로 inf가 출력된다.
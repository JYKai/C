# 정수 자료형

## 정수 자료형 사용하기
정수 자료형은 크게 char, int가 있으며 앞에 부호 키워드(signed, unsigned)와 크기(short, long)를 붙여서 특성을 정의할 수 있다.

- signed: 부호 있는 정수를 표현한다. 보통 signed 키워드는 생략한다.
- unsigned: 부호 없는 정수를 표현한다. 따라서 값은 0부터 시작하게 된다. 

</br>

## 정수형 변수 선언하기
```c
#include <stdio.h>

int main(void)
{
    char num1 = -10;           // 1바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    short num2 = 30000;        // 2바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    int num3 = -1234567890;    // 4바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    long num4 = 1234567890;    // 4바이트 부호 있는 정수형으로 변수를 선언하고 값 할당
    long long num5 = -1234567890123456789;     // 8바이트 부호 있는 정수형으로 변수를 
                                               // 선언하고 값 할당

    // char, short, int는 %d로 출력하고 long은 %ld, long long은 %lld로 출력
    printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);
    // -10 30000 -1234567890 1234567890 -1234567890123456789
    return 0;
}
```
- 보통 부호 있는 정수는 signed를 생략한다.
- short와 long도 int를 생략하여 사용한다. 
- char는 문자(character)를 뜻하지만 기본적으로 정수형이다.
- printf 함수에서 char, short, int는 서식지정자 %d로 출력하지만 long은 %ld를 사용하고 long long은 %lld를 사용한다.

```c
#include <stdio.h>

int main()
{
    unsigned char num1 = 200;                          // 1바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    unsigned short num2 = 60000;                       // 2바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    unsigned int num3 = 4123456789;                    // 4바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    unsigned long num4 = 4123456789;                   // 4바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    unsigned long long num5 = 12345678901234567890;    // 8바이트 부호 없는 정수형으로 
                                                       // 변수를 선언하고 값 할당

    // unsigned char, unsigned short, unsigned int는 %u로 출력하고 
    // unsigned long은 %lu, unsigned long long은 %llu로 출력
    printf("%u %u %u %lu %llu\n", num1, num2, num3, num4, num5);
    // 200 60000 4123456789 4123456789 12345678901234567890

    return 0;
}
```
- 부호 없는 정수 자료형은 앞에 unsigned키워드를 붙여주면 된다.
- printf 함수에서 unsigned char, unsigned short는 서식 지정자 %d로도 충분히 출력할 수 있지만 unsigned int는 %u, unsigned long은 %lu, unsigned long long은 %llu로 출력해야 한다.

</br>

## 오버플로우와 언더플로우
**오버플로우**  
저장할 수 있는 범위를 넘어서면 최솟값부터 다시 시작하게 된다.

**언더플로우**  
최솟값보다 작아지면 최댓값부터 다시 시작하게 된다(값을 계속 뺀다면 최댓값에서 값이 계속 작아짐).

</br>

## 자료형 크기 구하기
**sizeof**  
자료형(타입)의 크기를 바이트(byte) 단위로 구한다.
- sizeof 표현식
- sizeof(자료형)
- sizeof(표현식)

```c
#include <stdio.h>

int main()
{
    int num1 = 0;
    int size;

    size = sizeof num1;
    printf("num1의 크기: %d\n", size); // num1의 크기: 4

    return 0;
}
```
- int와 같은 자료형의 크기를 직접 구하려면 sizeof(자료형) 형식으로 사용해야 한다.
- sizeof(표현식) 형식도 사용할 수 있다.

```c
#include <stdio.h>

int main()
{
    // char: 1, short: 2, int: 4, long: 8, long long: 8
    printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
        sizeof(char),
        sizeof(short),
        sizeof(int),
        sizeof(long),
        sizeof(long long));
    
    return 0;
}
```

</br>

## 최솟값과 최댓값 표현
소스 코드에서 정수의 최솟값을 표현하려면 ```limits.h``` 헤더 파일을 사용해야 한다.

```c
#include <stdio.h>
#include <limits.h> // 자료형의 최댓값과 최솟값이 정의된 헤더 파일

int main()
{
    char num1 = CHAR_MIN;
    short num2 = SHRT_MIN;
    int num3 = INT_MIN;
    long num4 = LONG_MIN;
    long long num5 = LLONG_MIN;

    printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);
    // -128 -32768 -2147483648 -9223372036854775808 -9223372036854775808
   
    return 0;
}
```

</br>

## 크기가 표시된 정수 자료형 사용
```stdint.h``` 헤더 파일을 사용하여 크기가 표시된 정수 자료형으로 변수를 선언하는 방법

```c
#include <stdio.h>
#include <stdint.h>    // 크기별로 정수 자료형이 정의된 헤더 파일

int main()
{
    int8_t num1 = -128;                    // 8비트(1바이트) 크기의 부호 있는 정수형 변수 선언
    int16_t num2 = 32767;                  // 16비트(2바이트) 크기의 부호 있는 정수형 변수 선언 
    int32_t num3 = 2147483647;             // 32비트(4바이트) 크기의 부호 있는 정수형 변수 선언
    int64_t num4 = 9223372036854775807;    // 64비트(8바이트) 크기의 부호 있는 정수형 변수 선언

    // int8_t, int16_t, int32_t는 %d로 출력하고 int64_t는 %lld로 출력
    printf("%d %d %d %lld\n", num1, num2, num3, num4); // -128 32767 2147483647 9223372036854775807

    uint8_t num5 = 255;                      // 8비트(1바이트) 크기의 부호 없는 정수형 변수 선언
    uint16_t num6 = 65535;                   // 16비트(2바이트) 크기의 부호 없는 정수형 변수 선언
    uint32_t num7 = 4294967295;              // 32비트(4바이트) 크기의 부호 없는 정수형 변수 선언
    uint64_t num8 = 1844674407370955161;    // 64비트(8바이트) 크기의 부호 없는 정수형 변수 선언

    // uint8_t, uint16_t, uint32_t는 %u로 출력하고 uint64_t는 %llu로 출력
    printf("%u %u %u %llu\n", num5, num6, num7, num8); // 255 65535 4294967295 18446744073709551615

    return 0;
}
```
- ```stdint```의 최소, 최댓값은 ```stdint.h``` 헤더 파일 안에 정의되어 있으므로 ```limits.h``` 헤더 파일을 사용하지 않아도 된다. 
- 자료형과 마찬가지로 최소, 최댓값도 비트 단위로 크기가 표시되어 있으므로 간편하게 사용할 수 있다.
    - 부호 있는 정수(signed) 최솟값: ```INT8_MIN, INT16_MIN, INT32_MIN, INT64_MIN```
    - 부호 있는 정수 최댓값: ```INT8_MAX, INT16_MAX, INT32_MAX, INT64_MAX```
    - 부호 없는 정수(unsigned) 최솟값: 0
    - 부호 없는 정수 최댓값: ```UINT8_MAX, UINT16_MAX, UINT32_MAX, UINT64_MAX```
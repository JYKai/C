# Hello, world

## Hello, world 출력하기

```C
# include <stdio.h>

int main(void)
{
    printf("Hello, world\n");

    return 0;
}
```
- ```#include```는 헤더 파일을 포함하는 문법이며 printf 함수를 사용하려면 stdio.h 헤더 파일이 필요하다.
- main함수는 C 언어로 프로그램을 만들었을 때 가장 처음에 실행되는 특별한 함수이다.
    - 소스에서 main 함수가 없으면 컴파일이 되지 않는다.
- ```return 0;```
    - 함수는 반환값을 함수 바깥으로 전달할 수 있는데 main 함수도 함수이므로 반환값을 설정할 수 있다.

## 서식 지정자(format specifier) 사용

```C
#include <stdio.h>

int main(void)
{
    printf("%s\n", "Hello, world!");
}
```

- 서식 지정자를 사용하든 "Hello, world!"를 바로 출력하든 결과에는 차이가 없다. 하지만 서식 지정자는 변수를 사용하여 같은 내용을 여러 개 출력하거나, 출력 형태를 바꿀 때 유용하게 사용할 수 있다.
- %s: 문자열(string)의 약어로 s를 사용한다.
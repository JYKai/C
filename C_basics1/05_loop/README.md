# 반복문
일정 조건을 만족하는 동안 같은 실행문을 반복하는 것

## while문, for문, do ~ while문
- while문 : 조건을 먼저 물어보고 만족하는 동안 실행문을 실행
- for문 : 초깃값을 최초 설정한 다음 조건을 물어보고 실행문을 실행한 다음 증감식을 실행하고 다시 조건을 확인
- do ~ while문 : 실행문을 무조건 실행하고 조건을 확인한 후에 다시 실행문을 실행

### while문
```c
// while문을 사용한 반복문

#include <stdio.h>

int main(void)
{
    int a = 1;

    while (a < 10)
    {
        a *= 2;
    }
    
    printf("a = %d\n", a);

    return 0;
}
```
- 모든 반복문은 실행문을 중괄호로 묶어 반복할 부분을 표시한다.
    - 실행문이 한 문장일 경우 생략할 수 있다.
    - 불필요한 에러를 막기 위해 실행문의 개수와 상관없이 항상 중괄호를 사용할 수 있도록 한다.
- 컴파일러는 반복문의 조건식과 실행문을 모두 한 문장으로 인식한다.
- ```while(1) == for(;;)```


### for문
```c
// for문을 사용한 반복문

#include <stdio.h>

int main(void)
{
    int a = 1;
    int i;

    for (i = 0; i < 3; i++)
    {
        a *= 2;
    }
    printf("a = %d\n", a);
    return 0;
}
```
- 초기식, 조건식, 증감식은 반복 횟수를 알기 쉽게 작성한다.
- 반복 횟수를 세는 변수를 반복문 안에서 바꾸지 않는 것이 좋다.
- 반복 횟수가 정해진 경우라면 while문이 아닌 for문을 사용하는 것이 좋다.


### do ~ while문
```c
// do ~ while문을 사용한 반복문

#include <stdio.h>

int main(void)
{
    int a = 1;

    do
    {
        a *= 2;
    } while (a < 10);
    printf("a = %d\n", a);

    return 0;
}
```
- do ~ while문은 어떤 값이 입력되더라도 최소한 한 번은 do안의 문장을 실행한다.

</br>

## 반복문 활용

### 중첩 반복문
반복문 안에 실행할 문장으로 반복문이 포함된 것
```c
// 중첩 반복문을 사용한 별 출력

#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

### break와 continue 분기문

**break : 반복문 안에서 반복을 즉시 끝낼 때 사용**  
```c
// break를 사용한 반복문 종료

#include <stdio.h>

int main(void)
{
    int i;
    int sum = 0;

    for (i = 1; i <= 10; i++)
    {
        sum += i;
        if (sum > 30) { break; }
    }
    printf("누적한 값 : %d\n", sum);
    printf("마지막으로 더한 값 : %d\n", i);

    return 0;
}
```
- break는 자신을 포함하는 반복문 하나만 벗어난다. 
    - 반복문이 중첩된 경우 가장 안쪽에서 break를 사용하며 모든 반복문을 벗어날 수 없다.
    - 반복문 이외의 블록에서 사용하면 그 블록을 포함한 반복문을 벗어난다.
- switch ~ case문의 블록 안에서 break를 사용하면 switch ~ case 블록만 벗어난다.

**continue : 반복문 일부를 건너뛴다.**  
블록을 탈출하는 것은 아니며, 조건에 따라 반복문의 일부를 제외하고 반복할 수 있다.
```c
for (i = 1; i <= 100; i++)
{
    if ((i % 3) == 0) { continue; }
    sum += i;
}
```
- i가 3의 배수인 경우는 제외하고 반복문을 실행.
- while문에서 continue를 사용하면 다음 실행 위치가 조건식이 되므로 무한 반복에 빠질 수 있다.
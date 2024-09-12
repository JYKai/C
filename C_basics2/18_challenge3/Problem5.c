#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char * get_choice_name(int choice)
{
    switch (choice)
    {
    case 1: return "바위";
    case 2: return "가위";
    case 3: return "보";
    default: return "알 수 없음";
    }
}

int main()
{
    int me, computer;
    int win = 0, draw = 0;

    srand((unsigned int)time(NULL));

    while (1)
    {
        printf("바위는 1, 가위는 2, 보는 3: ");
        scanf("%d", &me);

        computer = (rand() % 3) + 1; // 컴퓨터의 선택: 1부터 3까지의 값 생성

        printf("당신은 %s 선택, 컴퓨터는 %s 선택, ", get_choice_name(me), get_choice_name(computer));
        if (me == computer)
        {
            printf("비겼습니다!\n");
            draw++;
        } else if ((me == 1 && computer == 2) ||
                   (me == 2 && computer == 3) ||
                   (me == 3 && computer == 1))
        {
            printf("이겼습니다!\n");
            win++;
        } else
        {
            printf("당신이 졌습니다!\n");
            break;
        }
    }

    printf("게임의 결과: %d승 %d무\n", win, draw);
    return 0;
}

#include <stdio.h>

struct person
{
    char name[20];
    char phoneNum[20];
    int age;
};

int main(void)
{
    struct person arr[2] = {
        {"이승기", "010-1111-2222", 21},
        {"정지영", "010-2222-3333", 24}
    };

    int i;
    for (i = 0; i < 2; i++)
    {
        printf("%s %s %d \n", arr[i].name, arr[i].phoneNum, arr[i].age);
    }

    return 0;
}

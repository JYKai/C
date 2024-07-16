#include <stdio.h>

struct employee
{
    char name[20];
    char id[20];
    int salary;
};

int main(void)
{
    struct employee arr[3] = {
        {"이승기", "941222-1111111", 10000},
        {"정지영", "931013-1122222", 15000},
        {"장지후", "950614-1125232", 25000},
    };

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%s %s %d \n", arr[i].name, arr[i].id, arr[i].salary);
    }

    return 0;
}
#include <stdio.h>

struct employee
{
    char name[20];
    char id[20];
    int salary;
};

int main(void)
{
    struct employee man;
    scanf("%s", man.name);
    scanf("%s", man.id);
    scanf("%d", &(man.salary));

    printf("name = %s \n", man.name);
    printf("id = %s \n", man.id);
    printf("salary = %d \n", man.salary);

    return 0;
}
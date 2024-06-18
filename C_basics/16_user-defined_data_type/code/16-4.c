// 구조체를 반환하여 두 변수의 값 교환

#include <stdio.h>

struct vision
{
    double left;
    double right;
};


struct vision exchange(struct vision robot);

int main(void)
{
    struct vision robot;

    printf("시력 입력 : ");     // 시력 입력 : 15.5 20.0
    scanf("%lf%lf", &(robot.left), &(robot.right));

    robot = exchange(robot);  // 바뀐 시력 : 20.0, 15.5
    printf("바뀐 시력 : %.1lf, %.1lf\n", robot.left, robot.right);

    return 0;
}

struct vision exchange(struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}
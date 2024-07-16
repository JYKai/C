#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

void SwapPoint(Point *pos1, Point *pos2);

int main(void)
{
    Point pos1 = {2, 4};
    Point pos2 = {5, 7};

    SwapPoint(&pos1, &pos2);

    printf("pos1 = [%d, %d] \n", pos1.xpos, pos1.ypos);
    printf("pos2 = [%d, %d] \n", pos2.xpos, pos2.ypos);

    return 0;
}

void SwapPoint(Point *pos1, Point *pos2)
{
    Point temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}

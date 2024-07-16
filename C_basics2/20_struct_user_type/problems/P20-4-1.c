#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

typedef struct rectangle
{
    Point upLeft;
    Point downRight;
} Rectangle;

int GetArea(Rectangle * rptr);
void ShowRectangleInfo(Rectangle * rptr);

int main(void)
{
    int area;
    Rectangle rec = {2, 5, 7, 10};
    area = GetArea(&rec);
    printf("Rectangle area = %d \n", area);
    ShowRectangleInfo(&rec);

    return 0;
}

int GetArea(Rectangle * rptr)
{
    int area;
    Point upLeft = rptr->upLeft;
    Point downRight = rptr->downRight;
    area = (downRight.xpos - upLeft.xpos) * (downRight.ypos - upLeft.ypos);
    return area;
}
void ShowRectangleInfo(Rectangle * rptr)
{
    printf("upleft = [%d, %d], downright = [%d, %d] \n", (rptr->upLeft).xpos, (rptr->upLeft).ypos, (rptr->downRight).xpos, (rptr->downRight).ypos);
}
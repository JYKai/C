#include <stdio.h>

typedef struct point
{
    int xpos;
    int ypos;
} Point;

typedef struct Circle
{
    Point cen;
    double radius;
} Circle;

void ShowCircleInfo(Circle *cptr)
{
    printf("[%d, %d] \n", (cptr->cen).xpos, (cptr->cen).ypos);
    printf("radius = %g \n", cptr->radius);
}

int main(void)
{
    Circle c1 = {{1, 2}, 3.5};
    Circle c2 = {2, 4, 3.9};

    ShowCircleInfo(&c1);
    ShowCircleInfo(&c2);

    return 0;
}
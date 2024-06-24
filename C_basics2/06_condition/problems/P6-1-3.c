#include <stdio.h>

int main(void)
{
    double kor, eng, math;
    double avg;
    scanf("%lf %lf %lf", &kor, &eng, &math);
    avg = (kor + eng + math) / 3;

    if (avg >= 90) { printf("%c\n", 'A'); }
    else if (avg >= 80 || avg < 90){ printf("%c\n", 'B'); }
    else if (avg >= 70 || avg < 80){ printf("%c\n", 'C'); }
    else if (avg >= 50 || avg < 70){ printf("%c\n", 'D'); }
    else { printf("%c\n", 'F'); }

    return 0;
}
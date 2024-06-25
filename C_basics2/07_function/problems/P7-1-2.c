#include <stdio.h>

double CelToFas(double);
double FahToCel(double);

int main(void)
{
    double initDegree, celsius, fahr;
    scanf("%lf", &initDegree);
    fahr = CelToFas(initDegree);
    celsius = FahToCel(fahr);

    printf("입력 섭씨 %.1lf to 화씨 %.1lf\n", initDegree, fahr);
    printf("입력 화씨 %.1lf to 섭씨 %.1lf\n", fahr, celsius);

    return 0;
}

double CelToFas(double degree)
{
    return (1.8 * degree) + 32;
}

double FahToCel(double degree)
{
    return (degree - 32) / 1.8;
}
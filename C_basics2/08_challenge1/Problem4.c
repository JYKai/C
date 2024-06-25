#include <stdio.h>

int main(void)
{
    int money = 3500;
    int bread = 500, snack = 700, coke = 400;
    
    int breadInx, snackInx, cokeInx;

    for (breadInx = 1; breadInx <= 9; breadInx++)
    {
        for (snackInx = 1; snackInx <= 9; snackInx++)
        {
            for (cokeInx = 1; cokeInx <= 9; cokeInx++)
            {
                if (bread * breadInx + snack * snackInx + coke * cokeInx == money)
                {
                    printf("크림빵 %d개, 새우깡 %d개, 콜 라 %d개 \n", breadInx, snackInx, cokeInx);
                }
            }
        }
    }
    printf("어떻게 구입하시겠습니까? \n");
    return 0;
}
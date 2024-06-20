#include <stdio.h>

int main(void)
{  
    double d1 = 1.23e-3;
    double d2 = 1.23e-6;
    
    printf("%f \n", 0.1234);        // 0.123400 
    printf("%e \n", 0.1234);        // 1.234000e-01 
    printf("%f \n", 0.12345678);    // 0.123457 
    printf("%e \n", 0.12345678);    // 1.234568e-01 

    printf("%g \n", d1);            // 0.00123 
    printf("%g \n", d2);            // 1.23e-06 

    return 0;
}
#include <stdio.h>

void ComplexFuncOne(int** ptr1, int* (*ptr2)[5]);
void ComplexFuncTwo(int*** ptr3, int*** (*ptr4)[5]);

int main(void)
{
    int* arr1[3];           // int* 형으로 이루어진 1차원 배열
    int* arr2[3][5];        // int* 형으로 이루어진 2차원 배열
    int** arr3[5];          // int** 형으로 이루어진 1차원 배열
    int*** arr4[3][5];      // int*** 형으로 이루어진 2차원 배열

    ComplexFuncOne(arr1, arr2);
    ComplexFuncTwo(arr3, arr4);
}
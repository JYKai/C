#include <stdio.h>

int arr[100][100];
    int count = 1;

void Snail(int n);

void Left_to_Right(int row, int min, int max)
{
    for(int i=min;i<max;i++){
        arr[row][i] = count;
        count++;
    }
}

void Right_to_Left(int row, int max, int min)
{
    for(int i=max-2;i>=min;i--){
        arr[row][i] = count;
        count++;
    }
}

void Top_to_Bottom(int col, int min, int max)
{
    for(int i=min+1;i<max;i++){
        arr[i][col] = count;
        count++;
    }
}

void Bottom_to_Top(int col,int max, int min)
{
    for(int i=max-2;i>=min+1;i--){
        arr[i][col] = count;
        count++;
    }
}

int main(void)
{
    int n;
    
    printf("숫자를 입력하세요 : ");
    scanf("%d",&n);

    Snail(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void Snail(int n)
{
    int min = 0;
    int max = n;

    for(int i = 0; i < n/2; i++){
        Left_to_Right(i,min,max);
        Top_to_Bottom(n-1-i,min,max);
        Right_to_Left(n-1-i,max,min);
        Bottom_to_Top(i,max,min);
        min++;
        max--;
    }

    if(n%2==1){
        arr[n/2][n/2] = count;
    }
}
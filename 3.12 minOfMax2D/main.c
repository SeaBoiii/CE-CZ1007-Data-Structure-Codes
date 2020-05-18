#include <stdio.h>
#define SIZE 10
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize)
{
    int max, minMax = 9999999;
    for (int row=0; row<rowSize; row++) {
        max = ar[row][0];
        for (int col=0; col<colSize; col++) {
            if (max < ar[row][col])
                max = ar[row][col];
        }
        //printf("max: %d\n", max);
        if (minMax > max)
            minMax = max;
    }
    /*if (minMax > max)
        minMax = max;*/
    return minMax;
}
int main()
{
    int ar[SIZE][SIZE], rowSize, colSize;
    int i,j,min;

    printf("Enter row size of the 2D array: \n");
    scanf("%d", &rowSize);
    printf("Enter column size of the 2D array: \n");
    scanf("%d", &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
            scanf("%d", &ar[i][j]);
    min = minOfMax2D(ar, rowSize, colSize);
    printf("minOfMax2D(): %d\n", min);
    return 0;
}

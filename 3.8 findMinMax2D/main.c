#include <stdio.h>
#define SIZE 5
void findMinMax2D(int ar[SIZE][SIZE], int *min, int *max)
{
    *min = *max = ar[0][0];
    for (int row=0; row<5; row++) {
        for (int col=0; col<5; col++) {
            if (*max <= ar[row][col])
                *max = ar[row][col];
            if (*min >= ar[row][col])
                *min = ar[row][col];
        }
    }
}
int main()
{
    int A[5][5];
    int i,j,min,max;

    printf("Enter the matrix data (%dx%d): \n", SIZE, SIZE);
    for (i=0; i<5; i++){
        for (j=0; j<5; j++)
            scanf("%d", &A[i][j]);
    }
    findMinMax2D(A, &min, &max);
    printf("min = %d\nmax = %d", min, max);
    return 0;
}

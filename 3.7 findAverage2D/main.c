#include <stdio.h>
#include <stdlib.h>
void findAverage2D(float matrix[4][4])
{
    float sum = 0, avg;
    int row, col;
    for (row=0; row<4; row++) {
        for (col=0; col<3; col++) {
            sum += matrix[row][col];
        }
        avg = (float)sum/3;
        matrix[row][col] = avg;
        sum = 0;
    }
}
int main()
{
    float ar[4][4];
    int i,j;

    printf("Enter data: \n");
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++)
            scanf("%f", &ar[i][j]);
    }
    findAverage2D(ar);
    printf("findAverage2D: :\n");
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++)
            printf("%.2f ", ar[i][j]);
        printf("\n");
    }
    return 0;
}

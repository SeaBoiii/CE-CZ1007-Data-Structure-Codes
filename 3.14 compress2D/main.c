#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
    /*
    int count = 0, temp;
    for (int row=0; row<rowSize; row++) {
        temp = data[row][0];
        for (int col=0; col<colSize; col++) {
            if (data[row][col] != temp) {
                printf("%d %d ", temp, count);
                temp = data[row][col];
                count = 1;
            }
            else {
                count++;
            }
        }
        printf("%d %d\n", temp, count);
        count = 0;
    } */

    int count=0, temp;
    for (int row=0; row<rowSize; row++) {
        temp = data[row][0];
        for (int col=0; col<colSize; col++) {
            if (data[row][col] == temp) {
                count++;
            }
            else {
                printf("%d %d ", temp, count);
                temp = data[row][col];
                count = 1;
            }
        }
        printf("%d %d\n", temp, count);
        count=0;
    }
}
int main()
{
    int data[SIZE][SIZE];
    int i,j;
    int rowSize, colSize;

    printf("Enter the array size (rowSize, colSize): \n");
    scanf("%d %d", &rowSize, &colSize);
    printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
    for (i=0; i<rowSize; i++)
        for (j=0; j<colSize; j++)
            scanf("%d", &data[i][j]);
    printf("compress2D(): \n");
    compress2D(data, rowSize, colSize);
    return 0;
}

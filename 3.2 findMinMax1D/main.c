#include <stdio.h>
#include <stdlib.h>
void findMinMax1D(int ar[], int size, int *min, int *max)
{
    *max = ar[0]; *min = ar[0];
    for (int i=0; i<size; i++) {
        if (*max <= ar[i])
            *max = ar[i];
        if (*min >= ar[i])
            *min = ar[i];
    }
}
int main()
{
    int ar[40];
    int i, size;
    int min, max;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d", &ar[i]);
    findMinMax1D(ar, size, &min, &max);
    printf("min = %d; max = %d\n", min, max);
    return 0;
}

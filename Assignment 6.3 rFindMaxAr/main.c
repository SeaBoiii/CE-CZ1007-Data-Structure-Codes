#include <stdio.h>
#include <stdlib.h>
void rFindMaxAr(int *ar, int size, int *max);

int main()
{
    int ar[50],i,max,size;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d numbers: \n", size);
    for (i=0; i<size; i++)
        scanf("%d", &ar[i]);
    max=ar[0];
    rFindMaxAr(ar, size, &max);
    printf("rFindMaxAr(): %d\n", max);
    return 0;
}

void rFindMaxAr(int *ar, int size, int *max)
{
    if (size == 1)
        *max = *ar;
    else {
        if (ar[size-1] > *max){
            rFindMaxAr(&ar[0], size-1, max);
            *max = ar[size-1];
        }
        else
            rFindMaxAr(&ar[0], size-1, max);
    }
}

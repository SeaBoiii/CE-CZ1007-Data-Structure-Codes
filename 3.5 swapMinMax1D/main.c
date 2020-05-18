#include <stdio.h>
#include <stdlib.h>
void swapMinMax1D(int ar[], int size)
{
    int min, max, temp, maxid, minid;
    max = ar[0]; min = ar[0];
    for (int i=0; i<size; i++)
    {
        if (max <= ar[i]) {
            max = ar[i];
            maxid = i;
            //printf("maxid: %d\n", maxid);
        }
    }
    for (int i=0; i<size; i++)
    {
        if (min >= ar[i]) {
            min = ar[i];
            minid = i;
            //printf("minid: %d\n", minid);
        }
    }
    temp = ar[maxid];
    ar[maxid] = ar[minid];
    ar[minid] = temp;
}
int main()
{
    int ar[50],i,size;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d", ar+i);
    swapMinMax1D(ar, size);
    printf("swapMinMax1D(): ");
    for (i=0; i<size; i++)
        printf("%d ", *(ar+i));
    return 0;
}

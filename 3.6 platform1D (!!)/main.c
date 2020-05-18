#include <stdio.h>
#include <stdlib.h>
int platform1D(int ar[], int size)
{
    int count = 1, temp = ar[0], max = 1;
    for (int i=1; i<size; i++)
    {
        if (ar[i] == temp)
            count++;
        else {
            if (count > max)
                max = count;
            count = 1;
            temp = ar[i];
        }
    }
    if (count > max)
        max = count;
    return max;
}
int main()
{
    int i,b[50],size;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i<size; i++)
        scanf("%d", &b[i]);
    printf("platform1D(): %d\n", platform1D(b,size));
    return 0;
}

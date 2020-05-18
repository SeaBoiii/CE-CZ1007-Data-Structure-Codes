#include <stdio.h>
int rLookupAr(int array[], int size, int target)
{
    if (size == -1)
        return -1;
    if (array[size] == target)
        return size;
    else
        return rLookupAr(array, size-1, target);
}

int main()
{
    int numArray[80];
    int target, i, size;
    int result = -999;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter id numbers: \n");
    for (i=0; i<size; i++)
        scanf("%d", &numArray[i]);
    printf("Enter the target number: \n");
    scanf("%d", &target);
    result = rLookupAr(numArray, size, target);
    printf("rLookupAr(): %d", result);
    return 0;
}

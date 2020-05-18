#include <stdio.h>
#include <stdlib.h>
void printReverse1 (int ar[], int size);
void printReverse2 (int ar[], int size);
void reverseAr1D (int ar[], int size);

int main()
{
    int ar[10];
    int size, i;

    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i <= size-1; i++)
        scanf("%d", &ar[i]);
    printReverse1(ar, size);
    printReverse2(ar, size);
    reverseAr1D(ar, size);
    printf("reverseAr1D(): ");
    if (size > 0) {
        for (i=0; i<size; i++)
            printf("%d ", ar[i]);
    }
    return 0;
}

void printReverse1(int ar[], int size)
{
    int j;
    printf("printReverse1(): ");
    if (size > 0){
        for (j = size-1; j >= 0; j--)
            printf("%d ", ar[j]);
    }
    printf("\n");
}

void printReverse2(int ar[], int size)
{
    int j;
    printf("printReverse2(): ");
    if (size > 0){
        for (j = size-1; j >= 0; j--)
            printf("%d ", *(ar+j));
    }
    printf("\n");
}

void reverseAr1D(int ar[], int size)
{
    int j, k;
    int last = size - 1;

    if (size > 0){
        for (j=0; j < size/2; j++){
        k = ar[j];
        ar[j] = ar[last];
        ar[last] = k;

        last--;
        }
    }
}

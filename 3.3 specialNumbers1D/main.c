#include <stdio.h>
#include <stdlib.h>
void specialNumbers1D(int ar[], int num, int *size)
{
    if (num < 100 || num > 999) {
        printf("Invalid!\n");
        return;
    }
    int i, special=0;
    for (i=100; i<num; i++){
        special = ((i%10)*(i%10)*(i%10)) + ((i/10%10)*(i/10%10)*(i/10%10)) + ((i/100%10)*(i/100%10)*(i/100%10));
        if (special == i) {
            ar[*size] = special;
            //printf("special: %d\n", special);
            (*size)++;
        }
        special = 0;
    }
}
int main()
{
    int a[20],i,size=0,num;

    printf("Enter a number (between 100 and 999): \n");
    scanf("%d", &num);
    specialNumbers1D(a, num, &size);
    printf("specialNumbers1D(): ");
    for (i=0; i<size; i++)
        printf("%d ", a[i]);
    return 0;
}

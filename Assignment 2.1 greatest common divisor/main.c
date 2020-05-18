#include <stdio.h>
#include <stdlib.h>
int gcd1(int num1, int num2);
void gcd2(int num1, int num2, int *result);

int main()
{
    int x, y, result = -1;

    printf("Enter the 2 numbers: \n");
    scanf("%d %d", &x, &y);
    printf("gcd1(): %d\n", gcd1(x, y));
    gcd2(x, y, &result);
    printf("gdc2(): %d\n", result);
    return 0;
}

int gcd1(int num1, int num2)
{
    while (num1 != num2){
        if (num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }
    return num1;
}

void gcd2(int num1, int num2, int *result)
{
    while (num1 != num2){
        if (num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }
    *result = num1;
}

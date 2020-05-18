#include <stdio.h>
#include <stdlib.h>
void rReverseDigits(int num, int *result);

int main()
{
    int result=0, number;

    printf("Enter a number: \n");
    scanf("%d", &number);
    rReverseDigits(number, &result);
    printf("rReverseDigits(): %d\n", result);
    return 0;
}

void rReverseDigits(int num, int *result)
{
    int pow = 1;
    while (num / (pow*10))
        pow *= 10;
    if (num < 10)
        *result = num;
    else {
        rReverseDigits(num/10, result);
        *result += (num%10)*pow;
    }
}

#include <stdio.h>
int rAllOddDigits1(int num)
{
    if (num< 10) {
        if (num%10%2 == 0)
            return 0;
        return 1;
    }
    else
        if (num%10%2 == 0)
            return 0;
        return rAllOddDigits1(num/10);
}

void rAllOddDigits2(int num, int *result)
{
    if (num < 10) {
        if (num%10%2 == 0)
            *result = 0;
        else
            *result = 1;
    }
    else
    {
        rAllOddDigits2(num/10, &result);
    }
}
int main()
{
    int number, result = -1;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("rAllOddDigits1(): %d\n", rAllOddDigits1(number));
    rAllOddDigits2(number, &result);
    printf("rAllOddDigits2(): %d\n", result);
    return 0;
}

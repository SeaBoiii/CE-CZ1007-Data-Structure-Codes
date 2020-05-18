#include <stdio.h>
#include <stdlib.h>
int countOddDigits1(int num)
{
    int result = 0;
    do {
        for (int odd=1; odd<10; odd+=2) {
            if (num%10 == odd) {
                result++;
                break;
            }
        }
        num = num/10;
    } while (num != 0);
    return result;
}
void countOddDigits2(int num, int *result)
{
    *result = 0;
    do {
        for (int odd=1; odd<10; odd+=2) {
            if (num%10 == odd) {
                (*result)++;
                break;
            }
        }
        num = num/10;
    } while (num != 0);
}
int main()
{
    int number, result = -1;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("countOddDigits1(): %d\n", countOddDigits1(number));
    countOddDigits2(number, &result);
    printf("countOddDigits2(): %d\n", result);
    return 0;
}

#include <stdio.h>
#define INIT_VALUE 999
int extOddDigits1(int num)
{
    int count=1, newNum=0, result=0;
    do {
        newNum = 0;
        for (int odd=1;odd<10;odd+=2) {
            if (num%10 == odd) {
                newNum = odd;
                break;
            }
        }
        if (newNum > 0){
            result = result + newNum*count;
            count *= 10;
        }
        num = num/10;
    } while (num != 0);
    if (result == 0)
        result = -1;
    return result;
}
void extOddDigits2(int num, int *result)
{
    int count=1, newNum=0;
    *result = 0;
    do {
        newNum = 0;
        for (int odd=1;odd<10;odd+=2) {
            if (num%10 == odd) {
                newNum = odd;
                break;
            }
        }
        if (newNum > 0) {
            *result = (*result) + newNum*count;
            count *= 10;
        }
        num = num/10;
    } while (num != 0);
    if (*result == 0)
        *result = -1;
}
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extOddDigits1(): %d\n", extOddDigits1(number));
    extOddDigits2(number, &result);
    printf("extOddDigits2(): %d\n", result);
    return 0;
}

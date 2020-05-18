#include <stdio.h>
#include <stdlib.h>
int allOddDigits1(int num)
{
    do {
        for (int even=0; even<10; even+=2){
            if (num%10 == even) {
                return 0;
            }
        }
        num = num/10;
    } while (num != 0);
    return 1;
}
void allOddDigits2(int num, int *result)
{
    *result = 1;
    do {
        for (int even=0; even<10; even+=2){
            if (num%10 == even) {
                *result = 0;
                return;
            }
        }
        num = num/10;
    } while (num != 0);
}
int main()
{
    int number, p=999, result=999;

    printf("Enter a number: \n");
    scanf("%d", &number);
    p = allOddDigits1(number);
    if (p == 1)
        printf("allOddDigits1(): yes\n");
    else
        printf("allOddDigits1(): no\n");
    allOddDigits2(number, &result);
    if (result == 1)
        printf("allOddDigits2(): yes\n");
    else
        printf("allOddDigits2(): no\n");
    return 0;
}

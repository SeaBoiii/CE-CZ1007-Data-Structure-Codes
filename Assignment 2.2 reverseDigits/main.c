#include <stdio.h>
#include <stdlib.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);

int main()
{
    int num, result=999;

    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits1(): %d\n", reverseDigits1(num));
    reverseDigits2(num, &result);
    printf("reverseDigits2(): %d\n", result);
    return 0;
}

int reverseDigits1(int num)
{
    int lastDigit, reverseD = 0;
    while (num > 0){
        lastDigit = num%10;
        reverseD = (reverseD*10) + lastDigit;
        num = num/10;
    }
    return reverseD;
}

void reverseDigits2(int num, int *result)
{
    int lastDigit, reverseD = 0;
    while (num > 0){
        lastDigit = num%10;
        reverseD = (reverseD*10) + lastDigit;
        num = num/10;
    }
    *result = reverseD;
}

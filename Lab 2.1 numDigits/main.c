#include <stdio.h>
#include <stdlib.h>
int numDigits1(int num);
void numDigits2(int num, int *result);

int main()
{
    int number, result = 0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("numDigits1(): %d\n", numDigits1(number));
    numDigits2(number, &result);
    printf("numDigits2(): %d\n", result);
    return 0;
}

int numDigits1(int num) //Call by value
{
    int count = 0;
    do { //Whats the difference using Do or Do-While
            // if use while loop first, when input "o", count will be 0
        count++;
        num = num/10;
    } while (num>0);
    return count;
}

void numDigits2(int num, int *results) //Call by reference
{
    *results= 0;
    do {
        (*results)++;
        num = num/10;
    } while (num>0);
}

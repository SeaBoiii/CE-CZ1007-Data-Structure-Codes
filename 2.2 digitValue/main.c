#include <stdio.h>
#include <stdlib.h>
int digitValue1(int num, int k)
{
    int count = 1;
    do {
        if (count == k)
            return num%10;
        else {
            num = num/10;
            count ++;
        }
    } while (num%10 != 0);
    return 0;
}
void digitValue2(int num, int k, int *result)
{
    int count = 1;
    *result = 0;
    do {
        if (count == k) {
            *result = num%10;
            break;
        }
        else {
            num = num/10;
            count++;
        }
    } while (num%10 != 0);
}
int main()
{
    int num, digit, result=-1;

    printf("Enter the number: \n");
    scanf("%d", &num);
    printf("Enter k position: \n");
    scanf("%d", &digit);
    printf("digitValue1(): %d\n", digitValue1(num, digit));
    digitValue2(num, digit, &result);
    printf("digitValue2(): %d\n", result);
    return 0;
}

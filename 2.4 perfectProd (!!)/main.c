#include <stdio.h>
#include <stdlib.h>
int perfectProd1(int num)
{
    int i=0, perfectsum=0, total=1, factors=1;
    for(i=1; i<num; i++)
    {
        while (factors < i)
        {
            if(i%factors == 0)
            {
                perfectsum += factors;
            }
            factors++;
        }
        if (perfectsum == i)
        {
            total *= i;
        }
        perfectsum = 0;
        factors = 1;
    }
    return total;
}
void perfectProd2(int num, int *prod)
{
    int i=0, perfectsum=0, factors=1;
    *prod = 1;
    for(i=1; i<num; i++)
    {
        while (factors < i)
        {
            if(i%factors == 0)
            {
                perfectsum += factors;
            }
            factors++;
        }
        if (perfectsum == i)
        {
            (*prod) *= i;
        }
        perfectsum = 0;
        factors = 1;
    }
}
int main()
{
    int number, result = 0;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("perfectProd1(): %d\n", perfectProd1(number));
    perfectProd2(number, &result);
    printf("perfectProd2(): %d\n", result);
    return 0;
}

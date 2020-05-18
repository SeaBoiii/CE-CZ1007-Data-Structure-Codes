#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hours;
    float tax, grossPay, netPay;

    printf("Enter hours of work: \n");
    scanf("%d", &hours);


    if (hours > 40)
        grossPay = (float)9*(hours-40) + (40 * 6);
    else
        grossPay = (float)6*hours;
    if (grossPay < 1000)
        tax = ((float)10/100) * grossPay;
    else if (grossPay >= 1000 && grossPay < 1500)
        tax = (float)100 + (20/100 * (grossPay - 1000));
    else
        tax = (float)100 + 100 + (30/100 * (grossPay - 1500));
    netPay = grossPay - tax;
    printf("Gross pay = %.2f\n", grossPay);
    printf("Tax = %.2f\n", tax);
    printf("Net pay = %.2f\n", netPay);
    return 0;
}

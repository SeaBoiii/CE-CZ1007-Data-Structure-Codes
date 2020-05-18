#include <stdio.h>
#include <stdlib.h>

int main()
{
    int list, coe = 0, cat;
    double discounted, luxury = 0, gst, total;

    printf("Please enter the list price: \n");
    scanf("%d", &list);
    printf("Please enter the category: \n");
    scanf("%d", &cat);

    discounted = (double)0.9 * list;
    if (discounted >= 100000){
        luxury = (double)0.1 * discounted;
        //printf("luxury: %.2f\n", luxury);
    }
    gst = (double)0.03 * discounted;
    //printf("gst: %.2f\n", gst);

    if (cat == 1)
        coe = 70000;
    if (cat == 2)
        coe = 80000;
    if (cat == 3)
        coe = 23000;
    if (cat == 4)
        coe = 600;
    //printf("coe: %.2d\n", coe);
    total = discounted + luxury + gst + coe;

    printf("Total price is $%.2f\n", total);
    return 0;
}

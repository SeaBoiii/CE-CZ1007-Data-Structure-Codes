#include <stdio.h>
#include <stdlib.h>
#define PI 3.1416
int main()
{
    float r, h, v, a;

    printf("Enter the radius: \n");
    scanf("%f", &r);
    printf("Enter the height: \n");
    scanf("%f", &h);
    v = PI*r*r*h;
    a = 2*PI*r*h + 2*PI*r*r;
    printf("The volume is: %.2f\n", v);
    printf("The surface area is: %.2f\n", a);
}

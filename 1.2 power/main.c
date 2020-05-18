#include <stdio.h>
#include <stdlib.h>

int main()
{
    float p, i, r;

    printf("Enter the current: \n");
    scanf("%f", &i);
    printf("Enter the resistance: \n");
    scanf("%f", &r);
    p = i*i*r;
    printf("The power loss: %.2f \n", p);

    return 0;
}

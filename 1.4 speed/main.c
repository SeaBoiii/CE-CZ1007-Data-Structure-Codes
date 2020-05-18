#include <stdio.h>
#include <stdlib.h>

int main()
{
    float d, s, speed;
    printf("Enter distance (in km): \n");
    scanf("%f", &d);
    printf("Enter time (in sec): \n");
    scanf("%f", &s);
    speed = d/s;
    printf("The speed is %.2f km/sec \n", speed);
    return 0;
}

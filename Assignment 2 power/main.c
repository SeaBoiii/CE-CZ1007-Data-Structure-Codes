#include <stdio.h>
#include <stdlib.h>
float power1(float num, int p);
void power2(float num, int p, float *result);

int main()
{
    int power;
    float number, result = -1;

    printf("Enter the number and power: \n");
    scanf("%f %d", &number, &power);
    printf("power1(): %.2f\n", power1(number, power));
    power2(number,power,&result);
    printf("power2(): %.2f\n", result);
    return 0;
}

float power1(float num, int p)
{
    int i;
    float total = num;
    if (p>0){
        for (i=1; i<p; i++){
            total *= num;
        }
    }
    else if (p == 0) {
        total = 1;
    }
    else {
        total = (float)1 / num;
        num = (float)1 / num;
        for (i=-1; i>p; i--){
            total *= (float)num;
        }
    }
    return total;
}

void power2(float num, int p, float *result)
{
    int i;
    float total = num;
    if (p>0){
        for (i=1; i<p; i++){
            total *= num;
        }
    }
    else if (p == 0) {
        total = 1;
    }
    else {
        total = (float)1 / num;
        num = (float)1 / num;
        for (i=-1; i>p; i--){
            total *= (float)num;
        }
    }
    *result = total;
}

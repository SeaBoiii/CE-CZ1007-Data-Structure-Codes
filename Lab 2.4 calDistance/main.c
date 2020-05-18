#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inputXY(double *x1, double *y1, double *x2, double *y2);
void outputResult(double dist);
double calDistance1(double x1, double y1, double x2, double y2);
void calDistance2(double x1, double y1, double x2, double y2, double *dist);

int main()
{
    double x1, y1, x2, y2, distance = -1;

    inputXY(&x1, &y1, &x2, &y2);
    distance = calDistance1(x1, y1, x2, y2);
    printf("calDistance1(): ");
    outputResult(distance);
    calDistance2(x1, y1, x2, y2, &distance);
    printf("calDistance2(): ");
    outputResult(distance);
    return 0;
}

void inputXY(double *x1, double *y1, double *x2, double *y2)
{
    printf("Please input x1 y1 x2 y2: ");
    scanf("%lf %lf %lf %lf", x1, y1, x2, y2);
}

void outputResult(double dist)
{
    printf("%.2f \n", dist);
}

double calDistance1(double x1, double y1, double x2, double y2)
{
    x1 = x1-x2;     x1 = x1*x1;
    y1 = y1-y2;     y1 = y1*y1;
    return (sqrt(x1+y1));
}

void calDistance2(double x1, double y1, double x2, double y2, double *dist)
{
    x1 = x1-x2;     x1 = x1*x1;
    y1 = y1-y2;     y1 = y1*y1;
    *dist = (sqrt(x1+y1));
}

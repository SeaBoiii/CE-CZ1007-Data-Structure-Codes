#include <stdio.h>
#include <stdlib.h>
int divide1(int m, int n, int *r)
{
    int count = 0;
    if (n==0) {
        printf("Denominator cannot be 0!\n");
        return 0;
    }
    while (m >= n) {
        m -= n;
        count++;
    }
    *r = m;
    return count;
}
void divide2(int m, int n, int *q, int *r)
{
    *q = 0;
    if (n==0) {
        printf("Denominator cannot be 0!\n");
        return;
    }
    while (m >= n) {
        m -= n;
        (*q)++;
    }
    *r = m;
}
int main()
{
    int m, n, q, r;

    printf("Enter two numbers (m and n): \n");
    scanf("%d %d", &m, &n);
    q = divide1(m, n, &r);
    printf("divide1(): quotient %d remainder %d\n", q, r);
    divide2(m, n, &q, &r);
    printf("divide2(): quotient %d remainder %d\n", q, r);
    return 0;
}

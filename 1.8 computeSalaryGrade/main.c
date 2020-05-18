#include <stdio.h>
#include <stdlib.h>

int main()
{
    int salary, merit;
    char grade = 'C';

    printf("Enter the salary: \n");
    scanf("%d", &salary);
    printf("Enter the merit: \n");
    scanf("%d", &merit);
    if (salary >= 700 && merit >= 20)
        grade = 'A';
    else if (salary >= 600 && merit >= 10)
        grade = 'B';

    printf("The grade: %c", grade);
    return 0;
}

#include <stdio.h>
#include <string.h>
struct student{
   char name[20]; /* student name */
   double testScore; /* test score */
   double examScore; /* exam score */
   double total;  /* total = (testScore+examScore)/2 */
};
double average();
int main()
{
   printf("average(): %.2f\n", average());
   return 0;
}
double average()
{
    struct student stu[50];
    double sum = 0;
    int i;

    //get student scores
    i=0;
    printf("Enter student name: \n");
    gets(stu[i].name);
    while (strcmp(stu[i].name, "END")!= 0) {
        printf("Enter test score: \n");
        scanf("%lf", &stu[i].testScore);
        printf("Enter exam score: \n");
        scanf("%lf", &stu[i].examScore);

        //computes the total
        stu[i].total = (stu[i].testScore + stu[i].examScore)/2;
        printf("Student %s total = %.2f\n", stu[i].name, stu[i].total);
        sum += stu[i].total;
        i++;
        printf("Enter student name: \n");
        scanf("\n"); //clear buffer
        gets(stu[i].name);
    }
    if (i != 0)
        return (sum/i);
    else
        return 0;
}

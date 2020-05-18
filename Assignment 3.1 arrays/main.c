#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void initialize(int *size, int ar[]);
void insert(int max, int *size, int ar[], int num);
void iremove(int *size, int ar[], int num);
void display(int size, int ar[]);

int main()
{
    int option = 0;
    int num, ar[MAX], size = 0;

    printf("Please select an option: \n");
    printf("(1) Initialize the array \n");
    printf("(2) Insert an integer \n");
    printf("(3) Remove an integer \n");
    printf("(4) Display the numbers stored in the array \n");
    printf("(5) Quit \n");

    do {
        printf("Enter your choice: \n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                initialize(&size, ar);
                break;
            case 2:
                printf("Enter an integer: \n");
                scanf("%d", &num);
                insert(MAX, &size, ar, num);
                break;
            case 3:
                printf("Enter the integer to be removed: \n");
                scanf("%d", &num);
                iremove(&size, ar, num);
                break;
            case 4:
                display(size, ar);
                break;
            default:
                break;
        }
    } while (option < 5);
    return 0;
}

void display(int size, int ar[])
{
    int i;

    printf("The %d numbers in the array: \n", size);
    for (i=0; i<size; i++)
        printf("%d ", ar[i]);
    printf("\n");
}

void initialize(int *size, int ar[])
{
    int num, k, tempsize, count = 0;
    do {
        printf("Enter the total number of integers (MAX=10): \n");
        scanf("%d", &tempsize);//pointer size
        if (tempsize > 10)
            printf("Didn't I tell you that MAX = 10? Don't know how to read? \n");
        else
            count++;
    } while (count != 1);
    printf("Enter the integers: \n");
    for (k=0; k<tempsize; k++) //insertion of number
    {
        scanf("%d", &num);
        insert(MAX, size, ar, num);
    }
}

void insert(int max, int *size, int ar[], int num)
{
    int k;
    int i, j, temp;
    (*size)++;
    //printf("Current num: %d \n", num);
    if ((*size) > max) {
        printf("The array is full\n");
        (*size)--;
    }
    else if ((*size)==1){
        ar[0] = num;
        //printf("Current num in ar[0]: %d \n", ar[0]);
    }

    else { //insertion
        for (k=(*size)-1; k>=0; k--) {
            ar[k+1] = ar[k];
        }
        ar[0] = num;
    }
    /* //debugging
    printf("Current size: %d \n", *size);
    for (int c=0; c<*size; c++)
        printf("%d ", ar[c]); */

    for (i=0; i<*size; i++) //ascending sort
    {
        for (j=i+1; j<*size; j++)
        {
            if (ar[j] < ar[i])
            {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
}

void iremove(int *size, int ar[], int num)
{
    int i, c;
    int pos = -1;

    if ((*size) == 0) {
        printf("The array is empty\n");
    }
    else {
        for (i=0; i<*size; i++) {
            if (ar[i] == num){
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            for (c=pos;c<(*size)-1;c++)
                ar[c] = ar[c+1];
            (*size)--;
            printf("The integer is removed\n");
        }
        else
            printf("The number is not in the array\n");
    }
}

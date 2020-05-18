#include <stdio.h>
typedef struct {
    char name[20];
    int age;
} Person;

void readData(Person *p)
{
    int i;
    for (i=0; i<3; i++) {
        printf("Enter person %d:\n", i+1);
        scanf("\n");
        scanf("%s %d", p[i].name, &p[i].age);
    }
}

Person findMiddleAge(Person *p)
{
    int pos = 0;
    int max = p[0].age;
    for (int i=0; i<3; i++)
    {
        if(p[i].age > max)
            max = p[i].age;
        else if(p[i].age < max)
            pos = i;
    }
    return p[pos];
}

int main()
{
    Person man[3], middle;
    readData(man);
    middle = findMiddleAge(man);
    printf("findMiddleAge(): %s %d", middle.name, middle.age);
    return 0;
}

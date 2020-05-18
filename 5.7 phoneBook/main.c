#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
    char name[20];
    char telno[20];
} PhoneBk;

int readin(PhoneBk *p)
{
    int size = 0;

    do {
        printf("Enter name: \n");
        scanf("\n");
        gets(p[size].name);
        if (*(p[size].name) == '#')
            break;
        printf("Enter tel: \n");
        scanf("\n");
        gets(p[size].telno);
        size++;
    } while (size != 0);
    return size;
}

void search(PhoneBk *p, int size, char *target)
{
    int found = 0;
    for (int i=0; i<size; i++) {
        if (strcmp(p[i].name, target) == 0)
        {
            printf("Name = %s, Tel = %s", p[i].name, p[i].telno);
            found = 1;
        }
    }
    if (found == 0)
        printf("Name not found!");
}
int main()
{
    PhoneBk s[MAX];
    char t[20];
    int size;

    size = readin(s);
    printf("Enter search name: \n");
    gets(t);
    search(s,size,t);
    return 0;
}

#include <stdio.h>
int compareStr(char *s, char *t)
{
    while (*s != '\0' || *t != '\0')
    {
        if (*s > *t || *t > *s)
            return (*s - *t);
        /*if (*s == '\0') //not necessary...
            return -(*t);
        if (*t == '\0')
            return *s;*/
        t++; s++;
    }
    return 0;
}
int main()
{
    char a[80],b[80];

    printf("Enter the first string: \n");
    gets(a);
    printf("Enter the second string: \n");
    gets(b);
    printf("compareStr(): %d\n", compareStr(a,b));
    return 0;
}

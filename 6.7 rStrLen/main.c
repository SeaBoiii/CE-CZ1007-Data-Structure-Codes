#include <stdio.h>
int rStrLen(char *s)
{
    if (*s == '\0')
        return 0;
    else
        return 1 + rStrLen(++s);
}

int main()
{
    char str[80];

    printf("Enter the string: \n");
    gets(str);
    printf("rStrLen(): %d\n", rStrLen(str));
    return 0;
}

#include <stdio.h>
int longWordLength(char *s)
{
    int count = 0, countMax = 0;
    while (*s != '\0')
    {
        if (*s == ' ' || *s == '.' || *s == '!' || *s == '?')
        {
            //count--; //Minus off the space, dot or exclamation mark etc.
            if (countMax < count) {
                countMax = count;
            }
            count = 0;
        }
        if ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))
            count++;
        s++;
    }
    if (countMax < count)
        countMax = count;
    return countMax;
}
int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    printf("longWordLength(): %d\n", longWordLength(str));
    return 0;
}

#include <stdio.h>
int countWords(char *s)
{
    int count = 0;
    while (*s != '\0')
    {
        if (*s == ' ')
            count++;
        s++;
    }
    count++;
    return count;
}
int main()
{
    char str[50];

    printf("Enter the string: \n");
    gets(str);
    printf("countWords(): %d", countWords(str));
    return 0;
}

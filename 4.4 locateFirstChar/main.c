#include <stdio.h>
int locateFirstChar(char *str, char ch)
{
    int count = 1;
    while (*str != '\0') {
        if (*str == ch)
        {
            return count;
        }
        if (*str == ' ')
        {
            str++;
            continue;
        }
        str++; count++;
    }
    return -1;
}
int main()
{
    char str[40], ch;

    printf("Enter a string: \n");
    gets(str);
    printf("Enter the target character: \n");
    scanf("%c", &ch);
    printf("locateFirstChar(): %d\n", locateFirstChar(str, ch));
    return 0;
}

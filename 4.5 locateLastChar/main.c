#include <stdio.h>
int locateLastChar(char *str, char ch)
{
    //count
    /*int count = 1, charCount = 0;
    int spaceCount = 0;
    while (*str != '\0')
    {
        if (*str == ' ')
            spaceCount++;
        str++;
        charCount++;
    }
    int total = charCount - spaceCount;
    str--;
    //printf("str: %s\n", str);
    //printf("total: %d\n", total);
    while (charCount != 0)
    {
        if (*str == ch)
        {
            //printf("count: %d\n", (count-1));
            return (total-(count-1));
        }
        if (*str == ' ')
        {
            str--;
            charCount--;
            continue;
        }
        str--; count++; charCount--;
    }
    return -1;*/
    int max = -1;
    for (int i=0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
        {
            if (max < i)
                max = i;
        }
    }
    return max;
}
int main()
{
    char str[40], ch;

    printf("Enter a string: \n");
    gets(str);
    printf("Enter the target character: \n");
    scanf("%c", &ch);
    printf("locateLastChar(): %d\n", locateLastChar(str,ch));
    return 0;
}

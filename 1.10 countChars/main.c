#include <stdio.h>
#include <string.h>
void reverseStr(char *str)
{
    int strLen = strlen(str);
    char temp[80];
    strcpy(temp, str);
    for (int i=strLen-1; i>=0; i--)
    {
        *str = temp[i];
        str++;
    }
    str[strLen] = '\0';
}
int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    reverseStr(str);
    printf("reverseStr(): %s\n", str);
    return 0;
}

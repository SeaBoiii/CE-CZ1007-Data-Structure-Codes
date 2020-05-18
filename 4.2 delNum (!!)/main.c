#include <stdio.h>
#include <stdlib.h>
void delNum(char *str)
{
    char *src = str;

    while (*src != '\0') {
        if (*src <= '9' && *src >= '0') {
            src++;
            continue;
        }
        //printf("src: %s\n", src);
        *str = *src;
        str++; src++;
    }
    *str = '\0';
}
int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    delNum(str);
    printf("delNum(): %s", str);
    return 0;
}

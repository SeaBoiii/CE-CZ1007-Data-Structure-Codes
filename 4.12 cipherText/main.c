#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cipher(char *s)
{
    while (*s != '\0')
    {
        if (!isdigit(*s) && *s != ' ') {
            if (*s == 'z')
                *s = 'a';
            else if (*s == 'Z')
                *s = 'A';
            else
                *s = *s + 1;
        }
        s++;
    }
}
void decipher(char *s)
{
    while (*s != '\0')
    {
        if (!isdigit(*s) && *s != ' ') {
            if (*s == 'a')
                *s = 'z';
            else if (*s == 'A')
                *s = 'Z';
            else
                *s = *s - 1;
        }
        s++;
    }
}
int main()
{
    char str[80];

    printf("Enter the string: \n");
    gets(str);
    printf("To cipher: %s -> ", str);
    cipher(str);
    printf("%s\n", str);
    printf("To decipher: %s -> ", str);
    decipher(str);
    printf("%s\n", str);
    return 0;
}

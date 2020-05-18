#include <stdio.h>
void maxCharToFront(char *str)
{
    /*
    char *src = str;
    char maxL = *str;
    int pos = 0, maxPos = 0;

    while (*src != '\0')
    {
        if (maxL < *src) {
            maxL = *src;
            maxPos = pos;
        }
        pos++;
        src++;
    }
    for (int i=maxPos; i>0; i--) {
        str[i] = str[i-1];
    }
    str[0] = maxL; */

    char maxL = str[0];
    int maxPos = 0, count = 0;

    for (int k=0; str[k] != '\0'; k++)
    {
        if (maxL < str[k]) {
            maxL = str[k];
            maxPos = k;
        }
    }
    for (int i=maxPos; i>0; i--)
        str[i] = str[i-1];
    str[0] = maxL;
}
int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    printf("maxCharToFront(): ");
    maxCharToFront(str);
    puts(str);
    return 0;
}

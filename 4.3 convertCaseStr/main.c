#include <stdio.h>
#include <ctype.h>
void convertCaseStr(char *str)
{
    /*char *src = str;

    while (*src != '\0') {
        if (islower(*src)) {
            *src = toupper(*src);
        }
        else if (isupper(*src)) {
            *src = tolower(*src);
        }
        src++;
    } */

    for (int i=0; str[i] != '\0'; i++)
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        else if (isupper(str[i]))
            str[i] = tolower(str[i]);

}
int main()
{
    char str[80];

    printf("Enter a string: \n");
    gets(str);
    convertCaseStr(str);
    printf("convertCaseStr(): %s\n", str);
    return 0;
}

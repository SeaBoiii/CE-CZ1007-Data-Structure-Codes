#include <stdio.h>
#define INIT_VALUE -1
int findSubstring(char *str, char *substr)
{
    int i=0, j=0;

    while(str[i] != '\0' && substr[j] != '\0')
    {
        if(str[i] == substr[j])
            j++;
        else
        {
            j=0;
            if(substr[j] == str[i])
                j++;
        }
        i++;
    }

    if (substr[j] != '\0' || j == 0)
        return 0;
    else
        return 1;
}
int main()
{
    char str[40], substr[40];
    int result = INIT_VALUE;

    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    result = findSubstring(str, substr);
    if (result == 1)
        printf("findSubstring(): Is a substring\n");
    else if (result == 0)
        printf("findSubstring(): Not a substring\n");
    else
        printf("findSubstring(): An error\n");
    return 0;
}

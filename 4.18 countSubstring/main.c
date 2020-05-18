#include <stdio.h>
int countSubstring(char str[], char substr[])
{
    int i=0, j=0, count=0;

    while(str[i] != '\0' && substr[j] != '\0')
    {
        if(str[i] == substr[j])
            j++;
        if(substr[j] == '\0') {
            count++;
            j=0;
        }
        else
        {
            j=0;
            if(substr[j] == str[i]) //continue;
                j++;
        }
        i++;
    }
    return count;
}
int main()
{
    char str[80],substr[80];

    printf("Enter the string: \n");
    gets(str);
    printf("Enter the substring: \n");
    gets(substr);
    printf("countSubstring(): %d\n", countSubstring(str, substr));
    return 0;
}

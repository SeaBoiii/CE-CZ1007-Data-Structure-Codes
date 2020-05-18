#include <stdio.h>
void insertChar(char *str1, char *str2, char ch)
{
    int count = 0;
    while (*str1 != '\0') {
        if (count == 3) {
            *str2 = ch;
            count = 0;
            str2++;
        }
        else {
            *str2 = *str1;
            str1++;
            str2++;
            count++;
        }
    }
    if (count == 3) {
        *str2 = ch;
        str2++;
    }
    *str2 = '\0';
}
int main()
{
    char a[80],b[80];
    char ch;

    printf("Enter a string: \n");
    gets(a);
    printf("Enter a character to be inserted: \n");
    ch = getchar();
    insertChar(a,b,ch);
    printf("insertChar(): ");
    puts(b);
    return 0;
}

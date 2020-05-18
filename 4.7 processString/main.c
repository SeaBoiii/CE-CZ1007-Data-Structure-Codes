#include <stdio.h>
void processString(char *str, int *totVowels, int *totDigits)
{
    char vowels[10] = "aeiouAEIOU";
    *totDigits = *totVowels = 0;

    while (*str != '\0')
    {
        for (int i=0; i<10; i++) {
            if (vowels[i] == *str)
                (*totVowels)++;
        }
        if (*str >= '0' && *str <= '9')
            (*totDigits)++;
        str++;
    }
}
int main()
{
    char str[50];
    int totVowels, totDigits;

    printf("Enter the string: \n");
    gets(str);
    processString(str, &totVowels, &totDigits);
    printf("Total vowels = %d\n", totVowels);
    printf("Total digits = %d\n", totDigits);
    return 0;
}

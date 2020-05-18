#include <stdio.h>
#include <stdlib.h>
char *stringncpy(char *s1, char *s2, int n);
int main()
{
   char sourceStr[40], targetStr[40], *target;
   int length;
   printf("Enter the string: \n");
   gets(sourceStr);
   printf("Enter the number of characters: \n");
   scanf("%d", &length);
   target = stringncpy(targetStr, sourceStr, length);
   printf("stringncpy(): %s\n", target);
   return 0;
}
char *stringncpy(char *s1, char *s2, int n)
{
    int j,k;
    for (j=0; j<n; j++) {
        if (s2[j] != '\0')
            s1[j] = s2[j];
        else
            break;
    }
    s1[j] = '\0';
    for (k=j; k<n; k++) //as per question
        s1[k] = '\0';

    return s1;
}

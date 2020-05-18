#include <stdio.h>
#include <string.h>
char *sweepSpace1(char *sentence);
char *sweepSpace2(char *sentence);
int main()
{
   char str[80];

   printf("Enter the string: \n");
   gets(str);
   printf("sweepSpace1(): %s\n", sweepSpace1(str));
   printf("sweepSpace2(): %s\n", sweepSpace2(str));
   return 0;
}
char *sweepSpace1(char *sentence)
{
   int i, j, len;

   i=0; len=0;
   while (sentence[i]!='\0'){
      len++;
      i++;
   }
   j = 0;
   for (i=0; i < len; i++)
   {
      	if (sentence[i] != ' ')
      	{
            sentence[j] = sentence[i];
            j++;// update the string by removing any space detected
        }
    }
    sentence[j] = '\0'; // add a null character
    return sentence;
}
char *sweepSpace2(char *sentence) //using the string.h library
{
   int i, j, len;

   len = strlen(sentence);
   j = 0;
   for (i=0; i < len; i++)
   {
      	if (*(sentence+i) != ' ')
      	{
            *(sentence+j) = *(sentence+i);
            j++;// update the string by removing any space detected
        }
    }
    *(sentence+j) = '\0'; // add a null character
    return sentence;
}

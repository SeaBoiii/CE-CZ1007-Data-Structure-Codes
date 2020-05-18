#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[80] = "Aleem";
    int i, count = 0;
    while (str[i] != '\0')
    {
        i++;
        count++;
    }
    printf("StrLen: %d\n", count);
    return 0;
}

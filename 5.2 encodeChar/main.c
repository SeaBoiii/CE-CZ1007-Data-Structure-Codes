#include <stdio.h>
typedef struct {
    char source;
    char code;
} Rule;

void encodeChar(Rule *table, char *s, char *t)
{
    /*int i=0;
    while (*s != '\0')
    {
        while (table[i].source != '\0')
        {
            if (table[i].source == *s)
            {
                *t = table[i].code;
                t++; s++;
            }
            i++;
        }
        i=0;
        *t = *s;
        t++; s++;
    }
    *t = '\0'; */

    int i,j;
    i=0; j=0;

    while(s[i] != '\0')
    {
        while (table[j].source != '\0')
        {
            if (table[j].source == s[i])
            {
                t[i] = table[j].code;
                i++;
            }
            j++;
        }
        j=0;
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}

void createTable(Rule *table)
{
    int i, num;
    char dummychar;

    printf("Enter number of rules: \n");
    scanf("%d", &num);
    /*for (i=0; i<num; i++)
    {
        printf("Enter rule %d: \n", i+1);
        scanf("%c", &dummychar);
        printf("Enter source character: ");
        scanf("%c", &table->source);
        scanf("%c", &dummychar);
        printf("Enter code character: ");
        scanf("%c", &table->code);
        table++;
    }
    table->source = '\0';
    table->code = '\0';*/
    for (i=0; i<num; i++)
    {
        printf("Enter rule %d: \n", i+1);
        scanf("%c", &dummychar);
        printf("Enter source character: ");
        scanf("%c", &table[i].source);
        scanf("%c", &dummychar);
        printf("Enter code character: ");
        scanf("%c", &table[i].code);
        //table++;
    }
    table[i].source = '\0';
    table[i].code = '\0';
}

int main()
{
    char s[80],t[80], dummychar, repeat;
    Rule table[100];

    createTable(table);
    do {
        scanf("%c", &dummychar);
        printf("Source string: \n");
        gets(s);
        encodeChar(table, s, t);
        printf("Encoded string: %s\n", t);
        printf("Continue ('y' or 'n'): \n");
        scanf("%c", &repeat);
    } while (repeat == 'y');
    return 0;
}

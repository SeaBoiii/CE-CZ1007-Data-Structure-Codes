#include <stdio.h>
#include <string.h>
void createTable(char lookupTable[26][26]);
void printTable(char lookupTable[26][26]);
void encrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext);
void decrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext);

//Add exception handling for upper or lower

int main()
{
    int choice;
    char keyword[20];
    char table[26][26];
    char plaintext[80], ciphertext[80];

    printf("ENCRYPTION PROGRAM \n");
    printf("1: createTable()\n");
    printf("2: printTable()\n");
    printf("3: enter a new keyword\n");
    printf("4: encrypt() a plaintext message \n");
    printf("5: decrypt() a ciphertext message \n");
    printf("6: quit \n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createTable(table);
                printf("createTable() done \n");
                break;
            case 2:
                printf("printTable(): \n");
                createTable(table);
                printTable(table);
                break;
            case 3:
                printf("Enter a new keyword: \n");
                scanf("%s", keyword);
                strlwr(keyword);
                break;
            case 4:
                printf("Enter a plaintext: \n");
                scanf("%s", plaintext);
                strlwr(plaintext);
                encrypt(table, keyword, plaintext, ciphertext);
                printf("plaintext: %s\n", plaintext);
                printf("ciphertext: %s\n", ciphertext);
                break;
            case 5:
                printf("Enter a ciphertext: \n");
                scanf("%s", ciphertext);
                strupr(ciphertext);
                decrypt(table, keyword, plaintext, ciphertext);
                printf("ciphertext: %s\n", ciphertext);
                printf("plaintext: %s\n", plaintext);
                break;
            default:
                break;
        }
    } while (choice < 6);
    return 0;
}
void printTable(char lookupTable[26][26])
{
    int row, col;
    char c='a';

    printf(" ");printf(" ");
    for (row = 0; row < 26; ++row) {
        printf("%c ",c);
        c = c+1;
    }
    printf("\n");
    c='a';
    for (row = 0; row < 26; ++row) {
        printf("%c ", c);
        c = c+1;
        for (col = 0; col < 26; ++col) {
            printf("%c ", lookupTable[row][col]);
        }
        printf("\n");
    }
}

void createTable(char lookupTable[26][26])
{
    /* int row, col;

    lookupTable[0][0] = ' ';
    lookupTable[1][0] = 'a';
    lookupTable[0][1] = 'a';
    for (row=1; row<26; row++) {
        lookupTable[row][0] = lookupTable[row-1][0] + 1;
    }
    for (col=1; col<26; col++) {
        lookupTable[0][col] = lookupTable[0][col-1] + 1;
    }
    lookupTable[0] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    lookupTable[1] = "BCDEFGHIJKLMNOPQRSTUVWXYZA";
    lookupTable[2] = "CDEFGHIJKLMNOPQRSTUVWXYZAB";
    lookupTable[3] = "DEFGHIJKLMNOPQRSTUVWXYZABC";
    lookupTable[4] = "EFGHIJKLMNOPQRSTUVWXYZABCD";
    lookupTable[5] = "FGHIJKLMNOPQRSTUVWXYZABCDE";
    lookupTable[6] = "GHIJKLMNOPQRSTUVWXYZABCDEF";
    lookupTable[7] = "HIJKLMNOPQRSTUVWXYZABCDEFG";
    lookupTable[8] = "IJKLMNOPQRSTUVWXYZABCDEFGH";
    lookupTable[9] = "JKLMNOPQRSTUVWXYZABCDEFGHI";
    lookupTable[10] = "KLMNOPQRSTUVWXYZABCDEFGHIJ";
    lookupTable[11] = "LMNOPQRSTUVWXYZABCDEFGHIJK"; */

    char alph[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i,j,k;

    for(i=0;i<26;i++) {
        k=0;
        k=i+0;

        for(j=0;j<26;j++) {
            if(k<26) {
                lookupTable[i][j] = alph[k];
            }
            else if (k>=26)
                lookupTable[i][j] = alph[k%26];
            k++;
        }
    }
}

void encrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext)
{
    int i, j;
    int keyLen = strlen(keyword);
    int msgLen = strlen(plaintext);
    int row[msgLen], col[msgLen];
    //debug
    printf("Length of key: %d\n", keyLen);
    printf("Length of msg: %d\n", msgLen);

    char newKey[msgLen];
    char alph[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    //lengthen the key
    for (i=0, j=0; i<msgLen; ++i, ++j) {
        if(j == keyLen)
            j = 0;

        newKey[i] = keyword[j];
    }
    newKey[i] = '\0'; //converts it to a string array
    //printf("newKey: %s \n", newKey); //debug

    for (i=0; i<msgLen; i++) {
        for (j=0; j<26; j++) {
            if (alph[j] == newKey[i])
                row[i] = j;
        }
    }
    for (i=0; i<msgLen; i++) {
        for (j=0; j<26; j++) {
            if (alph[j] == plaintext[i])
                col[i] = j;
        }
    }
    for (i=0; i<msgLen; ++i) {
        *(ciphertext+i) = lookupTable[row[i]][col[i]];
    }
    *(ciphertext+i) = '\0';
}

void decrypt(char lookupTable[26][26], char keyword[20], char *plaintext, char *ciphertext)
{
    int i, j;
    int keyLen = strlen(keyword);
    int msgLen = strlen(ciphertext);
    int row[msgLen], col[msgLen];
    //debug
    //printf("Length of key: %d\n", keyLen);
    //printf("Length of msg: %d\n", msgLen);

    char newKey[msgLen];
    char alph[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    //lengthen the key
    for (i=0, j=0; i<msgLen; ++i, ++j) {
        if(j == keyLen)
            j = 0;

        newKey[i] = keyword[j];
    }
    newKey[i] = '\0'; //converts it to a string array
    //printf("newKey: %s \n", newKey); //debug

    for (i=0; i<msgLen; i++) {
        for (j=0; j<26; j++) {
            if (alph[j] == newKey[i])
                row[i] = j;
        }
    }
    for (i=0; i<msgLen; i++) {
        for (j=0; j<26; j++) {
            if (*(ciphertext+i) == lookupTable[row[i]][j])
                col[i] = j;
        }
    }
    for (i=0; i<msgLen; ++i) {
        *(plaintext+i) = alph[col[i]];
    }
    *(plaintext+i) = '\0';
}

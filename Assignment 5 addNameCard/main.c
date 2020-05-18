#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5
/*Structure*/
typedef struct
{
    int nameCardID;
    char personName[20];
    char companyName[20];
} NameCard;
/*Initialize functions*/
void listNameCards(NameCard ncHolder[], int numCards);
void addNameCard(NameCard ncHolder[], NameCard newCard, int *numCards);
void removeNameCard(NameCard ncHolder[], char *target, int *numCards);
void getNameCard(NameCard ncHolder[], char *target, int numCards);

int main()
{
    NameCard ncHolder[MAX], newCard;
    char target[20], dummychar;
    int choice, numCards=0;

    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM: \n");
    printf("1: listNameCards()\n");
    printf("2: addNameCard()\n");
    printf("3: removeNameCard()\n");
    printf("4: getNameCard()\n");
    printf("5: quit\n");

    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("listNameCards(): \n");
                listNameCards(ncHolder, numCards);
                break;
            case 2:
                printf("Enter nameCardID: \n");
                scanf("%d", &newCard.nameCardID);
                scanf("%c", &dummychar);
                printf("Enter personName: \n");
                gets(newCard.personName);
                printf("Enter companyName: \n");
                gets(newCard.companyName);
                addNameCard(ncHolder, newCard, &numCards);
                break;
            case 3:
                scanf("%c", &dummychar);
                printf("Enter personName: \n");
                gets(target);
                removeNameCard(ncHolder, target, &numCards);
                break;
            case 4:
                scanf("%c", &dummychar);
                printf("Enter personName: \n");
                gets(target);
                getNameCard(ncHolder, target, numCards);
                break;
            }
    } while (choice < 5);
    return 0;
}

/*Functions*/
void listNameCards(NameCard ncHolder[], int numCards)
{
    int i;

    if (numCards == 0)
        printf("The ncHolder is empty\n");
    else {
        for (i=0; i<numCards; i++) {
            printf("nameCardID: %d\n", ncHolder[i].nameCardID);
            printf("personName: %s\n", ncHolder[i].personName);
            printf("companyName: %s\n", ncHolder[i].companyName);
        }
    }
}

void addNameCard(NameCard ncHolder[], NameCard newCard, int *numCards)
{
    NameCard temp;
    //try to add number of cards into ncHolder
    (*numCards)++;
    if (newCard.nameCardID < 0) {
        printf("Please enter a positive number!\n");
        (*numCards)--;
        return;
    }
    //ID checker
    for (int i=0; i<*numCards-1; i++) {
        if (newCard.nameCardID == ncHolder[i].nameCardID) {
            printf("nameCardID has existed already! Enter another name card\n");
            (*numCards)--;
            return;
        }
    }
    //MAX checker
    if (*numCards <= MAX) {
        ncHolder[(*numCards)-1] = newCard;
        printf("The name card has been added successfully\n");
        //ascending check
        for (int k=0; k<(*numCards); k++) {
            for (int j=0; j<(*numCards); j++) {
                if (ncHolder[j].nameCardID > ncHolder[k].nameCardID) {
                    temp = ncHolder[k];
                    ncHolder[k] = ncHolder[j];
                    ncHolder[j] = temp;
                }
            }
        }
    }
    else {
        //if full, remove back numcards to reflect properly
        printf("Sorry! The ncHolder is full\n");
        (*numCards)--;
        return;
    }
}

void removeNameCard(NameCard ncHolder[], char *target, int *numCards)
{
    int msglen = strlen(target);
    char chartemp[20];

    //check if ncHolder is empty
    if ((*numCards) == 0)
        printf("removeNameCard(): The ncHolder is empty\n");
    else {
        //lowercasing of target name and ncHolder name
        for (int i=0; i<(*numCards); i++) {
            strcpy(chartemp, ncHolder[i].personName);
            for (int k=0; k<msglen; k++) {
                if (target[k] != ' ')
                    target[k] = tolower(target[k]);
                if (chartemp[k] != ' ')
                    chartemp[k] = tolower(chartemp[k]);
            }
            /*Debug*/
            //printf("%s\n", target);
            //printf("%s\n", chartemp);
            /*Removal of name*/
            if (strcmp(target, chartemp) == 0) {
                printf("The name card is removed\n");
                printf("nameCardID: %d \n", ncHolder[i].nameCardID);
                printf("personName: %s \n", ncHolder[i].personName);
                printf("companyName: %s \n", ncHolder[i].companyName);
                for (int j=i; j<(*numCards); j++){
                    ncHolder[j] = ncHolder[j+1];
                }
                //reduce the numCards to reflect correctly
                (*numCards)--;
                return;
            }
        }
        printf("The target person name is not in ncHolder\n");
    }
}

void getNameCard(NameCard ncHolder[], char *target, int numCards)
{
    int msglen = strlen(target);
    char chartemp[20];

    //if ncHolder is empty
    if (numCards == 0)
        printf("getNameCard(): The ncHolder is empty\n");
    else {
        //lowercasing of target and name in ncHolder
        for (int i=0; i<numCards; i++) {
            strcpy(chartemp, ncHolder[i].personName);
            for (int k=0; k<msglen; k++) {
                if (target[k] != ' ')
                    target[k] = tolower(target[k]);
                if (chartemp[k] != ' ')
                    chartemp[k] = tolower(chartemp[k]);
            }
            /*Debug*/
            //printf("%s\n", target);
            //printf("%s\n", chartemp);

            /*If found, print out corresponding data*/
            if (strcmp(target, chartemp) == 0) {
                printf("The target person name is found\n");
                printf("nameCardID: %d \n", ncHolder[i].nameCardID);
                printf("personName: %s \n", ncHolder[i].personName);
                printf("companyName: %s \n", ncHolder[i].companyName);
                return;
            }
        }
        printf("The target person name is not found\n");
    }
}

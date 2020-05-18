// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists
// Template for Q2, Q3, and Q4

//#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

//////////////////////////////////////////////////////

int searchList(ListNode *head, int value);
void deleteList(ListNode **p);

//////////////////////////////////////////////////////

int main()
{
	ListNode *head, *p, *temp;
	int n;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");

 ////////////////////////////////////////////////////////////////////

 // Question 2
    scanf("%d", &n);
    if (isalpha(n)==0)
    {
        while(n != -1)
        {
            if (head == NULL)
            {
                head = malloc(sizeof(ListNode));
                p=head;
            }
            else
            {
                p->next = malloc(sizeof(ListNode));
                p = p->next;
            }
            p->item = n;
            p->next = NULL;
            scanf("%d", &n);
        }

        printf("Current list: ");
        p = head;
        while (p != NULL)
        {
            printf("%d ", p->item);
            p = p->next;
        }
        printf("\n");
    }
    else
        printf("Please enter numbers only!\n");

//////////////////////////////////////////////////////////////////////

//search for a value in the list. Q3

	printf("Enter value to search for:");
	scanf("%d", &n);
	searchList(head,n);

/////////////////////////////////////////////////////////

    //free up memory for question 4
	//this part is wrong. It will cause problems.
/*	p = head;
	while (p!= NULL) {
		free(p);
		p=p->next;
	}
*/
    /*p = head;
    //temp = head;
    while (p != NULL) {
        temp = p->next; //temp = p
        free(p);
        p = temp;        //temp = temp->next
    }
    head = NULL;*/

    // Question 4
	//rewrite the free up using temporary pointer temp.
    deleteList(&head); //
/////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////

int searchList(ListNode *head, int value)
{

////////////////////////////////////////////////////////////////////

 // Question 3
    int count = 0;
    ListNode *p = head;
    while (p != NULL)
    {
        if (p->item == value)
        {
            printf("Value %d found at index %d \n", value, count);
            return count;
        }
        p = p->next;
        count++;
    }
    printf("Value %d can not be found! \n", value);
    return -1;

//////////////////////////////////////////////////////////////////////
}

void deleteList(ListNode **p)
{
    //Write your program code here.
    if(*p == NULL)
        return;
    deleteList(&((*p)->next)));
    free(*p);
    *p = NULL;

}


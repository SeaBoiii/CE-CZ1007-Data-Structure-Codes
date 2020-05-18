// CE1007/CZ1007 Data Structures
// Week 10 Lab Tutorial - Linked List

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////
////////////

typedef struct _listnode{
	int num;
	struct _listnode *next;
} ListNode;
typedef struct _linkedlist{
	ListNode *head;
	int size;
} LinkedList;
typedef struct _dbllistnode{
	int num;
	struct _dbllistnode *pre;
	struct _dbllistnode *next;
} DblListNode;

////////////////////////////////////////////////////////////////////
////////////
int removeNode(ListNode **ptrHead, int index);
int removeNode2(LinkedList *ll, int index);
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList);
int duplicateReverse(ListNode *head, ListNode **ptrNewHead);

void printList(ListNode *head);
ListNode * findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);


// these are for the practice questions
int moveMaxToFront(ListNode **ptrHead);
int concatenate(ListNode **ptrHead1, ListNode *head2);
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2);
int insertDbl(DblListNode **ptrHead, int index, int value);
void printDblList(DblListNode *head);

////////////////////////////////////////////////////////////////////
////////////

int main()
{
	int i;
	ListNode *head = NULL;
	ListNode *dupRevHead = NULL;
	ListNode *oddHead = NULL;
	ListNode *evenHead = NULL;
	ListNode *list1Head = NULL, *list2Head = NULL;
	ListNode *combAltHead = NULL;
	DblListNode *dblHead = NULL;
	LinkedList llist;
	int size = 0;

	//build a linked list
	if (insertNode(&head, 0, 6) == 0) size++;
	if (insertNode(&head, 0, 4) == 0) size++;
	if (insertNode(&head, 0, 2) == 0) size++;
	printf("After inserting 3 values.");
	printList(head);


	//removeNode(): question 1
	if (removeNode(&head, 3) == 0) size--;//this one can't be removed.
	if (removeNode(&head, 1) == 0) size--;
	if (removeNode(&head, 0) == 0) size--;

	printf("\nafter remove using removeNode(), ");
	printList(head);

	//insert some nodes
	if (insertNode(&head, 2, 3) == 0) size++; // this one can't be inserted.
	if (insertNode(&head, 1, 1) == 0) size++;
	if (insertNode(&head, 0, 0) == 0) size++;

	printf("\nafter insert, ");
	printList(head);

	//removeNode2(): question 2
	llist.head = head;
	llist.size = size;
	removeNode2(&llist, 2);
	removeNode2(&llist, 0);
	removeNode2(&llist, 0);
	head = llist.head;


	printf("\nafter remove using removeNode2(), ");
	printList(llist.head);
	// empty linked list now

	//split(): question 3
	for (i = 1; i <10; i++)//build a new linked list
		insertNode(&head, 0, i);
	printf("\n\ninsert 1-9 to the linked list,");
	printList(head);
	printf("split the current list, results:\n");
	split(head, &evenHead, &oddHead);
	printf("the even list");
	printList(evenHead);
	printf("the odd list");
	printList(oddHead);

	//duplicateReverse(): question 4
	printf("\n");
	printList(head);
	duplicateReverse(head, &dupRevHead);
	printf("After duplicateReverse(),");
	printList(dupRevHead);

	////////////////////////////////////////////////////////////////////////
	//the following are for the PRACTICE QUESTIONS

	printf("\n\nNow for the practice questions");

	//1.moveMaxToFront()
	printf("\n************** moveMaxToFront *******************\n");
	printList(dupRevHead);
	moveMaxToFront(&dupRevHead);
	printf("after moveMaxToFront()");
	printList(dupRevHead);

	//2. concatenate()
	printf("\n************** concatenate() *******************\n");
	concatenate(&head, dupRevHead);
	printf("concatenate(current list, duplicate reverse list)\n  ");
	printList(head);

	//3.combineAlternating()
	printf("\n************** combineAlternating() *******************\n");
	for (i = 3; i > 0; i--)				//build linked list 1
		insertNode(&list1Head, 0, i);
	for (i = 13; i > 10; i--)			//build linked list 2
		insertNode(&list2Head, 0, i);
	printf("List 1:");
	printList(list1Head);
	printf("List 2: ");
	printList(list2Head);
	combineAlternating(&combAltHead, list1Head, list2Head);
	printf("After combineAlternating(): ");
	printList(combAltHead);

	//4. insertDbl()
	printf("\n************** insertDbl() *******************\n");
	printf("insertDbl()\nDoubly-linked list: ");
	insertDbl(&dblHead, 0, 10);
	insertDbl(&dblHead, 0, 20);
	insertDbl(&dblHead, 1, 30);
	insertDbl(&dblHead, 2, 40);
	printDblList(dblHead);
	return 0;
}

////////////////////////////////////////////////////////////////////
////////////

void printList(ListNode *head){
	ListNode *cur = head;

	if (cur == NULL)
		return;

	printf("the current linked list is:\n");
	while (cur != NULL){
		printf("%d ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}

void printDblList(DblListNode *head){
	if (head == NULL) return;
	while (head != NULL){
		printf("%d ", head->num);
		head = head->next;
	}
	printf("\n");
}

ListNode * findNode(ListNode *head, int index){
	if (head == NULL || index < 0) return NULL;
	while (index > 0){
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}


int insertNode(ListNode **ptrHead, int index, int value){
	ListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead = malloc(sizeof(ListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		return 0;
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->num = value;
		pre->next->next = cur;
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////
////////////

int removeNode(ListNode **ptrHead, int index){

	// write your code here
	ListNode *p, *cur, *prev;
    int count=0;


    if(*ptrHead == NULL)
        return 0;

    if(index==0)
    {
      cur=*ptrHead;
      *ptrHead = cur->next;
      free(cur);
      return 1;
    }
    else
    {
        //Transverse through the ll
        // count+1
        //find if count++ == index ;
        //store prev->next & cur->next
        p = *ptrHead;
        while(p->next != NULL)
        {
            if(count+1 == index)
            {
                cur = p->next;
                p->next=cur->next;
                free(cur);
                return 1;

            }
            count++;
            p=p->next;
        }
        return 0;

    }
}

////////////////////////////////////////////////////////////////////////////////
////////////

int removeNode2(LinkedList *ll, int index) {

	// write your code here
	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}



int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList)
{

	// write your code here
	ListNode *p, *even, *odd;
    int counter=0;
    if(head == NULL)
    {
        return 0;
    }
    p=head;
    even = *ptrEvenList;
    odd = *ptrOddList;

    while(p != NULL)
    {
        ListNode *m = malloc(sizeof(ListNode));
        m->next = NULL;
        m->item = p->item;

        if((counter%2) ==0)
        {
            if(even == NULL)
            {
                *ptrEvenList = m;
                even = m;
            }
            else
            {
                even->next = m;
                even = m; //This is to add the next item
            }
        }
        else
        {
            if(odd == NULL)
            {
                *ptrOddList = m;
                odd = m;
            }
            else
            {
                odd->next = m;
                odd = m;
            }
        }
        counter++;
        p = p->next;

    }

}

int duplicateReverse(ListNode *head, ListNode **ptrNewHead){

	// write your code here
    ListNode *newNode, *p;
    p = head;

    while(p!=NULL)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->item = p->item;
        newNode->next = (*ptrNewHead);
        (*ptrNewHead) = newNode;

        p = p->next;
    }
}

////////////////////////////////////////////////////////////////////
////////////

int moveMaxToFront(ListNode **ptrHead){


	// write your code here
	ListNode *preNode, *curNode, *preTemp; //*curTemp;
    int max, index=0, maxindex=0;

    curNode = *ptrHead;
    if (*ptrHead == NULL) //if empty, return
        return -1;
    if ((*ptrHead)->next == NULL) //if only 1 node, return
        return 0;

    //transverse by 1
    max = curNode->item;
    preNode = curNode;
    curNode = curNode->next;
    index++;

    while (curNode != NULL)
    {
        if (curNode->item > max)
        {
            max = curNode->item;
            maxindex = index;
            preTemp = preNode;
            //curTemp = curNode;
        }
        index++;
        preNode = curNode;
        curNode = curNode->next;
    }

    if (maxindex == 0) //if max item at the start, do nothing
        return 0;

    curNode = preTemp->next;
    preTemp->next = preTemp->next->next;

    curNode->next = *ptrHead;
    *ptrHead = curNode;
    return maxindex;

}


int concatenate(ListNode **ptrHead1, ListNode *head2){

	// write your code here
	if((head2 == NULL))
        return 0;

    else if((*ptrHead1) == NULL){
        (*ptrHead1) = head2;
    }
    else
    {
        ListNode  *prev, *temp;

        prev = *ptrHead1;

        while(prev->next != NULL)
        {
            prev = prev->next;
        }
        //temp->next = head2;
        prev->next = head2;
    }

}


int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2){

	// write your code here
    ListNode *list1 = head1;
    ListNode *list2 = head2;
    ListNode *curlist;

    if((*ptrHead)==NULL)
    {
        if(head1!=NULL)
        {
        ListNode *temp  = malloc(sizeof(ListNode));
        temp->next = NULL;
        temp->item = head1->item;
        list1 = list1->next;
        *ptrHead = temp;

        }
        else if(head2!=NULL)
        {
            ListNode *temp = malloc(sizeof(ListNode));
            temp->next = NULL;
            temp->item = head2->item;
            list2 = list2->next;
            *ptrHead = temp;
        }

        curlist = (*ptrHead);
    }

    while(list1 != NULL || list2 != NULL)
    {
        if(list2 != NULL)
        {
            ListNode *temp = malloc(sizeof(ListNode));
            temp->item = list2->item;
            temp->next = NULL;
            curlist->next = temp;
            list2 = list2->next;
            curlist = curlist->next;
        }

        if(list1 != NULL)
        {
            ListNode *temp = malloc(sizeof(ListNode));
            temp->item = list1->item;
            temp->next = NULL;
            curlist->next = temp;
            list1 = list1->next;
            curlist = curlist->next;
        }


    }
}


int insertDbl(DblListNode **ptrHead, int index, int value){

	// write your code here
    DblListNode* newNode;
    DblListNode* pre;

    if(index==0){ //Empty list or insert node at index 0
        newNode = (DblListNode *) malloc(sizeof(DblListNode));
        newNode->item = value;
        newNode->next = *ptrHead;
        newNode->pre = NULL; //malloc() does not assign it to NULL

        if(*ptrHead!=NULL) //for non-empty case only
             (*ptrHead)->pre = newNode;

        *ptrHead = newNode;
        return 1;
    }
    else if ((pre=findDblListNode(*ptrHead,index-1))!=NULL){
        newNode = (DblListNode *) malloc(sizeof(DblListNode));
        newNode->item = value;
        newNode->next = pre->next;
        newNode->pre = pre;

        if(pre->next!=NULL) //not the insert at the end of list
            pre->next->pre = newNode;
        pre->next =newNode;
        return 1;
    }

    return 0;
}


////////////////////////////////////////////////////////////////////

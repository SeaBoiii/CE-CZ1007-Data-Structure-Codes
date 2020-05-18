//////////////////////////////////////////////////////////////////////

// CE1007/CZ1007 Data Structures
// Week 13 Lab and Tutorial - Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	// write your code here
//	BTNode *temp = *node;
//
//	while (temp != NULL)
//    {
//        if (value < temp->item)
//        {
//            if (temp->left = NULL)
//                break;
//            else
//                temp = temp->left;
//        }
//        else if (value > temp->item)
//        {
//            if (temp->right = NULL)
//                break;
//            else
//                temp = temp->right;
//        }
//        else
//        {
//            printf("Duplicated Item: %d\n", value);
//            return;
//        }
//    }
//
//    BTNode *tree = malloc(sizeof(BTNode));
//    tree->item = value;
//    tree->left = tree->right = NULL;
//
//    if (*node == NULL)
//        *node = tree;
//    else if (value < temp->item)
//        temp->left = tree;
//    else
//        temp->right = tree;
//    return;
    if (*node == NULL)
    {
        *node = malloc(sizepf(BTNode));
        (*node)->item = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return;
    }
    if (value<(*node)->item)
        insertBSTNode(&((*node)->left),value);
    else if (value>(*node)->item)
        insertBSTNode(&((*node)->right), value);
    else
        printf("Already exists in the BST\n");
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	// write your code here

	if (node = NULL)
        return;
    printBSTInOrder(node->left);
    printf("%d ", node->item);
    printBSTInOrder(node->right);

    return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	// write your code here
	if (node == NULL)
        return 1;
    if (node->item <= min)
        return 0;
    if (node->item >= max)
        return 0;

    return isBST(node->left, min, node->item) && isBST(node->right, node->item, max);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
	// write your code here
	BTNode *temp;

	if (node == NULL)
    {
        printf("can't find the value!\n");
        return NULL;
    }

    if (node->item > value)
        node->left = removeBSTNode(node->left, value);

    else if (node->item < value)
        node->right = removeBSTNode(node->right, value);
    else
    {
        if (node->left != NULL && node->right != NULL)
        {
            temp = findMin(node->right);
            node->item = temp->item;
            node->right = removeBSTNode(node->right, temp->item);
        }
        else
        {
            temp = node;
            if (node->left != NULL)
                node = node->left;
            else
                node = node->right;
            free(temp);
        }
    }
    return node;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	// write your code here
	if (p == NULL)
        return NULL;
	if (p->left != NULL)
        return findMin(p->left);
    else
        return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

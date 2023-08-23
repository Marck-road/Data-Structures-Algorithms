#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node *lc, *rc;
	int elem;
} tree, *bst;

void init(bst *head);
void insert(bst *head, int num);
int mem(bst head, int num);
void preorder(bst head);
void postorder(bst head);
void inorder(bst head);
void display(bst head);
int memRec(bst head, int num);
void deleteLeaf(bst *head, int num);
void deleteInode1Child(bst *head, int num);
void deleteInode2ChildOption1(bst *head, int num);
void deleteInode2ChildOption2(bst *head, int num);

int main()
{
	bst head;

	init(&head);
	insert(&head, 5);
	insert(&head, 2);
	insert(&head, 0);
	insert(&head, 3);
	insert(&head, -1);
	insert(&head, 6);
	insert(&head, 2);
	insert(&head, 1);
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 5);
    display(head);
	deleteLeaf(&head, 1);
    deleteLeaf(&head, 20);
	printf("\n\nAfter deleting 1 & 20:");
	display(head);
	deleteInode1Child(&head, 9);
	deleteInode1Child(&head, -4);
	printf("\n\nAfter deleting 9 & -4:");
	display(head);
	deleteInode2ChildOption1(&head, 2);
	deleteInode2ChildOption1(&head, -6);
	printf("\n\nAfter deleting 2 & -6:");
	display(head);
	deleteInode2ChildOption2(&head, 5);
	deleteInode2ChildOption2(&head, 99);
	printf("\n\nAfter deleting 5 & 99:");
	display(head);
	
	return 0;
}

void init(bst *head)
{
	*head = NULL;
}

void insert(bst *head, int num)
{
	if (memRec(*head, num) == 0){
		while (*head != NULL){
			head = (num > (*head)->elem) ? &(*head)->rc : &(*head)->lc;
		}
		*head = (bst)malloc(sizeof(tree));
		if (*head != NULL){
			(*head)->elem = num;
			(*head)->lc = (*head)->rc = NULL;
		}
	}
}

int mem(bst head, int num)
{
	while (head != NULL && (head)->elem != num){
		head = (num > (head)->elem) ? (head)->rc : (head)->lc;
	}

	return (head == NULL) ? 0 : 1;
}

void preorder(bst head)
{
	if (head != NULL){
		printf("%d ", head->elem);
		preorder(head->lc);
		preorder(head->rc);
	}
}

void postorder(bst head)
{
	if (head != NULL){
		postorder(head->lc);
		postorder(head->rc);
		printf("%d ", head->elem);
	}
}

void inorder(bst head)
{
	if (head != NULL){
		inorder(head->lc);
        printf("%d ", head->elem);
		inorder(head->rc);
	}
}

void display(bst head)
{
	printf("\n\n");
	preorder(head);
    printf("\n\n");
	postorder(head);
    printf("\n\n");
	inorder(head);
}

int memRec(bst head, int num)
{
	int result;

	if (head != NULL && head->elem != num){
		if(num > head->elem){
            result = memRec(head->rc, num);
        } else{
            result =  memRec(head->lc, num);
        }
        printf("%d ", result);
	} else {
		result = (head == NULL) ? 0 : 1;
        printf("%d ", result);
	}

	return result;
}

void deleteLeaf(bst *head, int num)
{
	if (mem(*head, num) == 1){
		bst temp;

		while (num != (*head)->elem){
			head = (num > (*head)->elem) ? &(*head)->rc : &(*head)->lc;
		}
		temp = *head;
		free(temp); 
		*head = NULL;
	}
}

void deleteInode1Child(bst *head, int num)
{
	if (memRec(*head, num) == 1){
		bst temp;

		while ((*head)->elem != num){
			head = ((*head)->elem < num) ? &(*head)->rc : &(*head)->lc;
		}
		temp = *head;
		*head = ((*head)->lc == NULL) ? (*head)->rc : (*head)->lc;
		free(temp);
	}
}

void deleteInode2ChildOption1(bst *head, int num)
{
	if (mem(*head, num) == 1){
		bst temp, del;
		int tempVal;

		while ((*head)->elem != num){
			head = (num > (*head)->elem) ? &(*head)->rc : &(*head)->lc;
		}
		temp = *head;
		for (head = &(*head)->lc; (*head)->rc != NULL; head = &(*head)->rc){}
		tempVal = (*head)->elem;
		(*head)->elem = temp->elem;
		temp->elem = tempVal;
		del = *head;
		*head = del->lc;
		free(del);
	}
}

void deleteInode2ChildOption2(bst *head, int num)
{
	if (memRec(*head, num) == 1){
		bst temp, del;
		int tempVal;

		while ((*head)->elem != num){
			head = ((*head)->elem < num) ? &(*head)->rc : &(*head)->lc;
		}
		temp = *head;
		for (head = &(*head)->rc; (*head)->lc != NULL; head = &(*head)->lc){}
		tempVal = (*head)->elem;
		(*head)->elem = temp->elem;
		temp->elem = tempVal;
		del = *head;
		*head = del->rc;
		free(del);
	}
}
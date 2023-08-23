#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

int menu();
void add(node *head);
node* traverse(node *current, int grade);
void show(node *head);
int countleft(node *current);
int countright(node *current);
void tree(node *head); 

int main(){
	node *head;
	
	head = (node *)malloc(sizeof(node));
	head -> data = 60;
	head -> left = NULL;
	head -> right = NULL;
	
	int choice=0;
	
	do{
		switch(menu()){
			case 1:
				add(head);
				break;
			case 2:
				show(head);
				break;
			case 3:
				exit(1);
		}
	
	}while(choice!=3);
		
	return 0;
}

int menu(){
	int input;
	
	printf("\n[1] Add: \n");
	printf("[2] Show Statistics: \n");
	printf("[3] Close: \n");	
	printf("Enter Input: ");
	scanf("%d", &input);
	
	return input;
}

node* traverse(node *current, int grade){
	
    if(grade<current->data){
        if(current->left == NULL)
            return current;
		traverse(current->left, grade);
	}else{
        if(current->right == NULL)
            return current;
        traverse(current->right, grade);		
	}
}

void add(node *head){
	node *current, *temp, *destination;
	
	current = head;
	int grade;
	
	printf("\n");
	printf("Input the grade of the student: ");
	scanf("%d", &grade);
	
	temp = (node *)malloc(sizeof(node));
	temp -> data = grade;
	temp -> left = NULL;
	temp -> right = NULL;

    destination = traverse(current, grade);
    
    if(destination->data > grade)
        destination->left = temp;
    else
        destination->right = temp;
}

void show(node *head){
    int pass, fail;
    fail = countleft(head->left);
    pass = countright(head->right);

	printf("Students who passed: %d\n", pass);
	printf("Students who failed: %d\n", fail);

    tree(head);
}

int countleft(node *current){
    if (current == NULL)
        return 0;

    return 1 + countleft(current->left) + countleft(current->right);
}

int countright(node *current){
    if (current == NULL)
        return 0;

    return 1 + countright(current->left) + countright(current->right);
}

void tree(node *head){
    if(head == NULL)
        return;
    

//	printf("%d -> ", head->data); //pre-order
    tree(head->left);
//  printf("%d -> ", head->data);//in-order
    tree(head->right);
//  printf("%d -> ", head->data); //post-order


}

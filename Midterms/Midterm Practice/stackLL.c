#include <stdio.h>
#include <stdlib.h>

typedef struct stackList{
    int data;
    struct stackList *next;
}stackList;

stackList* newNode(int data);
void push(stackList **root, int data);
void pop(stackList **root);
void peek(stackList *root);
int isEmpty(stackList *root);

int main(){
    stackList *root = NULL;

    peek(root);
    push(&root, 1);
    push(&root, 2);
    push(&root, 3);
    push(&root, 5);
    peek(root);
    pop(&root);

    return 0;
}

stackList* newNode(int data){
    stackList *newStack = (stackList *) malloc(sizeof(stackList));
    newStack->data = data;
    newStack->next = NULL;

    return newStack;
} 


int isEmpty(stackList *root){
    return !root;
}

void push(stackList **root, int data){
    stackList *temp = newNode(data);

    temp->next = *root;
    *root = temp;

    printf("%d pushed to stack!\n", data);

}

void pop(stackList **root){
    
    if(isEmpty(*root)){
        printf("Stack Underflow!\n");
        return;
    }
    
    stackList *temp = *root;
    *root = (*root)->next;

    printf("%d popped from stack!\n", temp->data);


    free(temp);
}

void peek(stackList *root){
    
    if(isEmpty(root)){
        printf("Empty Stack!\n");
        return;
    }

    printf("Current top: %d\n", root->data);

}

#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct element{
    int data;
    int next;
}element;

typedef struct cB{
    element info[30];
    int top;
    int capacity;
}cB;

int isFull(cB *root){
    return root->top+1 == root->capacity;
}

int isEmpty(cB *root){
    return root->top == -1;
}

void push(cB **root, int n){
    if(isFull(*root)){
        printf("Stack Overflow!\n");
        return;
    }
    int temp = (*root)->top;

    (*root)->info[++(*root)->top].data = n;
    (*root)->info[(*root)->top].next = temp;

    printf("%d pushed into stack! \n", (*root)->info[(*root)->top].data);
    
}

void pop(cB **root){
    if(isEmpty(*root)){
        printf("Stack Underflow!\n");
        return;
    }
    int temp = (*root)->top;
    (*root)->top = (*root)->info[(*root)->top].next;
    printf("%d popped from stack!\n", (*root)->info[temp].data);
}

void initialize(cB **root){
    (*root)->top = -1;
    (*root)->capacity = 30;
}

void peek(cB *root){
    if(isEmpty(root)){
        printf("Stack Underflow!\n");
        return;
    }

    printf("Top: %d\n", root->info[root->top].data);
}



int main(){
    cB *root;

    initialize(&root);

    peek(root);

    push(&root, 3);
    push(&root, 5);
    push(&root, 8);
    push(&root, 7);
    push(&root, 1);

    peek(root);

    pop(&root);
    printf("after delete:\n");
    peek(root);

    pop(&root);
    printf("after 2nd delete:\n");
    peek(root);


    printf("after 2nd add:\n");
    push(&root, 1);
    peek(root);
    return 0;
}

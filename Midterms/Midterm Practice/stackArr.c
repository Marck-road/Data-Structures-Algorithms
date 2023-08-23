#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode{
    int capacity;
    int top;
    int *array;
}stackNode;


int isEmpty(stackNode *root){
    return root->top == -1;
}

int isFull(stackNode *root){
    return root->top+1 == root->capacity;
}

void push(stackNode *root, int data){

    if(isFull(root)){
        printf("Stack Overflow!\n");
        return;
    }
    
    root->array[++root->top] = data;
    
    printf("%d pushed to stack!\n", data);
}

void pop(stackNode *root){
    if(isEmpty(root)){
        printf("Stack Underflow!\n");
        return;
    }

    int temp = root->array[root->top];

    --root->top;

    printf("%d popped from stack!\n", temp);


}
void peek(stackNode *root){
    if(isEmpty(root)){
        printf("Empty Stack!\n");
        return;
    }

    printf("Top: %d\n", root->array[root->top]);
}

stackNode *initStack(int capacity){
    stackNode *newStack = (stackNode *) malloc(sizeof(stackNode));
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->array = (int *)malloc(capacity * sizeof(int));

    return newStack;
}

int main(){
    stackNode *root = initStack(100);
    
    peek(root);
    pop(root);

    push(root, 1);
    push(root, 2);
    push(root, 3);
    push(root, 5);
    peek(root);
    pop(root);

    return 0;
}

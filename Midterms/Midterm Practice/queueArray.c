#include <stdio.h>
#include <stdlib.h>

typedef struct queueList{
    int capacity;
    int front;
    int rear;
    int *array;
}queueList;

int isEmpty(queueList *list){
    return list->front == -1;
}

int isFull(queueList *List){
    return List->rear == List->capacity-1;
}

void peek(queueList *List){
    if(isEmpty(List)){
        printf("Queue Underflow!\n");
        return;
    }

    printf("Front: %d\nRear: %d\n", List->array[List->front], List->array[List->rear]);
}

void enqueue(queueList **List, int data){
    if(isFull(*List)){
        printf("Queue Overflow!\n");
        return;
    }

    if((*List)->front == -1)
        (*List)->front = 0;


    (*List)->array[++(*List)->rear] = data;

    printf("%d enqueued into list!\n", (*List)->array[(*List)->rear]);
}

void dequeue(queueList **List){
    if(isEmpty(*List)){
        printf("Queue Underflow!\n");
        return;
    }

    int temp = (*List)->array[(*List)->front];
    ++(*List)->front; 

    printf("%d dequeued from list!\n", temp);
}

void initqueue(queueList **List){
    (*List)->front = -1;
    (*List)->rear = -1; 
    (*List)->capacity = 30;
    (*List)->array = (int *) malloc((*List)->capacity * sizeof(int));
}


int main(){
    queueList *List;
    
    initqueue(&List);

    dequeue(&List);
    peek(List);

    enqueue(&List, 1);
    enqueue(&List, 2);
    enqueue(&List, 3);
    enqueue(&List, 5);

    peek(List);

    dequeue(&List);
    peek(List);
    return 0;
}
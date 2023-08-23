#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode{
    int data;
    struct queueNode *next;
}queueNode;

typedef struct queuePtr{
    queueNode *front;
    queueNode *rear;
}queuePtr;

int isEmpty(queuePtr *queue){
    return queue->front == NULL;
}

queueNode* newNode(int data){
    queueNode *newQueue = (queueNode *)malloc(sizeof(queueNode));
    newQueue->data = data;
    newQueue->next = NULL;

    return newQueue;
}

void peek(queuePtr *queue){
    if(isEmpty(queue)){
        printf("Queue Underflow!\n");
        return;
    }

    printf("Front: %d\nRear: %d\n", queue->front->data, queue->rear->data);
}

void enqueue(queuePtr **queue, int data){

    queueNode *newStack = newNode(data);
    newStack->next = (*queue)->rear;


    if((*queue)->front == NULL)
        (*queue)->front = newStack;
    else
        (*queue)->rear->next = newStack;


    (*queue)->rear = newStack;

    printf("%d enqueued into list!\n", (*queue)->rear->data);
}

void dequeue(queuePtr **queue){
    if(isEmpty(*queue)){
        printf("Queue Underflow!\n");
        return;
    }

    queueNode *temp = (*queue)->front;

    (*queue)->front = temp->next;

    
    printf("%d dequeued from list!\n", temp->data);
    free(temp);
}

void initQueue(queuePtr *queue){
   
    queue->rear = NULL;
    queue->front = NULL;
    
}

int main(){
    queuePtr *queue;
    
    initQueue(queue);

    dequeue(&queue);
    peek(queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 5);

    peek(queue);

    dequeue(&queue);
    peek(queue);

    dequeue(&queue);
    peek(queue);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}*node;

typedef char String[30];

void addNode(node *head, int n);
void printList(node head);
void insertNode(node *head, int n, int index);
void deleteNode(node *head, int n);
void editNode(node *head, int n, int index);

int main(){
    node head = NULL;

    addNode(&head, 32);
    addNode(&head, 7);
    addNode(&head, 12);
    addNode(&head, 4);
    addNode(&head, 69);   

    printList(head);

    insertNode(&head, 100, 3);

    printList(head);

    editNode(&head, 200, 3);

    printList(head);
    
    deleteNode(&head, 3);

    printList(head);

    
}

void addNode(node *head, int n){
    node current, temp;

    temp = (node) malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;

    if(*head == NULL){
        *head = temp;
    } else{
        for(current = *head; current->next != NULL; current = current->next){}
        current->next = temp;
    }

    return;
}

void printList(node head){
    node current;
    int count=0; 

    printf("Linked List: \n");
    for(current = head; current!=NULL; current=current->next){
        printf("Node %d: %d\n", count, current->data);
        count++;
    }
}

void insertNode(node *head, int n, int index){
    node current, temp;
    int count = 0;

    temp = (node)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;

    if(index == 0){
        temp->next = *head;
        *head = temp;
    } else{
        for(current = *head; current!=NULL; current = current->next){
            if(count == index-1)
                break;
            count++;
        }        
        temp->next = current->next;
        current->next = temp;
    }
}

void deleteNode(node *head, int n){

    node temp, current;
    int count = 0;

    if(n == 0){
        temp = *head;
        *head = (*head)->next;
    }else{
        for(current=*head; current->next != NULL; current=current->next){
            if(count==n-1)
                break;
            count++;
        }
        
        temp = current->next;
        current->next = current->next->next;
    }

    free(temp);

    return;
}

void editNode(node *head, int n, int index){
    node temp, current;
    int count = 0;

    if(n == 0){
        (*head)->data = n;
    }else{
        for(current=*head; count!=index; current=current->next){
            count++;
        }
        current->data = n;    
    }
}

// << shift left
// >> shift right


// Adding = storage / 1 << node
// check  similiar to (storage % 2 == 1 && y == n)
// Removing = storage % ~(i<<n);
// Union = a / b
// Intersection = a % b



#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct element{
    int data;
    int next;
}element;

typedef struct cB{
    element info[30];
    int start;
    int avail;
}cB;


void add(cB *list, int n);
void display(cB list);
void initialize(cB *list);
void delete(cB *list, int n);
void update(cB *list);

int main(){
    cB list;

    list.avail = 0;
    list.start = 0;
    initialize(&list);
    add(&list, 3);
    add(&list, 5);
    add(&list, 8);
    add(&list, 7);
    add(&list, 1);

    display(list);

    delete(&list, 3);
    printf("after delete:\n");
    display(list);

    delete(&list, 1);
    printf("after 2nd delete:\n");
    display(list);


    printf("after 2nd add:\n");
    add(&list, 1);
    display(list);
    return 0;
}

void add(cB *list, int n){
    int i;

    for(i=0; i<30; i++){
        if(list->info[i].next == -1){
            list->info[i].next = list->avail;
            break;
        }
    }

    list->info[list->avail].data = n;
    list->info[list->avail].next = -1;

    update(list);
}

void display(cB list){
    int i;

    for(i = list.start; ; i=list.info[i].next){

        printf("[%d] Data: %d || Next: %d\n", i, list.info[i].data, list.info[i].next);

        if(list.info[i].next == -1)
            break;
    }

    printf("Start: %d\n", list.start);
    printf("Available: %d\n\n", list.avail);
}

void delete(cB *list, int n){
    int i, temp; 

    if(n == list->info[list->start].data){

        temp = list->start;
        list->start = list->info[list->start].next;
        
        list->info[temp].next = -2;
        
        update(list);
        return;
    }

    for(i = list->start; n != list->info[list->info[i].next].data ;i=list->info[i].next){}
    
    if (list->info[list->info[i].next].next == -1)
    {
        list->info[i].next = -1;
    }
    

    else{
        list->info[i].next = list->info[list->info[i].next].next;
    }
       
    
    list->info[list->info[i].next].next = -2;

    update(list);
    
}

void update(cB *list){
    int i;

    for(i = 0; i<30 ; i++){
        if (list->info[i].next == -2) 
            break;
    }

    list->avail = i;
}

void initialize(cB *list){
    int i;

    for(i = 0; i<30 ; i++){
        list->info[i].next = -2;
    }

}

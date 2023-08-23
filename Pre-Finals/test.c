#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node{
    int *arr;
    int count;
}node;

int main(){
    int start = 0;
    printf("Wish me luck!\n");
    int array[5][5];

    for(int x=0; x<5; x++){
        for(int y=0; y<5; y++){
            array[x][y] = ++start;
        }    
    }

    for(int x=0; x<5; x++){
        printf("Row %d: ", x+1);
        for(int y=0; y<5; y++){
             printf("%d ",array[x][y]);
        }    
        printf("\n");

    }
       

    
    return 0;
}
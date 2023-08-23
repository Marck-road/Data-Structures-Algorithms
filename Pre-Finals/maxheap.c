#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[30];

void heapify(int *arr, int size);
void display(int arr[],  int size);
void insert(int *arr, int *size, int elem);
void deleteMax(int *arr, int *size);
void heapSort(int *arr, int size);
int checkSize(int *arr);

int main(){
    int i, size;
    int arr[20] = {-1, 3, 1, 7, 11, 9, 13, 2, 17};

    size = checkSize(arr);
    
    printf("Original: ");
    display(arr, size);
    heapify(arr, size);
    printf("After heapifying: ");
    display(arr, size);

    printf("Add 20: ");
    insert(arr, &size, 20);
    display(arr, size);
    printf("Add 8: ");
    insert(arr, &size, 8);
    display(arr, size);
    printf("Add 5: ");
    insert(arr, &size, 5);
    display(arr, size);

    printf("Delete Max: ");
    deleteMax(arr, &size);
    display(arr, size);
    printf("Delete Max: ");
    deleteMax(arr, &size);
    display(arr, size);

    printf("Heap Sort: ");
    heapSort(arr, size);
    display(arr, size);

    return 0;
}

void heapify(int *arr, int size){
    int i, temp, x, flag=1;

    while(flag){        //Stops if no swaps were made
        flag = 0;
        for(i=size; i>0; i--){
            if(i*2 <= size){      //i.e. it has children
                if(i*2 + 1 >= size) //has ONLY left child
                    x = i * 2;                
                
                else
                    x = (arr[i*2] > arr[i*2 +1]) ? i*2 : i*2+1;

                if (arr[x] > arr[i]){
                    temp = arr[i];                  
                    arr[i] = arr[x];
                    arr[x] = temp;
                    flag=1;
                }
            }           //NOTE: Both the recursion and while loop works. However,
        }               //A while loop is more efficient and saves space than
    }                   //Using a recursion to check everything which is why we 
                        //used a while loop. But recursion also works though.
    
    // if(flag)
    //     heapify(arr, size);     //rechecks everything atleast one more time
}

void display(int arr[], int size){
    for(int i = 1; i<=size; i++){
        if(i == size)
            printf("%d", arr[i]); 

        else
            printf("%d, ", arr[i]);
    }
    printf("\n");
}

int checkSize(int *arr){
    int count = 0;

    while(arr[count] != 0){
        count++;
    }
    return count-1;
}

void insert(int *arr, int *size, int elem){
    int i, temp;

    arr[++(*size)] = elem;

    for(i= *size; i>1; i--){
        if(arr[i] > arr[i/2]){      //start from bottom
            temp = arr[i/2];        //switching in place
            arr[i/2] = arr[i];
            arr[i] = temp;
        }
    }
}

void deleteMax(int *arr, int *size){
    int temp;
    int i;

    temp = arr[*size];
    arr[*size] = arr[1];
    arr[1] = temp;

    (*size)--;

    heapify(arr, *size);

}

void heapSort(int *arr, int size){
    int i, temp = size;

    for(i=1; i<temp; i++){
        deleteMax(arr, &size);
    }
}
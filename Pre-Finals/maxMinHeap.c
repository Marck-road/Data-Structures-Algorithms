#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[30];

void maxHeapify(int *arr);
void minHeapify(int *arr);

int main(){
    int i;
    int arr[9] = {-1, 3, 1, 7, 11, 9, 13, 2, 17};
    
    int maxArr[9];
    int minArr[9];

    mempcpy(maxArr, arr, sizeof(arr));
    mempcpy(minArr, arr, sizeof(arr));


    printf("Original Heap: ");
    for(i=1; i<9; i++){
        if(i==8)
            printf("%d", arr[i]);

        else
            printf("%d, ", arr[i]);
    }

    maxHeapify(maxArr);
    minHeapify(minArr);

    printf("\nMax Heap: "); //display max heap
    for(i=1; i<9; i++){
        if(i==8)
            printf("%d", maxArr[i]);

        else
            printf("%d, ", maxArr[i]);
    }

    printf("\nMin Heap: "); //display min heap
    for(i=1; i<9; i++){

        if(i==8)
            printf("%d", minArr[i]);

        else
            printf("%d, ", minArr[i]);
    }

    return 0;
}

void maxHeapify(int *arr){  
    int i, temp, flag = 0;

    for(i= 8; i>1; i--){
        if(arr[i] > arr[i/2]){  //start from bottom
            temp = arr[i/2];    //switch in place
            arr[i/2] = arr[i];  
            arr[i] = temp;
            
            maxHeapify(arr);    //rechecks everything
        }
    }
}
void minHeapify(int *arr){
    int i, temp;

    for(i= 8; i>1; i--){
        if(arr[i] < arr[i/2]){      //start from bottom
            temp = arr[i/2];        //switching in place
            arr[i/2] = arr[i];
            arr[i] = temp;
            
            minHeapify(arr);   //rechecks everything
        }
    }
}
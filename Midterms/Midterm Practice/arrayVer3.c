#include <stdio.h>
#include <stdlib.h>

typedef struct dynamicArray{
    int *arr;
    int count;
}dynamicArray;

void initialize(dynamicArray *Arr, int count){
    Arr->arr = (int *) malloc (sizeof(int));
    Arr->count = 0;
}

void resize(dynamicArray *Arr, int capacity){
    Arr->arr = (int*) realloc(Arr->arr, capacity * sizeof(int)); 
}

void add(dynamicArray *Arr, int n){
    Arr->arr[Arr->count] = n;
    Arr->count++;
}

int get(dynamicArray dynArr, int index) {
    if (index < 0 || index >= dynArr.count) {
        printf("Index out of bounds.\n");
        return -1;
    }
    return dynArr.arr[index];
}

void delete(dynamicArray *Arr, int n){
    int i = 0;

    if(n<0 || n>= Arr->count){
        printf("Index out of bounds.\n");
    }

    for(i=n; i<Arr->count; i++){
        Arr->arr[i] = Arr->arr[i+1];
    }
    Arr->count--;
}

int main() {
    dynamicArray dynArr;
    initialize(&dynArr, 2);
    add(&dynArr, 1);
    add(&dynArr, 2);
    add(&dynArr, 3);
    printf("%d\n", get(dynArr, 5)); // should print 2
    delete(&dynArr, 1);
    printf("%d\n", get(dynArr, 1)); // should print 3
    // free(dynArr.arr);
    return 0;
}


















// typedef struct {
//     int* arr;
//     int size;
//     int capacity;
// } DynamicArray;

// void init(DynamicArray* dynArr, int capacity) {
//     dynArr->arr = (int*) malloc(capacity * sizeof(int));
//     dynArr->size = 0;
//     dynArr->capacity = capacity;
// }

// void resize(DynamicArray* dynArr) {
//     dynArr->capacity *= 2;
//     dynArr->arr = (int*) realloc(dynArr->arr, dynArr->capacity * sizeof(int));
// }

// void add(DynamicArray* dynArr, int elem) {
//     if (dynArr->size == dynArr->capacity) {
//         resize(dynArr);
//     }
//     dynArr->arr[dynArr->size] = elem;
//     dynArr->size++;
// }

// int get(DynamicArray* dynArr, int index) {
//     if (index < 0 || index >= dynArr->size) {
//         printf("Index out of bounds.\n");
//         return -1;
//     }
//     return dynArr->arr[index];
// }

// int main() {
//     DynamicArray dynArr;
//     init(&dynArr, 2);
//     add(&dynArr, 1);
//     add(&dynArr, 2);
//     add(&dynArr, 3);
//     printf("%d\n", get(&dynArr, 1)); // should print 2
//     printf("%d\n", get(&dynArr, 3)); // should print "Index out of bounds."
//     free(dynArr.arr);
//     return 0;
// }

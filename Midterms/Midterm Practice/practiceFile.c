#include <stdio.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

typedef struct {
    bool array[MAX_CAPACITY];
    int capacity;
} Set;

void initSet(Set* set, int capacity);
void addToSet(Set* set, int element);
void removeFromSet(Set* set, int element);
bool contains(Set* set, int element);
Set unionOfSets(Set* set1, Set* set2);
Set intersectionOfSets(Set* set1, Set* set2);
Set differenceOfSets(Set* set1, Set* set2);
void displaySet(Set* set);

void initSet(Set* set, int capacity) {
    set->capacity = capacity;
    for (int i = 0; i < capacity; i++) {
        set->array[i] = false;
    }
}

void addToSet(Set* set, int element) {
    if (!contains(set, element)) {
        set->array[element] = true;
    }
}   

void removeFromSet(Set* set, int element) {
    if (contains(set, element)) {
        set->array[element] = false;
    }
}

bool contains(Set* set, int element) {
    if (element < 0 || element >= set->capacity) {
        return false;
    }
    return set->array[element];
}

Set unionOfSets(Set* set1, Set* set2) {
    Set result;
    initSet(&result, set1->capacity);
    for (int i = 0; i < set1->capacity; i++) {
        if (contains(set1, i) || contains(set2, i)) {
            addToSet(&result, i);
        }
    }
    return result;
}

Set intersectionOfSets(Set* set1, Set* set2) {
    Set result;
    initSet(&result, set1->capacity);
    for (int i = 0; i < set1->capacity; i++) {
        if (contains(set1, i) && contains(set2, i)) {
            addToSet(&result, i);
        }
    }
    return result;
}

Set differenceOfSets(Set* set1, Set* set2) {
    Set result;
    initSet(&result, set1->capacity);
    for (int i = 0; i < set1->capacity; i++) {
        if (contains(set1, i) && !contains(set2, i)) {
            addToSet(&result, i);
        }
    }
    return result;
}

void displaySet(Set* set) {
    printf("{");
    for (int i = 0; i < set->capacity; i++) {
        if (contains(set, i)) {
            printf("%d, ", i);
        }
    }
    printf("\b\b}\n");
}

int main(){

    Set set1;
    Set set2;


    initSet(&set1, 10);
    initSet(&set2, 10);

    addToSet(&set1, 1);
    addToSet(&set1, 3);
    addToSet(&set1, 7);
    addToSet(&set1, 1);

    addToSet(&set2, 1);
    addToSet(&set2, 8);
    addToSet(&set2, 6);
    addToSet(&set2, 3);

    Set union1 = unionOfSets(&set1, &set2);
    Set intersect1 = intersectionOfSets(&set1, &set2);
    Set difference1 = differenceOfSets(&set1, &set2);
    
    displaySet(&set1);
    displaySet(&set2);
    displaySet(&union1);
    displaySet(&intersect1);
    displaySet(&difference1);

    return 0;
}
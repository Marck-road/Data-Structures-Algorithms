#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next; 
}node;

typedef struct Tree{
    int root;
    node *list[10];
}Tree;

Tree* initTree();
void addNode(Tree** tree, int data);

int main(){
    Tree *tree = initTree();
     

    return 0;
}

Tree* initTree(){
    int i;

    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = -1;
    for(i=0; i<10; i++){
        tree->list[i] = NULL;
    }

    return tree;
}

void addNode(Tree** tree, int data){

    node *temp = (Tree *) malloc(sizeof(Tree));
    temp->data = data;
    temp->next = NULL;

    if((*tree)->root == -1){
        (*tree)->root = temp->data;
        (*tree)->list[data] = temp;
    }

}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

void insert(node **root, int num);
void display(node *root);
node*  findMin(node *root);
node* findMax(node *root);
bool isMember(node *root, int num);
void delete(node **root, int num);

int main(){

    node *root = NULL;
    node *min, *max;
    
    insert(&root, 12);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 9);
    insert(&root, 15);
    insert(&root, 13);
    insert(&root, 17);

    min = findMin(root);
    max = findMax(root);
    
    display(root);
    printf("\n");
    printf("Min = %d\n", min->data);
    printf("Max = %d\n", max->data);

    (isMember(root, 15)) ? printf("True\n") : printf("False\n");
    (isMember(root, 69)) ? printf("True\n") : printf("False\n");
    (isMember(root, 1)) ? printf("True\n") : printf("False\n");

    delete(&root, 7); 
    delete(&root, 15);
    delete(&root, 1);
    display(root);

    return 0;
}

void insert(node **root, int num){
    node* temp = (node *) malloc(sizeof(node));
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;

    if(temp != NULL){
        if(*root == NULL){
            *root = temp;
        } else if ((*root)->data > num){
            insert(&((*root)->left), num);
        } else if ((*root)->data < num){
            insert(&((*root)->right), num);
        }
    }
}

void display(node *root){
    if(root == NULL)
        return;

    display(root->left);
    printf("%d ", root->data);
    display(root->right);

}

bool isMember(node *root, int num){

    if(root == NULL)
        return false;
    
    if(root->data == num)
        return true;
    else if(root->data > num)
        return isMember(root->left, num);
    else 
        return isMember(root->right, num);

        //could be simplified into a for loop and a 
        //ternary operator

}

node* findMin(node *root){  
    if(root == NULL){
        printf("Empty tree\n");
        return root;
    }
    
    if(root->left == NULL)
        return root;

    return findMin(root->left);
}

node*  findMax(node *root){

    if(root == NULL){
        printf("Empty tree\n");
        return root;
    }
    
    if(root->right == NULL)
        return root;

    return findMax(root->right);

    //can be simplified into a for loop and ends 
    //if shit is null and then you stop
}

void delete(node **root, int num){
    if (*root == NULL){
        printf("Empty tree\n");
        return;
    }
        
    
    if(num < (*root)->data)
        delete(&((*root)->left), num);
    
    else if(num > (*root)->data)
        delete(&((*root)->right), num);

    else {   // Finally found the node:)
        if((*root)->left==NULL && (*root)->right == NULL){
            free(*root);
            *root = NULL;
        }
            

        else if((*root)->left != NULL && (*root)->right == NULL){
            node *temp = (*root);
            *root = (*root)->left;
            free(temp);
        }

        else if((*root)->right != NULL && (*root)->left == NULL){
            node *temp = *root;
            (*root) = (*root)->right;
            free(temp);
        }

        else{
            //2 choices, either find the smallest node in the right
            //or find the biggest in the left.
            node *temp = findMin(((*root))->right);
            (*root) ->data = temp ->data;
            delete(&((*root)->right), temp->data);
        }


    }

}
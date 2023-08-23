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
// /--------------------------------------/
node* balanceTree(node **root, int balanceFactor);
int balanceFactor(node *root);
int getHeight(node *root);
// /--------------------------------------/
void LL_Rotation(node **root);
void LR_Rotation(node **root);
void RR_Rotation(node **root);
void RL_Rotation(node **root);


int main(){

    node *root = NULL;
    node *min, *max;

    insert(&root, 40);
    insert(&root, 30);
    insert(&root, 50);
    insert(&root, 20);
    insert(&root, 35);
    insert(&root, 45);
    insert(&root, 60);
    insert(&root, 41);
    insert(&root, 46);
    insert(&root, 70);
    insert(&root, 42);
    
    printf("Final:");
    display(root);
    printf("\n");

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
    int balanceCheck;

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

        //Time for AVL Yay!!! i wanna fcking die
        //tngina ngno nag IT man ko oy
        balanceCheck = balanceFactor((*root));

        if(balanceCheck > 1 || balanceCheck < -1)
            (*root) = balanceTree(&((*root)), balanceCheck);
    }
}

void display(node *root){
    if(root == NULL)
        return;

    printf("%d ", root->data);
    display(root->left);
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
        //ternary operator but kapoy

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

node* findMax(node *root){

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
        if((*root)->left==NULL && (*root)->right == NULL){  //No Child
            free(*root);
            *root = NULL;
        }

        else if((*root)->left != NULL && (*root)->right == NULL){       //if left child only
            node *temp = (*root);
            *root = (*root)->left;
            free(temp);
        }

        else if((*root)->right != NULL && (*root)->left == NULL){       //if right child only
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

        int balanceCheck = balanceFactor((*root));

        if(balanceCheck > 1 || balanceCheck < -1)
            (*root) = balanceTree(&((*root)), balanceCheck);
    }

    
}

int balanceFactor(node *root){
    if(root == NULL)
        return 0;


    return getHeight(root->left) - getHeight(root->right);
}

int getHeight(node *root){
    int lheight, rheight, greater;
    
    if (root == NULL)
        return 0;
    else{
        lheight = getHeight(root->left);
        rheight = getHeight(root->right);

        greater = (lheight > rheight) ? lheight : rheight;

        return 1 + greater;
    }
}

node* balanceTree(node **root, int balFac){
    display((*root));
    if(balFac>=2){
        if(balanceFactor((*root)->left) > 0){
            LL_Rotation(&((*root)));
        } else{
            LR_Rotation(&((*root)));
        }   
    } else{
        if(balanceFactor((*root)->right) < 0){
            RR_Rotation(&((*root)));
        } else{
            RL_Rotation(&((*root)));
        }
    }
    
    printf("\nBalancing Factor: %d. Initializing display: ", balFac);
    display((*root));
    printf("\n");
    return *root;
}

void LL_Rotation(node **root){
    node *newRoot = (*root)->left;
    node *temp = newRoot->right;
    newRoot->right = (*root);
    newRoot->right->left = temp;

    (*root) = newRoot;
}

void RR_Rotation(node **root){
    node *newRoot = (*root)->right;
    node *temp = newRoot->left;
    newRoot->left = (*root);
    newRoot->left->right = temp;

    (*root) = newRoot;
}
void LR_Rotation(node **root){
    node *newRoot = (*root)->left->right;
    node *tempLeft = newRoot->left;
    node *tempRight = newRoot->right;
    
    newRoot->right = (*root);
    newRoot->left = newRoot->right->left;
    newRoot->left->right = tempLeft;
    newRoot->right->left = tempRight;


    (*root) = newRoot;
}


void RL_Rotation(node **root){
    node *newRoot = (*root)->right->left;
    node *tempLeft = newRoot->left;
    node *tempRight = newRoot->right;
    
    newRoot->left = (*root);
    newRoot->right = newRoot->left->right;
    newRoot->right->left = tempRight;
    newRoot->left->right = tempLeft;


    (*root) = newRoot;
}


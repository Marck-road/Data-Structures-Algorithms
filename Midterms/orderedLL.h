#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data[100];
	struct node *link;
}*LIST;

typedef char String[30];

void insert(LIST *L, char *str)
{
	LIST *trav, temp, insert;
		
	temp = (LIST) malloc(sizeof(struct node));
	strcpy(temp->data, str);
	temp->link = NULL;
	if(*L != NULL){
		for(trav = L; *trav != NULL && strcmp(str, (*trav)->data) != -1; trav = &(*trav)->link){}
		//Traverse to find out asa na node i put ang data
		insert = *trav;
		
		temp->link = insert;
	    *trav = temp;
	    
	} else{
		*L = temp;
	}
}
void show(LIST *L){
	
	LIST trav = *L;
	int nodeCount = 0;
	
    printf("Node (%d) : %s\n", nodeCount, trav->data);
    while(trav->link != NULL){
        trav = trav->link;
        nodeCount++;
        printf("Node (%d) : %s\n", nodeCount, trav->data);
    }
}

void deleteThis(LIST *L, char *str){
	
    LIST trav = *L, temp;
    
	if(strcmp(trav->data, str) == 0){
        temp = trav;
        *L = trav->link;
    }
    
    else{
    	for(trav = *L; trav->link != NULL && strcmp(trav->link->data, str) != 0; trav = trav->link){}
        
		if(trav->link != NULL){	
			temp = trav->link;
	        trav->link = trav->link->link;
		} else{
			temp = trav->link;
			trav->link = NULL;
		}
    }
    
    free(temp);
}

void edit(LIST *L, char *str, char *strReplace){
    
    LIST trav = *L;
    
    if(strcmp(trav->data, str) == 0){
		strcpy(trav->data, strReplace);
    }
    
    else{
       
        for(trav = *L; strcmp(trav->data, str) != 0 && trav->link != NULL; trav = trav->link){}
        strcpy(trav->data, strReplace);
        
    }
    
    printf("Data has successfully been updated.\n");
}


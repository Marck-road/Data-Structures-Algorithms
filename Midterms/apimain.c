#include <stdio.h>
#include <string.h>
#include "orderedLL.h"

void insert(LIST *L, char *str);
void show(LIST *L);
void deleteThis(LIST *L, char *str);
void edit(LIST *L, char *str, char *strReplace);


int main()
{ 
	char string[100], replace[100];
    int option, i;
	LIST L = NULL;
	char str[100];

	do{
	    printf("\n\nMenu\n ");
	    printf("1. Insert Node\n ");
	    printf("2. Show all Nodes\n ");
	    printf("3. Delete Node\n ");
	    printf("4. Edit Node\n ");
	    printf("5. Exit\n\n");
	    printf("Choose action: ");
	    scanf("%d",&option);
	
	    switch(option)
	    {
	        case 1:
				printf("Enter String: ");
				scanf("%s", string);
	            insert(&L, string);
				break;
	        case 2:
	            show(&L);	
	            break;
	        case 3:
	        	printf("Enter String to delete: ");
	        	fflush(stdin);
				scanf("%s", string);
	            deleteThis(&L, string);
	            break;
	        case 4:
				printf("Enter string to replace: ");
				scanf("%s", str);
				printf("Replace with: ");
				scanf("%s", replace);
	
	            edit(&L, str, replace);
	            break;
	        case 5:
	            return 0;
	    }
	} while(option != 5);

}

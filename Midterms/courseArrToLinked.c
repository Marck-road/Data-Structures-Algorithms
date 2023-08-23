#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 0XFF

typedef struct{
	char FName[24], MI, LName[16];
	unsigned int ID;
	char course[8];
	int yearLevel;
}studtype;

typedef struct node{
	studtype stud;
	struct node *link;
}*LinkedList;

typedef struct{
	studtype stud[SIZE];
	int count;
}ArrayList;

void transfer(LinkedList *head, ArrayList list, char selectCourse[]);
void purge(ArrayList *list, char selectCourse[]);
void display(LinkedList head);
void displayArr(ArrayList list);

int main(){
	ArrayList list;
	LinkedList head = NULL;
	int i, count, choice;
	char selectCourse[8];
	
	//Initializing all values to 0 or null
	memset(list.stud, 0, SIZE * sizeof(studtype));
	
	printf("Enter number of students: ");
	fflush(stdin);
	scanf("%d", &list.count);
	count = list.count;
	
	for(i=0; i<count; i++){
		
		printf("Student %d/%d\n", i+1,count);
		
		printf("Enter first name: ");
		fflush(stdin);
		scanf("%s", list.stud[i].FName);
		printf("Enter middle initial: ");
		fflush(stdin);
		scanf(" %c", &list.stud[i].MI);
		printf("Enter last name: ");
		fflush(stdin);
		scanf("%s", list.stud[i].LName);
		printf("Enter ID number: ");
		fflush(stdin);
		scanf("%u", &list.stud[i].ID);
		printf("Enter course: ");
		fflush(stdin);
		scanf("%s", list.stud[i].course);
		printf("Enter year level: ");
		fflush(stdin);
		scanf("%d", &list.stud[i].yearLevel);
		fflush(stdin);
		printf("\n");
	}	

	//Start of menu
	do{
		printf("Menu: \n");
		if(list.count <= 0)
			printf("[0] Display Array List [WARNING: EMPTY ARRAY]\n");
		else
			printf("[0] Display Array List\n");
		if(head == NULL)
			printf("[1] Display Linked List [WARNIG: EMPTY LINKED LIST]\n");
		else
		printf("[1] Display Linked List\n");
		printf("[2] Move Courses to Linked List\n");
		printf("[3] Exit\n");
		printf("Enter input: ");
		fflush(stdin);
		scanf("%d", &choice);
		
		switch(choice){
			case 0:
				displayArr(list);
				break;
			case 1:
				display(head);
				break;
			case 2:
				printf("Enter course of students to move: ");
				fflush(stdin);
				scanf("%s", selectCourse);
				transfer(&head, list, selectCourse);
				purge(&list, selectCourse);
				break;
			case 3:
				exit(1);
		}
		
	}while(choice != 3);
	
	
	displayArr(list); //list now displays properly

	
//	printf("\n List.count = %d\n", list.count);

}

void transfer(LinkedList *head, ArrayList list, char selectCourse[]){
	LinkedList current, temp;
	int i, flag=0;
	//	printf("Working %d\n", list.count);
	
	for(i=0; i<SIZE; i++){
	
		if(strcmp(selectCourse, list.stud[i].course) == 0){
			flag++;
			temp = (LinkedList)malloc(sizeof(struct node));
		
				//copying values
				strcpy(temp->stud.FName, list.stud[i].FName);
				temp->stud.MI = list.stud[i].MI;
				strcpy(temp->stud.LName, list.stud[i].LName);
				temp->stud.ID = list.stud[i].ID;
				strcpy(temp->stud.course, list.stud[i].course);
				temp->stud.yearLevel = list.stud[i].yearLevel;
				temp->link = NULL;
			
		//		printf("%s\n", list.stud[i].LName);
		//		printf("Working %d\n", list.stud[0].ID);
				
				//Arrranging
				current = *head;
				
				
				
//					printf("Working %d\n", i);
				//Adds the first value to the node
				if(*head == NULL){
					*head = temp;
					
				} else{
					
					while(current->link != NULL){
						current = current->link;
					}
					
					while(current != NULL){
						
						//Only checks the head if it is the same or not.
						if(strcmp(temp->stud.LName,current->stud.LName) == -1 && current->link != NULL){
							temp->link = *head;
							*head = temp;
							break;
						} else if(strcmp(temp->stud.LName,current->stud.LName) == -1 && strcmp(temp->stud.course,current->stud.course) == 0){
							temp->link = *head;
							*head = temp;
							break;
						} else if(current->link == NULL){
							current->link = temp;
							break;
						} 
						
						else{	
							if(strcmp(temp->stud.LName,current->link->stud.LName) == -1){
								temp->link = current->link;
								current->link = temp;
								break;
							}
							else if(strcmp(temp->stud.LName,current->link->stud.LName) == 0){
								temp->link = current->link;
								current->link = temp;
								break;
							}
				
						}
						current = current -> link;
					}
					
					
					
				}
			
		}
	}
	if(!flag)
		printf("Such course does not exist in data!!\n\n");
}

void purge(ArrayList *list, char selectCourse[]){
	int i;
	printf("\n");
	for(i=0; i<SIZE; i++){
		if(strcmp(selectCourse, list->stud[i].course) == 0){
			list->stud[i].FName[0] = '\0';
			list->stud[i].MI = '\0';
			list->stud[i].LName[0] = '\0';
			list->stud[i].ID = 0;
			list->stud[i].course[0] = '\0';
			list->stud[i].yearLevel = 0;
			list->count -= 1;
			printf("Successfully Deleted Array #[%d]...\n", i);
		}
	}
	printf("\n");
}

void displayArr(ArrayList list){
	int i, flag=0;
	printf("\nArray List: \n");
	printf("# of Elements: %d\n\n", list.count);
	
	for(i=0; i<SIZE; i++){
		if(list.stud[i].ID > 0){
			printf("First name: %s\n", list.stud[i].FName);
			printf("Middle initial: %c\n", list.stud[i].MI);
			printf("Last name: %s\n", list.stud[i].LName);
			printf("ID number: %u\n", list.stud[i].ID);
			printf("Course: %s\n", list.stud[i].course);
			printf("Year level: %d\n\n", list.stud[i].yearLevel);
			flag++;
		}
	}
	
	if(!flag)
		printf("Nothing left in the array!\n\n");
}

void display(LinkedList head){
	int flag = 0;
	LinkedList current = head;
	printf("\nLinked List: \n\n");
	while(current != NULL){
		printf("First name: %s\n", current->stud.FName);
		printf("Middle initial: %c\n", current->stud.MI);
		printf("Last name: %s\n", current->stud.LName);
		printf("ID number: %u\n", current->stud.ID);
		printf("Course: %s\n", current->stud.course);
		printf("Year level: %d\n\n", current->stud.yearLevel);
		flag++;
		current = current->link;
	}
	if(!flag)
		printf("Nothing inside the linked list!\n\n");
}

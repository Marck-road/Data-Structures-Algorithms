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

typedef struct element{
	studtype data;
	int next;
}element;

typedef struct dB{
	element info[30];
	int start;
	int available;
}dB;

void addStudent(ArrayList *list, char Fname[], char MI, char Lname[], unsigned int ID, char course[], int yearLevel); //DONE
void transfer(dB *cbData, ArrayList list, char selectCourse[]); 
void initialize(dB *cbData); //DONElectCourse[]);  //DONE
void displayCb(dB cbData, int next); //DONE
void displayArr(ArrayList list); //DONE

int main(){
	ArrayList list;
	dB cbData;
	
	int i, count, choice;
	char selectCourse[8];
	
	//Initializing all values to 0 or null
	memset(list.stud, 0, SIZE * sizeof(studtype));
	//Initializing all next of Cursor-Based List to -2 which signifies that that index is empty
	initialize(&cbData);
	
	list.count = 5;
	printf("Number of students: %d", list.count);
	
	addStudent(&list, "Tasha", 'L', "Pongos", 2123450, "BSIT", 2);
	addStudent(&list, "Dan", 'S', "Zabala", 21544352, "BSCS", 2);
	addStudent(&list, "Mark", 'M', "Calzada", 21100770, "BSIT", 2);
	addStudent(&list, "Eric", 'Z', "Panganiban", 2114320, "BSIT", 2);
	addStudent(&list, "Trish", 'M', "Doria", 21100662, "BSCS", 2);
	
	//Start of menu
	do{
		printf("Menu: \n");
		if(list.count <= 0)
			printf("[0] Display Array List [WARNING: EMPTY ARRAY]\n");
		else
			printf("[0] Display Array List\n");
		if(cbData.info[cbData.start].next == -2)
			printf("[1] Display Cursor-Based List [WARNIG: EMPTY LINKED LIST]\n");
		else
			printf("[1] Display Cursor-Based List\n");
		printf("[2] Move Courses to Cursor-Based List\n");
		printf("[3] Exit\n");
		printf("Enter input: ");
		fflush(stdin);
		scanf("%d", &choice);
		
		switch(choice){
			case 0:
				displayArr(list);
				break;
			case 1:
				displayCb(cbData, cbData.start);
				break;
			case 2:
				printf("Enter course of students to move: ");
				fflush(stdin);
				scanf("%s", selectCourse);
				transfer(&cbData, list, selectCourse);
				purge(&list, selectCourse);
				break;
			case 3:
				exit(1);
		}
		
	}while(choice != 3);
	
	displayArr(list); //list now displays properly
}

void addStudent(ArrayList *list, char Fname[], char MI, char Lname[], unsigned int ID, char course[], int yearLevel){
	
	strcpy(list.stud[list.count].FName, Fname);
	list.stud[list.count].MI = MI;
	strcpy(list.stud[list.count].LName, Lname);
	list.stud[list.count].ID = ID;
	strcpy(list.stud[list.count].course, course);
	list.stud[list.count].yearLevel = yearLevel;
	list.count++;
	
}

void initialize(dB *cbData){
	int i;
	
	for(i=0; i<SIZE; i++)						//Initializing all the indexes' to -2
		cbData->info[i].next = -2;				//which will represent every index that is 
												//still vacant
	cbData->start = 0;					//Initializes both start and avail to 0 since the list
	cbData->available = 0;				//is still practically empty at this point
}

void transfer(dB *cbData, ArrayList list, char selectCourse[]){
	int i, flag=0, cursorTrav;
	
	for(i=0; i<SIZE; i++){
		if(strcmp(selectCourse, list.stud[i].course) == 0){
			
			for(cursorTrav = cbData->start; strcmp(cbData->info[cursorTrav].data.LName, list.stud[i].LName) < 0; cursorTrav = cbData->info[cursorTrav].next){
				//a loop that stops if we reach a node where A < B so that it can be inserted after
			}
			
			flag++;
			
			memcpy(cbData->info[cbData->available].data, list.stud[i], sizeof(studtype));			//copying values
			cbData->info[cbData->available].next = cursorTrav;
			
			cbData->available+=1 ;
		}
	}
	if(!flag)
		printf("Such course does not exist in data!!\n\n");
	
	cbData->start = cbData->available;
}

void purge(ArrayList *list, char selectCourse[]){
	int i, x;
	printf("\n");
	
	for(i=0; i<SIZE; i++){
		if(strcmp(selectCourse, list->stud[i].course) == 0){
			
			for(x=i+1; x<SIZE; x++){
				memcpy(list->stud[i], list->stud[x], sizeof(studtype) * (SIZE-i-1));
			}
			
			list->count -= 1;
		}
	}
	printf("Successfully deleted specified courses from array!\n\n");\
}

void displayArr(ArrayList list){
	int i, flag=0;
	printf("\nArray List: \n");
	printf("# of Elements: %d\n\n", list.count);
	
	for(i=0; i<SIZE; i++){
		if(list.stud[i].ID > 0){
//			printf("First name: %s\n", list.stud[i].FName);
//			printf("Middle initial: %c\n", list.stud[i].MI);
//			printf("Last name: %s\n", list.stud[i].LName);
//			printf("ID number: %u\n", list.stud[i].ID);
//			printf("Course: %s\n", list.stud[i].course);
//			printf("Year level: %d\n\n", list.stud[i].yearLevel);
			
			printf("%s %c %s, %u, %s, %d\n", list.stud[i].FName, list.stud[i].MI, list.stud[i].LName, list.stud[i].ID, list.stud[i].course, list.stud[i].yearLevel);
			
			
			flag++;
		}
		printf("\n");
	}
	
	if(!flag)
		printf("Nothing left in the array!\n\n");
}

void displayCb(dB cbData, int next){
	
	if(cbData.info[next].next == -2){
		printf("Nothing inside database!\n");
		return;
	}
	
	printf("[%d] data: %d || next: %d\n", next, cbData->info[next].data, cbData->info[next].next);
	
	if(cbData.info[next].next == -1){
		printf("Available: %d\n", cbData.available);
		printf("Start: %d\n\n", cbData.start);
		
		return;
	} else{
		next = cbData.info[next].next;
		displayAll(cbData, next);
	}
}

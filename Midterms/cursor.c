#include <stdio.h>

typedef struct element{
	int data;
	int next;
}element;

typedef struct dB{
	element info[30];
	int start;
	int available;
}dB, *dBptr;

int menu();					//Menu
void addElement(dBptr dbptr);		//Add element to cursor based
void displayAll(dBptr dbptr, int next);		//Display all elements of cursor based
void initialize(dBptr dbptr);		//Initialize everything with -2. Explanation is found in function
void deleteElement(dBptr dbptr);	//deletes an element
void updateAvail(dBptr dbptr);	//Updates the first available space everytime changes are made
void makelines();			//make lines 
void makespace();			//makes space between inputs


int main(){
	int input=1;
	dB data;
	
	//dbptr refers to the whole thing
	dBptr dbptr = &data; 
	
	//Initializing everything to -2
	initialize(dbptr);
	
	while(input != 4){
		input = menu();
		switch(input){
			case 1:
				makespace();
				// system("cls");		//Adding Element
				addElement(dbptr);
				break;
			case 2:
				makespace();
				// system("cls");		//Deleting Element
				deleteElement(dbptr);
				break;
			case 3:
				// system("cls");
				makespace();
				makelines();		//Display all data
				printf("%23s\n", "Displaying Data");
				makelines();
				displayAll(dbptr, data.start);
				break;
				
			default:
				// system("cls");		//Wrong input
				printf("Invalid Input!\n");
				break;
		}
	}
}

int menu(){
	int input;
	makespace();
	makelines();
	printf("%17s\n", "Menu");
	makelines();
	printf("[1] Add Element\n");
	printf("[2] Delete Element\n");		//Menu
	printf("[3] Display Elements\n");
	printf("[4] Exit\n");
	makelines();
	printf("Enter input: ");
	fflush(stdin);
	scanf("%d", &input);
	
	return input;
}

void initialize(dBptr dbptr){
	int i;									//Initializing everything to nigative 2 because
	for(i = 0; i<30; i++){					//it will represent every single value that has
		dbptr->info[i].next = -2;			//a vacant value and signifies it is available
	}

	dbptr->start=0;					//Initializes both the start and avail to 0 since 
	dbptr->available=0;				//the list is basically still empty here
}

void addElement(dBptr dbptr){
	int element, i;
	int nextAvail;
	
	//Finds the previous one so that ang iyaha next ma change
	for(i=0; i<30; i++){
		if(dbptr->info[i].next == -1){
			dbptr->info[i].next = dbptr->available;
		}
	}
	
	printf("\n");
	makelines();
	printf("%22s\n", "Adding Element");
	makelines();
	//Adding Element
	printf("Enter element to add: ");
	fflush(stdin);
	scanf("%d", &dbptr->info[dbptr->available].data);	//puts the data in the next available spot
	dbptr->info[dbptr->available].next = -1;			//sets the data of that node to -1
														//since it is the latest added node and new end


	updateAvail(dbptr);
	
	printf("Successfully added element!\n");
}

void displayAll(dBptr dbptr, int next){
	int data;
	
	//Returns if there are nothiing inside
	if(dbptr->info[next].next == -2){		
		printf("Nothing inside database!\n");
		return;
	}

	printf("[%d] data: %d || next: %d\n", next, dbptr->info[next].data, dbptr->info[next].next);
	
	if(dbptr->info[next].next == -1){
		makelines();
		printf("Available: %d\n", dbptr->available);
		printf("Start: %d\n\n", dbptr->start);
		
		return;
	} else{
		next = dbptr->info[next].next;
		displayAll(dbptr, next);
	}

}


void deleteElement(dBptr dbptr){
	int i, n, temp, flag = 0;
	int trav=dbptr->start;
	int null, nextAvail;

	makelines();
	printf("%22s\n", "Delete Element");
	makelines();

	//Returns if there are nothing inside
	if(dbptr->info[trav].next == -2){
		printf("There is nothing to delete!\n");
		return;
	}

	printf("Enter an element to delete: ");
	fflush(stdin);
	scanf("%d", &n);
	
	//If head deleted
	if(n == dbptr->info[dbptr->start].data){

		temp = dbptr->start;

		if(dbptr->info[dbptr->start].next == -1)		//if the head is only value
			dbptr->start = temp;
		else
			dbptr->start = dbptr->info[dbptr->start].next;		//if the head is not the only value
		
		dbptr->available = temp;
		dbptr->info[temp].data = null;			
		dbptr->info[temp].next = -2;		// removes the data now here

		printf("Successfully Deleted First node!\n\n");

		updateAvail(dbptr);		//not needed but yea for double sure

		return;
	}

	while(dbptr->info[trav].next != -1){
		if(dbptr->info[dbptr->info[trav].next].data == n){//this looks for scanned data to be deleted
			flag++;
			temp = dbptr->info[trav].next;

			if(dbptr->info[dbptr->info[trav].next].next == -1)//checks if the selected data to be deleted is the last data
				dbptr->info[trav].next = -1;
			else{
				dbptr->info[trav].next = dbptr->info[dbptr->info[trav].next].next;	//if the last one is not the last
			}
				
			dbptr->info[temp].data = null;	//deletes the index now
			dbptr->info[temp].next = -2;

			updateAvail(dbptr);
			
			printf("Successfully Deleted!\n\n");
			return;
		}
		
		trav = dbptr->info[trav].next;
	}

	if(!flag)
		printf("Data does not exist in database!\n");

}

void makelines(){
	int i;
	for(i=0; i<30; i++){
		printf("-");
	}
		
	printf("\n");
	
}

void updateAvail(dBptr dbptr){
	int nextAvail;
	int i;
	//Updates Next available space by finding first instance of -2
	for(i=0; i<30; i++){
		if(dbptr->info[i].next == -2){
			nextAvail = i;
			break;
		}
	}

	dbptr->available = nextAvail;
}

void makespace(){
	int i;
	for(i=0; i<2; i++)
		printf("\n");

}





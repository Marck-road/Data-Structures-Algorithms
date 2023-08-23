/******************************************************************
 * Project Name:  List, Set and Dictionary                        *
 * Programmer  :  Put your Name here                              *
 * Date Completed: March 25, 2023                                 *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_SIZE     0XC    //size of Virtual Heap
#define OPEN_DSIZE  0XA    //size of Open Hash Table
#define CLOSE_DSIZE 0XC    //size of Close Hash Table
#define LIST_SIZE   0XF    //size of the array implementation of List
/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {  
	char name[24];          // Chocolate name  
 	int  weight;            // Chocolate weight in grams  
}chocoDesc;
 
typedef struct {
   char prodID[8];          //  product ID uniquely identifies the products; EMPTY or DELETED   
  	chocoDesc prodDesc;     //  product description 
 	float prodPrice;        //  product price 
  	int prodQty;            //  product count or quantity   
}product;                   //  product record  

typedef struct {
	product elem;            
	int next;                
}prodNode;                 // Product node, used in cursor-based implementation of Set  


/************************
 * Virtual Heap         *
 ************************/
typedef struct {
   prodNode VH_node[VH_SIZE];
   int avail;
}VHeap;

/******************************************
 * Cursor-Based Implementation of SET     *
 ******************************************/
typedef struct {
   int elemIndex;        // index of the 1st element in the set  
   int count;            // holds the actual number of elements in the set  
   VHeap *VHptr;         // holds the pointer to the virtual heap  
}cursorSet;            

/********************************************
 * Open Hashing Implementation of Dictionary*
 ********************************************/
typedef struct {
	int header[OPEN_DSIZE];  // array of sets   
	int count;               // total number of elements in the dictionary  
	VHeap *dicVHptr;         // holds the pointer to the virtual heap  
}openDic;


/**********************************************
 * Closed Hashing with 2 pass loading          *
 **********************************************/
#define EMPTY   "empty"     // stored in product ID field  
#define DELETED  "del"      // stored in product ID field * 
 
typedef product closeDic[CLOSE_DSIZE];   //Definition of the closed hash dictionary
  
typedef struct {
	product prod[LIST_SIZE];
	int last;   //index of the last element; -1 if list is empty	
}List;



/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #1 ---
void initVHeap(VHeap *VH);
cursorSet initCursorSet(VHeap *VH);
void displayVHeap(VHeap V);
void displaySet(cursorSet A);

//---Problem #2 ---
int mallocInVHeap(VHeap *VH);
void insertSorted(cursorSet *A, product P);
void populateSet(cursorSet *A);

//---Problem #3 ---
int openHash(char *IDen);                
openDic initOpenDict(VHeap *VH);
openDic convertToOpenDict(cursorSet *A);
void displayOpenDict(openDic D);

//---Problem #4 ---
void freeInVHeap(VHeap *VH, int ndx);
void deleteDict(openDic *D, char *IDen);

//---Problem #5 ---
int closeHash(char *ID);
void initCloseDict(closeDic CD);
closeDic * convertToCloseDict(openDic *D);	
void displayCloseDict(closeDic CD);


 
/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *                                                                                  *
 ***********************************************************************************/
 int main( ) 
 {	
 /*---------------------------------------------------------------------------------
 * 	Problem #1 ::  1) Initializes the virtual heap and the cursor Set             *
 *                 2) Displays the contents  virtual heap and cursor Set          *
 *--------------------------------------------------------------------------------*/
 	printf("\n\n\nProblem #1:: "); 
 	printf("\n------------");
 	//Declare variables needed for Problem #1
    VHeap myHeap;
    cursorSet myCursor;

	
 	//Function Calls for Problem #1
    initVHeap(&myHeap);
    myCursor = initCursorSet(&myHeap);
    
    displayVHeap(myHeap);
    displaySet(myCursor);

/*---------------------------------------------------------------------------------
 * 	Problem #2 ::  1) Populates the Cursor set which is sorted in ascending order *
 *                    according to ID                                             *
 *                 2) Displays the Cursor set                                     * 
 *--------------------------------------------------------------------------------*/	 
 	printf("\n\n\nProblem #2:: "); 
 	printf("\n------------");
	//Declare variables needed for Problem #2
 	 
	
 	//Function Calls for Problem #2

    populateSet(&myCursor);
    displayVHeap(myHeap);

    displaySet(myCursor);

	// int mallocInVHeap(VHeap *VH);
    // void insertSorted(cursorSet *A, product P);

/*---------------------------------------------------------------------------------
 * 	Problem #3 ::  1) Converts the Cursor set into an Open Hash Dictionary        *      
 *                 2) Displays the Open Hash Dictionary                           *
 *                 3) Displays the empty Cursor set.                              * 
 *--------------------------------------------------------------------------------*/	
	printf("\n\n\nProblem #3:: "); 
 	printf("\n------------");
	//Declare variables needed for Problem #3
 	openDic myDick;
	
 	//Function Calls for Problem #3             
	myDick = convertToOpenDict(&myCursor);
	// printf("%d", myDick.count);
	displayOpenDict(myDick);

/*---------------------------------------------------------------------------------
 * 	Problem #4 ::  1) Perform 3 delete operations on the Open Hash Dictionary     *
 *                 2) Displays the Open Hash Dictionary                           *
 *                 3) Displays the Virtual Heap                                   * 
 *--------------------------------------------------------------------------------*/	
 	printf("\n\n\nProblem #4:: "); 
 	printf("\n------------");	
 //Declare variables needed for Problem #4
    char delete01[] = "1703";
    char delete02[] = "1358";    
	char delete03[] = "1601";
	
 
//Function Calls for Problem #4	    
    
    

/*------------------------------------------------------------------------------------
 * 	Problem #5 :: 1) Converts the Open Hash Dictionary into a Closed Hash Dictionary *
 *                2) Displays the Closed Hash Dictionary                             * 
 *                3) Displays the virtual heap                                       *
 *---------------------------------------------------------------------------------*/	
	printf("\n\n\nProblem #5:: ");
    printf("\n------------");
    //Declare variables needed for Problem #5
    
    
    //Function Calls for Problem #5
	 
	

	return 0;
}

/************************************************************
 *  Problem 1:: Function Definitions                          *
 ************************************************************/
 void initVHeap(VHeap *V)
 {
    int i;

    for(i=VH_SIZE; i>=0; --i){
        V->VH_node[i].next = i-1;
        strcpy(V->VH_node[i].elem.prodID, "    ");
    }
    
    V->avail = VH_SIZE-1;
 }

cursorSet initCursorSet(VHeap *VH)
{
    cursorSet newCursor;

    newCursor.VHptr = VH;
    newCursor.count = 0;
    newCursor.elemIndex = VH->avail;

    return newCursor;
}

void displayVHeap(VHeap V)
{
	//Variable Declaration here
	int i;

    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  ::  %d", V.avail);       //Complete this statement
	printf("\nVHeap Address    ::  %p", &V);       //Complete this statemet
	
    printf("\n\n%10s", "Index");
    printf("%10s", "Prod ID");
    printf("%15s", "Next Field");
	printf("\n%10s%10s%15s", "-----", "-------","----------");	
     
    //Write your code here 

    for(i=0; i<VH_SIZE; i++){
        printf("\n%10d", i);
        printf("%10s", V.VH_node[i].elem.prodID);
        printf("%15d", V.VH_node[i].next);
    }

	 
	 

	printf("\n\n"); system("Pause");
}

void displaySet(cursorSet A)
{
	int x=0, i;
	product p;
	
	printf("\n\nDetails of the Set :: ");
	printf("\n---------------------");
	printf("\nNo. of elements ::  %d", A.count);      //Complete this code
	printf("\n\n%-7s", "ID");
	printf("%-12s","Choco Name");
	printf("%-15s","Choco Weight");
	printf("%-10s","VHeap Index");
	printf("\n%-7s%-12s%-15s%-10s", "--", "----------", "------------", "-----------");

	//Write your code here
	for(i=A.elemIndex; x<A.count; i = A.VHptr->VH_node[i].next){
        printf("\n%-7s", A.VHptr->VH_node[i].elem.prodID);
        printf("%-12s",A.VHptr->VH_node[i].elem.prodDesc.name);
        printf("%-15d",A.VHptr->VH_node[i].elem.prodDesc.weight);
        printf("%-10d", i);
		x++;
    }
	 

	printf("\n\n"); system("Pause");	
}


/************************************************************
 *  Problem 2:: Function Definitions                         *
 ************************************************************/
int mallocInVHeap(VHeap *VH)
{
//	VH->VH_node[VH->avail] = NULL;
	
	return VH->avail;
}


void insertSorted(cursorSet *A, product P)
{
    int i, flag=0, temp, x=0;


    if(A->count > VH_SIZE-1){
        printf("\nNo Available Space. Product with ID: %s cannot be inserted.", P.prodID);
        return;
    }
    
    for(i=0; i<A->count; i++){
        if(strcmp(P.prodID, A->VHptr->VH_node[i].elem.prodID) == 0){
            printf("\nProduct with ID %s already exists in the set.", P.prodID);
            return;
        }
    }
	
    //putting in Virtual Heap.
    A->VHptr->VH_node[A->VHptr->avail].elem = P;

	//if head is empty
    if(A->count == 0){
    	A->VHptr->VH_node[A->VHptr->avail].elem = P;
	}

	//if head is bigger than new word and count <= 2
	else if(strcmp(P.prodID, A->VHptr->VH_node[A->elemIndex].elem.prodID) == -1 && A->count<=2){
		A->VHptr->VH_node[A->VHptr->avail].next = A->elemIndex;
		A->elemIndex = A->VHptr->avail;
	}

	//if head is bigger than new word and count > 2
	else if(strcmp(P.prodID, A->VHptr->VH_node[A->elemIndex].elem.prodID) == -1){
    	temp = A->VHptr->VH_node[A->VHptr->avail].next;
        A->VHptr->VH_node[A->VHptr->avail].next = A->elemIndex;
        A->VHptr->VH_node[A->elemIndex].next = temp;
		A->elemIndex = A->VHptr->avail;
    }else{
        for(i=A->elemIndex; x<=A->count-1; i = A->VHptr->VH_node[i].next){
			if(strcmp(P.prodID, A->VHptr->VH_node[A->VHptr->VH_node[i].next].elem.prodID) != 1){
				flag++;
				break;
			}
			x++;
		}

		if(!flag){
			A->VHptr->VH_node[i].next = A->VHptr->avail;	
		}

		else{
			A->VHptr->VH_node[A->VHptr->avail].next = A->VHptr->VH_node[i].next;		
			A->VHptr->VH_node[i].next = A->VHptr->avail;	
		}
    }

    A->VHptr->avail--;
    A->count++;



	
	// for(y = A->elemIndex; z<=A->count-1; y= A->VHptr->VH_node[y].next){
	// 	printf("\n%-7s", A->VHptr->VH_node[y].elem.prodID);
    //     printf("%-12s",A->VHptr->VH_node[y].elem.prodDesc.name);
    //     printf("%-15d",A->VHptr->VH_node[y].elem.prodDesc.weight);
    //     printf("%-10d", y);
    //     z++;
	// }
	// printf("\n\nDone Pass\n");

}

void populateSet(cursorSet *A)
{
	const int COUNT = 15;
	product data[] = { 	{"1701", {"Toblerone", 135}, 150.75, 20},
						{"1356", {"Ferrero", 200}, 250.75, 85},
						{"1109", {"Patchi", 50}, 99.75, 35},
						{"1550", {"Cadbury", 120}, 200.00, 30},
						{"1807", {"Mars", 100}, 150.75, 20},
						{"1201", {"Kitkat", 50}, 97.75, 40},
						{"1450", {"Ferrero", 100},150.50, 50},
						{"1701", {"Toblerone", 50}, 90.75, 80},
						{"1601", {"Meiji", 75}, 75.50, 60},
						{"1310", {"Nestle", 100}, 124.50, 70},
						{"1807", {"Valor", 120}, 149.50, 90},
						{"1455", {"Tango", 75}, 49.50, 100},
						{"1703", {"Toblerone", 100}, 125.75, 60},
						{"1284", {"Lindt", 100}, 250.75, 15},
						{"1688", {"Guylian", 50}, 99.75, 35},
					
		              };
    //Inserts each element of the array to the cursor set
    //Write your code here!!
    int i;

    for(i=0; i<COUNT; i++){

        insertSorted(A, data[i]);

    }


}



/************************************************************
 *  Problem 3:: Function Definitions                        *
 ************************************************************/
int openHash(char * prodID)               
{ 

	int temp;
	int hash=0, i;

	temp = atoi(prodID);


	for(i = temp; i>0; i/=10){
		hash += i % 10; 
	}


	if(hash >= OPEN_DSIZE)
		hash -= OPEN_DSIZE;

		// printf("\n%d || %d\n", temp, hash);

	return hash;

}


openDic initOpenDict(VHeap *VH)
{
	openDic myDick;
	VHeap *newheap = VH;

	int i;
	myDick.count = 0;
	myDick.dicVHptr = newheap;

	for(i=0; i<OPEN_DSIZE; i++)
		myDick.header[i] = -1;

	return myDick;
}

openDic convertToOpenDict(cursorSet *A)
{
	openDic myDick;
	int i, x, y, placeholderX, placeholderY;
	int hash, temp;

	myDick = initOpenDict(A->VHptr);

	//copying
	for(i=0; i<VH_SIZE; i++){
		
		myDick.dicVHptr->VH_node[i].next = -1;
		hash = openHash(A->VHptr->VH_node[i].elem.prodID);

		printf("%s %d \n", A->VHptr->VH_node[i].elem.prodID, hash);
		if(myDick.header[hash] == -1){
			myDick.header[hash] = i;
		} else{
			for(x=myDick.header[hash]; A->VHptr->VH_node[x].next != -1; x = A->VHptr->VH_node[x].next){}
			myDick.dicVHptr->VH_node[x].next = i;
		}
		myDick.count++;
	}

	//Sorting
	displayVHeap(*myDick.dicVHptr);


	// for(i=0; i<OPEN_DSIZE; i++){
	// 	//makes sure that index has values
	// 	if(myDick.header[i] != -1){
	// 		for(x = myDick.header[myDick.header[i]]; A->VHptr->VH_node[x].next != -1; x = A->VHptr->VH_node[x].next){
	// 			for(y = myDick.dicVHptr->VH_node[x].next; A->VHptr->VH_node[y].next != -1; y = myDick.dicVHptr->VH_node[y].next){
	// 				if(strcmp(myDick.dicVHptr->VH_node[y].elem.prodID, myDick.dicVHptr->VH_node[x].elem.prodID) == -1){
	// 					printf("Hi x: %d, y: %d", x, y);

	// 					if(x == myDick.header[myDick.header[i]]){	//if it is bigger than first index
	// 					printf("Work1");
	// 						temp = myDick.dicVHptr->VH_node[y].next;
	// 						myDick.header[i] = y;
	// 						myDick.dicVHptr->VH_node[y].next = x;
	// 						myDick.dicVHptr->VH_node[x].next = temp; 
	// 					}

	// 					else if(x == placeholderY){
	// 						printf("Work2 %d %d %d", placeholderX, y, x);

	// 						myDick.dicVHptr->VH_node[placeholderX].next = y;
	// 						temp = myDick.dicVHptr->VH_node[y].next;
	// 						myDick.dicVHptr->VH_node[y].next = x;
	// 						myDick.dicVHptr->VH_node[x].next = temp;
	// 					}

	// 					else{

	// 						// printf("Work3 %d %d %d", placeholderX, y, x);
	// 						myDick.dicVHptr->VH_node[placeholderX].next = y;
	// 						temp = myDick.dicVHptr->VH_node[y].next;
	// 						myDick.dicVHptr->VH_node[y].next = myDick.dicVHptr->VH_node[x].next;
	// 						myDick.dicVHptr->VH_node[x].next = temp;
	// 						myDick.dicVHptr->VH_node[placeholderY].next = x;

	// 					}

	// 					printf("finish\n");
	// 					break;

	// 				}
	// 				placeholderY = y;
	// 			}
	// 			placeholderX = x;
	// 		}
	// 	}
	// 	printf("finished %d \n", i);
	// }

	//deleting
	A->count = 0;
	A->elemIndex = -1;
	return myDick;
}




void displayOpenDict(openDic D)
{
	//Variable declaration here 
	int i, x;

	printf("\n\nDetails of the Open Hash Dictionary:: ");
	printf("\n-------------------------------------");
	
	printf("\nNo. of elements :: %d", D.count);
	printf("\n\n%-7s", "GROUPS");
	printf("%15s","ID Numbers");
	printf("\n%-7s%15s", "------","----------");
	
	//Write your code here
	for(i=0; i<OPEN_DSIZE; i++){
		printf("\nGroup[%d] :: ", i);
		
		for(x = D.header[i]; D.dicVHptr->VH_node[x].next != -1; x = D.dicVHptr->VH_node[x].next){
			printf("%s\t", D.dicVHptr->VH_node[x].elem.prodID);
		}
		printf("\n");
	}

    printf("\n\n"); system("Pause");	
}


/************************************************************
 *  Problem 4:: Function Definitions                        *
 ************************************************************/
void freeInVHeap(VHeap *VH, int ndx)
{
	 
}

void deleteDict(openDic *D, char *IDen)
{
 
}


 /************************************************************
 *  Problem 5:: Function Definitions                        *
 ************************************************************/
int closeHash(char *ID)
{
     
}



void initCloseDict(closeDic CD)
{
	 

}
 
closeDic * convertToCloseDict(openDic *D)
{
    
}	

void displayCloseDict(closeDic CD)
{
 	//Variable declaration here
 	
 	
	printf("\n\nDetails of Closed Hash Dictionary :: ");
	printf("\n-------------------------------------");
	printf("\n\n%-6s", "Index");
	printf("%-10s", "ChocoID");
	printf("%-15s", "Choco Name");
	printf("\n%-6s%-10s%-15s", "-----", "-------", "----------"); 
	
	//Write your code here
	 
	
	printf("\n\n"); system("Pause");
 
}
 


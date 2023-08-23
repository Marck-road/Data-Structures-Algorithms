#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char String[20];

typedef struct line{
	String word;
}line;

typedef struct page{
	line value[30];
}page;

typedef struct Dictionary{
	page value[26];
}Dictionary;

void retrieve();
int encrypt(String value, int size);
void add();

int main(){
	
	int input;
	
	do{
		printf("Menu: \n");
		printf("[1] Add \n");
		printf("[2] Retrieve: \n");
		printf("[3] Exit: \n");
		printf("Input: ");
		scanf("%d", &input);
	
		switch(input){
		case 1:
			add();
			break;
		case 2:
			retrieve();
			break;
		case 3:
			exit(1);
			break;
		default:
			printf("Invalid input!\n");
			break;
		}	
		printf("\n");
	} while(input !=3);
	
	return 0;
}

void add(){
	String value;
	int page, key;
	Dictionary dictionary;
	
	printf("Enter a string to put in the dictionary: ");
	scanf("%s", &value);
	
	page = toupper(value[0]) - 64;
	key = encrypt(value, strlen(value));
	
	strcpy(dictionary.value[page].value[key].word, value);
	
}

void retrieve(){
	String value;
	int page, key;
	Dictionary dictionary;
	
	printf("Enter a string to find in the dictionary: ");
	scanf("%s", &value);
	page = toupper(value[0] - 64);
	key = encrypt(value, strlen(value));
	
	if(dictionary.value[page].value[key].word[0] == '\0')
		printf("The word %s does not exist in dictionary!\n", value);
	
	else
		printf("The word %s is found in page %d with unique key %d!\n", dictionary.value[page].value[key].word, page, key);
	
}

int encrypt(String value, int size){
	int i, key=0;
	
	for(i=0; i<size; i++){
		key+=(toupper(value[i])-64);
	}
	
	return key;
}




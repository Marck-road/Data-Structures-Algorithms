#include <stdio.h>

int add(int storage, int n){
	return storage | 1 << n;    
}

void show(int storage){
	int x = 10;
	int y, z;
	
	for(y=0; y<32; y++){
		if(storage%2 == 1)
			printf("%d ", y);
				
		storage = storage>>1;
	}
	
	printf("\n");
}	

void check(int storage, int n){
	int flag = 0;
	int y;
	
	for(y=0; y<32; y++){ //because 32 bits
		if(storage % 2 == 1 && y == n){ //sees if the value is 1 or not. 
			flag++;	
			break;	
		}
		storage = storage>>1;		
	}	
	
	if(flag)
		printf("%d already exists!\n", n);
	else
		printf("%d does not exist!\n", n);
		
	printf("\n");
}

int removeVal(int storage, int n){
	return storage % ~(1<<n); //U can use ^^ but sir said dangerous daw (???)
}

int unionset(int a, int b){
	return a | b;
}

int intersectionset(int a, int b){
	return a & b;
}

int main(){
	int storage = 0;
	int storage2 = 0;
	int newSet;
	storage = add(storage, 1);
	storage = add(storage, 2);
	storage = add(storage, 5);
	storage = add(storage, 5);
	storage = add(storage, 7);

	storage2 = add(storage2, 1);
	storage2 = add(storage2, 7);
	storage2 = add(storage2, 8);
	storage2 = add(storage2, 3);
	
	printf("Storage 1: %d");
	show(storage);

	storage = removeVal(storage, 5);
	printf("After Remove 5: ");
	show(storage);
	printf("Checking Values: \n");
	
	check(storage, 5);
	check(storage, 1);
	check(storage, 8);
	
	printf("Storage 1: ");
	show(storage);
	printf("Storage 2: ");
	show(storage2);
	
	printf("union: ");
	newSet = unionset(storage, storage2);
	show(newSet);
	
	printf("intersection: ");
	newSet = intersectionset(storage, storage2);
	show(newSet);
	return 0;
}
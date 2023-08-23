#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[30][5];

void pop(char *ptr);

int main(){
    String arr;
    int count=0;
   
    int first, second, answer;
    char operation;
    char null;

    while(arr[count-1][0] != '='){
        
		printf("Enter an element: ");
    	
        scanf("%s", &arr[count][0]);
       
		if(arr[count][0] == '=')
        	break;
		
		else if(arr[count][0] == ')'){
            arr[count][0] = null;
            count--;
            second = atoi(&arr[count][0]);
            arr[count][0] = null;
            count--;
            operation = arr[count][0];
            arr[count][0] = null;
            count--;
            first = atoi(&arr[count][0]);
            arr[count][0] = null;
            count--;
            arr[count][0] = null;
                
        	
            if(operation == '+'){
            	answer = first + second;
            	itoa(answer, &arr[count][0], 10);
			}
                
            else if (operation == '-'){
            	answer = first - second;
            	itoa(answer, &arr[count][0], 10);
			}
            else if (operation == '*'){
            	answer = first * second;
            	itoa(answer, &arr[count][0], 10);
			}
            else if (operation == '/'){
            	answer = first / second;
            	itoa(answer, &arr[count][0], 10);
			}
                
        } 
        
        count++;  
    }
    arr[count][0]=null;
    
    if(arr[1][0] != '\0'){
    	operation = arr[1][0];
    	second = atoi(&arr[2][0]);
    	first = atoi(&arr[0][0]);
    	
    	arr[2][0] = null;
    	arr[1][0] = null;
    	
		if(operation == '+'){
            	answer = first + second;
            	itoa(answer, &arr[0][0], 10);
		}
                
		else if (operation == '-'){
			answer = first - second;
			itoa(answer, &arr[0][0], 10);
		}
		else if (operation == '*'){
			answer = first * second;
			itoa(answer, &arr[0][0], 10);
		}
		else if (operation == '/'){
			answer = first / second;
			itoa(answer, &arr[0][0], 10);
		}

	}
    
    printf("%s", arr);
}



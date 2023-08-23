/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[30] = "1357";
    char str2[30] = "1550";

    printf("Hello World %d", strcmp(str1, str2));
    int add=0, i;
    for(i=0; i<strlen(str1); i++){
        add+=str1[i];
        printf("%d\n", add);
    }

    return 0;
}

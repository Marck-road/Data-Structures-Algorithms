#include <stdio.h>
#include <stdlib.h>
#define MAX 15
#define root -1
#define EMPTY -2

typedef int Tree[MAX];

void INITIALIZE(Tree T);
void CREATE1(int v, int *T1);
void CREATE2(int v, int *T1, int *T2);
void CREATE3(int v, int *T1, int *T2, int *T3);
void display(Tree T);
int PARENT(int n, Tree T);
int LABEL(int n, Tree T);
int ROOT(Tree T);

int main()
{
	Tree T;

	INITIALIZE(T);
	// create tree/root 8 with child 0
	CREATE1(8, T+0);
	// create tree/root 5 with children 1, 8, 11
	CREATE3(5, T+1, T+8, T+11);
    // create tree/root 2 with child 9
	CREATE1(2, T+9);
	// create tree/root 10 with children 5, 2
	CREATE2(10, T+5, T+2);
	// create tree/root 6 with children 7, 10
	CREATE2(6, T+7, T+10);
	// establish root without proper ancestor
	T[6] = root;
	display(T);
    printf("Parent of node 5: %d\n", PARENT(5, T));
    printf("Parent of node 6: %d\n", PARENT(6, T));
    // printf("Label of node 2: %d\n", LABEL(2, T));
    // printf("Label of node 9: %d\n", LABEL(9, T));
    printf("Root: %d\n", ROOT(T));

	return 0;
}

void INITIALIZE(Tree T)
{
	int idx;

	for (idx = 0; idx < MAX; idx++){
		T[idx] = EMPTY;
	}
}

void CREATE1(int v, int *T1)
{
	*T1 = v;
}

void CREATE2(int v, int *T1, int *T2)
{
	*T1 = *T2 = v;
}

void CREATE3(int v, int *T1, int *T2, int *T3)
{
	*T1 = *T2 = *T3 = v;
}

void display(Tree T)
{
	int idx;

	for (idx = 0; idx < MAX; idx++){
		printf("T[%d] = %d\n", idx, T[idx]);
	}
}

int PARENT(int n, Tree T)
{
	return T[n] == -1 ? '^' : T[n];
}

int LABEL(int n, Tree T)
{
    return T[n];
}

int ROOT(Tree T)
{
    int idx;

    for (idx = 0; T[idx] != root; idx++){}

    return idx;
}
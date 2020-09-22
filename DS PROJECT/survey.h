#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"

typedef struct stack
{	
	char *arr;
	int top;
	
}STACK;

int getche();

STACK *createStack(int );	

void push(STACK  *, char );	//Function to add an item to stack and increases top by 1

int isempty(STACK * );	//Stack is empty when top is equal to -1

char pop(STACK * );	   //Function to remove an item from stack and decreases top by 1

char peek(STACK * );	//Function to return the top from stack without removing it

void display(STACK *);		//Print all the stack elements

int result(STACK * ,STACK * );	//Compare the two stack and produce the result



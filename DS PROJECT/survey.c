#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include "survey.h"


int getche()
{
        struct termios t;
        int c;

	tcgetattr(0,&t);
        t.c_lflag&=~ICANON;
        tcsetattr(0,TCSANOW,&t);
        fflush(stdout);
        c=getchar();
        t.c_lflag|=ICANON;
        tcsetattr(0,TCSANOW,&t);
        return c;
}


STACK *createStack(int size)
{
	STACK *stack = malloc(sizeof(STACK));            //allocating the memory for stack
	stack->top = -1;
	stack->arr = (char*)malloc(sizeof(char)*size);                //allocating  the memory for char array dynamically
	return stack;
}


void push(STACK  *st,char c)
{
	st->top++;
	st->arr[st->top] = c;                  //insert the element to the stack 
}


int isempty(STACK *st)
{
	if(st->top == -1)
		return 1;
		
	else
		return 0;
}


char pop(STACK *st)
{
	char item = st->arr[st->top];        //remove the top element from the stack
	st->top--;
	return item;
}


char peek(STACK *st)
{
	if(!isempty(st))
		return(st->arr[st->top]);                  //get the top element of the stack without removing it
}


void display(STACK *st)
{
	int i;
	if(isempty(st))
		printf("Stack is empty\n");
	else
	{
		for(i=st->top; i>=0; i--)
			printf("%c ",st->arr[i]);
	}
}


int result(STACK *s1,STACK *s2)
{
	int total = 0;
	pop(s2);                 
	while( !isempty(s1) && !isempty(s2) )
       {
         if( peek(s1) != peek(s2) ) 	//compare the top elements
          {
          	pop(s1);
          	pop(s2);
          }
          else
          {
          	total++;		//if the answer is correct then increment the count
          	pop(s1);
          	pop(s2);     
          }
      }
    return total;
}

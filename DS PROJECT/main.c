#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include "survey.h"

int main()
{
	STACK *st  = createStack(20);	//creating a stack for 20 elements
	FILE *fp = fopen("question.txt","r");		//open the question file
	
	STACK *at = createStack(20);		
	FILE *fp1 = fopen("ans.txt","r");	//open the answer file
	char ch;
	int count = 0;
	
	if(fp1==NULL)		//check if the file exists
	{
		printf("Failed to open the file\n");
		exit(0);
	}
	else
	{
		while((ch=fgetc(fp1))!=EOF && (ch!='\n'))		//read the contents of the file char by char until new line or eof is reached
		{
			push(at,ch);		//inserting elements in the stack
		}
	}
	
	char c;
	char line[500];

	if(fp==NULL)
	{
		printf("Failed to open the file\n");
		exit(0);
	}
	else
	{	
	while(fgets(line,500,fp))		//read line by line from question file to display the questions
		{				
		printf("\n%s\n",line);
		printf("\nPlease enter your answer (A,B,C,D) or 's' to leave the question\n");
		c = getche();	
		if(c=='A' || c=='B' || c=='C' || c=='D')	
			{	
				push(st,c);
				printf("\nYour ans is : %c",c);
			}
		else if(c=='S')
			{
				push(st,c);		
			}
			else
			{
				printf("\nEnter a valid entry (A,B,C,D)\n");
				c = getche();
				if(c=='A' || c=='B' || c=='C' || c=='D')
					{
					push(st,c);
					printf("\nYour ans is : %c",c);
					}			
			}
		}
		printf("\n");
	}
	display(st);
	printf("\nYour total score is : %d",result(st,at));	//Generate the final score
	fclose(fp);	//close the file
	fclose(fp1);	
	return 0;
}

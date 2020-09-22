Prog : main.o survey.o 
	gcc -o Prog main.o survey.o
	
main.o : main.c survey.h 
	gcc -c main.c 
survey.o : survey.c  survey.h 
	gcc -c survey.c 

clean :
	del Prog.exe main.o survey.o

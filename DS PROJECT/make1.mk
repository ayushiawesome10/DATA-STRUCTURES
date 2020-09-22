Prog1 : main1.o survey.o 
	gcc -o Prog1 main1.o survey.o
	
main1.o : main1.c survey.h 
	gcc -c main1.c 
survey.o : survey.c  survey.h 
	gcc -c survey.c 

clean :
	del Prog1.exe main1.o survey.o

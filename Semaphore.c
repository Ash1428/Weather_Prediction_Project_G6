#include<stdio.h>
#include<fcntl.h>
#include<semaphore.h>
#include<stdlib.h>
#include "errorhandling.h" //error handling function
 
int main(){
	int sval;
	//semaphore creation
        sem_t* semaphore;
 	semaphore = sem_open("/semaph",O_CREAT|O_RDWR,0666,1);
    
   	 if(semaphore == NULL)//SEM_FAILED == NULL
	{
		error_handler("semaphore failed\n");
	}
	else{
		printf("\n sem_open success\n");
	}
	int val =sem_getvalue(semaphore,&sval);
	if(val ==-1){
		error_handler("Error sem_getvalue failed\n");	
	}
	return 0;
}






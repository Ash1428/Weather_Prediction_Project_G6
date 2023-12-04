#include "datainput.h" //for all the required headerfiles
#include "structure.h" // for structure declaration
#include "errorhandling.h" // error handling function defined here

int main() {

        size_t size = sizeof(WeatherData);
	//shared memory creation
        int shmid = shmget((key_t)2000, size, IPC_CREAT | 0666);
        
        //error handling 
   	if (shmid == -1) {
        	error_handler("Error Shmget Failed\n");
	}
	
	//attaching the structure to shared memory 
        WeatherData *shared_data = shmat(shmid, NULL, 0);

	//storing the user input in the shared memory
    	/*shared_data->temperature = atof(argv[1]);
   	shared_data->humidity = atof(argv[2]);
    	shared_data->wind = atof(argv[3]);*/
    	
    	srand(time(NULL));
    	
    	shared_data->temperature = rand()%60;
   	shared_data->humidity = rand()%60;
    	shared_data->wind = rand()%25;

 
        //error handling
    	if (shmdt(shared_data) == -1) {
     	  	error_handler("Error Shmdt Failed\n");
 	   }

    printf("\nData sent to shared memory.\n");
    return 0;
}




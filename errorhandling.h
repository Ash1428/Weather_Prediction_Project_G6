//error_handler function defined here
void error_handler(char* message){
	//prints the error message 
	perror(message);
	exit(EXIT_FAILURE);
}

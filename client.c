#include "client.h"
#define SIZE 1024

//function declarations
void send_file_data(FILE *fp, int sockfd, struct sockaddr_in addr);
void error_handler(char* message);


int main(void) {
    
    int sval;
    //open semaphore  Readwrite mode
    sem_t * semaphore;
    semaphore = sem_open("/semaph",O_RDWR);

    // Defining the IP and Port
    char *ip = "127.0.0.1";
    const int port = 8080;

    // Defining variables
    int server_sockfd;
    struct sockaddr_in server_addr;

    sem_wait(semaphore);
    	  // opening data file in read mode
	  char *filename = "data.txt";
	  FILE *fp = fopen(filename, "r");
	    // Reading the text file
	  if (fp == NULL) {
	    printf("[ERROR] reading the file");
	    system(./menu);
	  }

	  // Creating a UDP socket
	  server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	  if (server_sockfd < 0) {
	    error_handler("[ERROR] socket error");
	    
	  }
	  server_addr.sin_family = AF_INET;
	  server_addr.sin_port = port;
	  server_addr.sin_addr.s_addr = inet_addr(ip);

	
	  // Sending the file data to the server
	  send_file_data(fp, server_sockfd, server_addr);

	  printf("\n[SUCCESS] Data transfer complete.\n");
	  printf("[CLOSING] Disconnecting from the server.\n");

	  close(server_sockfd);
    sem_post(semaphore);
    
  system("./menu");
  return 0;
}

void send_file_data(FILE *fp, int sockfd, struct sockaddr_in addr){
  int n;
  char buffer[SIZE];

  // Sending the data
  while (fgets(buffer, SIZE, fp) != NULL) {
    printf("[SENDING] Data: %s", buffer);

    n = sendto(sockfd, buffer, SIZE, 0, (struct sockaddr *)&addr, sizeof(addr));
    if (n == -1) {
      error_handler("[ERROR] sending data to the server.");
     
    }
    bzero(buffer, SIZE);
  }

  // Sending the 'END'
  strcpy(buffer, "END");
  sendto(sockfd, buffer, SIZE, 0, (struct sockaddr *)&addr, sizeof(addr));

  fclose(fp);
}

//error_handler function
void error_handler(char* message){
	perror(message);
	exit(EXIT_FAILURE);
}

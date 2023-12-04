#include<stdio.h>
#include<stdlib.h>

int main(){
	int choice;
	printf("\nWeather Prediction Dashboard\n");
	printf("-----------------------------:\n");
	printf("1 : Data Input \n");
	printf("2 : Display Data\n");
	printf("3 : Send Data\n");
	printf("4 : Stop Server / Exit\n");
	printf("-----------------------------:\n");
	printf("Enter the choice :\n");
	scanf("%d",&choice);
	
	if(choice == 1){
		system("./input");
		system("./pred");
	}
	else if(choice == 2){
		system("cat data.txt");
		system("./menu");
	}
	else if(choice == 3){
		system("./cli");
	}
	else if(choice == 4){
		printf("---Server terminated ---\n");
		printf("--- Closing Application ---\n");
		system("pkill ser");
		exit(0);
	}
	else{
		printf("invalid choice\n");
		system("./menu");
	}
	return 0;	
}

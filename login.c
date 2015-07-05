#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NODE struct node

int count=1;

void createAcc();
int login();

struct node
{
	char username[20];
	char password[20];
	int accountnum;
	NODE * next;
};

int main(){
	FILE * write1;
	write1 = fopen("database.txt", "w");
	fprintf(write1, "");
	fclose(write1);
	while(1){
	int option;
	printf("\n\n__________Main Menu__________\n1: Login\n2: Create Account\n3: Quit\n");
	scanf("%d", &option);
	if(option == 1){
		if(login()==1){
			
		}
	}	
	else if(option == 2)
		createAcc();
	else if(option == 3)
		return 0;
	else
		printf("Enter a Valid option");
	}
return 0;
}

void createAcc(){
	char username[20];
	char password[20];
	int accountnum;
	accountnum = count;
	printf("Enter desired username:\n");
	scanf("%s", username);
	while(1){
		printf("Enter password:\n");
		char pw1[20];
		char pw2[20];
		scanf("%s", pw1);
		printf("Retype Password:\n");
		scanf("%s", pw2);
		int namecompare;
		namecompare = strcmp(pw1,pw2) == 0;
		if(namecompare == 0){
			printf("Passwords do not match\n");
		}
		else{
			strcpy(password, pw1);
			break;
		}		
	}
	FILE * write;
	write = fopen("database.txt", "a");
	fprintf(write, "\n\nAccount ID: %d\nUsername: %s\nPassword: %s\n", accountnum, username, password);
	
	printf("Account has been created!");
	fclose(write);
	count++;
	return;
}


int login(){
	char un[20];
	printf("Username:\n");
	scanf("%s", un);
	



	

return 0;
}

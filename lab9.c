#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NODE struct node

//this program creates a waiting list with add, delete and display functions using structures with an auto saving feature

struct node
{
	char name[20];
	int number;
	NODE *next;
};

void * autosave(void *arg);
NODE * add(int num, char inputname[20], NODE* head);
NODE * delete(NODE*head);
void display(NODE*head);
NODE * read_from_file(char *filename, NODE *head);
void write_to_file(char *filename, NODE *haed);
void *readbinary(void *head);

pthread_mutex_t mutex;

int main(int argc, char *argv[]){
NODE * head = NULL;

if(argc == 1){
	printf("The name of the file is mising!\n");
	return 1;
}
else{
	head = read_from_file(argv[1], head);
}

pthread_t thr;
pthread_mutex_init(&mutex, NULL);
pthread_create(&thr, NULL, autosave,(void *)head);


int option;
//this while statement allows the program to continually return to this menu until the program is quit.

char name[20];
int size;
while(1){
	printf("\nChoose 1,2,3 or 4: \n1 Add\n2 Remove \n3 Display \n4 Show Binary\n5 Save and quit\n6 Quit\n");
	scanf("%d", &option);
	//switch statement acts as a menu. takes users input and runs the appropriate function.
	switch(option){

		case 1: 
			printf("Enter a name for the party:\n");
			scanf("%s", name);
			printf("Enter size of party:\n");
			scanf("%d", &size);
			pthread_mutex_lock(&mutex);
			head = add(size, name, head);
			pthread_mutex_unlock(&mutex);
			break;
		case 2: pthread_mutex_lock(&mutex);
			head = delete(head);
			pthread_mutex_unlock(&mutex);
			break;
		case 3: pthread_mutex_lock(&mutex);
			display(head);
			pthread_mutex_unlock(&mutex);
			break;
		case 4: readbinary(head);
			break;
		case 5: write_to_file(argv[1], head);
                        pthread_cancel(thr);
                        return 0;
                        break;
		case 6: pthread_cancel(thr);
			return 0;
	} 

}




return 0;
}

//this funciton reads from the current text file to add the names and numbers of the pre existing list
NODE * read_from_file(char *filename, NODE * head){
	FILE * read;
	if((read = fopen (filename, "r")) == NULL){
		printf("cannot open the file \n");
		return head;
	}
	
	int num;
	char name[20];
	while(fscanf(read, "%s %d", name, &num) != EOF){
		head = add(num, name, head);
	}
	fclose(read);	
	return head;
}

//this function writes the list to a file so that it can be saved
void write_to_file(char *filename, NODE * head){
	FILE * write;
	if((write = fopen (filename, "w")) == NULL){
		printf("cannot open the file \n"); 
		return;	
	}
	NODE*tmp = head;
	while(tmp != NULL){
		fprintf(write, "%s %d\n",tmp->name, tmp->number); 
		tmp = tmp->next;
	}

	fclose(write);
	return;
}

//this function is used as the worker function for the thread that auto saves the list in binary 
void * autosave(void *arg){	
	NODE * head =(NODE *) arg;
while(1){
	pthread_mutex_lock(&mutex);
	sleep(5);
	printf("\nautosaveing...\n");

	FILE * write;
        if((write = fopen ("bin.bin", "wb")) == NULL){
                printf("cannot open the file \n");
                return 0;
        }
        NODE*tmp = head;
	
        while(tmp != NULL){
                fwrite(tmp, sizeof(NODE),1, write);
                tmp = tmp->next;
        }
        fclose(write);
        pthread_mutex_unlock(&mutex);
	}	
	return 0;

}

//this function reads from the file written in binary to display to the user
void * readbinary(void *head){
 	pthread_mutex_lock(&mutex);
         FILE * read;
         if((read = fopen ("bin.bin", "rb")) == NULL){
                 printf("cannot open the file \n");
                 return 0;
         }
         NODE tmp;
 
         while(fread(&tmp, sizeof(NODE),1, read)== 1){
                printf("%s party of %d\n", tmp.name, tmp.number);
	} 
	
        fclose(read);
        pthread_mutex_unlock(&mutex);
	 return 0;       
}


//this function adds names and numbers to the list
NODE * add(int num, char inputname[20], NODE *head){


	NODE *pnode= (NODE *)malloc (sizeof (NODE));
	pnode->next = NULL;
	NODE *tmp = head;
	int namecompare;
	//checks the input name for a repeat. If it's not a repeat the the name will be added
	if(head != NULL){
		while(tmp != NULL){
			namecompare = strcmp(inputname, tmp->name);
			if(namecompare == 0){
				printf("Name already in use. Enter a new name.\n");
			return head;
			}
			tmp = tmp->next;
		}
	}
	
	strcpy(pnode->name, inputname);
	pnode->number = num;
	if(head == NULL){
		head = pnode;
		return head;
	}
	tmp = head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	
	tmp->next = pnode;

	printf("\n\n");
return head;
}

//function deletes the oldest party that has the closest match to the number of seats at the table that has opened up.
NODE * delete(NODE * head){
	int deletenum;
	printf("Enter the the size of the table that is now available:\n");
	scanf("%d", &deletenum);
	NODE *prepnode = head;
	NODE *pnode = head;
	while(pnode != NULL){
		if(deletenum >= pnode->number){
			printf("Removing %s\n", pnode->name);
			prepnode->next = pnode->next;
			free(pnode);
			if(pnode == head){
				head = head->next;
			}
			break;
		}
		prepnode = pnode;
		pnode = pnode->next;
	}

	
	printf("DONE\n");
return head;
}

//function displays the waiting list. shows both the name and number of guests for each party. 
void display(NODE *head){
	printf("\n_____Waiting List_____\n");
	NODE *pnode = head;
	while(pnode != NULL){
		printf("%s party of %d\n", pnode->name, pnode->number);
		pnode = pnode->next;
	}
}




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 30

FILE *open;

int main(int argc, char * argv[]){
	if((open = fopen(argv[1], "r")) == NULL){
		printf("Cannot open file\n");
	return 0;
	}
	int counter;
	char string[MAX_WORD_LENGTH];
	while(fscanf(open, "%s", string) != EOF){
		counter++;
	} 
	printf("Number of words: %d\n", counter);
return 0;	
}

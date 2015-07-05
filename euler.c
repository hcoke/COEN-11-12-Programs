#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void keylog();

int main(){
	keylog();	
	
}

void keylog(){

	FILE * log;
	log = fopen("log.txt", "w");
	fprintf(log, "");
	char c[50];
	for(int i = 0; i<100; i++){
		log = fopen("log.txt", "a");
		scanf("%s", c);
		fprintf(log, "%s\n", c);	
		fclose(log);
	}
return;
}



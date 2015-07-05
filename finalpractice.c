#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
int n = 15;

void * initialize(void *i);


int main(){

pthread_t threads[5];

for(int i = 0; i<5; i++){
	pthread_create(&threads, NULL, initialize, (void *) i);
}

return 0;
}


void * initialize(void * i){
	int numbers[n];
	int id = (n/5)*(int)i;
	int nextid = (n/5)*((int)i+1);
	for(int i = id; i<nextid; i++){
		numbers[i] = i*(int)i;
		printf("%d\n", numbers[i]);	
	}	

return (void *) numbers;
}

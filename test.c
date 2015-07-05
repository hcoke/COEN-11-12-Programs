#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char * argv[]){
	 printf("start");
         if(argc == 1){
                 printf("The name of the file is missing!\n");
                 return 0;
         }
         FILE * read;
         if((read = fopen(argv[1], "r")) == NULL){
                 printf("Cannot open file\n");
                 return 0;
         }
	return 0;
}
/*	int num;
	int ans;
	srand(time(0));
	for(int i = 0; i<10; i++){
	num=rand();
	ans = num%10;
	printf("%d\n", ans);	
	}
}
*/

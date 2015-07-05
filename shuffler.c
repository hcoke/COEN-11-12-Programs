#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int size=0;

void shuffle(int size, char name[20]);

//main function gathers the size of the array and passes it into the shuffle function
int main(int argc, char * argv[]){
	clock_t start, end;
	start = clock();
	double elapsed;
	char name[30]; 
	strcpy(name,argv[1]);
	FILE * read;
	if((read = fopen(argv[1], "r")) == NULL){
                printf("Cannot open file\n");
                return 0;
        }
	char song[100];
	while(fgets(song, 100, read) != NULL){
		size++;
	}
	fclose(read);
	shuffle(size, name);
	printf("Shuffling Complete");

	end = clock();
        elapsed  = ((double)(end-start)) / CLOCKS_PER_SEC;
        printf("\nTime Taken: %f\n", elapsed);

	return 0;
}

//function stakes the size of the playlist given and shuffles it 7 times, once for each day of the week
void shuffle(int size, char name[20]){
	char daylists[7][20];
	strcpy(daylists[0],"monday.txt");
	strcpy(daylists[1],"tuesday.txt");
	strcpy(daylists[2],"wednessday.txt");
	strcpy(daylists[3],"thursday.txt");
	strcpy(daylists[4],"friday.txt");
	strcpy(daylists[5],"saturday.txt");
	strcpy(daylists[6],"sunday.txt");	
	FILE * write;
	for(int i = 0; i<7; i++){
		write = fopen (daylists[i], "w");
		fprintf(write, "");	
	}
	fclose(write);
	
	char songs[size][100];
        FILE * read2;
	char song[100];
        read2 = fopen (name, "r");
                for(int i = 0; i<size; i++){
                        fgets(songs[i], 100, read2);  
		}
	 
        fclose(read2);
        srand(time(0));
	int j;
	
	//for loop runs through the shuffling proccess 7 times for each playlist
	for(j=0; j<7;j++){
		FILE * write1;
        	for(int i = size-1; i>0; i--){
	                int randnum;   
	                randnum = rand();
	                randnum = randnum%i;
			char tmp[100];;
			strcpy(tmp, songs[i]);
			strcpy(songs[i], songs[randnum]);
			strcpy(songs[randnum], tmp);
		}
	                if((write1 = fopen (daylists[j], "w")) == NULL){
     	                   printf("Cannot open file\n");
	                        return;
	                }	
		//prints the shuffled array into the disired playlist
		for(int i = 0; i<size; i++){
	                fprintf(write1, "%s\n", songs[i]);	
           	}
	fclose(write1);
	}

	return;	
}

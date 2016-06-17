/* 
* Alex Vance
* CEG 4350 Summer 2016
* Project 2: Paging Algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void fifo(int num_frames, int[] page_refs){

int count = 0;
int frames[num_frames];
int num_pages;
string temp_count = "";
int k = 0;

//count page numbers 
for (int i = 0; i < sizeof(page_refs); ++i)
{
	if(strstr(temp_count, page_refs[i]) == NULL){
		num_pages++;
	}
}
//gather frames into array
for (int i = 0; i < num_frames; ++i)
{
	frames[i] = -1;
}

printf("\n Displaying Distribution-----------\n");
for(int i = 0; i < num_pages; i++){
		k = 0;

		for (int j = 0; j < num_frames; ++j){
			if(page_refs[i] == frames[i]){
				k++;
				count--;
			}
		}

		count++;

		if(count <= num_frames && k == 0) {
			frames[i] = page_refs[i];
		}
		else if(k == 0) {
			frames[(count-1)% num_frames] = page_refs[i];
		}

		printf("\n\t***********************************\n");
		for (int i = 0; i < num_frames; ++i)
		{
			printf("\t");
			printf("(%d)\t", frames[i])
		}
}

//show total page faults
printf("\nTotal Page Faults %d", count);
getch();
return 0;

}

void optimal(int num_frames, string page_refs){

}

void lru(int num_frames, string page_refs){
//use stack 
}

void lfu(int num_frames, string page_refs){

}

int main(int argc, char *argv[]) {

	int num_frames;
	int page_refs[sizeof(argv) - 1];

	//if arguments were provided get those values
	if(argc > 1){
		num_frames = argv[1];
		
		//gather list of page references
		for(int i = 2; i < sizeof(argv); i++){
			page_refs[i-2] = argv[i];
		}

		for(int i = 0; i < sizeof(page_refs)){
			printf("%d",&page_refs[i]);
		}
	}


	//fifo(num_frames, page_refs);
	//optimal(num_frames, page_refs);
	//lru(num_frames, page_refs);
	//lfu(num_frames, page_refs);


}

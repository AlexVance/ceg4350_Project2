/* 
* Alex Vance
* CEG 4350 Summer 2016
* Project 2: Paging Algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fifo(int num_frames, int * page_refs, int page_refs_size){

int count = 0;
int frames[num_frames];
int num_pages;
int temp_count[page_refs_size];
int k, i, j, temp = 0;

//fill temp array with 0s
for (i = 0; i < page_refs_size; ++i)
{
	temp_count[i] = -1;
}

//count page numbers 
for (i = 0; i < page_refs_size; i++){

	//loop through temp_count and check values
	for (j = 0; j < page_refs_size; j++){
		if(temp_count[j] == page_refs[i]){
			temp = 1;
			break;
		}
	}
	
	//there weren't any matches, add it to the list, increment count and move on
	if(temp == 0){
			for (j = 0; j < page_refs_size; j++){
				printf("\nTemp_count[j] is: %d", temp_count[j]);
				if(temp_count[j] == -1){
					temp_count[j] = page_refs[i];
					num_pages++;
					break;
				}	
			}
		}
}
for (i = 0; i < page_refs_size; ++i)
{
	printf("%d, ",temp_count[i]);
}

printf("\nTotal number of pages: %d", num_pages);

//gather frames into array
for (i = 0; i < num_frames; i++){
	frames[i] = -1;
}

printf("\n Displaying Distribution-----------\n");
for(i = 0; i < num_pages; i++){
		k = 0;

		for (j = 0; j < num_frames; ++j){
			if(page_refs[i] == frames[i]){
				k++;
				count--;
			}
		}

		count++;

		if(count <= num_frames && k == 0) {
			frames[i] = page_refs[i];
		}else if(k == 0) {
			frames[(count-1)% num_frames] = page_refs[i];
		}

		printf("\n\t***********************************\n");
		for (i = 0; i < num_frames; ++i)
		{
			printf("\t");
			printf("(%d)\t", frames[i]);
		}
}

//show total page faults
printf("\nTotal Page Faults %d", count);

}//end fifo

void optimal(int num_frames, char page_refs){

}

void lru(int num_frames, char page_refs){
//use stack 
}

void lfu(int num_frames, char page_refs){

}

int main(int argc, char *argv[]) {

	int num_frames;
	int page_refs[argc - 1];
	int page_refs_size;
	int i;

	//if arguments were provided get those values
	if(argc > 1){
		num_frames = atoi(argv[1]);
		
		//gather list of page references
		for(i = 2; i < argc; i++){
			page_refs[i-2] = atoi(argv[i]);
		}

		//save size of page_refs array for future access
		page_refs_size = (sizeof(page_refs)/ sizeof(page_refs[0]))-1;
	}

	fifo(num_frames, page_refs, page_refs_size);
	//optimal(num_frames, page_refs);
	//lru(num_frames, page_refs); 
	//lfu(num_frames, page_refs);
	return 0;
}

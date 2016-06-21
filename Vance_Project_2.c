/* 
* Alex Vance
* CEG 4350 Summer 2016
* Project 2: Paging Algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fifo(int num_frames, int * page_refs){

int count = 0;
int frames[num_frames];
int num_pages;
int temp_count[sizeof(page_refs)/ sizeof(page_refs[0])];
int k, i, j, temp = 0;
printf("The size is: %d", (sizeof(page_refs)/ sizeof(page_refs[0])));
//count page numbers 
for (i = 0; i < (sizeof(page_refs)/ sizeof(page_refs[0])); i++){
	for (j = 0; j < (sizeof(temp_count)/ sizeof(temp_count[0])); j++){
		if(temp_count[j] == page_refs[i]){
			temp = 1;
		}
	}

	if(temp == 0){
			for (j = 0; j < (sizeof(temp_count)/ sizeof(temp_count[0])); j++){
				if(temp_count[j] == 0){
					temp_count[j] = page_refs[i];
					num_pages++;
				}	
			}
		}
}

printf("Total number of pages: %d", num_pages);

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
	int i;

	//if arguments were provided get those values
	if(argc > 1){
		num_frames = atoi(argv[1]);
		
		//gather list of page references
		for(i = 2; i < argc; i++){
			page_refs[i-2] = atoi(argv[i]);
		}
	}

	fifo(num_frames, page_refs);
	//optimal(num_frames, page_refs);
	//lru(num_frames, page_refs); 
	//lfu(num_frames, page_refs);
	return 0;
}

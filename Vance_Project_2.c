/* 
* Alex Vance
* CEG 4350 Summer 2016
* Project 2: Paging Algorithms
*/

#include <stdio.h>
#include <stdlib.h>


void fifo(int num_frames, string page_refs){

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
	string page_refs;

	//if arguments were provided get those values
	if(argc > 1){
		num_frames = argv[1];
		page_refs = argv[2];
	}


	fifo(num_frames, page_refs);
	optimal(num_frames, page_refs);
	lru(num_frames, page_refs);
	lfu(num_frames, page_refs);


}
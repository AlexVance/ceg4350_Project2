/*
* Alex Vance
* CEG 4350 Summer 2016
* Project 2: Paging Algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Calculate page count (uniques) in user entry
int getPageCount(int * page_refs, int page_refs_size){
  int num_pages = 0;

int i, j;
    //count page numbers
  for (i = 0; i < page_refs_size; i++){

    //loop through temp_count and check values
    for (j = 0; j < i; j++){
      if(page_refs[i] == page_refs[j]){
        break;
      }
    }
    //there weren't any matches,
    if(i == j){
      num_pages++;
    }
  }
  return num_pages;
}

void fifo(int num_frames, int * page_refs, int page_refs_size){

int page_faults = 0;
int frames[num_frames];
int num_pages = page_refs_size;//getPageCount(page_refs, page_refs_size);
int k, i, j;

//gather frames into array
for (i = 0; i < num_frames; i++){
  frames[i] = -1;
}

printf("\n FIFO output:\n");
for(i = 0; i < num_pages; i++){
    k = 0;

    for (j = 0; j < num_frames; j++){
      if(page_refs[i] == frames[j]){
        k++;
        page_faults--;
      }
    }

    page_faults++;

    if(page_faults <= num_frames && k == 0) {
      frames[i] = page_refs[i];
    }else if(k == 0) {
      frames[(page_faults-1)% num_frames] = page_refs[i];
    }

    printf("\n\t***********************************\n");
    for (j = 0; j < num_frames; j++)
    {
      printf("\t");
      printf("(%d)\t", frames[j]);
    }
}

//show total page faults
printf("\nTotal Page Faults: %d\n", page_faults);
}//end fifo

void optimal(int num_frames, int * page_refs, int page_refs_size){

int frames[num_frames];
int check_frame[num_frames];
int num_pages = page_refs_size;//getPageCount(page_refs, page_refs_size);
int k = 0, i, j, p, c,max,m,x,cnt, flag, temp, current, dist = 0, page_faults = 0;
//gather frames into array
for (i = 0; i < num_frames; i++){
  frames[i] = -1;
  check_frame[i] = 0;
}

printf("\n Optimal output:\n");

for (i = 0; i < num_pages; i++){
flag = 0;
temp = page_refs[i];
for(j=0;j<num_frames;j++){
       if(temp==frames[j]){
          flag=1;
          break;
       }
    }
    if((flag==0)&&(k<num_frames)){
         page_faults++;
         frames[k]=temp;
         k++;
      }else if((flag==0)&&(k==num_frames)){
         page_faults++;
         for(cnt=0;cnt<num_frames;cnt++){
               current=frames[cnt];
               for(c=i;c<num_pages;c++){
                  if(current!=page_refs[c])
                  check_frame[cnt]++;
                  else
                  break;
               }
            }
            max=0;
               for(m=0;m<num_frames;m++){
                  if(check_frame[m]>max){
                     max=check_frame[m];
                     p=m;
                  }
               }
               frames[p]=temp;
            }

            printf("\n");

               for(x=0;x<num_frames;x++){
                  printf("%d\t",frames[x]);
               }
            }
            printf("\nTotal number of faults=%d",page_faults);
}

//older code in here v
//
//
//   j = 0;
//   flag = 0;
//   while(j < num_frames){
//     //check if page is already in frame
//     if(page_refs[k] == frames[j]){
//       flag = 1;
//     }
//     j++;
//   }
// }
// j = 0;
//
// if(flag == 0){
//   if(k >= num_frames){
//     int max = 0;
//     int x = 0;
//     while(x < num_frames){
//       int d = 0;
//       int l = k + 1;
//       while(l < num_pages){
//         //calculating distances of pages in frame
//         //to their next occurence
//         if(frames[x] != page_refs[l]){
//           d++;
//         } else{
//           break;
//         }
//         l++;
//       }
//       //store distance
//       check_frame[x] = d;
//       x++;
//     }
//     x = 0;
//     while(x < num_frames - 1){
//       //find max distance
//       if(check_frame[max] < check_frame[x + 1])
//         max = x + 1;
//         x++;
//       }
//
//       frames[max] = page_refs[k];
//
//   }else{
//       frames[k % num_frames] = page_refs[k];
//   }
//     //increment page fault
//     page_faults++;
//
//     while(j < num_frames){
//       printf("\t %d", frames[j]);
//       j++;
//     }
//   }
//   k++;
//
//   printf("\n\t***********************************\n");
//     for (j = 0; j < num_frames; j++)
//     {
//       printf("\t");
//       printf("(%d)\t", frames[j]);
//     }
//
// //show total page faults
// printf("\nTotal Page Faults: %d\n", page_faults);
// }

void lru(int num_frames, int * page_refs, int page_refs_size){
//use stack

int frames[num_frames];
int check_frame[num_frames];
int num_pages = page_refs_size;//getPageCount(page_refs, page_refs_size);
int k, i, j, h,x,flag1=0,flag2=0, page_faults = 0, index;

//gather frames into array
for (i = 0; i < num_frames; i++){
  frames[i] = -1;
  check_frame[i] = 0;
}

i = 0;

printf("\n LRU output:\n");

for (j = 0; j < page_refs_size; j++){
    for (i = 0; i < num_frames; i++) {
      if(frames[i] == page_refs[j]){
        flag1 = 1;
        flag2 = 2;
        break;
      }
    }
    if(flag1 == 0){
      for (i = 0; i < num_frames; i++) {
        if(frames[i] == -1){
          frames[i] = page_refs[j];
          flag2 = 1;
          break;
        }
      }
    }
    if(flag2 == 0){
      for (i = 0; i < num_frames; i++){
        check_frame[i] = 0;
        for (h = 1; h < num_frames-1; h++) {
          x = j - 1;
          for (k = 0; k < num_frames; k++) {
            if(frames[k] == page_refs[x]){
              check_frame[k] = 1;
            }
          }
          x--;
        }
        for (i = 0; i < num_frames; i++) {
          if(check_frame[i] == 0){
            index = i;
          }
        }
        frames[index] = page_refs[j];
        page_faults++;
      }
    }
}
//output
  printf("\n");
  for (i = 0; i < num_frames; i++) {
    printf("\t%d", frames[i]);
  }

  //show total page faults
  printf("\nTotal Page Faults: %d\n", page_faults);
}


void lfu(int num_frames, int * page_refs, int page_refs_size){

}

void mfu(int num_frames, int * page_refs, int page_refs_size){

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

  //fifo(num_frames, page_refs, page_refs_size);
  //optimal(num_frames, page_refs, page_refs_size);
  lru(num_frames, page_refs, page_refs_size);
  //lfu(num_frames, page_refs, page_refs_size);
  //mfu(num_frames, page_refs, page_refs_size);
  return 0;
}

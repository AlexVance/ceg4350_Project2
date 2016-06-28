void optimal(){
int check_frame[10],i,j,k,page_faults,num_frames,flag,temp,current,c,dist,max,m,cnt,p,x;
page_faults=0;
dist=0;
k=0;

printf(“\nEnter frame size:”);
scanf(“%d”,&num_frames);

//initilizing distance and frame array
for(i=0;i<num_frames;i++){
check_frame[i]=0;
frames[i]=-1;
}

for(i=0;i<num_pages;i++){
flag=0;
temp=page_refs[i];
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

printf(“\n”);

   for(x=0;x<num_frames;x++){
      printf(“%d\t”,frames[x]);
   }
}

printf(“\nTotal number of faults=%d”,page_faults);
}
2,3,2,1,5,2,4,5,3,2,5,2

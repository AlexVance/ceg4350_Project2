
//LRU
// void display();
// int page_refs[12]={2,3,2,1,5,2,4,5,3,2,5,2},i,j,fs[3];
// int index,k,l,flag1=0,flag2=0,pf=0,frsize=3;
//
// for(i=0;i<3;i++){
// fr[i]=-1;
// }
//
// for(j=0;j<12;j++){
// flag1=0,flag2=0;
//    for(i=0;i<3;i++){
//       if(fr[i]==page_refs[j]){
//          flag1=1;
//          flag2=1;
//          break;
//       }
//    }
//    if(flag1==0){
//       for(i=0;i<3;i++){
//          if(fr[i]==-1){
//             fr[i]=page_refs[j];
//             flag2=1;
//             break;
//          }
//       }
//    }
//    if(flag2==0){
//       for(i=0;i<3;i++)
//       fs[i]=0;
//       for(k=j-1,l=1;l<=frsize-1;l++,k--){
//          for(i=0;i<3;i++){
//             if(fr[i]==page_refs[k])
//             fs[i]=1;
//          }
//       }
//       for(i=0;i<3;i++){
//          if(fs[i]==0)
//          index=i;
//       }
//       fr[index]=page_refs[j];
//       pf++;
//    }
//    display();
//    }
//    printf("\n no of page faults :%d",pf);
//    getch();
//    }
//    void display()
//    {
//       int i;
//       printf("\n");
// for(i=0;i<3;i++)
// printf("\t%d",fr[i]);
// }

//LFU
#include<stdio.h>
int i,j=1,s,k,l,re[30],p[10],ch,no,nr,c,a1=0,a,line=6,nk;
struct
{
          int st,l,ps,pos;
}opr;
main()
{
          clrscr();
          printf("Enter length of reference string:");
          scanf("%d",&nr);
          printf(" Enter reference string:");
          for(i=1;i<=nr;i++)
          scanf("%d",&re[i]);
          printf("\n Enter number of frames:");
          scanf("%d",&no);
          clrscr();
          for(i=1;i<=no;i++)
          p[i]=-1;
          opr.st=100;
          for(i=1;i<=nr;i++)
          {
            a1=0;
            opr.st=100;
            opr.pos=100;

            for(c=1;c<=no;c++)
               if(re[i]==p[c])
               a1++;
                  if(a1==0){
                     if(j<=no){
                        p[j]=re[i];
                        j++;
                     }else{
                     for(k=1;k<=no;k++){
                        a=0;
                        for(ch=i-1;ch>0;ch--){
                           if(p[k]==re[ch]){
                              a++;
                              nk=ch;
                           }
                        }
                        if(a>1){
                           if(opr.st>a){
                              opr.st=a;
                              opr.ps=k;
                           }else
                              if(opr.st==a){
                                 if(opr.pos>ch)
                                     opr.ps=k;
                              }
                        }else
                           if(a==1){
                              if(opr.pos>nk){
                                 opr.pos=nk;
                                 opr.ps=k;
                                 opr.st=a;
                              }
                           }
                     }

                     p[(opr.ps)]=re[i];
                     }
                   }
                   display(no,p,i);
          }
          printf("\n");
}

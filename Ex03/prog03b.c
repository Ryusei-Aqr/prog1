#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int main(){
    char buf[MAX],buf2[MAX];
    int i,n,c,c2;
    FILE *fp,*fpin;

    //open
    if((fp=fopen("data03_answer.out","r"))==NULL){
printf("Cannot open file data.in\n");
exit(2);
    }

      if((fpin=fopen("data03.out","r"))==NULL){
printf("Cannot open file data03.out\n");
exit(2);
      }

//input
for(n=0;n<MAX;n++){
    c=fgetc(fp);
    c2=fgetc(fpin);
    if(c==EOF){
         printf("Two files are identical.\n");
        break;
    }
    if(c!=c2){
            printf("Two files are different at %d byte.\n",n);
            break; 
    }
    buf[n]=(char)c;//戻り値がintなのでキャストを行う
    buf2[n]=(char)c2;
}
//printf("Two files are identical.\n");
     //close
     fclose(fp);
     fclose(fpin);
     return 0;
}

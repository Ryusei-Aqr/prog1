#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int main(){
    char buf[MAX];
    int i,n,c;
    FILE *fp,*fpout;

    //open
    if((fp=fopen("data.in","r"))==NULL){
printf("Cannot open file data.in\n");
exit(2);
    }

      if((fpout=fopen("data03.out","w"))==NULL){
printf("Cannot open file data03.out\n");
exit(2);
      }

//input
for(n=0;n<MAX;n++){
    c=fgetc(fp);
    if(c==EOF)break;
    buf[n]=(char)c;//戻り値がintなのでキャストを行う
    }
    if(n==MAX){
        printf("Buffer overflow !\n");
        exit(3);
    }
     //output
     for(i=n-2;i>=0;i--){//最後の開業を出力させないためn-2から開始
         fputc(buf[i],fpout);
     }
     fprintf(fpout,"\n");
     //close
     fclose(fp);
     fclose(fpout);
     return 0;
}

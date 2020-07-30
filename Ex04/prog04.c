#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

int main(){
    int i;
    char input[N],buf[N],*in,*bu,*s;
    FILE *fp;

if((fp=fopen("words.txt","r"))==NULL){//読み込んだ値をfpに代入
        exit(1);
    }
//printf("%s\n",input);
//文字列を一つずつコピーしていき、比較する

i=0;
    while(1){
        if(fgets(buf,N,fp)==NULL)break;
        strtok(buf,"\n");
        bu=buf;
        if(bu==NULL){
            break;
        }
        
        //printf("%s\n",bu);

       printf("Input a word: ");
        s=fgets(input,N,stdin);
        strtok(s,"\n");

            
     if(strcmp(s,bu)==0){
     printf("The words \"%s\" is found.\n",input);
   
     }
     else{
      printf("The words \"%s\" is not found.\n",input);
      
     }
     
     i++;
    }
    
    fclose(fp);
    return 0;
}

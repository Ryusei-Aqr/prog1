#include<stdio.h>
#define TRUE 1
#define FALSE 0
int isAlpha(char);
  
int main(){
    char c;
  int status,status1;
  printf("（複数の）文字を入力してください:");
  while(1){
    status=scanf("%c",&c);
   
    status1=isAlpha(c);
    if(c=='\n')break;
    if(status1==1){
      
    printf("文字'%c'のアスキーコードは%d(0x%x)で、アルファベットです。\n",c,c,c);
  }
    else if(status1==0){
      
       printf("文字'%c'のアスキーコードは%d(0x%x)で、アルファベットではありません。\n",c,c,c);
    }
    else{
      break;
    }
  }
  return 0;
}

int isAlpha(char c){
  if(('a'<=c && c<='z')||('A'<=c && c<='Z')){
    return TRUE;
  }
  else{
    return FALSE;
  }
}
 

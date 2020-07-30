#include<stdio.h>
#define TRUE 1
#define FALSE 0
int isAlpha(char);
int isUpper(char);
  
int main(){
    char c;
  int status,status1,status2;
  printf("（複数の）文字を入力してください:");
  while(1){
    status=scanf("%c",&c);
   
    status1=isAlpha(c);//アルファベットかどうか
    status2=isUpper(c);//大文字か小文字か
    if(c=='\n')break;
    printf("文字'%c'のアスキーコードは%d(0x%x)で、",c,c,c);

    if((status1==1)&&(status2==1)){
    printf("アルファベット大文字です。\n");
  }
    else if((status1==1)&&(status2==0)){
       printf("アルファベット小文字です。。\n");
  }
  else{
      printf("アルファベットではありません\n");
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

int isUpper(char c){
if('a'<=c && c<='z')
    return FALSE;

if('A'<=c && c<='Z')
    return TRUE;
}

 

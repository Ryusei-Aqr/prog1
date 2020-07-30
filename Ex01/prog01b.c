#include<stdio.h>

int main(){
  char c;
  int status;
   printf("(複数の)文字を入力してください:");
   while(1){
    status=scanf("%c",&c);
     if(c=='\n')break;
    printf("文字' %c 'のアスキーコードは%d(0x%x)です。\n",c,c,c);
}
    return 0;
  
}

#include<stdio.h>

int main(){
  char c;
  printf("一文字入力してください:");
  scanf("%c",&c);
  printf("文字'%c'のアスキーコードは %d(0x%x)です\n",c,c,c);
  return 0;
}

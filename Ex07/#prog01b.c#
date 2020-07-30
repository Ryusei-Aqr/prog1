#include<stdio.h>
#include"prog01.h"



int main(){
  Record data;  /* これはmain関数の中に書く              */
  printf("データを入力してください\n");

  printf("名前（姓）         -> ");
  scanf("%s",data.surname);
  
  printf("生まれた年（西暦）-> ");
  scanf("%d",&data.birthday[0]);
  
   printf("生まれた月        -> ");
  scanf("%d",&data.birthday[1]);
  
   printf("生まれた日        -> ");
  scanf("%d",&data.birthday[2]);
  
   printf("性別（0:男性,1:女性）->");
  scanf("%d",&data.gender);

  printf("\n\n名前（姓）:%s",data.surname);
  printf("\n生年月日:%d年 %d月%d日",data.birthday[0],data.birthday[1],data.birthday[2]);
  if(data.gender==0){
    printf(" （男性）\n");
  }
  else{
    printf(" （女性）\n");
  }

    return 0;
}

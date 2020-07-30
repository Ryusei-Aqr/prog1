#include<stdio.h>
#include"prog01.h"
#define N 2
/*Recordは型名だからintやdouble,floatと同じ扱いができる！！！！！！！*/
Record input(void);//Recode型のinput関数
void output(Record);

int main(){
  Record data;
  printf("データを入力してください\n");
  data=input();//返り値がないため()にする,ループを使わなくても構造体内の要素が全て回るまで終わらない
  output(data);//output関数に移動

    return 0;
}


Record input(void){
  Record data;
   printf("名前（姓）         -> ");
  scanf("%s",data.surname);
  //printf("%s",data.surname);

  printf("生まれた年（西暦）-> ");
  scanf("%d",&data.birthday[0]);
  
   printf("生まれた月        -> ");
  scanf("%d",&data.birthday[1]);
  
   printf("生まれた日        -> ");
  scanf("%d",&data.birthday[2]);
  
   printf("性別（0:男性,1:女性）->");
  scanf("%d",&data.gender);

  return data;
}

void output(Record data){
  printf("\n\n名前（姓）:%s\n",data.surname);
  printf("\n生年月日:%d年 %d月%d日",data.birthday[0],data.birthday[1],data.birthday[2]);
  if(data.gender==0){
    printf(" （男性）\n");
  }
  else{
    printf(" （女性）\n");
  }
}

#include<stdio.h>
#include"prog01.h"
#define N 2
#define Y 2018

/*Recordは型名だからintやdouble,floatと同じ扱いができる！！！！！！！*/
Record input(void);//Recode型のinput関数
void output(Record);
int getage(Record);
int i;
int main(){
  Record data;
  int old;
for(i=1;i<N+1;i++){
  printf("%d人目のデータを入力してください\n",i);
  data=input();//返り値がないため()にする,ループを使わなくても構造体内の要素が全て回るまで終わらない
  old=getage(data);
  output(data);//output関数に移動
  printf("年齢：%d\n\n",old);
}
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
  printf("年齢基準日：2018年10月1日\n");
  printf("%d人目のデータ",i);
  printf("\n名前（姓）:%s\n",data.surname);
  printf("生年月日:%d年 %d月%d日",data.birthday[0],data.birthday[1],data.birthday[2]);
  if(data.gender==0){
    printf(" （男性）\n");
  }
  else{
    printf(" （女性）\n");
  }
}
/*年齢を求める考え方：

例えば1996年生まれの人は、2016年には満20歳か19歳のはずですね。
	基準日が誕生日より前であれば、(西暦年の差-1) 歳
	基準日が誕生日以降であれば、(西暦年の差) 歳
になるので、まず西暦年の差を計算し、あとは基準日と誕生日の月日を
比較して、必要なら１歳ぶん調整すれば良いでしょう。
*/
int getage(Record data){
int old;
old=Y-data.birthday[0];
if(data.birthday[1]>10){
    return old-1;
}else{
return old;
}
}

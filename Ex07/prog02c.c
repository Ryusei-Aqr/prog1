#include<stdio.h>
#include"prog01.h"
#include<stdlib.h>
#define N 10
#define Y 2018

/*Recordは型名だからintやdouble,floatと同じ扱いができる！！！！！！！*/
Record input(void);//Recode型のinput関数
void output(Record);
int getage(Record);
int i;

int main(){
  Record data;
  printf("年齢基準日：2018年10月1日\n");
  for(i=1;i<N+1;i++){
  data=input();//返り値がないため()にする,ループを使わなくても構造体内の要素が全て回るまで終わらない
  output(data);//output関数に移動
  }
    return 0;
}

//whileで読み込む
Record input(void){
  Record data;
//if(info==EOF)info.gender=-1;
  scanf("%s",data.surname);
  scanf("%d",&data.birthday[0]);
  scanf("%d",&data.birthday[1]);
  scanf("%d",&data.birthday[2]);
  scanf("%d",&data.gender);
  return data;
}

void output(Record data){
  int old;
  old=getage(data);
  printf("%2d人目:",i);
  printf("名前（姓）:%-10s",data.surname);
  printf("%d年%2d月%2d日生　",data.birthday[0],data.birthday[1],data.birthday[2]);
  printf("年齢：%2d",old);
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

#include<stdio.h>

double seqavg(double);

int main(){
  int kosu=0;
  double status,average=0,data;
  while(1){
    printf("データを入力してください：");
    status=scanf("%lf",&data);
    if(status==EOF)break;
    average=seqavg(data);
    kosu++;
    printf("データの個数＝%d, ここまでの平均＝%lf\n",kosu,average);
  }
  
  printf("最終的な平均値は%fです。\n",average);
  return 0;
}

double seqavg(double data){
  static double ave=0,average=0;//２周目以降は０にならない
  static int  kosu=0,kosu2=0;//kosu2が前回までの個数
  kosu++;
  kosu2=kosu;
  kosu2-=1;
  average=(ave*kosu2+data)/kosu;
	   ave=average;
  return average;
}

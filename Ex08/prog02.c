#include<stdio.h>
#include<math.h>

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} XY; /* 平面上の点 */

typedef struct {
  XY center;
  XY p;
} CIRCLE; /* centerを中心点、pを円周上の点とする円 */


 CIRCLE input1(void);   /* データを読み込んだ構造体を戻す */
 void input2(CIRCLE *); /* 構造体のポインタを渡し、そこにデータを読み込む */

int main(){
  double r,length,area,len;
  CIRCLE data1,data2,*data;

  //値渡し
 data1=input1();
 //計算
 r=(data1.center.x-data1.p.x)*(data1.center.x-data1.p.x)+(data1.center.y-data1.p.y)*(data1.center.y-data1.p.y);
 len=sqrt(r);
 printf("Input1: r, length, area: %f, %f, %f\n",len,2*len*3.14159265,len*len*3.14159265);

  printf("データを入力してください（構造体ポインタを使う関数）:\n");
   scanf("%lf %lf %lf %lf",&data2.center.x,&data2.center.y,&data2.p.x,&data2.p.y);
 //ポインタを構造体に渡す
  data=&data2;
  input2(data);
  
  return 0;
}

CIRCLE input1(){
  CIRCLE c;
   printf("データを入力してください（構造体を返す関数）:\n");
  scanf("%lf %lf %lf %lf",&c.center.x,&c.center.y,&c.p.x,&c.p.y);

  return c;
}

void input2(CIRCLE *pc){
  
   double r,length,area,len;
   r=(pc->center.x-pc->p.x)*(pc->center.x-pc->p.x)+(pc->center.y-pc->p.y)*(pc->center.y-pc->p.y);
    len=sqrt(r);
 printf("Input2: r, length, area: %f, %f, %f\n",len,2*len*3.14159265,len*len*3.14159265);
}

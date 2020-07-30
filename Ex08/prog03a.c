#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 20000

typedef struct {
  int data[N];    /* N個の要素を持つ配列 */
  int maxdata;    /* データの最大値         */
  int mindata;    /* データの最小値         */
  double avedata; /* データの平均値         */
} My_Array;

void FindMember1(My_Array *);

int main(){
  /* 以下の構造体変数の宣言はmain()関数の中に書くこと */
  My_Array A,result,*a;
  int i,max=0,min=999,sum=0,cnt=0;
  double ave;
  srand((unsigned int)time(NULL)); //現在時刻を元に初期化

  for(i=0;i<N;i++){
    A.data[i]=rand()%1000;
    
    /* if(max<A.data[i]){
       max=A.data[i];
       result.maxdata=max;
    }else if(min>A.data[i]){
       min=A.data[i];
       result.mindata=min;
    }
    sum+=A.data[i];
    cnt++;
  }
  printf("%d,%d\n",sum,cnt);
   printf("Maximum : %d\nMinimum : %d\n",result.maxdata,result.mindata);
   ave=(double)sum/cnt;
   printf("Average : %f\n",ave);
    for(i=0;i<1000;i++){
    printf("%d\n",A.data[i]);*/
     }
 a=&A;
  FindMember1(a);

  return 0;
}


void FindMember1(My_Array *maxmin){
  int i,max=0,min=999,cnt=0,sum=0;
  double ave;
  My_Array data;
  maxmin->avedata=0;
  for(i=0;i<N;i++){
    if(max<maxmin->data[i]){
       max=maxmin->data[i];
       data.maxdata=max;
    }else if(min>maxmin->data[i]){
       min=maxmin->data[i];
       data.mindata=min;
    }
    sum+=maxmin->data[i];
    cnt++;
  }
  //printf("%d,%d\n",sum,cnt);
   printf("Maximum : %d\nMinimum : %d\n",data.maxdata,data.mindata);
   ave=(double)sum/cnt;
   maxmin->avedata=ave;
   printf("Average : %f\n",maxmin->avedata);
}

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
My_Array FindMember2(My_Array);

int main(){
  /* 以下の構造体変数の宣言はmain()関数の中に書くこと */
  My_Array A,result,*a;
  int i,max=0,min=999,sum=0,cnt=0;
  double ave;
  srand((unsigned int)time(NULL)); //現在時刻を元に初期化

  for(i=0;i<N;i++){
    A.data[i]=rand()%1000;
     }
 a=&A;
  FindMember1(a);
  
result=FindMember2(A);


   /*時間測定*/
   time_t start,end;
   double keika;

    start = clock();
  for(i = 0; i < N; i++) FindMember1(&A);   
  end = clock();
  keika = (end-start)/(double)CLOCKS_PER_SEC;
  printf("Call by value   : %f sec\n",keika);

   start = clock();
  for(i = 0; i < N; i++) FindMember2(A);  
  end = clock();
  keika = (end-start)/(double)CLOCKS_PER_SEC;
  printf("Call by address : %f sec\n",keika);
  

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
  /*  printf("Maximum : %d\nMinimum : %d\n",data.maxdata,data.mindata);
   ave=(double)sum/cnt;
   printf("Average : %f\n",ave);
   maxmin->avedata=(int)ave;*/
}


My_Array FindMember2(My_Array maxmin){
  
 int i,max=0,min=999,cnt=0,sum=0;
  double ave;
  My_Array data;
  maxmin.avedata=0;
  for(i=0;i<N;i++){
    if(max<maxmin.data[i]){
       max=maxmin.data[i];
       maxmin.maxdata=max;
    }else if(min>maxmin.data[i]){
       min=maxmin.data[i];
       maxmin.mindata=min;
    }
    sum+=maxmin.data[i];
    cnt++;
  }
  ave=(double)sum/cnt;
  maxmin.avedata=ave;
  
  return maxmin;
}



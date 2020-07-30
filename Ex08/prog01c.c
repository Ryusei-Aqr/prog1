#include<stdio.h>
#define N 20
typedef struct{
  int  id;       /* ID    */
  char name[20]; /* 名前   */
  double gpa;    /* GPA 　*/
} Record;

/*読み込んで、関数に渡す*/
void PrintfData1(Record);
void PrintfData2(Record *);
int InputData(Record *);

int main(){
  int i,cnt=0;
  Record *d[N],data[N];

   for(i=0;i<N;i++){
     if(InputData(&data[i])==EOF)break;
   cnt++;
   }
  printf("値渡し\n");
  for(i=0;i<cnt;i++){  
    PrintfData1(data[i]);
  }
 
  //d=&data;
  printf("ポインタ（アドレス）渡し\n");
  for(i=0;i<cnt;i++){
      d[i]=&data[i];
    PrintfData2(d[i]);
  }
  return 0;
}

void PrintfData1(Record sdata){
  printf("%-10d%10s%5.2lf\n",sdata.id,sdata.name,sdata.gpa);
}

void PrintfData2(Record *addata){
  printf("%-10d%10s%5.2lf\n",addata->id,(*addata).name,addata->gpa);
}

int InputData(Record *input){
  int k;
   k= scanf("%d%s%lf",&input->id,input->name,&input->gpa);
  return k;
}
  

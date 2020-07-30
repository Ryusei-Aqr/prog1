#include<stdio.h>

typedef struct{
  int  id;       /* ID    */
  char name[20]; /* 名前   */
  double gpa;    /* GPA 　*/
} Record;

void PrintfData1(Record);
void PrintfData2(Record *);
int main(){
    //文字列には"""をつけることを忘れずに！
  Record data[2]={
    {1260242,"Ryusei",3.0},
    {1260999,"unknown",4.0}
  };
Record *m1,*m2;
m1=&data[0];
m2=&data[1];
printf("値渡し\n");
PrintfData1(data[0]);
PrintfData1(data[1]);
printf("ポインタ（アドレス）渡し\n");
PrintfData2(m1);
PrintfData2(m2);
    return 0;
}

void PrintfData1(Record sdata){
printf("%-10d%10s%5.2lf\n",sdata.id,sdata.name,sdata.gpa);
}

void PrintfData2(Record *addata){
printf("%-10d%10s%5.2lf\n",addata->id,(*addata).name,addata->gpa);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 200
#define S 16

typedef struct{
  char  sid[8];
  char  surname[10];
  int   score[4];
  char  grade;
  double ave;
} Record;

char grade_char(double);
Record input(void);
void output(Record);

int main(int argc,char *argv[]){
  Record data[N];
  char student[N];
  FILE *fp;
  char buf[1000];
  int i,j,status,nameid,f=0;

  if(argc!=2){
    printf("Usage:%s datafilename\n",argv[0]);
    exit(8);
  }
  fp=fopen(argv[1],"r");
  for(i=0;i<N;i++){
    fscanf(fp,"%7s",data[i].sid);
    fscanf(fp,"%s",data[i].surname);
    fscanf(fp,"%d",&data[i].score[0]);
    fscanf(fp,"%d",&data[i].score[1]);
    fscanf(fp,"%d",&data[i].score[2]);
    status=fscanf(fp,"%d",&data[i].score[3]);
    data[i].ave=(double)((data[i].score[0]+data[i].score[1]+data[i].score[2]+data[i].score[3])/4);
    if(status==EOF)break;
  }

  for(j=0;j<i;j++){
    output(data[j]);
  }

  while(1){
    printf("Input a student name/ID :");
    nameid=scanf("%s",student);

    if(nameid==EOF)break;

    //リニアサーチ
    for(j=0;j<i;j++){
      if((strcmp(data[j].sid,student))==0){
	f=1;
	break;
	//printf("%s",data[j].sid);
      }
      else if((strcmp(data[j].surname,student))==0){
	f=1;
	//printf("%s",data[j].surname);
	break;
      }
      else{
	f=-1;
      }
    }

    if(f<0){
      printf("This student does not exist!\n");
    }
    else if(f>0){
      output(data[j]);
    }
  }
  fclose(fp);
  return 0;
}

char grade_char(double score){//成績の文字を返す関数
  if(0<=score && score<=34){
    return 'F';
  }
  else if(35<=score && score<=49){
    return 'D';
  }
  else if(50<=score && score<=64){
    return 'C';
  }
  else if(65<=score && score<=79){
    return 'B';
  }
  else {
    return 'A';
  }
}

void output(Record data){
  char grade;
  grade=grade_char(data.ave);
  printf("%-10s%-10s%4d%4d%4d%4d%5.1lf%3c\n",data.sid,data.surname,data.score[0],data.score[1],data.score[2],data.score[3],data.ave,grade);

}

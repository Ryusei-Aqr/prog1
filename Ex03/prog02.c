#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#define N 32

int main(){
  int status;
  double num,max=0,min=DBL_MAX;
  FILE *fp1,*fp2;
  //FILE open
  if((fp1=fopen("rand.in","r"))==NULL){
    exit(2);
  }
  if((fp2=fopen("rand.out","w"))==NULL){
      exit(2);
    }

   //FILE input&output
  while(1){

    status=fscanf(fp1,"%lf",&num);

    if(status==EOF)break;

    if(num>max){
      max=num;
    }
    else if(num<min){
      min=num;
    }
  }
 fprintf(fp2,"max=%.3lf",max);
  fprintf(fp2,",min=%.3lf\n",min);



  
  //FILE close
  fclose(fp1);
  fclose(fp2);
  return 0;
   
    
  }

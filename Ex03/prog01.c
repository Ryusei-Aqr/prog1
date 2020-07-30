#include<stdio.h>
#include<stdlib.h>
#define N 1000

char cnv(char);
char cnv2(char);
char cnv3(char);

int main(){
  int i,cnt=0,c;
  char buf[N],ch,ch2,ch3;
  FILE *fpin,*fpout;
  fpin=fopen("data.in","r");//読み込んで格納する

  if(fpin==NULL){
    printf("read file open error\n");
    exit(1);
  }

  fpout=fopen("data01.out","w");//大文字を小文字にして出力、全てを大文字にして出力、小文字を大文字にし大文字に小文字にして出力する

  if(fpout==NULL){
    printf("write file open error\n");
    fclose(fpin);
    exit(2);
  }
  
 //格納
  for(i=0;i<N;i++){
    c=fgetc(fpin);
    if(c==EOF)break;
    buf[i]=(char)c;
    cnt=i;
  }
  
for(i=0;i<=cnt;i++){
  fprintf(fpout,"%c",cnv(buf[i]));
     //関数の呼出し
    //ch=cnv(buf[i]);
  //fputc(ch,fpout);
 }

for(i=0;i<=cnt;i++){
  fprintf(fpout,"%c",cnv2(buf[i]));
     //関数の呼出し
  // ch2=cnv2(buf[i]);
  //fputc(ch2,fpout);
 } 

  for(i=0;i<=cnt;i++){
    fprintf(fpout,"%c",cnv3(buf[i]));
     //関数の呼出し
    //ch3=cnv3(buf[i]);
  //fputc(ch3,fpout);
 } 

  
  fclose(fpout);
  fclose(fpin);
  return 0;
}


char cnv(char in){
  if('A'<=in && in<='Z'){
    return in+32;//小文字に変換
  }else{
    return in;
}
}

  char cnv2(char in){
  if('a'<=in && in<='z'){
    return in-32;//大文字に変換
  }else {
    return in;
  }
  }

  char cnv3(char in){
  if('A'<=in && in<='Z'){
    return in+32;//小文字を大文字に、大文字を小文字に変換
  }
  else if ('a'<=in && in<='z'){
    return in-32;
  }else {
    return in;
  }
  }

  

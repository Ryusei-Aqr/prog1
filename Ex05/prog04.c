#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * MAXDATA:最大データ数
 * LENIP  :IPアドレスの最長文字数+1
 * LENHOST:最長文字数+1
 */
#define MAXDATA 1024
#define LENIP   16
#define LENHOST 256

int main(){
  int i;
  int ndata;
  FILE *fp;
  char ipadr[MAXDATA][LENIP];
  char host [MAXDATA][LENHOST];
  char query[LENHOST];
  /* その他必要な変数を定義して良い */
  int j;
  char *s,t;
  /*** データの読み出し処理 ***/
  /* ファイルのオープン */
    fp = fopen("stdhosts.txt","r");
  if (fp == NULL) {
    printf("Cannot open file!\n");
    exit(1);
  }
  /* データの読み出し */
  for( i=0 ; i < MAXDATA ; i++ ){
    /* ２項目読めなければループを抜ける */
    if (fscanf(fp,"%s %s",
      ipadr[i],host[i]) != 2) break;
    //printf("%d,%d",ipadr[i],host[i]);
  
  ndata=i;
  }
  /*** 問合せの処理 ***/
  while(1){
    int r;
    r=0;
    s=fgets(query,LENIP,stdin);
      if(s==NULL)break;
      strtok(s,"\n");
	/*t=scanf("%s",query);
	  if(t==EOF)break;*/
    /* 文字列の配列の使用方法に注意      *
     * host[xxx]でxxx番目の文字列を示す */
    //printf("%s\n",s);
    //printf("%s\n",host[j]);
      
    for(j=0;j<ndata;j++){
      if(strcmp(host[j],query)==0){
	r=1;
	break;
      }
    }
    if(r==1){
      printf("%s %s\n",host[j],ipadr[j]);
    }
    else{
      printf("%s is not found!!\n",query);
    }
  }
  printf("\n");
  fclose(fp);
  return 0;
}

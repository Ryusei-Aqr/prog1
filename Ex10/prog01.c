#include <stdio.h>

int myatoi(char *);

int main()
{
  char str2[][20]={"  258.64",
		   " -38B",
		   "+45 678",
		   "B876",
		   "345-67",
		   "+-382",
		   ""};
  int ival, i;
  //行末にくるまで読み取る
  for ( i=0; str2[i][0]!='\0'; i++ ){
    ival = myatoi( str2[i] );
    printf("文字列:%s\n", str2[i]);
    printf("\n");
    printf("読み取り値:%d\n", ival);
    printf("\n");
  }
  return 0;
}

/* この後に関数 myatoi を作成する */
int myatoi(char *c){
  int i,mainasu=0,cnt=0,at[10],num=0;
  //空白飛し
  i=0;
  while(c[i]==' '){
    i++;
    cnt=i;
  }
   //符号の判定符号が続いたらreturn 0;
  if(c[cnt]=='-'){
    mainasu=-1;
    cnt++;
    if(c[cnt]=='-' || c[cnt]=='+'){
      return 0;
    }
  }
  else if(c[cnt]=='+'){
    cnt++;
    if(c[cnt]=='-' || c[cnt]=='+'){
      return 0;
    }
  }
  //printf("aiueo\n");
  
  //値をかえす
  i=0;
  while(1){
    if(c[cnt+i]>='0' &&  c[cnt+i]<='9'){
      at[i]=c[cnt+i]-'0';
      num*=10;
      num+=at[i];
      i++;
      }
    else {
      break;
    }
  }
  
  if(mainasu==-1){
    return num*(-1);
  }else{
    return num;
}
}

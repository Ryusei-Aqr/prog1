#include<stdio.h>
#include<stdlib.h>
int myatoi(char *);

/*標準入力をしてポインタで文字列を送り、帰ってきたint型によって出力を変更する*/
int main(){
    int i,wareki=0,cnt=0;
    char when[4],*c;
    printf("和暦を(H11等) :");
    scanf("%s",when);

       wareki=myatoi(&when[1]);//配列の１番目から渡す
       //printf("%d",wareki);
       if(wareki==0){printf("数字を読み取れません\n");return 0;}
    if(when[0]=='H')printf("Year (A.D.): %d\n",1989+wareki-1);
     if(when[0]=='S')printf("Year (A.D.): %d\n",1926+wareki-1);
      if(when[0]=='T')printf("Year (A.D.): %d\n",1912+wareki-1);
       if(when[0]=='M')printf("Year (A.D.): %d\n",1868+wareki-1);
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

#include<stdio.h>
#include<stdlib.h>
#define N 5
char grade_char(int);//点数を渡して評定を返す
//argcはコマンドラインの引数の数、argvには引数が格納される
int main(int argc, char *argv[]){
  int i,score;
  char hyotei;
  //配列を関数に渡す
  for(i=1;i<argc;i++){
      score=atoi(argv[i]);
      hyotei=grade_char(score);
      printf("Point %d:%c\n",score,hyotei);
  }

  return 0;
}

char grade_char(int score){//成績の文字を返す関数
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



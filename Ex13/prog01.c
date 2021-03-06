#include <stdio.h>

#define TATE 3
#define YOKO 4

struct arr {
  int a[TATE][YOKO];
};

void change_ary1(int (*p)[YOKO]);
void change_ary2(int x[TATE][YOKO]);
void change_ary3(struct arr);

void print_array(int x[TATE][YOKO]);

int main() {
  int i, j;
  int a1[TATE][YOKO] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
  int a2[TATE][YOKO] = { {1,2,3,4},{2,3,4,5},{3,4,5,6} };
  struct arr a3;

  for (i = 0; i < TATE; i++) {
    for (j = 0; j < YOKO; j++) {
      a3.a[i][j] = a1[i][j];
    }
  }
  /* 以下のコメント中の番号は 本課題を完成する手順の順番です*/

  printf("------ a1: -------\n");
  change_ary1(a1);
  /*
    4 3 2 1
    5 4 3 2
    6 5 4 3
  */
	
  printf("main-after change_ary1():\n");
  print_array(a1);
  printf("\n------- a2: -------\n");
  change_ary2(a2);
  /*
    4 3 2 1
    5 4 3 2
    6 5 4 3
  */

  printf("main-after change_ary2():\n");
  print_array(a2);


  printf("\n------- a3: -------\n");
  change_ary3(a3);
  /*
    4 3 2 1
    5 4 3 2
    6 5 4 3
  */

  printf("main-after change_ary3():\n");
  print_array(a3.a);

  /* （５）　上記３種類の処理結果の考察
     change_ary1,2の考察は予想通り反転されたがchange_ary3については予想が外れ反転はせずそのままの順番で表示された。1,2は配列の0番目のアドレスを渡しているの変更されるが3は構造体を渡しているので変更されない。main関数の中では変更されない
*/

  return 0;
}

/* 　（１）　配列内容出力 */
void print_array(int x[TATE][YOKO]) {
  int i,j;
  for(i=0;i<TATE;i++){
    for(j=0;j<YOKO;j++){
      printf("%2d",x[i][j]);
    }
    printf("\n");
  }
}

void change_ary1(int (*p)[YOKO]) {
  int i, j, v;
  printf("inside change_ary1(int(*p)[YOKO]):\n");
  printf("\tbefore:\n");
  print_array(p);

  /* （２）　引数の配列を左右反転 */

  for(i=0;i<TATE;i++){
    for(j=0;j<YOKO/2;j++){
      v=p[i][j];
      p[i][j]=p[i][YOKO -j -1];
      p[i][YOKO-j-1]=v;
    }
  }
	
  printf("\tafter:\n");
  print_array(p);
}
void change_ary2(int x[TATE][YOKO]) {
  int i, j, v;
  printf("inside change_ary2(int x[TATE][YOKO]):\n");

  printf("\tbefore:\n");
  print_array(x);

  /* （３）　引数の配列を左右反転 */
  for(i=0;i<TATE;i++){
    for(j=0;j<YOKO/2;j++){
      v=x[i][j];
      x[i][j]=x[i][YOKO -j -1];
      x[i][YOKO-j-1]=v;
    }
  }




  printf("\tafter:\n");
  print_array(x);
}
void change_ary3(struct arr x) {
  int i, j, v;
  printf("inside change_ary2(struct arr x):\n");

  printf("\tbefore:\n");
  print_array(x.a);

  /* （３）　引数の配列を左右反転 */
  for(i=0;i<TATE;i++){
    for(j=0;j<YOKO/2;j++){
      v=x.a[i][j];
      x.a[i][j]=x.a[i][YOKO -j -1];
      x.a[i][YOKO-j-1]=v;
    }
  }

  printf("\tafter:\n");
  print_array(x.a);
}

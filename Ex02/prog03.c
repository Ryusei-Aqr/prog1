#include <stdio.h>
#define N 5
#define EMPTY -1
#define FULL  -2

int func(int);

int main()
{
  int n, r;

  while (1) {
    printf("数値を入力して下さい (正：格納，負：取出，0：終了): ");
    scanf("%d", &n);
    if (n == 0) break; /* 終了 */
    r = func(n); /* 格納または取出 */
    func(0); /* 表示 */
    if (r > 0) printf("取り出したデータ: %d\n", r); /* 取得データの表示 */
    else if (r == EMPTY) printf("エラー（スタックが空です）\n"); 
    else if (r == FULL ) printf("エラー（スタックが満杯です）\n"); 
  }
  return 0;
}

/* 
[引数]
正の整数: 格納，負の整数: 取出，0: 表示
[戻り値]
格納の場合) スタックが満杯: マクロ定数 FULL，それ以外: 0
取出の場合) スタックが空: マクロ定数 EMPTY，それ以外: 取り出した値
表示の場合) 0
*/
int func(int x)
{
  static int stack[N]; /* データを格納する配列 */
  static int size = 0; /* データ数 */
  //ここから自作
  int i;
//push
if(x>0){
  stack[size]=x;
  size++;
printf("size= %d [",size);
for ( i=0; i<size; i++ ){ printf("%d ", stack[i]);}
printf("]\n");
if(x==N){
return FULL;
}
return 0;
}
//pop
else if(x<0){
  size--;
printf("size= %d [",size);
for ( i=size-1; i>=0; i-- ){ printf("%d ", stack[i]);}
printf("]\n");
  printf("取り出したデータ＝%d \n", stack[size]);
if(size<0){
  return EMPTY;
}
}
/*else if(x==0){
  return 0;
}:*/
  return 0;
}

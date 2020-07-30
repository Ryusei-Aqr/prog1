#include <stdio.h>
#define N 10

typedef struct {
  int map[N][N];
  int step;
  int msize, nsize;
} SMAP;

void routing(int, int, SMAP);
void mapprint(SMAP);

int pat=0; /* ゴールに到達したパターン数を記録するための外部変数 */

int main()
{
  SMAP smap;
  int i,j;

  printf("マスのサイズを入力して下さい(msize, nsize):\n");
  scanf("%d%d", &smap.msize, &smap.nsize);

  /* smapの初期化 */
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      smap.map[i][j]=0;
  smap.step=1;

  routing(smap.msize-1,smap.nsize-1,smap); /* msize-1, nsize-1から探索開始 */

  return 0;
}

void routing(int m, int n, SMAP smap)
{
  /* まずm, n がマップ（マス）外なら即return */
  /* m,nが0,0ならゴールなので、pat++し、マップ表示して、return */
  /* m,nの位置に数値があれば、なにもせずにreturn */
  /* m,nの位置が０ならstepを代入し、step++ */
  /* m,nの周辺４方向について、再度routingを呼び出す */
  /* 注）一般に配列は[縦][横]で使うが、 m,nはマスの
  　　　 横、縦を表すので、整合性に注意して下さい */

  /*************************
      ここを作成
  **************************/

  //printf("%d,%d,\n%d,%d\n",m,n,smap.msize,smap.nsize);
  
  if((m>=smap.msize || n>=smap.nsize)||(m<0 || n<0)) return;

 if(m==0 && n==0){
   pat++;
    printf("パターン:%d,経路長:%d\n",pat,smap.step);
    smap.map[m][n]=smap.step;
   mapprint(smap);
   return;
 }
 else if(smap.map[m][n]>0){
   return;
 }
 else if(smap.map[m][n]==0){
   smap.map[m][n]=smap.step++;

 routing(m-1,n,smap);
  routing(m+1,n,smap);
   routing(m,n-1,smap);
    routing(m,n+1,smap);
 
}
}

void mapprint(SMAP smap)
{
  /*************************
      ここを作成
  **************************/
  
  int i,j;
  for(i=0;i<smap.nsize;i++){
    for(j=0;j<smap.msize;j++){
      
      printf("%2d ",smap.map[j][i]);
    }
    printf("\n");
  }

}

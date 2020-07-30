#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;        /* アリの位置（横） */
  int y;        /* アリの位置（縦） */
  char dr;      /* 'R':右向き  'D':下向き */
  int in;       /* 1:アリは盤上にいる 0:既に盤外に出ている */
}AntPos;

int main(int argc, char *argv[])
{
  int w, h, n;  /* 幅、高さ、初期状態でのアリの数 */
  int t=0;      /* 時間ステップのカウンタ */
  int i, j, num,cnt=0,k;
  AntPos *ant;
  FILE *ifile;

  if (argc < 2) {
    printf( "error: input file name is required!\n");
    exit(1);
  }
  /* ファイルオープン */
  ifile=fopen(argv[1],"r");

  /* ファイルの1行目から盤の幅w、高さh、アリの数nを読み込む */
  fscanf(ifile,"%d%d%d",&w,&h,&n);
  //printf("%d%d%d\n",w,h,n);
  cnt=n;
  /* アリの情報を収めておく構造体配列を動的に確保 */
  ant=(AntPos *)malloc(n*sizeof(AntPos));
 
  /* ファイルから各アリの位置と向きを読み込む。なお、文字型を読む時は
     " %c"のように%c手前にスペースを入れると、R/D手前のスペースを読み飛ばせる。
     読み込めたら、確認のため読んだ情報を一度出力しておこう */
  for(i=0;i<n;i++){
    fscanf(ifile,"%d%d %c",&ant[i].x,&ant[i].y,&ant[i].dr);
    printf("%d %d %c\n",ant[i].x,ant[i].y,ant[i].dr);
    ant[i].in=1;
  }
  /* 1ステップごとのループ。盤上にいるアリの数が0になったら終了 */
  /* 時間の更新、アリの座標の更新、アリが盤の外に出たかどうかのチェックと表示、
     2匹のアリが同じマスにいるかどうかのチェックと（必要なら）向きの更新 */
  while(cnt!=0){
    t++;
    for(i=0;i<n;i++){
    
      if(ant[i].in==0)continue;
      //右向きのとき
      if(ant[i].dr=='R'){
	ant[i].x++;
	if(w<ant[i].x){
	  ant[i].in=0;
	  printf("Step %d: Ant No.%d has gone out to (%d,%d).\n",t,i+1,ant[i].x,ant[i].y);
	  cnt--;
	}
      }
      //下向きのとき
      else if(ant[i].dr='D'){
	ant[i].y++;
	if(h<ant[i].y){
	  ant[i].in=0;
	  printf("Step %d: Ant No.%d has gone out to (%d,%d).\n",t,i+1,ant[i].x,ant[i].y);
	  cnt--;
	}
      }
    }
    //ありが被っているのか、白黒どちらのマスにいるのか
    for(j=0;j<n;j++){
      for(k=j+1;k<n;k++){
	if(ant[j].x==ant[k].x && ant[j].y==ant[k].y){
	  //白にいるとき
	  if((t+ant[i].y)%2!=0){
	    if(ant[j].dr=='R'){
	      ant[j].dr='D';
	      ant[k].dr='R';
	    }
	    else{
	      ant[k].dr='D';
	      ant[j].dr='R';
	    }
	  }
	}
      }
    }
  }
    //printf("Step %d: Ant No.%d has gone out to (%d,%d).\n",t,i+1,t+w,t+h);
    fclose(ifile);
    return 0;
}

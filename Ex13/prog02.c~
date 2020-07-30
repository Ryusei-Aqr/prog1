#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLACK '1'
#define WHITE '0'

#define PI 3.14159265358979323846264338

char **pbm_alloc(int, int);
void   pbm_free(char **, int, int);
char **pbm_read(int *x, int *y);
void   pbm_write(char **, int, int);
void   pbm_circle(char **, int, int, int, char);

int main() {
	char **pbm;
	int i;
	int ix, iy, r;

	/* 標準入力から入力された画像に合わせて領域を確保し、画素を読み込む */
	pbm = pbm_read(&ix, &iy);

	/* 外周円の半径を画像サイズに合わせて決める */
	if (ix>iy) r = iy / 2;
	else r = ix / 2;

	r--;

	/* 円を書く */
	pbm_circle(pbm, ix, iy, r, '1');
	pbm_circle(pbm, ix, iy, r/2, '1');

	/* 画像を書きだす */
	pbm_write(pbm, ix, iy);
	/* 画像領域の解放 */
	pbm_free(pbm, ix, iy);
	return 0;
}
//横幅と高さ
char **pbm_alloc(int x, int y) {
	char **data;
	int i;
	
	/* ２次元配列の作成 */
	
	data=(char **)malloc(y*sizeof(char *));

	for(i=0;i<y;i++){
	  
	  data[i]=(char *)malloc(x*sizeof(char ));

	  if(data[i]==NULL){
	    free(data);
	    return NULL;
	  }
	}

	return data;
}

void  pbm_free(char **pbm, int x, int y) {
	int i;
	for (i = 0; i<y; i++)
		free(pbm[i]);
	free(pbm);
}

void   pbm_write(char **pbm, int x, int y) {
	int i, j;
	/* 最初にP1とx,yの画素数を出力 */
	printf("P1\n");
	printf("%d %d\n", x, y);
	/* 実際のデータ出力 */
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			printf("%c ", pbm[i][j]);
		}
		printf("\n");
	}
}

char **pbm_read(int *x, int *y) {
  char **data;
  int yoko,tate,i,j,*xp,*yp;
//白黒画像の画像形式がPlainPBMとなっているので必ず最初にP1読み込まれるのでその判定をする必要がある
  if(getchar()!='P' || getchar()!='1'){
    exit(2);
  }
  
  //アドレスの値を読み込むので&は不要
  scanf("%d%d",x,y);
  data=pbm_alloc(*x,*y);
  
  if(data==NULL)exit(1);
 
				     
  //データの入力、jが横
  for(i=0;i<*y;i++){
    for(j=0;j<*x;j++){
      scanf(" %c",&data[i][j]);
    }
  } 
 
  return data;
}



/********************************************/
/* 画像に円を描画                         */
/* pbm, x, y: 画像データの配列と大きさ      */
/* r: 円の半径　　　                        */
/* col: 線分の色(0か1)                      */
/********************************************/
void   pbm_circle(char **pbm, int x, int y, int r, char col) {
  //円を求めて画素を黒くする
  int i,xp=0,yp=0;
  double cx=0.0,cy=0.0,rad=0.0;
  //中心の座標
  cx=x/2;
  cy=y/2;
  //度数法を使う
  rad=(PI/180);
  for(i=0;i<360;i++){
    xp=(int)(cx+r*cos(rad*i));
    yp=(int)(cy+r*sin(rad*i));
	pbm[yp][xp]=col;
    }
  }


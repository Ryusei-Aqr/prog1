#include <stdio.h>
#include <stdlib.h>

#define BLACK '1'
#define WHITE '0'

char **pbm_alloc(int, int);
void   pbm_free(char **,int, int);
char **pbm_read(int *, int *);
void   pbm_write(char **, int, int);
/*エロージョンを使う関数、収縮、注目する画素とその周辺の画素が全て黒なら結果を黒に、それ以外は白にする*/
char **pbm_erode(char **, int, int);
/*ダイレーションを使う関数、膨張*、注目する画素とその周辺の画素が一つでも黒なら結果を黒に、それ以外は白にする*/
char **pbm_dilate(char **, int, int);


int main(){
  char **pbm1, **pbm2;
  int ix,iy;

  pbm1 = pbm_read(&ix,&iy);
  if(pbm1==NULL){
    fprintf(stderr,"Invlid image format.");
    exit(1);
  }

#ifdef ERODE
  pbm2=pbm_erode(pbm1,ix,iy);
  pbm_free(pbm1,ix,iy);
#elif DILATE
  pbm2=pbm_dilate(pbm1,ix,iy);
  pbm_free(pbm1,ix,iy);
#else
  pbm2=pbm1;
#endif

  /* 画像を書きだす */
  pbm_write(pbm2,ix,iy);
  /* 画像領域の解放 */
  pbm_free(pbm2,ix,iy);
  return 0;
}

/*erodeとdilateの作成*/
char **pbm_erode(char **pbm, int x, int y){
  char **erode;
  int i,j;
  
  erode=pbm_alloc(x,y);
  
  //全ての範囲を回す
  for(i=1;i<y-1;i++){
    for(j=1;j<x-1;j++){
      //全て黒なら黒を格納しそれ以外なら白を格納する
      if(pbm[i][j]==BLACK && pbm[i+1][j]==BLACK && pbm[i-1][j]==BLACK && pbm[i][j+1]==BLACK && pbm[i][j-1]==BLACK){
	erode[i][j]=BLACK;
      }else{
	erode[i][j]=WHITE;
      }
    }
  }
  
      /*0 i+1行目について注目点が黒なら黒にし白なら白にする
	１からi-１列目について黒の時に黒、白の時は白を格納*/
   for(i=0;i<=y-1;i++){
    for(j=0;j<=x-1;j++){
      if(i-1<0 || i+1>y){
	if(erode[i][j]==BLACK){
	  erode[i][j]=BLACK;
	}else{
	  erode[i][j]=WHITE;
	}
      }
      
      if(j-1<0 || j+1>x){
	if(erode[i][j]==BLACK){
	  erode[i][j]=BLACK;
	}else{
	  erode[i][j]=WHITE;
	}
      }
    }
  }
    return erode;
  }

char **pbm_dilate(char **pbm, int x, int y){
  char **dilate;
  int i,j;

  dilate=pbm_alloc(x,y);

   
  //全ての範囲を回す
  for(i=1;i<y-1;i++){
    for(j=1;j<x-1;j++){
      //全て黒なら黒を格納しそれ以外なら白を格納する
      if(pbm[i][j]==WHITE && pbm[i+1][j]==WHITE && pbm[i-1][j]==WHITE && pbm[i][j+1]==WHITE && pbm[i][j-1]==WHITE){
	dilate[i][j]=WHITE;
      }else{
	dilate[i][j]=BLACK;
      }
    }
  }
  
      /*0 i+1行目について注目点が黒なら黒にし白なら白にする
	１からi-１列目について黒の時に黒、白の時は白を格納*/
   for(i=0;i<=y-1;i++){
    for(j=0;j<=x-1;j++){
      if(i-1<0 || i+1>y){
	if(dilate[i][j]==BLACK){
	  dilate[i][j]=BLACK;
	}else{
	  dilate[i][j]=WHITE;
	}
      }
      
      if(j-1<0 || j+1>x){
	if(dilate[i][j]==BLACK){
	  dilate[i][j]=BLACK;
	}else{
	  dilate[i][j]=WHITE;
	}
      }
    }
  }
  
  return dilate;}


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

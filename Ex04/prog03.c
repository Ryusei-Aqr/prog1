#include<stdio.h>
#define N 256
//strcpyは使っちゃだめ
int main()
{
  char str[N], str_new[N];
  int i;

  printf("Input : ");
  scanf("%s",str);   /* 1単語を標準入力から入力 */

  i = 0;
  //printf("%c\n",str[i]);
  while (str[i]!='\0'){ /* 単語の最後に達していなければ繰り返す */
    /* 文字が A〜Z, a〜z ならそのままstr_newにコピー */
    /* 文字がそれ以外ならstr_newに' 'を代入する処理を書く */
    /* その他、ループ関連の処理も */
    if(('A'<=str[i] && str[i]<='Z') || ('a'<=str[i]&& str[i]<='z')){
    str_new[i]=str[i];
    }
    else{
    str_new[i]=' ';
    }
    i++;
    //printf("a\n");
  }
  /* str_newの末尾の処理も必要 */
str_new[i]='\0';
  printf("Before : %s\n", str);
  printf("After  : %s\n", str_new);
  return 0;
}

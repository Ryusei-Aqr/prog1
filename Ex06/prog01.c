#include <stdio.h>
#include <ctype.h> /* 関数toupperを使うため */

void printFavoriteVehicle(char *favoritevehicle);

int main() {
  char *vehicles[]={"train", "car", "motorbike"};
  int i;

  printf("Suppose that we now have (0) %s, (1) %s, (2) %s.\n",
                                    vehicles[0],vehicles[1],vehicles[2]);
  printf("Which do you like?\n");
  printf("Input 0, 1, or 2: ");
  scanf("%d",&i);//iの領域
  
  if(0 <= i && i <= 2) { /* i が 0-2 の範囲になければエラーを避けるため何もしない */
    printFavoriteVehicle(*vehicles);
  }  
  return 0;
}
//アドレス渡しを行う、配列のポインタは要素の０番目を指す、%sは文字列の出力なのでヌル文字まで出力できる
void printFavoriteVehicle(char *favoritevehicle) {
  
  printf("%c",toupper(*favoritevehicle)); /* 最初の文字を大文字で出力 */
  printf("%s",favoritevehicle+1); /* 二文字目以降を出力 */
  printf(" is your favorite vehicle!\n");
  
}

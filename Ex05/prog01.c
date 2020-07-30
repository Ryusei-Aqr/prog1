#include <stdio.h>
int main()
{
   int i;
   int array[] = {11,22,33,44};//int型は4バイトを使うため4ずつ増える
//追加文
//longは4バイト使う
//charは1バイト使う
//doubleは8バイト使う
long l_array[] = {123,234,345,456};//アドレスは4ずつ増える
char c_array[] = {'a','b','c','d'};//アドレスは1ずつ増える
char *str_array[] = {"A","BC","DEF","GHIJK"};//アドレスは4ずつ増える
double d_array[] = {1e-3, 2e-4, 3e-5, 4e-6};//アドレスは8ずつ増える
char array_2dc[][10] = {"a","bcde","fgh","ij"};//アドレスは10ずつ増える
/*口頭採点
アドレスの増えかたは型によって異なり、charは1バイト、longは4バイト、double8はバイトずつ増える
また、メモリのアドレスは16進数で増える(1・・・9a・・・f)*/

   for(i = 0 ; i < 4 ; i++)
     printf( "%d %p %d\n",i,&array[i],array[i]);
   printf("\n%p\n\n",array);
for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %ld\n",i,&l_array[i],l_array[i]);
   printf("\n%p\n\n",l_array);
for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %c\n",i,&c_array[i],c_array[i]);
   printf("\n%p\n\n",c_array);
for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %s\n",i,&str_array[i],str_array[i]);
   printf("\n%p\n\n",str_array);
for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %f\n",i,&d_array[i],d_array[i]);
   printf("\n%p\n\n",d_array);
for(i = 0 ; i < 4 ; i++)
    printf( "%d %p %s\n",i,&array_2dc[i],array_2dc[i]);
   printf("\n%p\n\n",array_2dc);
   
   return 0;
}

#include<stdio.h>
#include"prog03_1.h"

#if defined TEST
int main(){

  printf("test\n");
  return 0;
}
#endif

vector CalcCentroid(vector in){
  vector result;

  result.cent[0] = (in.vec1[0] + in.vec2[0] + in.vec3[0])/3;
  result.cent[1] = (in.vec1[1] + in.vec2[1] + in.vec3[1])/3;

  return result;
}

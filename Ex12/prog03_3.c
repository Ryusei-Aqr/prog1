#include<stdio.h>
#include"prog03_1.h"

#if defined TEST
int main(){
  
  vector point;

  //point = (vector *)malloc(sizeof(vector));
  
  point = IuputShape();
  
  printf("vec_last: %f %f",point.vec3[0],point.vec3[1]);
 
  
  return 0;
}
#endif

vector InputShape(){
    
  vector result;

  printf("Vertex 1:");
  scanf("%lf %lf",&(result.vec1[0]),&(result.vec1[1]));
  
  printf("Vertex 2:");
  scanf("%lf %lf",&(result.vec2[0]),&(result.vec2[1]));
  
  printf("Vertex 3:");
  scanf("%lf %lf",&(result.vec3[0]),&(result.vec3[1]));

  return result;
} 

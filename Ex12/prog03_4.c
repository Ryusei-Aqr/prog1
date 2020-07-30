#include<stdio.h>
#include<math.h>
#include"prog03_1.h"
  

//int isTriangle(vector);
#ifdef test
int main(){
    
  int hantei;
    
  struct vector vectol[3]={
    {1.0,2.0},
    {1.0,8.0},
    {1.0,12.0},
  };
    
  hantei=isTriangle(vectol);
    
  printf("%d\n",hantei);
  return 0;
}
#endif

int IsTriangle(vector triangle){
  // double a,b,c,d1=0,d2=0,d3=0;
  int t=0;
  /*
  a=((triangle.vec2[0]-triangle.vec1[0])*(triangle.vec2[0]-triangle.vec1[0]))+((triangle.vec2[1]-triangle.vec1[1])*(triangle.vec2[1]-triangle.vec1[1]));
  d1=sqrt(a);
  
  b=((triangle.vec2[0]-triangle.vec1[0])*(triangle.vec2[0]-triangle.vec1[0]))+((triangle.vec2[1]-triangle.vec1[1])*(triangle.vec2[1]-triangle.vec1[1]));
  d2=sqrt(b);
  
  c=((triangle.vec2[0]-triangle.vec1[0]))*((triangle.vec2[0]-triangle.vec1[0]))+((triangle.vec2[1]-triangle.vec1[1]))*((triangle.vec2[1]-triangle.vec1[1]));
  d3=sqrt(c);
  
  if(d1+d2>+d3 && d2+d3>=d1 && d3+d1>=d2){
    //t=1;
    return 1;
  }
  else{
    //t=-1;
    return -1;
    }*/
  vector a;
  a=GetArea(triangle);
  if(a.area==0){
    return -1;
  }
  else return 1;
  
}

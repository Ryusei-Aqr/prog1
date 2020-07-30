#include <stdio.h>
#include "prog03_1.h" /* (1) */
 /* 必要に応じてプログラムを追加、修正 */
 #if defined TEST
int main () {/* (2) */
   vector vertex1,vertex2;
   int a;
   double area1,area2;
   while(1)
     {
        /* 1番目の三角形のパラメータ（３頂点）を入力する */
   printf("Input 1st triangle:\n");
  	vertex1 = InputShape(/*引数なし*/);
	a = isTriangle(vertex1);
	if(a  == 0)
	  {
	/* IsTriangleの結果を元に先へ進むか，InputShapeで再入力へ */
	    printf("These data can not form a triangle!\n");
	    printf("Again,");
	  } else break;
     }
   printf("V1: (%f, %f)\n",vertex1.vec1[0],vertex1.vec1[1]);
   printf("V2: (%f, %f)\n",vertex1.vec2[0],vertex1.vec2[1]);
   printf("V3: (%f, %f)\n",vertex1.vec3[0],vertex1.vec3[1]);
   while(1)
     {
	
        /* 2番目の三角形のパラメータ（３頂点）を入力する */
       printf("Input 2nd triangle:\n");
  	vertex2 = InputShape(/*引数なし*/);
	a = isTriangle(vertex2);
	if(a == 0)
	  {
	/* IsTriangleの結果を元に先へ進むか，InputShapeで再入力へ */
	    printf("These data can not form a triangle!\n");
	    printf("Again,");
	  } else break;
     }
   printf("V1: (%f, %f)\n",vertex2.vec1[0],vertex2.vec1[1]);
   printf("V2: (%f, %f)\n",vertex2.vec2[0],vertex2.vec2[1]);
   printf("V3: (%f, %f)\n",vertex2.vec3[0],vertex2.vec3[1]);
	
	vertex1 = GetArea(vertex1);
	vertex2  = GetArea(vertex2);

	printf("Area of 1st one: %f   Area of 2nd one: %f",vertex1.area,vertex2.area);

        /* 面積の大きい方を表示 */
	if(vertex1.area > vertex2.area)
	  printf("The 2nd one is larger than the 1st one!\n");
	else printf("The 1st one is larger than the 2nd one!\n");

	 vertex1 = CalcCentroid(vertex1);
	 vertex2 = CalcCentroid(vertex2);
	printf("Centroid of 1st one: (%f, %f)",vertex1.cent[0],vertex1.cent[1]); 
        printf("Centroid of 2nd one: (%f, %f)",vertex2.cent[0],vertex2.cent[1]);
        return 0;
}
#endif
vector GetArea(vector vertex)
{
  double a;
  a = (vertex.vec1[0] - vertex.vec3[0])*(vertex.vec2[1] - vertex.vec3[1]) - (vertex.vec2[0] - vertex.vec3[0])*(vertex.vec1[1] - vertex.vec3[1]);
  if(a < 0) a = a*(-1);
  vertex.area = 0.5*a;
  
  return vertex;
}

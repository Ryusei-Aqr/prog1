typedef struct{
  double vec1[2];
  double vec2[2];
  double vec3[2];
  double cent[2];
  double area;
}vector;

int IsTriangle(vector);
vector InputShape(void);
vector CalcCentroid(vector);
vector GetArea(vector);
	     

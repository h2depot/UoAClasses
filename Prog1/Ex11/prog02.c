#include <stdio.h>
#include <math.h>
 
typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;
 
Point rotate1(double, Point, Point);
void  rotate2(double, Point *, Point *);
Point rotate3(double, Point *);
void  rotate4(double, Point *);
 
int main()
{
  double rad, deg;
  Point c = {1.0, 1.0}, a = {2.0, 3.0}; /* 中心と回転対象の点 */
  Point b1, b2, b3;         /* 結果を入れる構造体 */
  Point array3[2]={c,a},array4[3]={c,a};
 
  printf("回転角 [度] を入力してください\n");
  scanf("%lf", &deg);
  rad = deg*M_PI/180;
  printf("回転角 %f [deg] (%f [rad])\n", deg, rad);
  
  /*b1 = rotate1(rad,c,a);
  b2 = a; 
  rotate2(rad,&c,&b2);*/

  b3 = rotate3(rad,array3);
  rotate4(rad,array4);
 
  printf("Center  : %f %f\n", c.x, c.y);
  printf("Point A : %f %f\n", a.x, a.y);
  //printf("Point B (rotate1) : %f %f\n", b1.x, b1.y);   /* rotate1関数の結果を出力 */
  //printf("Point B (rotate2) : %f %f\n", b2.x, b2.y);   /* rotate2関数の結果を出力 */
  printf("Point B (rotate3) : %f %f\n", b3.x, b3.y);
  printf("Point B (rotate4) : %f %f\n", array4[2].x, array4[2].y);

  return 0;
}

Point rotate1(double arg, Point c, Point a){
  Point temp;
  temp.x = (a.x-c.x) * cos(arg) + (a.y-c.y) * (-sin(arg)) + c.x;
  temp.y = (a.x-c.x) * sin(arg) + (a.y-c.y) * cos(arg) + c.y;

  return temp;
}

void rotate2(double argp, Point *cp,Point *b2){
  Point temp;

  temp=*b2;

  b2->x= (temp.x-cp->x) * cos(argp) + (temp.y-cp->y) * (-sin(argp)) + cp->x;
  b2->y= (temp.x-cp->x) * sin(argp) + (temp.y-cp->y) * cos(argp) + cp->y;
}

Point rotate3(double arga3, Point *array3){
  Point temp;

  temp.x = (array3[1].x-array3[0].x) * cos(arga3) + (array3[1].y-array3[0].y) * (-sin(arga3)) + array3[0].x;
  temp.y = (array3[1].x-array3[0].x) * sin(arga3) + (array3[1].y-array3[0].y) * cos(arga3) + array3[0].y;

  return temp;
}

void rotate4(double arga4, Point *array4){
  
  array4[2].x = (array4[1].x-array4[0].x) * cos(arga4) + (array4[1].y-array4[0].y) * (-sin(arga4)) + array4[0].x;
  array4[2].y = (array4[1].x-array4[0].x) * sin(arga4) + (array4[1].y-array4[0].y) * cos(arga4) + array4[0].y;
}
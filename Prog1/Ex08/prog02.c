#include <stdio.h>
#include <math.h>

typedef struct{
	double x; /* x座標 */
	double y; /* y座標 */
}XY; /* 平面上の点 */
 
typedef struct{
    XY center;
    double radius;
    double length;
    double area;
}CIRCLE; 

CIRCLE inputCircle(void);
void inputCirclePtr(CIRCLE *);

int main(){
    CIRCLE data,tmp1;

    data = inputCircle();
    printf("Circle1:\n  Center, Radius : (%f,%f), %f\n  Length, Area : %f, %f\n",data.center.x,data.center.y,data.radius,data.length,data.area);


    inputCirclePtr(&tmp1);
    printf("Circle2:\n  Center, Radius : (%f,%f), %f\n  Length, Area : %f, %f\n",tmp1.center.x,tmp1.center.y,tmp1.radius,tmp1.length,tmp1.area);

  return 0;
}

CIRCLE inputCircle(){
    XY inputc,inputr;
    CIRCLE tmp;
    printf("構造体を返す関数 (inputCircle):\n円の中心点の座標と円周上の1点の座標を入力:\n");
    scanf("%lf%lf%lf%lf",&inputc.x,&inputc.y,&inputr.x,&inputr.y);
    tmp.center = inputc;
    tmp.radius = sqrt((inputr.x - tmp.center.x)*(inputr.x - tmp.center.x)+(inputr.y - tmp.center.y)*(inputr.y - tmp.center.y));
    tmp.length = tmp.radius*2*M_PI;
    tmp.area = tmp.radius*tmp.radius*M_PI;

    return tmp; 
}

void inputCirclePtr(CIRCLE *circle){
    XY inputc1,inputr1;
    printf("構造体ポインタを使う関数 (inputCirclePtr):\n円の中心点の座標と円周上の1点の座標を入力:\n");
    scanf("%lf%lf%lf%lf",&inputc1.x,&inputc1.y,&inputr1.x,&inputr1.y);
    circle->center = inputc1;
    circle->radius = sqrt((inputr1.x - circle->center.x)*(inputr1.x - circle->center.x)+(inputr1.y - circle->center.y)*(inputr1.y - circle->center.y));
    circle->length = circle->radius*2*M_PI;
    circle->area = circle->radius*circle->radius*M_PI;
}
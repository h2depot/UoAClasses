#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
  double x;
  double y;
};


void Coffo(int,struct point,struct point);

int main(){
  int n;
  struct point p1,p2;
  p1.x=0;
  p1.y=0;
  p2.x=100;
  p2.y=0;
  scanf("%d",&n);
  printf("%f %f\n",p1.x,p1.y);
  Coffo(n,p1,p2);
  printf("%f %f\n",p2.x,p2.y);
  return 0;
}

void Coffo(int n,struct point p1,struct point p2){
  struct point t,u,s;
  double theta=M_PI/3;

  if(n==0)return;

  s.x=(p2.x-p1.x)/(double)3+p1.x;
  s.y=(p2.y-p1.y)/(double)3+p1.y;
  t.x=(p2.x-p1.x)*2/(double)3+p1.x;
  t.y=(p2.y-p1.y)*2/(double)3+p1.y;
  u.x=(t.x-s.x)*cos(theta)-(t.y-s.y)*sin(theta)+s.x;
  u.y=(t.x-s.x)*sin(theta)+(t.y-s.y)*cos(theta)+s.y;
 

  Coffo(n-1,p1,s);
  printf("%f %f\n",s.x,s.y);
  Coffo(n-1,s,u);
  printf("%f %f\n",u.x,u.y);
  Coffo(n-1,u,t);
  printf("%f %f\n",t.x,t.y);
  Coffo(n-1,t,p2);
}

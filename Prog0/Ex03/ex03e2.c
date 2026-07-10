#include <stdio.h>

int main()

{
  double a,b,c,d,e,ave;
  
  printf("5人分の体重を空白で分けて入力してください\n");
  scanf("%lf%lf%lf%lf%lf", &a,&b,&c,&d,&e);

  ave = (a + b + c + d + e) / 5;
  
  printf("5人の体重の平均値:%6.1f[kg]\n", ave);

  printf("1人目の体重:%6.1f[kg]、平均からの偏差:%+6.1f[kg]\n",a, a - ave);
  printf("2人目の体重:%6.1f[kg]、平均からの偏差:%+6.1f[kg]\n",b, b - ave);
  printf("3人目の体重:%6.1f[kg]、平均からの偏差:%+6.1f[kg]\n",c, c - ave);
  printf("4人目の体重:%6.1f[kg]、平均からの偏差:%+6.1f[kg]\n",d, d - ave);
  printf("5人目の体重:%6.1f[kg]、平均からの偏差:%+6.1f[kg]\n",e, e - ave);

  return 0;
}

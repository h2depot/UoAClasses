#include <stdio.h>

double aveandsub_ptr(double *, double *, double *);   /* プロトタイプ宣言 */

int main()
{
  double a, b, c, ave;

  printf("3つ値を入力してください:\n");
  scanf("%lf%lf%lf", &a, &b, &c);

  ave = aveandsub_ptr( &a, &b, &c);   /* 関数の呼び出し */

  printf("平均:  %.3f\n", ave);
  printf("平均からの差分:  %+.3f  %+.3f  %+.3f\n", a, b, c);
  return 0;
}

/* 平均を計算して戻り値とするとともに、ポインタ渡しされた値も平均からの差分に書き換える関数。 */
double aveandsub_ptr(double *x, double *y, double *z)
{
  double avef;

  avef=(*x+*y+*z)/3;

  *x = *x - avef;
  *y = *y - avef;
  *z = *z - avef;
  
  return avef;
}
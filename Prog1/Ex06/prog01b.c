#include <stdio.h>

double aveandsub_arr(double []);   /* プロトタイプ宣言 */

int main()
{
  double data[3], ave;

  printf("3つ値を入力してください:\n");
  scanf("%lf%lf%lf", &data[0], &data[1], &data[2]);
  ave = aveandsub_arr(data);   /* 関数の呼び出し */

  printf("平均:  %.3f\n", ave);
  printf("平均からの差分:  %+.3f  %+.3f  %+.3f\n", data[0], data[1], data[2]);
  return 0;
}

/* 平均を計算して戻り値とするとともに、ポインタ渡しされた値も平均からの差分に書き換える関数。 */
double aveandsub_arr(double x[])
{
  double avef;
  int i;

  avef=(x[0]+x[1]+x[2])/3;
  for(i=0;i<3;i++){
    x[i]=x[i]-avef;
  }

  return avef;
}
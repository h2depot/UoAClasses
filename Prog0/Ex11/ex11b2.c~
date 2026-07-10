#include <stdio.h>

double round_to(double, int);

int main()
{
  int m;
  double num;
  printf("正の実数値を入力してください：");
  scanf("%lf", &num);

  printf("小数点以下の桁数を入力してください：");
  scanf("%d", &m);

  num = round_to(num, m);

  printf("%f\n", num);

  return 0;
}

double round_to(double x, int y)
{
  int i, ten=10;
  for (i=0; i < y; i++)ten = ten*10;
  int n = x*ten;
  n = (double)n/10 + 0.5;
  n = n*10;
  x = n/(double)ten;

  return x;
}

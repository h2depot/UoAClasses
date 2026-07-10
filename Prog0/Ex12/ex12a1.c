#include <stdio.h>

void function(double, double);

int main()
{
  double a,b;

  printf("係数aとbの値を入力してください：");
  scanf("%lf%lf", &a, &b);
  printf("関数の値は以下の通りです。\n");
  function(a,b);

  return 0;
}

void function(double a2, double b2)
{
  int x;
  double y;
  for (x=1;x<=4; x++)
    {
      y = a2*x + b2;

      printf("x = %d のとき y = %.1f\n", x, y);
    }
}

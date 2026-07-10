#include <stdio.h>

int main()

{
  int a;

  printf("整数値を入力してください: ");
  scanf("%d", &a);
  printf("入力された値は%dで、これを3で割った余りは%dです。\n", a, a%3);

  return 0;
}

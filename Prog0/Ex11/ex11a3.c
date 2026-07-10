#include <stdio.h>

int main()
{
  int a, b, value;

  printf("数値を2つ入力してください：");
  value = scanf("%d%d", &a, &b);
  printf("value = %d, a = %d, b = %d\n", value, a, b);

  return 0;
}

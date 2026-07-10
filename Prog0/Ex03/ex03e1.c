#include <stdio.h>

int main()

{
  int num10;

  printf("10進数を1つ入力してください：");

  scanf("%d", &num10);

  printf("%dは16進数で%xです\n", num10, num10);

  return 0;
}

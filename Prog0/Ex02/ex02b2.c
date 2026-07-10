#include <stdio.h>

int main()

{
  int length,width,height;

  printf("縦の長さを整数値で入力しなさい ");
  scanf("%d", &length);
  printf("横の長さを整数値で入力しなさい ");
  scanf("%d", &width);
  printf("高さを整数値で入力しなさい ");
  scanf("%d", &height);
  printf("体積：%d\n", length * width * height);
  printf("表面積：%d\n", length * width * 2 + width * height * 2 + length * height * 2);

  return 0;
}

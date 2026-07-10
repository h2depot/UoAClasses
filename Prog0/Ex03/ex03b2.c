#include <stdio.h>

int main()

{
  double num, cutnum;

  int intnum;

  printf("正の実数を1つ入力してください：");
  scanf("%lf", &num);

  intnum = num * 100;

  cutnum = (double)intnum / 100;

  printf("%f\n", cutnum);

  return 0;
  
}

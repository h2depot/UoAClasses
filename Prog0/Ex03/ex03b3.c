#include <stdio.h>

int main()

{
  int cash, pointsum, taxsum, sum;
  double  point = 0.1 , tax = 0.08;

  printf("商品代金（税抜き）を入力してください：");

  scanf("%d", &cash);

  taxsum = tax * cash;
  pointsum = point * cash;
  sum = cash + taxsum;

  printf("消費税は%d円、お支払い額は%d円です\n", taxsum, sum);

  printf("%dポイントつきました！\n", pointsum);

  return 0;
  
}

#include <stdio.h>

int main()

{
  int i = 12;
  double x = 34.5;

  printf("単位数は%04dです\n", i);
  printf("単位数は%-4dです\n", i);
  printf("単位数は%+4dです\n", i);
  printf("単位数は%4dです\n", i);
  printf("点数は%6.2f点です\n", x);
  printf("点数は%5.3E点です\n", x);
  printf("点数は%e点です\n", x);

  return 0;
}

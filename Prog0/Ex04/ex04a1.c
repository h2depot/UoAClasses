#include <stdio.h>

int main()

{
  int a = 0;
  int b = -1;

  if(a == 0) printf("条件式1は真\n");
  if(b != 0)  printf("条件式2は真\n");
  if(!b)  printf("条件式3は真\n");
  if(a + b > 0)  printf("条件式4は真\n");
  if(a * b <= 0)  printf("条件式5は真\n");
  if(a >=  0 && b >= 0)  printf("条件式6は真\n");
  if(a == 0 && b == 0)  printf("条件式7は真\n");
  if(a == 0 || b == 0) printf("条件式8は真\n");
  if(a > 0 || b < 0)  printf("条件式9は真\n");
  if(!(a == 0 || b == 0))  printf("条件式10は真\n");

  return 0;
}

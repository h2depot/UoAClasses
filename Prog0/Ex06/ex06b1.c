#include <stdio.h>

int main()
{
  int i,n, factorial = 1;

  printf("階乗を計算したい数を入力してください : ");
  scanf("%d", &n);

  if (n < 0 || n >= 13) printf("計算できません\n");
  else
  {
    for (i = n; i > 0 ; i--)
    {
      factorial = factorial * i;
    }
    printf("%d\n", factorial);
  } 

  return 0;
  
}

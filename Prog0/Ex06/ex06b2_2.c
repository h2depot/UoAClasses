#include <stdio.h>

int main()
{
  int i, j , n, r, factorial = 1, factorial2 = 1, c;

  printf("nとrを入力してください：");
  scanf("%d%d", &n, &r);

  for (i = n; i > n - r ; i--)
    {
      factorial = factorial * i;
    }


  for(j = r ; j > 0 ; j--)
    {
      factorial2 = factorial2 * j;
    }

  c = factorial / factorial2;

  printf("%dC%d = %d\n", n, r, c);

  return 0;
}

#include <stdio.h>

int main()
{
  int i, j , m, n, r, factorial = 1, factorial2 = 1, factorial3 = 1, c;

  printf("nとrを入力してください：");
  scanf("%d%d", &n, &r);

  for (i = n; i > 0 ; i--)
    {
      factorial = factorial * i;
    }

  for(j = n - r ; j > 0 ; j--)
    {
      factorial2 = factorial2 * j;
    }

  for(m = r ; m > 0 ; m--)
    {
      factorial3 = factorial3 * m;
    }

  c = factorial / factorial2 / factorial3;

  printf("%dC%d = %d\n", n, r, c);

  return 0;
  
}

#include <stdio.h>

int main()
{
  int i, j, n, count = 0, test = 0;

  for (i = 1; i < 6; i++)
    {
      printf("%d個目の整数を入力してください：", i);
      scanf("%d", &n);
      test = 0;

      if (n < 0)
	{
          printf("入力は正の整数にしてください\n");
	  continue;
        }
      else  if ( n == 0 || n == 1)
	{
          printf("入力された整数が%dなのでスキップします\n", n);
	  continue;
	}
      else
	{
          for (j = 2; j <  n -1; j++)
	    {
              if (n % j == 0)
		{
		  test = 1;
		  continue;
	        }
	    }
	  if (test == 0)
	    {
          printf("%dは素数\n", n);
	  count++;
	    }
	}
    }

  printf("素数は%d個ありました\n", count);
  
  return 0;
}

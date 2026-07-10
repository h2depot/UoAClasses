#include <stdio.h>

int main()
{
  int i, m = 0, array[11];

  for (i = 0 ; i <= 10 ; i++)
    {
      if (i == 0)
	{
	  array[i] = m;
	  printf("%3d:%8d\n", i, array[i]);
	}
      else
	{
	m = 2 * m + 1;
	array[i] = m;
	printf("%3d:%8d\n", i, array[i]);
        }
    }
}

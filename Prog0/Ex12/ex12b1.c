#include <stdio.h>
#include <stdlib.h>

void d2b(int);

int main()
{
  int data,keta,i,n,exp,total;

  while(1)
    {
      printf("10進数を入力してください：");
      scanf("%d", &data);

      if (data < 0)exit(0);

      if (data >= 256)
	{
          printf("256以上の値が入力されました\n");
	  continue;
	}
      d2b(data);
    }
  return 0;
}

void d2b(int x)
{
  int i = 128;
  int n;

  n = x;
  while (i != 0)
    {
      if(n/i == 1)
	{
	  printf("1");
	  n = n - i;
	}
      else if (n/i == 0)printf("0");
      i /= 2;
    }

  printf("\n");
}

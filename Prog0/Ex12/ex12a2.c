#include <stdio.h>

int digits(int);
int get_1_digit(int, int);

int main()
{
  int n;
  int keta, get_1;
  int i;
  

  printf("正の整数を入力してください：");
  scanf("%d", &n);

  keta = digits(n);

  printf("%dの桁数は%dです\n", n, keta);

  for (i=1;i<=keta;i++)
    {
      if ((keta+1 - i)%3 == 0 && i != 1)printf(",");
      get_1 = get_1_digit(n, keta+1 - i);
      printf("%d", get_1);


    }
  printf("\n");
  
  return 0;
}

int digits(int x)
{
  int keta = 1;

  while (x /= 10) keta++;

  return keta;
}

int get_1_digit(int x, int pos)
{
  int i,j;

  for (i=1;i<pos;i++)x /= 10;

  j = x % 10;

  return j;
}

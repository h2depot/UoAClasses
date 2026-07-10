#include <stdio.h>

int square(int);
double recipro(int);

int main(){

  int m,n;
  double res;

  printf("整数値を入力してください：");
  scanf("%d", &n);

  m=square(n);
  res = recipro(m);

  printf("n = %d, m = %d, res = %f\n", n, m, res);
  
  return 0;
}

int square(int x)
{
  return x*x;
}

double recipro(int x)
{
  return 1/(double)x;
}

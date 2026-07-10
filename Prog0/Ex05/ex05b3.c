#include <stdio.h>

int main()

{
  int m, n, f;

  printf("m n を入力して下さい：");
  scanf("%d%d", &m, &n);

  while(n != 0){

    printf("%d %% %d = %d\n", m, n, m%n);
    f = n;
    n = m % n;
    m = f;

  }

  printf("最大公約数は%dです\n", m);
  
  return 0;
}

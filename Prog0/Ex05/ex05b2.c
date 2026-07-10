#include <stdio.h>

int main()

{
  int n, count = 0;

  printf("0でない自然数nを入力\n");
  scanf("%d", &n);

  while( n != 1) {
    count++;
    printf("%d回目\n", count);
    if(n % 2 == 0){
      printf("%dは偶数\n", n);
      n /= 2;
    }
    else {
      printf("%dは奇数\n", n);
      n = n*3 + 1;
    }

    printf("次のn = %d\n\n", n);
    
  }

  printf("%d回目で n = 1になりました\n", count);
  return 0;
}

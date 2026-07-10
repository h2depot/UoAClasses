#include <stdio.h>

int main()
{
  int i;
  int count;
  int score;

  int L = 50;
  int U = 80;

  count = 0;
  printf("点数を入力してください\n");
  for(i = 0; i < 15; i++)
    {
      scanf("%d", &score);

      if( score < 0 ) break;
      if( score < L  || score >= U) continue;
      
      count++;
    }

  printf("%d点以上、%d点未満の答案の数は%dです\n", L, U, count);

  return 0;
}

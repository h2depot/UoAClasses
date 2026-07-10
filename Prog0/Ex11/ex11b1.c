#include <stdio.h>

int teaspoon(int);

int main()
{
  int n;
  
  printf("紅茶の杯数を入力してください：");
  scanf("%d", &n);
  if (n == 0)
    {
      printf("またどうぞ\n");
    }
  else{
  teaspoon(n);
  }

  
  return 0;
}

int teaspoon(int x)
{
  int i;
  for(i=1;i<=x;i++)
    {
      printf("%dさじ、", i);
    }
  printf("%dさじ\nお湯を注ぐ…\nお茶をどうぞ！\n", i);

  return x;
}

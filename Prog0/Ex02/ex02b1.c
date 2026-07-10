#include <stdio.h>

int main()

{
  int year;

  printf("平成元年（1989年）から平成31年（2019年）までの知りたい西暦を入力してください[1989-2019]:");
  scanf("%d", &year);
  printf("%d年は平成%d年です。\n", year, year - 1988);

  return 0;
}

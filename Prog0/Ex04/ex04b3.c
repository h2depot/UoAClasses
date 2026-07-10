#include <stdio.h>

int main()

{
  int mon;

  printf("月を入力してください：");
  scanf("%d", &mon);

  switch(mon){

  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    printf("%d月は31日間あります\n", mon);
    break;
  case 2:
    printf("%d月は28日間、または29日間です\n", mon);
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    printf("%d月は30日間あります\n", mon);
    break;
  default:
    printf("%d月は存在しません\n", mon);
  }
  return 0;
}

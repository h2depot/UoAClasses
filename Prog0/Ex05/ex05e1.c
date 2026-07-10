#include <stdio.h>

int main()

{

  int m, d, sum, pm;

  printf("月と日を空白で区切って入力してください：");
  scanf("%d%d", &m, &d);

  sum = d;

  pm = m;
  
  while(1){

    m = m-1;
    if (m == 0) break;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) sum = sum + 31;
    else if(m == 4 || m == 6 || m == 9 || m == 11) sum = sum + 30;
    else sum = sum + 28;
  }

  switch(sum % 7){

  case 0:
    printf("2023年%d月%d日は%d日目で土曜日です\n", pm, d, sum);
    break;

  case 1:
    printf("2023年%d月%d日は%d日目で日曜日です\n", pm, d, sum);
    break;

  case 2:
    printf("2023年%d月%d日は%d日目で月曜日です\n", pm, d, sum);
    break;

  case 3:
    printf("2023年%d月%d日は%d日目で火曜日です\n", pm, d, sum);
    break;

  case 4:
    printf("2023年%d月%d日は%d日目で水曜日です\n", pm, d, sum);
    break;

  case 5:
    printf("2023年%d月%d日は%d日目で木曜日です\n", pm, d, sum);
    break;

  case 6:
    printf("2023年%d月%d日は%d日目で金曜日です\n", pm, d, sum);
    break;
  }
  return 0;
}

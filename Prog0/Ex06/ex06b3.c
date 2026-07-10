#include <stdio.h>

int main()
{
  int i, p, n, gun = 10000, rate;

  printf("利率と期間を整数で入力してください：");
  scanf("%d%d", &p, &n);

  
  for ( i = n; i > 0; i--)
    {

       rate = gun * p / 100;

       gun = gun + rate;
      
    }
  printf("%dヶ月後の借金は%d円です\n", n, gun);
  
  return 0;
}

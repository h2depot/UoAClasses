#include <stdio.h>

int main()
{ 
  int i, j, array[7];

  printf("7人分の評点を入力してください。\n");

  for ( i = 0 ; i < 7 ; i++)
    {
      scanf("%d", &array[i]);
    }

  for ( j = 0 ; j < 7 ; j++)
    {
      if (array[j] >= 0 && array[j] < 35 ) printf("%d:  %-4dF\n", j, array[j]);
      else if ( array[j] >= 35 && array[j] < 50 ) printf("%d:  %-4dD\n", j, array[j]);
      else if ( array[j] >= 50 && array[j] < 65 ) printf("%d:  %-4dC\n", j, array[j]);
      else if ( array[j] >= 65 && array[j] < 80 ) printf("%d:  %-4dB\n", j, array[j]);
      else if ( array[j] >= 80 && array[j] <= 100) printf("%d:  %-4dA\n", j, array[j]);
      else printf("範囲外の値が入力されました。\n");
    }

  return 0;
}

#include <stdio.h>

#define SIZE 10

int main()
{
  int array[SIZE][SIZE];
  int n, m, s;
  int i, j;

  printf("行列の大きさを入力してください（最大10×10）：");
  scanf("%d%d", &n, &m);

  printf("%d × %d 行列を整数値で入力してください\n", n, m);
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      scanf("%d", &array[i][j]);

  printf("行列を何倍にしますか？");
  scanf("%d",&s);
  
  for (i=0;i<n;i++){
    for (j=0;j<m;j++){
      array[i][j] = array[i][j] * s;
      printf("%2d ", array[i][j]);
    }
    printf("\n");
  }

  return 0;
}

#include <stdio.h>

int main()
{
  int i, j, m, n;
  int inarray[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  int mat1[5][3], mat2[3][5];

  for (i=0;i<5;i++)
    for (j=0;j<3;j++)
      mat1[i][j] = inarray[i*3 + j];

  printf("1次元配列から5×3配列への変換結果\n");
  for (i=0;i<5;i++){
    for (j=0;j<3;j++){
      printf("%2d ", mat1[i][j]);
    }
    printf("\n");
  }

  for (m=0;m<3;m++)
    for (n=0;n<5;n++)
      {
	i = (m*5+n)/3;
	j = (m*5+n)%3;
	mat2[m][n] = mat1[i][j];
      }

  printf("5×3配列から3×5配列への変換結果\n");
  for (i=0;i<3;i++){
    for (j=0;j<5;j++){
      printf("%2d ", mat2[i][j]);
    }
    printf("\n");
  }
  return 0;
}

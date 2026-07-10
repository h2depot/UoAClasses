#include <stdio.h>

int main()
{
  int i, j, mat[][3]={1,2,3,4,5,6,7,8,9};

  for (i=0;i<3;i++)
    {
      for (j=0;j<3;j++)
	{
          printf("%d ", mat[i][j]);
	}
      printf("\n");
    }

  printf("行列の主対角線にある要素値\n");
      for (i=0;i<3;i++)
       {
         printf("%d ", mat[i][i]);
       }

  printf("\n");

  return 0;
}

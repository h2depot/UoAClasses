#include <stdio.h>
#define GYO 2
#define RETSU 3

int main()
{
  int i, j, k;
  int data, mat[GYO][RETSU];
  int MAX=GYO*RETSU;

  k=0;
  while(k<MAX){
    i=k/RETSU;
    j=k%RETSU;
    printf("%d行%d列の要素の値を正の整数で入力してください\n", i+1, j+1);
    scanf("%d", &data);

    if (data < 0){
      fprintf(stderr,"Error!負の値が入力されました\n");
      break;
    }

    mat[i][j]=data;
    k += 1;
  }

  if(data >= 0){
    printf("行列の値は\n");
    for (i=0; i<GYO; i++){
      for (j=0; j<RETSU; j++){
	printf("%d ", mat[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}

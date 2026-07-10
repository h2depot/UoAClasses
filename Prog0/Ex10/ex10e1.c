#include <stdio.h>
#include <stdlib.h>
#define MSIZE 800
#define COEF 1.5

int main()
{
  int dat[MSIZE][MSIZE];
  int i, j, width, height, maxval;

  if(getchar() != 'P' || getchar() != '2'){
    fprintf(stderr, "データの形式が違います\n");
    exit(1);
  }

  scanf("%d %d", &width, &height);
  scanf("%d", &maxval);

  if (width < 1 || height < 1 || width > MSIZE || height > MSIZE){
    fprintf(stderr, "設定サイズが範囲外です\n");
    exit(2);
  }

  if (maxval < 1 || maxval >= 65536){
    fprintf(stderr, "階調が範囲外です\n");
    exit(2);
  }

  for (i=0; i < height; i++){
    for (j=0; j<width; j++){
      if (scanf("%d", &dat[i][j]) != 1){
	fprintf(stderr, "データ入力に異常があります\n");
	exit(3);
      }
      if (dat[i][j] < 0 || dat[i][j] > maxval){
	fprintf(stderr, "データが異常でした\n");
	exit(4);
      }
    }
  }

  printf("P2\n");
  printf("%d %d\n", width, height);
  printf("%d\n", maxval);

  for (i=0; i < height; i++){
    for (j=0; j < width; j++){
      if(dat[i][j]>=maxval/2)dat[i][j] *= COEF;
      else if(dat[i][j]<maxval/2)dat[i][j] *= 1/COEF;
      printf("%2d ", dat[i][j]);
    }
    printf("\n");
  }
  return 0;
}

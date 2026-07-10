#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num, i;
  double v0, vn;
  double *x;

  /* 最初の値、最後の値、数値の個数を入力 */
  printf("最初の数値, 最後の数値, 個数を入力: ");
  scanf("%lf%lf%d", &v0, &vn, &num);

  /* これ以降を作成すること */

  /* メモリ確保 */
  x=(double*)malloc(num*sizeof(double));
 /* 格納する値の決定。
    端の値のぶんを考慮して分割数を決める事と、整数除算しないように注意 */
    for(i=0;;i++){
      *(x+i) = v0 + i*(vn-v0)/(num-1);
      if(*(x+i)==vn)break;
    }

  /* 結果の表示 */
    printf("数値の列\n");
    for(i=0;;i++){
      printf("%.3f ",*(x+i));
      if(*(x+i)==vn)break;
    }
    printf("\n数値の列\n");
    for(i=0;;i++){
      printf("%.3f ",*(x+i)*2);
      if(*(x+i)==vn)break;
    }
    printf("\n");
  /* メモリ確保したので後処理をする */
    free(x);

  return 0;
}
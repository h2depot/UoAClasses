#include <stdio.h>
#include <stdlib.h>

#define BLACK '1'
#define WHITE '0'


char **img_alloc(int, int);
void   img_free(char **, int, int);
char **img_read(int *x, int *y);
void   img_write(char **, int, int);
void   img_square(char **, int, int, int, int, int);
void   img_xdot(char **, int, int, int, int);

int main(int argc, char *argv[]) {
  char **pbm;
  int x, y;      /* x, yは画像サイズ */
  int i;
  int cx, cy, d; /* 正方形用データ */


  /* コマンドラインから、正方形の中心点と半辺長を取得 */
  if (argc<4) {
    fprintf(stderr, "usage: ./a.out cx cy d <pbmfile\n");
    exit(4);
  }
  cx=atoi(argv[1]);
  cy=atoi(argv[2]);
  d=atoi(argv[3]);

  /* 標準入力から入力された画像に合わせて領域を確保し、画素を読み込む */
  pbm = img_read(&x, &y);

  /* 指定領域を反転する */
  img_square(pbm, x, y, cx, cy, d);

  /* 画像を書きだす */
  img_write(pbm, x, y);
  /* 画像領域の解放 */
  img_free(pbm, x, y);
  return 0;
}

/********************************************/
/* 画像データ用の2次元配列確保              */
/* x, y: 確保する2次元配列の大きさ          */
/********************************************/
char **img_alloc(int x, int y) {
  char **data;
  /* この関数は未完成であり、問題3の完成対象である */



  return data;
}

/********************************************/
/* 画像データ領域開放                       */
/* pbm: 画像データの配列                    */
/* x, y: ダミー（他の関数との互換性のため） */
/********************************************/
void  img_free(char **pbm, int x, int y) {
/* この関数は完成している */
  int i;
  for (i = 0; i<y; i++) free(pbm[i]);
  free(pbm);
}

/********************************************/
/* 画像データ出力                           */
/* pbm, x, y: 画像データの配列と大きさ      */
/********************************************/
void   img_write(char **pbm, int x, int y) {
/* この関数は完成している */
  int i, j;
  /* 最初にP1とx,yの画素数を出力 */
  printf("P1\n");
  printf("%d %d\n", x, y);
  /* 実際のデータ出力 */
  for (i = 0; i < y; i++) {
    for (j = 0; j < x; j++) {
      printf("%c ", pbm[i][j]);
    }
    printf("\n");
  }
}

/********************************************/
/* 画像データの読み込み                     */
/* x, y: 画像データの大きさ                 */
/********************************************/
char **img_read(int *x, int *y) {
  char **data;
  /* この関数は未完成であり、問題3の完成対象である */
  

  return data;
}


/********************************************/
/* 画像に正方形を描画                       */
/* pbm, x, y: 画像データの配列と大きさ      */
/* cx, cy: 正方形の中心座標                 */
/* d: 正方形の半辺長                        */
/********************************************/
void   img_square(char **pbm, int x, int y, int cx, int cy, int d) {
/* この関数は未完成であり、問題3の完成対象である */
/* 実際の点の描画にはimg_xdotを使うこと */


}


/********************************************/
/* 画像中の指定された座標の１点を反転する   */
/* ただし、画像外なら何もしない             */
/* pbm, x, y: 画像データの配列と大きさ      */
/* px, py: 点の座標                         */
/********************************************/
void   img_xdot(char **pbm, int x, int y, int px, int py)
{
/* この関数は未完成であり、問題3の完成対象である */


}

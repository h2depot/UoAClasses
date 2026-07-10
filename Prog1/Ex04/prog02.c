    #include <stdio.h>
     
    int main(){
      double a, b;
      double *p, *q;
      
      /*
       * ここでポインタ変数p, qに適切な代入を行った後、
       * それ以降は変数 a, b を使わない形に書き換える
       * （以下のa,bの代入文もa,bを使わないように書き換えること）
       */
      p = &a;
      q = &b;

      printf("aの値を入力\n");
      scanf("%lf",p);
      printf("bの値を入力\n");
      scanf("%lf",q);
          
      printf("aの値: %.1f, aのアドレス: %p\n", *p, p);
      printf("bの値: %.1f, bのアドレス: %p\n", *q, q);
      printf("積: %.1f\n", *p * *q);
      printf("商: %.1f\n", *p / *q);
      return 0;
    }
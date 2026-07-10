    #include <stdio.h>
    #define N 5
    #define EMPTY -1
    #define FULL  -2
     
    int stackIO(int);
     
    int main()
    {
      int n, r;
     
      printf("スタックを実現するプログラム\n");
      printf("  正の整数値：入力値をスタックに格納する(Push)\n");
      printf("  負の整数値：スタックからデータを取り出す(Pop)\n");
      printf("  0：終了\n");
      while (1) {
        printf("整数値を入力 (正：格納(Push)，負：取出(Pop)，0：終了): ");
        scanf("%d", &n);
        if (n == 0) break; 
        r = stackIO(n); 
        if (r > 0) printf("取出データ = %d\n", r); 
        else if (r == EMPTY) printf("エラー（スタックが空です）\n"); 
        else if (r == FULL ) printf("エラー（スタックが満杯です）\n"); 
        stackIO(0); 
      }
      return 0;
    }
     
    int stackIO(int x)
    {
      static int stack[N];
      static int size = 0;
      int i;

      if(x == 0){
        printf("size = %d [",size);
        for(i=0;i<size;i++)printf("%d ",stack[i]);
        printf("]\n");
        return 0;
      }

      if(x>0){
	if(size == N)return FULL;
        stack[size]=x;
        size++;
	return 0;
      }else if(x<0){
	if(size==0)return EMPTY;
	size -= 1;
	return stack[size];
      }
      
     
    }

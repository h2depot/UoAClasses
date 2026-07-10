    #include <stdio.h>
    #define N 5
    #define EMPTY -1
    #define FULL  -2
     
    int queueIO(int);
     
    int main()
    {
      int n, r;
     
      printf("キューを実現するプログラム\n");
      printf("  正の整数値：入力値をキューに格納する(Enqueue)\n");
      printf("  負の整数値：キューからデータを取り出す(Dequeue)\n");
      printf("  0：終了\n");
      while (1) {
        printf("整数値を入力 (正：格納 (Enqueue)，負：取出 (Dequeue)，0：終了): ");
        scanf("%d", &n);
        if (n == 0) break; 
        r = queueIO(n); 
        if (r > 0) printf("取出データ: %d\n", r); 
        else if (r == EMPTY) printf("エラー（キューが空です）\n"); 
        else if (r == FULL ) printf("エラー（キューが満杯です）\n"); 
        queueIO(0); 
      }
      return 0;
    }
     

    int queueIO(int x)
    {
      static int queue[N]; 
      static int head = 0, tail = 0, size = 0;
      int i,n,val;

      if(x==0){
	printf("head = %d, tail = %d, size = %d [",head,tail,size);
	n=0;
	i=head;
	  while(!(n==size)){

	  printf("%d ",queue[i]);
	  n++;
	  if(i==4)i=0;
          else i++;
	}
	printf("]\n");
        return 0;
      }

      if(x>0){
        if(size==N)return FULL;
	queue[tail] = x;
	tail = (tail+1)%N;
	size++;
	return 0;
      }else if(x<0){
        if(size == 0)return EMPTY;
	val = queue[head];
	head = (head+1)%N;
	size--;
	return val;
      }

    }

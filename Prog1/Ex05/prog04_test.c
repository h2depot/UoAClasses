    #include <stdio.h>
     
    #define N 6
     
    int main()
    {
      int data[N];     /* 配列の宣言 */
      int tmp;
      int min_idx;
      int i, j;
     
      printf("Please input %d numbers\n", N);
      for(i = 0; i < N; i++)
        scanf("%d", &data[i]);
     
      for(i = 0; i < N - 1; i++){
        min_idx = i;
        for(j = i + 1; j < N; j++){
          if(data[j] < data[min_idx]) min_idx = j;
        }
        tmp = data[i];
        data[i] = data[min_idx];
        data[min_idx] = tmp;
        printf("%d\n", data[min_idx]);
      }
     
      printf("Sorted data\n");
      for(i = 0; i < N; i++) {
        printf("%d  ", data[i]);
      }
      printf("\n");
      return 0;
    }
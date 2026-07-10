    #include <stdio.h>
     
    #define N 6
     
    int main()
    {
      int data[N];     /* 配列の宣言 */
      int tmp;
      int *p, *q,*max_ptr;

     
      printf("Please input %d numbers\n", N);
      for(q=&data[0];q!=&data[N]; q++)
        scanf("%d",q);

    
     
      for(q=&data[0];q!=&data[N-1];q++){
        max_ptr = q;
        for(p=q+1;p!=&data[N];p++){
        if(*p > *max_ptr) max_ptr=p;
        }
        tmp=*q;
        *q=*max_ptr;
        //printf("%d ", *max_ptr);
        *max_ptr=tmp;
        //printf("%d ", *max_ptr);
        //printf("%d ", *q);
      }
      printf("\n");
     
      printf("Sorted data\n");
      for(q=&data[0];q!=&data[N]; q++) {
        printf("%d  ",*q);
      }
      printf("\n");
      return 0;
    }
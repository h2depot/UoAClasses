#include <stdio.h>

int fibon(int);
int main(){
  int i;
  double per;
  double golden = 1.618033988749895;
  
  for (i = 0; i <= 9; i++)printf("F(%d)=%d\t",i,fibon(i));
  printf("\n");

  for (i = 10; i <= 30; i++){

    per = (double)fibon(i+1)/(double)fibon(i);
    
    printf("%d\t%.12e\t%.12e\n", i, per, per - golden);
  }
  
  return 0;
}

int fibon(int i){
  int fib[i+1];
  int j;
  int total = 0;
  fib[0]=0;
  fib[1]=1;
  for (j = 2; j <= i+1; j++){
      fib [j] = fib[j-1] + fib[j-2];
    }

  return fib[i];
}

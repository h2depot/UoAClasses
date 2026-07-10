#include <stdio.h>

int fibo(int);

int memory=0;

int main(){
  int num,ans;

  printf("n = ");
  scanf("%d",&num);

  ans = fibo(num);

  printf("fibo(%d) = %d\n",num,ans);

  return 0;
}

int fibo(int n){
  memory++;
  printf("called %d times: n=%d\n",memory,n);

  if(n>=2){
    return fibo(n-1)+fibo(n-2);
  }else if(n==1){
    return 1;
  }else if(n==0){
    return 0;
  }
}
#include <stdio.h>
#include <stdlib.h>

long long calc_fibo(int,long long *);

int main(){
  int n;
  long long result;

  scanf("%d",&n);
  long long *fibo=(long long *)malloc(n*sizeof(long long));
  if(n==0||n==1){
    printf("1\n");
    return 0;
  }else{
    result =calc_fibo(n,fibo);
  }
  result/=10000;
  printf("%lld\n",result);

  return 0;
}

long long calc_fibo(int n,long long *fibo){
  int i;

  fibo[0]=1;
  fibo[1]=1;

  for(i=2;i<=n;i++){
    fibo[i]=fibo[i-1]+fibo[i-2];
  }
  return fibo[n];
}


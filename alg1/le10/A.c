#include <stdio.h>
#include <stdlib.h>

int calc_fibo(int,int *);

int main(){
  int n,result;

  scanf("%d",&n);
  int *fibo=(int *)malloc(n*sizeof(int));
  if(n==0||n==1){
    printf("1\n");
    return 0;
  }else{
    result =calc_fibo(n,fibo);
  }
  printf("%d\n",result);

  return 0;
}

int calc_fibo(int n,int *fibo){
  int i;

  fibo[0]=1;
  fibo[1]=1;

  for(i=2;i<=n;i++){
    fibo[i]=fibo[i-1]+fibo[i-2];
  }
  return fibo[n];
}
#include <stdio.h>
#include <stdlib.h>

int fibo(int);
int fibo_array(int, int *);

int memory=0;

int main(){
  int num,ans;
  int *array;
  int i;

  printf("n = ");
  scanf("%d",&num);

  array = (int *)malloc((num+1) * sizeof(int));
  for(i=0;i<num+1;i++)array[i]=0;

  ans = fibo(num);
  printf("fibo(%d) = %d\n",num,ans);
  memory=0;

  ans = fibo_array(num,array);
  printf("fibo(%d) = %d\n",num,ans);

  free(array);

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

int fibo_array(int n, int *a){
  memory++;
  printf("called %d times: n=%d\n",memory,n); 

  if(a[n]!=0)return a[n];
  else{
  if(n>=2){
    a[n]=fibo_array(n-1,a)+fibo_array(n-2,a);
    return a[n];
  }else if(n==1){
    a[n]=1;
    return a[n];
  }else if(n==0){
    a[n]=0;
    return a[n];
  }
  }

}
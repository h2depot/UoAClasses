#include <stdio.h>
#include <stdlib.h>

#define NMAX 1000

int top=-1;

int main(){
  int stack[NMAX],n,i,sum=0;

  for(i=0;i<NMAX;i++){
    scanf("%d",&n);
    if(n==0){
      stack[top--];
    }else{
      stack[++top]=n;
    }    
  }

  for(i=0;i<=top;i++){
    sum+=stack[i];
  }
  printf("%d\n",sum);

  return 0;
}


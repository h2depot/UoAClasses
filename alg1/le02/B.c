#include <stdio.h>
#include <stdlib.h>

#define NMAX 100
#define AMAX 100

int main(){
  int A[NMAX];
  int n,flag=0,tmp,count=0;
  int minj;
  int i,j;

  scanf("%d",&n);
  if(!(n>=1 && n<= NMAX)){
    exit(1);
  }

  for(i=0;i<n;i++){
    scanf("\n%d",&A[i]);
    if(!(A[i]>=0 && A[i]<=AMAX)){
      exit(1);
    }
  }

  for(i=0;i<=n-1;i++){
    minj =i;
    for(j=i;j<=n-1;j++){
        if(A[j]<A[minj]){
            minj =j;
        }
    }
    if(i!=minj){
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    count++;
    }

  }

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);

  return 0;
}

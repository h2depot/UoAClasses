#include <stdio.h>
#include <stdlib.h>

#define NMAX 100
#define AMAX 1000

int main(){

  int A[AMAX],N;
  int i,j,k;
  int v;

  scanf("%d",&N);
  if(!(N>=0 && N<=100)){
    exit(1);
  }
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

    for(k=0;k<N-1;k++){
    printf("%d ",A[k]);
    }
    printf("%d",A[k]);
    printf("\n");

  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
        A[j+1]=A[j];
        j--;
        A[j+1]=v;
    }
    for(k=0;k<N-1;k++){
    printf("%d ",A[k]);
    }
    printf("%d",A[k]);
    printf("\n");
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NMAX 1000000
#define HMAX 1000000001

int main(){
  int i,count=0;
  int*A=(int*)malloc(NMAX*sizeof(int));
  bool*hashash=(bool*)malloc(HMAX*sizeof(bool));

  for(i=0;i<HMAX;i++)hashash[i]=false;

  for(i=0;i<NMAX;i++)scanf("%d",&A[i]);
  //for(i=0;i<12;i++)printf("%d ",A[i]);printf("\n");
  //for(i=0;i<12;i++)printf("%d ",hashash[i]);printf("\n");
  for(i=0;i<NMAX;i++){
    hashash[A[i]]=true;
  }
  free(A);

  int*B=(int*)malloc(NMAX*sizeof(int));  
  for(i=0;i<NMAX;i++)scanf("%d",&B[i]);
  for(i=0;i<NMAX;i++){
    if(hashash[B[i]]==true){
      count++;
    }
  }

  printf("%d\n",count);

  free(B);
  free(hashash);

  return 0;
}




#include <stdio.h>
#include <stdlib.h>

#define KMAX 10000

int main(){
    int n;
    int i,j;
    int C[KMAX];

    scanf("%d",&n);
    int *A=(int *)malloc(n*sizeof(int));
    int *B=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)scanf("%d",&A[i]);

    for(i=0;i<KMAX;i++)C[i]=0;

    for(j=0;j<n;j++)C[A[j]]++;

    for(i=1;i<KMAX;i++)C[i]=C[i]+C[i-1];
    
    for(j=n-1;j>=0;j--){
      B[C[A[j]]-1]=A[j];
      C[A[j]]--;
    }

    for(i=0;i<n-1;i++)printf("%d ",B[i]);
    printf("%d\n",B[i]);

    free(A);
    free(B);

    return 0;
}
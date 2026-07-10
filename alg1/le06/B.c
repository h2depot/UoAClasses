#include <stdio.h>
#include <stdlib.h>

#define KMAX 10000

int main(){
    int n;
    int i,j,p=1,x;
    int tmp;

    scanf("%d",&n);
    int *A=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)scanf("%d",&A[i]);

    x=A[n-1];
    for(j=0,i=-1;j<n-1;j++){
        if(A[j]<=x){
            i++;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    tmp=A[i+1];
    A[i+1]=A[n-1];
    A[n-1]=tmp;

    for(j=0;j<i+1;j++)printf("%d ",A[j]);
    printf("[%d] ",A[j]);
    for(j=i+2;j<n-1;j++)printf("%d ",A[j]);
    printf("%d\n",A[j]);

    return 0;
}
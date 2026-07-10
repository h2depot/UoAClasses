#include <stdio.h>
#include <stdlib.h>

#define INFTY 1000000001

void margeSort(int*,int,int);
void marge(int*,int,int,int);

long long count=0;

int main(){
  int n;
  int i;

  scanf("%d",&n);
  int *A=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  margeSort(A,0,n);
  printf("%ld\n",count);

    free(A);
    return 0;
}

void margeSort(int *A,int left,int right){
  int mid;

    if(left+1<right){
      mid=(left+right)/2;
      margeSort(A,left,mid);
      margeSort(A,mid,right);
      marge(A,left,mid,right);
    }
}

void marge(int *A,int left,int mid,int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  int *L=(int *)malloc((n1+1)*sizeof(int));
  int *R=(int *)malloc((n2+1)*sizeof(int));

  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
        A[k]=L[i];
        i++;
    }else{
        A[k]=R[j];
        j++;
        count+=(long long)n1-(long long)i;
    }
  }
    free(L);
    free(R);
}

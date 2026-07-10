#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int *,int,int);

int main(){
  int n;
  int i;

  scanf("%d",&n);
  int *nodes=(int *)malloc((n+1)*sizeof(int));
  for(i=1;i<n+1;i++)scanf("%d",&nodes[i]);
  
  for(i=n/2;i>0;i--)maxHeapify(nodes,i,n);

  for(i=1;i<n;i++)printf(" %d",nodes[i]);
  printf(" %d\n",nodes[i]);;
  
  free(nodes);

  return 0;
}

void maxHeapify(int*A,int i,int n){
    int l = i*2;
    int r = i*2+1;
    int largest,tmp;

    if(l<=n && A[l]>A[i])largest=l;
    else largest=i;

    if(r<=n && A[r]>A[largest])largest=r;

    if(largest != i){
      tmp = A[i];
      A[i]=A[largest];
      A[largest]=tmp;
      maxHeapify(A,largest,n);
    }
}
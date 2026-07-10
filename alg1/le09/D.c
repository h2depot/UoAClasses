#include <stdio.h>
#include <stdlib.h>

void heapSort(int,int*);
void maxHeapify(int*,int,int);
void ChangeHeap(int*,int);

int main(){
  int n,tmp,tmp_j;
  int i,j;

  scanf("%d",&n);
  int *array=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&array[i]);
  heapSort(n,array);
for(i=0;i<n-1;i++){
    ChangeHeap(array,i);
    //for(j=0;j<n-1;j++)printf("%d ",array[j]);
    //printf("%d\n\n",array[j]);
  }
  tmp=array[0];
  array[0]=array[n-1];
  array[n-1]=tmp;

  for(i=0;i<n-1;i++)printf("%d ",array[i]);
  printf("%d\n",array[i]);


  free(array);
  return 0;
}

void heapSort(int n,int* array){
  int i;
  int heapSize=n,tmp;

  for(i=n/2-1;i>=0;i--)maxHeapify(array,i,heapSize);
  while(heapSize>=2){
    tmp=array[heapSize-1];
    array[heapSize-1]=array[0];
    array[0]=tmp;
    heapSize--;
    maxHeapify(array,0,heapSize);
  }
}

void maxHeapify(int*array,int i,int heapSize){
  int l=2*i+1;
  int r=2*i+2;
  int largest,tmp;

  if(l<heapSize && array[l]>array[i])largest=l;
  else largest=i;
  if(r<heapSize && array[r]>array[largest])largest=r;
  if(largest!=i){
    tmp=array[i];
    array[i]=array[largest];
    array[largest]=tmp;
    maxHeapify(array,largest,heapSize);
  }
}

void ChangeHeap(int*array,int i){
  int parent=(i-1)/2,child=i,tmp;
  while(parent>0){
    //printf("child=%d, parent=%d\n",child,parent);
    //if (array[child]>array[parent]){
    tmp=array[child];
    array[child]=array[parent];
    array[parent]=tmp;
    //}
    child=parent;
    parent=(child-1)/2;
  }
}



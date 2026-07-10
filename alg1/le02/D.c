#include <stdio.h>
#include <stdlib.h>

int *shell_sort(int *,int);

int main(){
  int n;
  int i;

  scanf("%d",&n);
  int *A =(int*)malloc(n * sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  A = shell_sort(A,n);
  
  for(i=0;i<n;i++)printf("%d\n",A[i]);

  free(A);
  return 0;
}

int *shell_sort(int *array,int n){
  int cnt=0,h;
  int i,j;
  int m;
  int *G_tmp=(int*)malloc(m * sizeof(int));
  int *G=(int*)malloc(m * sizeof(int));
  
  for(h=1,i=0;h<n;h=3*h+1,i++)G_tmp[i]=h;
  if(i==0){
    i++;
    G[0]=1;
  }
  m=i;
  for(i=m-1;i>=0;i--)G[i]=G_tmp[m-1-i];

  for(i=0;i<m;i++){
    for(j=G[i];j<n;j++){
      int v=array[j];
      int k=j-G[i];
      while(k>=0 && array[k]>v){
        array[k+G[i]] = array[k];
        k=k-G[i];
        cnt++;
      }
      array[k+G[i]]=v;
    }
  }

  printf("%d\n",m);
  for(i=0;i<m-1;i++)printf("%d ",G[i]);
  printf("%d\n",G[i]);
  printf("%d\n",cnt);

  return array;
}

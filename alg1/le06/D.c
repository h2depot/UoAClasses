#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXW 10000

int sortingcost(int *,int);
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int T[MAXW+1];

int main(){
  int n;
  int i;

  scanf("%d",&n);
  int *W=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&W[i]);
  
  int result= sortingcost(W,n);

  printf("%d\n",result);

  free(W);
  return 0;
}

int sortingcost(int *W,int n){
  int answer=0;
  int i;

  int *Bool=(int *)malloc(n*sizeof(int));
  int *W2=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    Bool[i]=0;
    W2[i]=W[i];
  }
 qsort(W2, n, sizeof(int), compare);
  for(i=0;i<n;i++)T[W2[i]]=i;
  for(i=0;i<n;i++){
    if(Bool[i]==1)continue;
    int current=i,sum=0,an=0,m=MAXW;
    while(1){
      Bool[current]=1;
      an++;
      int v=W[current];
      if(m>v)m=v;
      sum+=v;
      current=T[v];
      if(Bool[current]==1)break;
    }
    answer+=((sum + (an - 2) * m)<(sum + m + (an + 1) * W2[0]))?sum + (an - 2) * m:sum + m + (an + 1) * W2[0];
  }
  free(Bool);
  free(W2);
  return answer;
}




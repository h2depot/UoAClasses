#include <stdio.h>
#include <stdlib.h>

int content(long long,int*,int,int);

int main(){
  int n,k;
  int i;
  int v;
  long long start,end,mid,sum=0;

  scanf("%d%d",&n,&k);
  int *w=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&w[i]);
    sum+=w[i];
  }

  start=0;
  end=n*10000;
  while(end-start>1){
    //printf("entered while\n");
    mid=(start+end)/2;
    v=content(mid,w,k,n);
    //printf("%d\n",v);
    if(v>=n)end=mid;
    else start=mid;
  }
  printf("%d\n",end);

  free(w);

  return 0;
}

int content(long long p,int *w,int k,int n){
  int i=0,j;
  long long tmp=0;
  for(j=0;j<k;j++){
    tmp=0;
    while(tmp+(long long)w[i]<=p){
      tmp+=(long long)w[i];
      i++;
      if(i==n)return n;
    }
  }
  return i;
}

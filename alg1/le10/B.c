#include <stdio.h>
#include <stdlib.h>

long long matrixChainOrder(int,int*);

int main(){
  int n,flag=0;
  int i,j,k=0;
  long long result;

  scanf("%d",&n);
  int *p = (int *)malloc((n+1)*sizeof(int));
  for(i=0;i<2*n;i++){
    scanf("%d",&j);
    if(i>1 && flag==1)if(j==p[k-1]){
      flag=0;
      continue;
    }
    p[k]=j;
    k++;
    flag=1;
  }
  //for(i=0;i<n+1;i++)printf("%d ",p[i]);
  //printf("\n");

  result=matrixChainOrder(n,p);

  printf("%lld\n",result);
 
  free(p);
  return 0;
}

long long matrixChainOrder(int n,int*p){
  long long q;
  int i,j,k,l;

  long long **m=(long long**)malloc(n*sizeof(long long*));
  for(i=0;i<n;i++)m[i]=(long long *)malloc(n*sizeof(long long));

  for(i=0;i<n;i++)m[i][i]=0;

  for(i=2;i<=n;i++){
    for(j=0;j<=n-i;j++){
      k=j+i-1;
      m[j][k]=-1;
      for(l=j;l<k;l++){
        q=m[j][l]+m[l+1][k]+(long long)(p[j]*p[l+1]*p[k+1]);
        if(m[j][k]==-1 || m[j][k]>q)m[j][k]=q;
      }
    }
  }
  
  q=m[0][n-1];
  for (int i = 0; i < n; i++)free(m[i]);
  free(m); 
  return q;
}

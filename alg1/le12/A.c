#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,min,sum=0,tmp,dock,count=0;
  int i,j,k;

  scanf("%d",&n);
  int **matrix=(int**)malloc(n*sizeof(int*));
  for(i=0;i<n;i++)matrix[i]=(int*)malloc(n*sizeof(int));
  int *visit=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&matrix[i][j]);
  for(i=0;i<n;i++)visit[i]=0;

  i=0;
  visit[0]=1;
  while(1){
    tmp=2001;
    dock=-1;
    for(k=0;k<n;k++){
      if(visit[k]==1){
        for(j=0;j<n;j++){
          if(visit[j]==1)continue;
          if(tmp>matrix[k][j] && matrix[k][j]!=-1){
            tmp=matrix[k][j];
            dock=j;
          }
        }
      }
    }
    if(dock!=-1){
      visit[dock]=1;
      sum+=tmp;
      count++;
    }else break;
  }
  

  printf("%d\n",sum);

  for (i=0;i<n;i++)free(matrix[i]);
  free(matrix);
  free(visit);
  return 0;
}

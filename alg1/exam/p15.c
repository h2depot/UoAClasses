#include <stdio.h>
#include <stdlib.h>

#define NMAX 1000000000

int main(){
  int n,min,sum=0,tmp,dock,count=0,max=0;
  int i,j,k;

  
  int matrix[100][100],visit[100];

  for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&matrix[i][j]);
  for(i=0;i<n;i++)visit[i]=0;

  i=0;
  visit[0]=1;
  while(1){
    tmp=2001;
    dock=NMAX;
    for(k=0;k<n;k++){
      if(visit[k]==1){
        for(j=0;j<n;j++){
          if(visit[j]==1)continue;
          if(tmp>matrix[k][j] && matrix[k][j]!=NMAX){
            tmp=matrix[k][j];
            dock=j;
          }
        }
      }
    }
    if(dock!=NMAX){
      visit[dock]=1;
      sum+=tmp;
      count++;
    }else break;
  }
  

  printf("%d\n",sum);
  return 0;
}

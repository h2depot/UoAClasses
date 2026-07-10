#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

void dijkstra(int**,int);

int current=0,top=1;

int main(){
  int n,num,num_ch,child;
  int i,j,k;

  scanf("%d",&n);
  int **matrix_tour=(int**)malloc(n*sizeof(int*));
  for(i=0;i<n;i++)matrix_tour[i]=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)for(j=0;j<n;j++)matrix_tour[i][j]=INT_MAX;

  for(i=0;i<n;i++){
    scanf("%d%d",&num,&num_ch);
    for(j=0;j<num_ch;j++){
      scanf("%d",&child);
      scanf("%d",&matrix_tour[num][child]);
    }
  }
  dijkstra(matrix_tour,n);

  for(i=0;i<n;i++)free(matrix_tour[i]);
  free(matrix_tour);
  return 0;
}

void dijkstra(int **Matrix,int n){
  int*color=(int*)malloc(n*sizeof(int));
  int*d=(int*)malloc(n*sizeof(int));
  int*p=(int*)malloc(n*sizeof(int));
  int min,location;
  int i,j;

  for(i=0;i<n;i++){
    d[i]=INT_MAX;
    color[i]=-1;
  }
  d[0]=0;
  color[0]=0;
  while(1){
    min=INT_MAX;
    location=-1;
    for(i=0;i<n;i++){
      if(min>d[i] && color[i]!=1){
        location=i;
        min=d[i];
      }
    }
    if(location==-1)break;
    color[location]=1;
    for(j=0;j<n;j++){
      if(color[j]!=1 && Matrix[location][j]!=INT_MAX){
        if(d[j]>d[location]+Matrix[location][j]){
          d[j]=d[location]+Matrix[location][j];
          color[j]=0;
        }
      }
    }
  }
  for(i=0;i<n;i++)printf("%d %d\n",i,d[i]);
  free(color);
  free(d);
  free(p);
}



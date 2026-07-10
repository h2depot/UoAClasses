#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int num;
  int ch_num;
  int child[100];
}Graph;

int main(){
    int n;
    int i,j,k;

    scanf("%d",&n);
    Graph* graph = (Graph*)malloc(n*sizeof(Graph));
    int **matrix=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)matrix[i]=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        scanf("%d",&graph[i].num);
        scanf("%d",&graph[i].ch_num);
        for(j=0;j<graph[i].ch_num;j++)scanf("%d",&graph[i].child[j]);
    }
    
    for(i=0;i<n;i++)for(j=0;j<n;j++)matrix[i][j]=0;
    for(i=0;i<n;i++)for(k=0;k<graph[i].ch_num;k++)matrix[i][graph[i].child[k]-1]=1;

    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++)printf("%d ",matrix[i][j]); 
        printf("%d",matrix[i][j]);            
        printf("\n");
    }

    free(graph);
    for (i=0;i<n;i++)free(matrix[i]);
    free(matrix);
    return 0;
}

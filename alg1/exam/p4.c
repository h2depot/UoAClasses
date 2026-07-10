#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NMAX 100

typedef struct{
  int num;
  int ch_num;
  int child[100];
}Graph;

void tansaku(Graph*,int);

bool visit[NMAX]={false};

int main(){
    int n,count=0;
    int i,j,k;
    Graph graph[NMAX];

    for(i=0;i<NMAX;i++){
        scanf("%d",&graph[i].num);
        scanf("%d",&graph[i].ch_num);
        for(j=0;j<graph[i].ch_num;j++)scanf("%d",&graph[i].child[j]);
    }
    tansaku(graph,0);

    for(i=0;i<NMAX;i++)if(visit[i]==false)count++;
    printf("%d\n",count);

    return 0;
}

void tansaku(Graph* graph, int current){
  int i;
  visit[current]=true;
  for(i=0;i<graph[current].ch_num;i++){
    if(visit[graph[current].child[i]]==false){
        tansaku(graph,graph[current].child[i]);
    }
  }
}



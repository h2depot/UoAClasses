#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int num;
  int ch_num;
  int child[100];
}Graph;

int head=0,tail=0;

void enqueue(int,int*,int);
int dequeue(int,int*);

int main(){
    int n;
    int i,j,k;

    scanf("%d",&n);
    Graph* graph = (Graph*)malloc(n*sizeof(Graph));
    int* bfs=(int *)malloc(n*sizeof(int));
    int* queue=(int *)malloc(n*sizeof(int));
    int* visit=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&graph[i].num);
        scanf("%d",&graph[i].ch_num);
        for(j=0;j<graph[i].ch_num;j++)scanf("%d",&graph[i].child[j]);
    }

    int time=1;
    for(i=0;i<n;i++){
        visit[i]=0;
        bfs[i]=-1;
    }
    visit[0]=1;
    bfs[0]=0;
    enqueue(n,queue,0);
    while(head!=tail){
      int current=dequeue(n,queue);
      for(j=0;j<graph[current].ch_num;j++){
        if(visit[graph[current].child[j]-1]==0){
            bfs[graph[current].child[j]-1]=bfs[current]+1;
            enqueue(n,queue,graph[current].child[j]-1);
            visit[graph[current].child[j]-1]=1;
        }
      }
    }

    for(i=0;i<n;i++)printf("%d %d\n",i+1,bfs[i]);

    free(graph);
    free(bfs);
    free(queue);
    free(visit);
    return 0;
}

void enqueue(int n,int*queue,int key){
    int next = (tail+1)%n;
    queue[tail]=key;
    tail=next;
}

int dequeue(int n,int*queue){
    int val=queue[head];
    head=(head+1)%n;
    return val;
}




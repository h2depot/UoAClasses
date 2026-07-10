#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int num;
  int ch_num;
  int child[100];
}Graph;

int top=-1;

int main(){
    int n;
    int i,j,k;

    scanf("%d",&n);
    Graph* graph = (Graph*)malloc(n*sizeof(Graph));
    int* f_DFS=(int *)malloc(n*sizeof(int));
    int* d_DFS=(int *)malloc(n*sizeof(int));
    int* stack=(int *)malloc(n*sizeof(int));
    int* visit=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&graph[i].num);
        scanf("%d",&graph[i].ch_num);
        for(j=0;j<graph[i].ch_num;j++)scanf("%d",&graph[i].child[j]);
    }

    int current=0,time=1;
    for(i=0;i<n;i++){
        visit[i]=0;
        f_DFS[i]=0;
        d_DFS[i]=0;
    }
    while(1){
        //printf("current=%d\ntime=%d\ntop=%d\n\n",current,time,top);
        if(visit[current]==0){
        d_DFS[current]=time++;
        visit[current]=1;
        stack[++top]=current;
        }
        int flag=0;
        for(j=0;j<graph[current].ch_num;j++){
          if(visit[graph[current].child[j]-1]==0){
            current=graph[current].child[j]-1;
            flag=1;
            break;
          }
        }
        if(flag==0){
            //printf("entered flag!\n");
            f_DFS[stack[top]]=time++;
            //printf("stack[top]=%d\n",stack[top]);
            current=stack[top--];
            for(j=0;j<graph[stack[top]].ch_num;j++){
              if(visit[graph[stack[top]].child[j]-1]==0){
                current=graph[stack[top]].child[j]-1;
                break;
              }
            }
        }
        if(top<0){
          flag=0;
          for(i=0;i<n;i++){
            if(visit[i]==0){
              current=i;
              flag=1;
              break;
            }
          }
          if(flag==0)break;
        }
    }

    for(i=0;i<n;i++)printf("%d %d %d\n",i+1,d_DFS[i],f_DFS[i]);

    free(graph);
    free(d_DFS);
    free(f_DFS);
    free(stack);
    free(visit);
    return 0;
}



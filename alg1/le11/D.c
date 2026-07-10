#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
} Graph;

Graph **graph;
int *stack;
int*ch_num;
int*val;

int top=-1;
int n,m;

void make_route();

int main(){
  int order;  
  int i;
  scanf("%d%d",&n,&m);
  graph=(Graph**)malloc(n*sizeof(Graph*));
  for(i=0;i<n;i++)graph[i]=NULL;
  stack=(int*)malloc(n*sizeof(int));
  ch_num=(int*)calloc(n,sizeof(int));
  val=(int*)calloc(n,sizeof(int));
  for(i=0;i<m;i++){
    int s,t;
    scanf("%d%d",&s,&t);
    Graph*graph1=(Graph*)malloc(sizeof(Graph));
    Graph*graph2=(Graph*)malloc(sizeof(Graph));
    graph1->num=t;
    graph2->num=s;
    graph1->next=graph[s];
    graph[s]=graph1;
    graph2->next=graph[t];
    graph[t]=graph2;
  }
  make_route();

  scanf("%d",&order);
  for(i=0;i<order;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    if(val[u]==val[v])printf("yes\n");
    else printf("no\n");
  }
  
  return 0;
}

void make_route(){
  int i,j,k;

  for(i=0,j=1;i<n;i++,j++){
    if(val[i]==0){
    stack[++top]=i;
    val[i]=j;
    while(top>=0){
      int popper=stack[top--];
      Graph* tmp = graph[popper];
      while(tmp!=NULL){
        int vone=tmp->num;
        if(val[vone]==0){
          val[vone]=j;
          stack[++top]=vone;
        }
        tmp=tmp->next;
      }
    }
    }
  }
}

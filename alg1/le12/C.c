#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

typedef struct node{

  int num;
  int weight;
  struct node*next;

}Node;

typedef struct graph{
  int graph_num;
  Node**NeighborList;
}Graph;

Graph* create_Graph(int);
void add_Edge(Graph*,int,int,int);

void dijkstra(Graph*,int);

int main(){
  int n,num,num_ch,child,weight;
  int i,j,k;

  scanf("%d",&n);
  Graph*graph=create_Graph(n);
  for(i=0;i<n;i++){
    scanf("%d%d",&num,&num_ch);
    for(j=0;j<num_ch;j++){
      scanf("%d%d",&child,&weight);
      add_Edge(graph,num,child,weight);
    }
  }
  dijkstra(graph,n);


  return 0;
}

Graph*create_Graph(int n){
  int i;

  Graph*graph=(Graph*)malloc(sizeof(Graph));
  graph->graph_num=n;
  graph->NeighborList=(Node**)malloc(n*sizeof(Node*));

  for(i=0;i<n;i++)graph->NeighborList[i]=NULL;

  return graph;
}

void add_Edge(Graph* graph,int num,int child,int weight){
  Node*node=(Node*)malloc(sizeof(Node));
  node->num=child;
  node->weight=weight;
  node->next=graph->NeighborList[num];
  graph->NeighborList[num]=node;
}

void dijkstra(Graph*graph,int n){
  int*color=(int*)malloc(n*sizeof(int));
  int*d=(int*)malloc(n*sizeof(int));
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
    Node*node_tmp=graph->NeighborList[location];
    while(node_tmp){
      if(d[node_tmp->num]>d[location]+ node_tmp->weight){
        d[node_tmp->num]=d[location]+ node_tmp->weight;
        color[node_tmp->num]=0;
      }
      node_tmp=node_tmp->next;
    }
  }
  for(i=0;i<n;i++)printf("%d %d\n",i,d[i]);
}




#include <stdio.h>
#include <stdlib.h>

#define NMAX 100000

typedef struct {
  int num;
  int depth;
  int parent;
  int first_c;
  int next_s;
}Node;

int preorder (int,Node*);

int count=0;

int main(){
  int i,j,n,child,child_tmp=-1,num_ch,num_num;

  scanf("%d",&n);
  Node *nodes=(Node *)malloc(sizeof(Node)*n);
  for(i=0;i<n;i++){
    nodes[i].parent=-1;
    nodes[i].first_c=-1;
    nodes[i].next_s=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&num_num);
    scanf("%d",&num_ch);
    nodes[num_num].num=num_num;
    child_tmp=-1;
    for(j=0;j<num_ch;j++){
      scanf("%d",&child);
      if(j==0)nodes[num_num].first_c=child;
      //nodes[child].parent=nodes[i].num;
      nodes[child].parent=nodes[num_num].num;
      if(child_tmp!=-1)nodes[child_tmp].next_s=child;
      child_tmp=child;
    }
  }
  for(i=0;i<n;i++){
    if(nodes[i].parent==-1){
      nodes[i].depth=0;
    }else{
      count=0;
      nodes[i].depth=preorder(i,nodes);
    }
  }
  int next_node;
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,nodes[i].parent,nodes[i].depth);
    if(nodes[i].parent==-1)printf("root, [");
    else if(nodes[i].first_c==-1)printf("leaf, [");
    else printf("internal node, [");
    next_node=nodes[i].first_c;
    while(next_node!=-1){
      printf("%d",nodes[next_node].num);
      next_node=nodes[next_node].next_s;
      if(next_node!=-1)printf(", ");
    }
    printf("]\n");
  }

  free(nodes);
  return 0;
}

int preorder(int current,Node *nodes){
  if(nodes[current].parent!=-1){
    count++;
    preorder(nodes[current].parent,nodes);
  }
  return count;
}




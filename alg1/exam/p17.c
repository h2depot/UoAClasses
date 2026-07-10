#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int parent;
  int sibling;
  int degree;
  int left;
  int right;
  int depth;
  int height;
}Node;

int calc_depth(int,Node*);
int calc_height(int,Node*);

int count_d=0;


int main(){
  int n,num,num_left,num_right,count=0;
  int i,j;


  Node nodes[44];
  for(i=0;i<44;i++){
  nodes[i].parent=-1;
  nodes[i].sibling=-1;
  nodes[i].degree=0;
  nodes[i].left=-1;
  nodes[i].right=-1;
  nodes[i].depth=-1;
  nodes[i].height=-1;
  }

  for(i=0;i<44;i++){
    scanf("%d",&num);

    scanf("%d",&num_left);
    if(num_left!=-1){
      nodes[num].left=num_left;
      nodes[num_left].parent=num;
    }else nodes[num].left=num_left;

    scanf("%d",&num_right);
    if(num_right!=-1){
      nodes[num].right=num_right;
      nodes[num_right].parent=num;
    }else nodes[num].right=num_right;
   if(num_left!=-1)nodes[num_left].sibling=num_right;
   if(num_right!=-1)nodes[num_right].sibling=num_left;
   if(num_left !=-1 && num_right!=-1)nodes[num].degree=2;
   else if(num_left!=-1 || num_right!=-1)nodes[num].degree=1;
   else nodes[num].degree=0;
  }

  for(i=0;i<44;i++){
    if(nodes[i].parent==-1){
      nodes[i].depth=0;
    }else{
      count_d=0;
      nodes[i].depth=calc_depth(i,nodes);
    }
  }

  for(i=0;i<44;i++){
    if(nodes[i].left==-1 && nodes[i].right==-1){
      nodes[i].height=0;
    }else{
      nodes[i].height=calc_height(i,nodes);
    }
  }

  for(i=0;i<44;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,nodes[i].parent,nodes[i].sibling,nodes[i].degree,nodes[i].depth,nodes[i].height);
    if(nodes[i].parent==-1)printf("root\n");
    else if(nodes[i].degree==0)printf("leaf\n");
    else printf("internal node\n");
    if(nodes[i].depth>=4)count++;
  }
  printf("count=%d\n",count);

  return 0;
}

int calc_depth(int current,Node* nodes){
  if(nodes[current].parent!=-1){
    count_d++;
    calc_depth(nodes[current].parent,nodes);
  }
  return count_d;
}

int calc_height(int current,Node* nodes){
  if(current==-1)return -1;

  int count_hl = calc_height(nodes[current].left, nodes);
  int count_hr = calc_height(nodes[current].right, nodes);

  return (count_hl>count_hr ? count_hl : count_hr)+1;
}



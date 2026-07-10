#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int parent;
  int sibling;
  int left;
  int right;

}Node;

void preorder(int,Node*);
void inorder(int,Node*);
void postorder(int,Node*);

int main(){
  int n,num,num_left,num_right;
  int i,j;

  scanf("%d",&n);
  Node *nodes=(Node *)malloc(n*(sizeof(Node)));
  for(i=0;i<n;i++){
  nodes[i].parent=-1;
  nodes[i].sibling=-1;
  nodes[i].left=-1;
  nodes[i].right=-1;

  }

  for(i=0;i<n;i++){
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
  }

  int root;
  for(i=0;i<n;i++){
    if(nodes[i].parent==-1)break;
  }
  root=i;

  printf("Preorder\n");
  preorder(root,nodes);
  printf("\nInorder\n");
  inorder(root,nodes);
  printf("\nPostorder\n");
  postorder(root,nodes);
  printf("\n");

  return 0;
}

void preorder(int current, Node* nodes){
  if(current==-1)return;
  printf(" %d",current);
  preorder(nodes[current].left,nodes);
  preorder(nodes[current].right,nodes);
}

void inorder(int current, Node* nodes){
  if(current==-1)return;
  inorder(nodes[current].left,nodes);
  printf(" %d",current);
  inorder(nodes[current].right,nodes); 
}

void postorder(int current, Node* nodes){
  if(current==-1)return;
  postorder(nodes[current].left,nodes);
  postorder(nodes[current].right,nodes);   
  printf(" %d",current);
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node{
    long long num;
    struct tree_node *right;
    struct tree_node *left;
}Node;

void insert(Node**,long long);
void print_pre(Node**);
void print_in(Node**);
int find(Node**,long long);

int main(){
  int n;
  long long key;
  char com[7];
  Node *node_head=NULL;

  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%s",com);
    if(strcmp(com,"insert")==0){
      scanf("%lld",&key);
      insert(&node_head,key);
    }else if(strcmp(com,"print")==0){
      print_in(&node_head);
      printf("\n");
      print_pre(&node_head);
      printf("\n");
    }else{
      scanf("%lld",&key);
      if(find(&node_head,key)==1){
        printf("yes\n");
      }else{
        printf("no\n");
      }
    }
  }
    return 0;
}

void insert(Node** node,long long key){
  if(*node==NULL){
    *node=malloc(sizeof(Node));
    (*node)->num=key;
    (*node)->left=NULL;
    (*node)->right=NULL;
  }else{
  if((*node)->num>=key){
    insert(&(*node)->left,key);
  }else{
    insert(&(*node)->right,key);
  }
  }
}

void print_pre(Node** node){
  if(*node==NULL)return;
  printf(" %lld",(*node)->num);
  print_pre(&(*node)->left);
  print_pre(&(*node)->right);
}

void print_in(Node** node){
  if(*node==NULL)return;
  print_in(&(*node)->left);
  printf(" %lld",(*node)->num);
  print_in(&(*node)->right);   
}

int find(Node** node,long long key){
  if(*node==NULL)return 0;
  if((*node)->num==key)return 1;
  if((*node)->num>=key){
    find(&(*node)->left,key);
  }else{
    find(&(*node)->right,key);
  }
}
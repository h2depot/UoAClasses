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
long long find(Node**,long long);
Node* delete(Node*, long long);
Node* find_min(Node*);


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
    }else if(strcmp(com,"find")==0){
      scanf("%lld",&key);
      if(find(&node_head,key)!=-1){
        printf("yes\n");
      }else{
        printf("no\n");
      }
    }else{
      scanf("%lld",&key);
      node_head = delete(node_head,key);
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

long long find(Node** node,long long key){
  if(*node==NULL)return -1;
  if((*node)->num==key)return (*node)->num;
  if((*node)->num>=key){
    return find(&(*node)->left,key);
  }else{
    return find(&(*node)->right,key);
  }
}

Node* delete(Node* node, long long key){
  if (key<node->num){
    node->left=delete(node->left,key);
  }else if(key>node->num){
    node->right=delete(node->right,key);
  }else{
  if(node->left==NULL){
    Node *tmp=node->right;
    free(node);
    return tmp;
  }
  if(node->right==NULL){
    Node *tmp=node->left;
    free(node);
    return tmp;
  }
  
  Node *tmp = find_min(node->right);
  node->num= tmp->num;
  node->right = delete(node->right,tmp->num);
  }
  return node;
}

Node* find_min(Node* node){
  while(node->left != NULL){
    node=node->left;
  }
  retur
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int key;
    struct node *next;
    struct node *prev;
};
typedef struct node * Nodepointer;

Nodepointer insert(int);
Nodepointer delete(int);
Nodepointer finditem(int);
Nodepointer make_1node(int,Nodepointer);

Nodepointer head;

int main(){
    int n;
    int i;
    int key;
    char c_key[12];
    Nodepointer node;

    head=make_1node(0,NULL);

    scanf("%d",&n);

    for(i=0;i<n;i++){
      scanf("%s%d",c_key,&key);
      if(strcmp(c_key,"insert")==0){
        insert(key);
      }else if(strcmp(c_key,"delete")==0){
        delete(key);
      }else if(strcmp(c_key,"deleteFirst")==0){

      }else if(strcmp(c_key,"deleteLast")==0){

      }
    }

    for(node=head->next;node->next!=NULL;node=node->next){
        printf("%d ",node->key);
    }
    printf("%d\n",node->key);

    return 0;
}

Nodepointer insert(int keydata){
  Nodepointer newnode;
  newnode = make_1node(keydata,head->next);
  head->next = newnode;
  return newnode;
}

Nodepointer delete(int keydata){
  Nodepointer n;

  n=finditem(keydata);
  if(n!=NULL){
    Nodepointer target=n->next;
    n->next=target->next;
    free(target);
  }
}

Nodepointer finditem(int keydata){
  Nodepointer n;

  for(n=head;n->next!=NULL;n=n->next){
    if(n->next->key==keydata)return n;
  }
  return NULL;
}

Nodepointer make_1node(int keydata,Nodepointer p){
    Nodepointer n;
    if((n=(Nodepointer)malloc(sizeof(struct node)))==NULL){
        printf("Error in memory allocation\n");
        exit(1);
    }
    n->key=keydata;
    n->next=p;

    return n;
}
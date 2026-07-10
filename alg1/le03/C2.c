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
Nodepointer deleteFirst(void);
Nodepointer deleteLast(void);

Nodepointer head,tail;

int main(){
    int n;
    int i;
    int key;
    char c_key[12];
    Nodepointer node;

    //printf("I am here!\n");

    head=make_1node(0,NULL);
    tail=make_1node(0,NULL);

    //printf("I am here after head & tail!\n");

    head->next=tail;
    tail->prev=head;

    scanf("%d",&n);

    for(i=0;i<n;i++){
      scanf("%s%d",c_key,&key);
      if(strcmp(c_key,"insert")==0){
        insert(key);
      }else if(strcmp(c_key,"delete")==0){
        delete(key);
      }else if(strcmp(c_key,"deleteFirst")==0){
        deleteFirst();
      }else if(strcmp(c_key,"deleteLast")==0){
        deleteLast();
      }
    }

    for(node=head->next;node!=tail;node=node->next){
        printf("%d",node->key);
        if(node->next!=tail)printf(" ");
      }
      printf("\n");
    return 0;
}

Nodepointer insert(int keydata){
  Nodepointer newnode,tmpnode;
  newnode = make_1node(keydata,head->next);
  
  tmpnode=head->next;
  head->next = newnode;
  newnode->prev = head;
  tmpnode->prev=newnode;

  return newnode;
}

Nodepointer delete(int keydata){
  Nodepointer n;

  n=finditem(keydata);
  if(n!=NULL){
    Nodepointer target,t_next;
    target=n->next;
    t_next=target->next;

    n->next=t_next;
    t_next->prev=n;
    free(target);
    return n;
  }
  return NULL;
}

Nodepointer finditem(int keydata){
  Nodepointer n;

  for(n=head;n->next!=tail;n=n->next){
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

Nodepointer deleteFirst(){
  Nodepointer target,t_next;
  target=head->next;
  t_next=target->next;

  head->next=t_next;
  t_next->prev=head;
  
  free(target);

  return target;
}

Nodepointer deleteLast(){
  Nodepointer target,t_prev;
  target=tail->prev;
  t_prev=target->prev;

  t_prev->next=tail;
  tail->prev=t_prev;
  free(target);
  
  return target;
}
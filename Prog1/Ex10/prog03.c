#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studlist10.h"

int main()
{
  Record r;
  int i;
  FILE *fp;
 
  /* リストの初期化 */
  head = make_1node( r , NULL );

  fp=fopen("Student.txt","r");
  while(1){
  if (fscanf(fp,"%d %s %s %d", &r.id, r.surname, r.givenname, &r.age) != 4) {
    printf("\n");
    break;
  }
  if (insert(r) == NULL) {
    printf("ID %d is already on the list!\n", r.id);
  }
  }
  fclose(fp);

  listprint();
  
  /* 新しいノードをリストに追加する */
  /* CTL+D でループを抜ける */
  while (1) {
    //printf("Insert new student data: (ID Surname Givenname Age) -> ");
    
    /*if (scanf("%d %s %s %d", &r.id, r.surname, r.givenname, &r.age) != 4) {
      printf("\n");
      break;
    }
    if (insert(r) == NULL) {
      printf("ID %d is already on the list!\n", r.id);
    }
    listprint();*/
    char str[8];
    
    printf("Input match data (ID) -> ");
    if(scanf("%s",str)==EOF)break;
    listprint_sel(str);

  }
  printf("\n");
  return 0;
}

NodePointer insert(Record r)
{
  NodePointer newnode,n;

  if (finditem(r.id) == NULL) { /* 重複するノードの検索 */
    for(n = head; n->next!=NULL; n = n->next)continue;
    newnode = make_1node(r, n->next); /* headの下に新しいノードを作成 */
    n->next = newnode; /* headの下に新しいノードをつなぐ */
    return newnode;
  }
  else return NULL;
}

void listprint(void)
{
  NodePointer n;
  int count=0;

  printf("Head - \n");
  for(n = head->next; n!=NULL; n = n->next){ /* headの次のノードからNULLの前までたどる */
    printf("  %7d %-12s %-12s %d\n", n->data.id, n->data.surname, n->data.givenname, n->data.age);
    count++;
  }
  printf("%d nodes exist in the list\n",count);
  printf("\n");
}

NodePointer finditem(int sid)
{
  NodePointer n;

  for (n = head; n->next!=NULL; n=n->next) { /* headからNULLの一つ前までのノードをたどる */
    if (n->next->data.id == sid) return n; /* sidと同じ値が見つかったら一つ手前のノードを指すポインタを返す */
  }
  return NULL;
}

NodePointer make_1node(Record r, NodePointer p)
{
  NodePointer n;

  if ((n = (NodePointer)malloc(sizeof(struct node)) ) == NULL) { /* メモリ確保 */
    printf("Error in memory allocation\n");
    exit(8);
  }

  /* dataとnextに引数の値をセットする */
  n->data = r; 
  n->next = p; 
  return n;
}

void listprint_sel(char *c){
  NodePointer n;
  char strid[8];
  int cntstr;

  cntstr=strlen(c);
  for(n=head;n!=NULL;n=n->next){
    sprintf(strid,"%d",n->data.id);
    if(strncmp(strid,c,cntstr)==0){
    printf("  %7d %-12s %-12s %d\n", n->data.id, n->data.surname, n->data.givenname, n->data.age);
    }
  }
  printf("\n");
}

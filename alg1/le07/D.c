#include <stdio.h>
#include <stdlib.h>

void restruct_Tree(int,int*,int*,int,int,int*);

int count_meta=0;

int main(){
  int n;
  int i;

  scanf("%d",&n);
  int *preorder=(int *)malloc(n*sizeof(int));
  int *inorder=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)scanf("%d",&preorder[i]);
  for(i=0;i<n;i++)scanf("%d",&inorder[i]);
  int count=-1;
  restruct_Tree(n,preorder,inorder,0,n,&count);

  free(preorder);
  free(inorder);

  return 0;
}

void restruct_Tree(int n,int *preorder,int *inorder, int l, int r,int *count){
  int i,m,c;

  if(l>=r)return;
  (*count)++;
  //printf("count_meta = %d\n",count_meta);
  c=preorder[*count];
  for(m=l;m<r;m++)if(inorder[m]==c)break;
  restruct_Tree(n,preorder,inorder,l,m,count);
  restruct_Tree(n,preorder,inorder,m+1,r,count);
  if(count_meta<n-1){
    printf("%d ",c);
    count_meta++;
  }else{
    printf("%d\n",c);

  }
}

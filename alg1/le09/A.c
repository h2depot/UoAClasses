#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  int i;

  scanf("%d",&n);
  int *nodes=(int *)malloc((n+1)*sizeof(int));
  for(i=1;i<n+1;i++){
    scanf("%d",&nodes[i]);
  }

  for(i=1;i<n+1;i++){
    printf("node %d: key = %d, ",i,nodes[i]);
    if(i/2>0)printf("parent key = %d, ",nodes[i/2]);
    if(i*2<=n)printf("left key = %d, ",nodes[i*2]);
    if((i*2+1)<=n)printf("right key = %d, ",nodes[i*2+1]);
    printf("\n");
  }
  
  free(nodes);

  return 0;
}
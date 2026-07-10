#include <stdio.h>
#include <stdlib.h>


int main(){
  int n;
  int i;
  int max_pro,min;

  scanf("%d",&n);

  int* R = (int*)malloc(n * sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  max_pro = R[1]-R[0];
  min = R[0];
  for(i=1;i<n;i++){
    if(max_pro < R[i]-min)max_pro=R[i]-min;
    if(min > R[i])min=R[i];
  }

  printf("%d\n",max_pro);

  free(R)

  return 0;
}

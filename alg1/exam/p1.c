#include <stdio.h>
#include <stdlib.h>

#define NMAX 10001

int main(){
  int array[NMAX];
  int i,ans;

  for(i=0;i<NMAX;i++)scanf("%d",&array[i]);
  int x=array[10000];
  for(i=0;i<NMAX;i++){
    if(array[i]==x){
      ans=i;
      break;
    }
  }
  printf("%d\n",ans);
    
  return 0;
}

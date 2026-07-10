#include <stdio.h>
#include <stdlib.h>

#define NMAX 10000
#define TMAX 500

int main(){
  int N[NMAX],T[TMAX],n,q;
  int i,j;
  int count=0;

  scanf("%d",&n);
  if(!(n<=NMAX))exit(1);
  for(i=0;i<n;i++){
    scanf("%d",&N[i]);
  }
  scanf("%d",&q);
  if(!(q<=TMAX))exit(1);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==N[j]){
        count++;
        j=n;
        }
    }
  }

  printf("%d\n",count);


    return 0;
}
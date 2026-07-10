#include <stdio.h>
#include <stdlib.h>

#define NMAX 100000
#define TMAX 50000

int main(){
  int N[NMAX],T[TMAX],n,q;
  int i,j;
  int mid,start,end;
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
    start=0;
    end=n;
    while(start<end){
      mid=(start+end)/2;
      if(N[mid]>T[i]){
        end=mid;
      }else if(N[mid]<T[i]){
        start=mid+1;
      }else if(N[mid]==T[i]){
        count++;
        start=end;
      }
    }

  }

  printf("%d\n",count);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define NMAX 10000
#define NUMMAX 100000000

int main(){

int array[NMAX],n;
int i,j,k;
int count=0,flag=0;

scanf("%d",&n);
if(!(n>=1 && n<=NMAX))exit(1);

for(i=0;i<n;i++){
  scanf("%d",&array[i]);
  if(!(array[i]>=2 && n <=NUMMAX))exit(1);
}

for(i=0;i<n;i++){
  flag=1;
  for(j=2;j*j<=array[i];j++){
    if(array[i]%j==0){
      flag=0;
    }
  }
  if(flag==1)count++;
}

printf("%d\n",count);

return 0;
}
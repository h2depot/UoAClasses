#include <stdio.h>
#include <stdlib.h>

#define NUMMAX 1000000000

int main(){

  int x,y,d,tmp=1;
  int i;

 
  scanf("%d%d",&x,&y);

  if(!(x>=1 && x<=NUMMAX && y>=1 && y<=NUMMAX)){
    exit(1);
  }

  if(x > y){
    d=x%y;
    for(i=2;i<d;i++){
      if(d%i==0 && y%i==0 && i>tmp){
        tmp=i;
      }
    }
  }else if(x < y){
    d=y%x;
    for(i=2;i<d;i++){
      if(d%i==0 && x%i==0 && i>tmp){
        tmp=i;
      }
    }
  }else{
    tmp=x;
  }
    printf("%d\n",tmp);

  return 0;
}

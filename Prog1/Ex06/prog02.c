#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
  int i;

  for(i=1;i<argc;i++){
    int x;
    x = atoi(argv[i]);
    if(x<35){
      printf("評定%d 評価：F\n",x);
    }else if(x >=35 && x<= 49){
      printf("評定%d 評価：D\n",x);
    }else if(x >=50 && x<= 64){
      printf("評定%d 評価：C\n",x);       
    }else if(x >= 65 && x<= 79){
      printf("評定%d 評価：B\n",x);       
    }else if(x >= 80 && x<= 100){
      printf("評定%d 評価：A\n",x);
    }
  }

    return 0;
}
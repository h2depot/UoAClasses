#include <stdio.h>
#include <stdlib.h>

#define MAXOPERA 100
#define MAXMARK 99
//#define MAXNUM1 1000000000
//#define MAXNUM2 1000000

int calc(int,int,char);
int tenjou(int,int);

int main(){
  char opemark;
  int opera[MAXOPERA+1],po[6];
  int j,k,o=1;
  int num;

  while(1){
    if(scanf("%c",&opemark)==EOF)break;
    if(opemark>='0' && opemark<='9'){
      //printf("enered number!\n");
      num=0;
      po[0]=opemark-'0';
      for(j=1;;j++){
        scanf("%c",&opemark);
        if(opemark==' ')break;
        po[j]=opemark-'0';
        //printf("j = %d\n",j);
      }
      for(k=j;k>0;k--){
        num+=tenjou(po[j-k],k);
        }
        opera[o]=num;
        //printf("new ! opera[o] = %d\n",opera[o]);
        //printf("o = %d\n",o);
        o++;
    }else if(opemark=='+' || opemark=='-' || opemark=='*'){
      //printf("o = %d\nopera[o-2] = %d\nopera[o-1] = %d\n",o,opera[o-2],opera[o-1]);
      opera[o-2]=calc(opera[o-2],opera[o-1],opemark);
      o--;
    }else{
        continue;
    }
  }
  printf("%d\n",opera[o-1]);

  return 0;
}

int calc(int a,int b,char c){
    if(c == '+'){
      return a+b;
    }else if(c == '*'){
      return a*b;
    }else if(c == '-'){
      return a-b;
    }
}

int tenjou(int a,int jou){
    int i;
  for(i=jou-1;i>0;i--){
    a=a*10;
  }
  return a;
}



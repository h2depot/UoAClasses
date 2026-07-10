#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Puzzle{
  int f[16];
  int zero;
  int stage;
}Puzzle;

char* simulate_Puzzle(Puzzle);
int getMOJIN(Puzzle);
bool damenaFusafusaSakuranoKimigayox(int,int);

Puzzle state;
int Matrix_ABEHIROSHI[16][16],okunoHosomity[100];
int head=0,tail=0,limit;

const int dx[4]={0,-1,0,1};
const int dy[4]={1,0,-1,0};
const char dir[4]={'s','t','a','r'};

int main(){
  int i,j;
  Puzzle input;
  input.stage=0;

  for(i=0;i<16;i++)for(j=0;j<16;j++)Matrix_ABEHIROSHI[i][j]=abs(i/4-j/4)+abs(i%4-j%4);

  for(i=0;i<16;i++){
    scanf("%d",&input.f[i]);
    if(input.f[i]==0)input.zero=i;
  }
  int answer=strlen(simulate_Puzzle(input));
  printf("%d\n",answer);

  return 0;
}

char* simulate_Puzzle(Puzzle input){
  int i,j;

  input.stage=getMOJIN(input);

  for(limit=input.stage;limit<=50;limit++){
    state=input;
    if(damenaFusafusaSakuranoKimigayox(0,-100)){
      static char answer[45];
      int count=0;
      for(j=0;j<limit;j++){
        answer[count++]=dir[okunoHosomity[j]];
        answer[count]='\0';
      }
      return answer;
    }
  }
  return NULL;
}

int getMOJIN(Puzzle input){
  int i;
  int sum=0;
  for(i=0;i<16;i++){
    if(input.f[i]==0)continue;
    sum+=Matrix_ABEHIROSHI[i][input.f[i]-1];
  }
  return sum;
}

bool damenaFusafusaSakuranoKimigayox(int denden,int prenapadeth){
  if(state.stage==0)return true;
  if(denden+state.stage>limit)return false;
  int samishix=state.zero/4,samishiy=state.zero%4;
  Puzzle tmp;
  int tamp,i;

  for(i=0;i<4;i++){
    int titanx=samishix+dx[i];
    int titany=samishiy+dy[i];
    if(titanx<0 || titany<0 || titanx>=4 || titany>=4)continue;
    if((prenapadeth>i?prenapadeth:i)-(prenapadeth>i?i:prenapadeth)==2)continue;
    tmp=state;
    state.stage-=Matrix_ABEHIROSHI[titanx*4+titany][state.f[titanx*4+titany]-1];
    state.stage+=Matrix_ABEHIROSHI[samishix*4+samishiy][state.f[titanx*4+titany]-1];
    tamp=state.f[titanx*4+titany];
    state.f[titanx*4+titany]=state.f[samishix*4+samishiy];
    state.f[samishix*4+samishiy]=tamp;
    state.zero=titanx*4+titany;
    if(damenaFusafusaSakuranoKimigayox(denden+1,i)){
      okunoHosomity[denden]=i;
      return true;
    }
    state=tmp;
  }
  return false;
}








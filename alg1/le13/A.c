#include <stdio.h>
#include <stdlib.h>

void Locatify(int);
void Print(void);

int Board[8][8],array_gyo[8],array_retu[8],nana1[15],nana2[15];

int main(){
  int n,row,col;
  int i,j;

  for(i=0;i<8;i++)for(j=0;j<8;j++)Board[i][j]=0;
  for(i=0;i<8;i++){
    array_gyo[i]=-1;
    array_retu[i]=0;
  }
  for(i=0;i<15;i++){
    nana1[i]=0;
    nana2[i]=0;
  }
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&row,&col);
    Board[row][col]=1;
  }
  Locatify(0);

  return 0;
}

void Locatify(int x){
  int i;

  if(x==8){
    Print();
    return;
  }
  for(i=0;i<8;i++){
    if(array_retu[i]==1 || nana1[x+i]==1 || nana2[x-i+7]==1)continue;
    array_gyo[x]=i;
    array_retu[i]=1;
    nana1[x+i]=1;
    nana2[x-i+7]=1;
    Locatify(x+1);
    array_gyo[x]=0;
    array_retu[i]=0;
    nana1[x+i]=0;
    nana2[x-i+7]=0;
  }
}

void Print(){
  int i,j;

  for(i=0;i<8;i++)for(j=0;j<8;j++)if(Board[i][j]==1)if(array_gyo[i]!=j)return;
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      if(array_gyo[i]==j)printf("Q");
      else printf(".");
    }
    printf("\n");
  }
}

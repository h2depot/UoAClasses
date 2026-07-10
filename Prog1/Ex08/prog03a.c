#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 600000 /* 試行回数 */
     
typedef struct{
  int data[N]; /* N個の要素を持つ配列 */
  int count[6]; /* 各出目の回数 */
}DiceRollData;

void ComputerStatisticsPtr(DiceRollData *);

int main(){
  int i;
  DiceRollData dice;

  srand((unsigned int)time(NULL));

  for(i=0;i<N;i++){
    dice.data[i]=rand()%6;
  }
  for(i=0;i<6;i++){
    dice.count[i]=0;
  }

  ComputerStatisticsPtr(&dice);
  
  for(i=0;i<6;i++){
    printf("[%d]: %d\n",i,dice.count[i]);
  }

  return 0;
}

void ComputerStatisticsPtr(DiceRollData *dicep){
    int i;
    for(i=0;i<N;i++){
    switch(dicep->data[i]){
      case 0:
      dicep->count[0]++;
      break;
      case 1:
      dicep->count[1]++;
      break;
      case 2:
      dicep->count[2]++;
      break;
      case 3:
      dicep->count[3]++;
      break;
      case 4:
      dicep->count[4]++;
      break;
      case 5:
      dicep->count[5]++;
      break;
    }
    }
}
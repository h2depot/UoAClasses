#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 600000 /* 試行回数 */
     
typedef struct{
  int data[N]; /* N個の要素を持つ配列 */
  int count[6]; /* 各出目の回数 */
}DiceRollData;

void ComputerStatisticsPtr(DiceRollData *);
DiceRollData ComputeStatisticsV(DiceRollData);

int main(){
  int i;
  DiceRollData dice;
  time_t start,end;
  double keikap,keikav;

  srand((unsigned int)time(NULL));
  
  for(i=0;i<N;i++)dice.data[i]=rand()%6;
  for(i=0;i<6;i++)dice.count[i]=0;
  printf("ComputeStaticsPtr (Call by address):\n");
  start=clock();
  ComputerStatisticsPtr(&dice);
  end=clock();
  keikap=(end-start)/(double)CLOCKS_PER_SEC;
  for(i=0;i<6;i++)printf("[%d]: %d\n",i,dice.count[i]);
  printf("\n");

  for(i=0;i<N;i++)dice.data[i]=rand()%6;
  for(i=0;i<6;i++)dice.count[i]=0;
  printf("ComputeStaticsV (Call by value):\n");
  start=clock();
  dice=ComputeStatisticsV(dice);
  end=clock();
  keikav=(end-start)/(double)CLOCKS_PER_SEC;
  for(i=0;i<6;i++)printf("[%d]: %d\n",i,dice.count[i]);
  printf("\n");

  printf("--- time ---\n");
  printf("Call by address:   %fsec\n",keikap);  
  printf("Call by value:   %fsec\n",keikav);  

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

DiceRollData ComputeStatisticsV(DiceRollData dice){
  int j;
    for(j=0;j<N;j++){
    switch(dice.data[j]){
      case 0:
      dice.count[0]++;
      break;
      case 1:
      dice.count[1]++;
      break;
      case 2:
      dice.count[2]++;
      break;
      case 3:
      dice.count[3]++;
      break;
      case 4:
      dice.count[4]++;
      break;
      case 5:
      dice.count[5]++;
      break;
    }
    }
    return dice;
}
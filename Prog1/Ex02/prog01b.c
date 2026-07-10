#include <stdio.h>

void seqaverage_global(double);

double avg=0;
int cnt=0;

int main(){

  double input;
    while(1){
    
    printf("入力データ:");
    if(scanf("%lf", &input) == EOF)break;
    seqaverage_global(input);

    printf("データ数:%d, 平均:%f\n",cnt,avg);
  }
  
  printf("\n最終結果はデータ数%dで、平均値%fでした\n",cnt,avg);
  
  return 0;
}

void seqaverage_global(double input){
  cnt++;
  avg=(avg*(cnt-1)+input)/cnt;

}

#include <stdio.h>

double seqaverage_static(double);

int main(){
  double input;
  int cnt;
  double ave;
  
    while(1){
    
    printf("入力データ:");
    if(scanf("%lf", &input) == EOF)break;
    cnt++;
    ave = seqaverage_static(input);
    printf("データ数:%d, 平均:%f\n",cnt,ave);
    
  }
  
  printf("\n最終結果はデータ数%dで、平均値%fでした\n",cnt,ave);
  
  return 0;
}

double seqaverage_static(double input){
  static double avg=0;
  static int count=0;
  count++;
  avg=(avg*(count-1)+input)/count;
  
  
  return avg;
}

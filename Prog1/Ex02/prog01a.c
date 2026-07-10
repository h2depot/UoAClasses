#include <stdio.h>

double seqaverage(double, double, int);

int main(){
  double ave = 0,input;
  int count = 0;

  while(1){
    
    printf("入力データ:");
    if(scanf("%lf", &input) == EOF)break;
    count++;
    ave = seqaverage(input,ave,count);

    printf("データ数:%d, 平均:%f\n",count,ave);
  }

  

  printf("\n最終結果はデータ数%dで、平均値%fでした\n",count,ave);
  
  return 0;
}

double seqaverage(double input,double ave,int count){
  double newave;

  newave = (ave*(count-1)+input)/count;

  return newave;
}

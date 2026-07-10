#include <stdio.h>
#define MAX 12

int bmi_hantei(double);
int main(){
  int scan,count=0,count2=0, hantei,BMI[MAX], per = 0;
  int i;
  double cm[MAX], kg[MAX], bmi[MAX], metre;
  
  printf("身長(cm)と体重(kg)を空白で区切って入力してください。\n入力可能な最大の人数は12人です。\n");

  for (i=0; i <MAX; i++){
    scan = scanf("%lf%lf", &cm[i], &kg[i]);
    if (scan == EOF)break;
    metre = cm[i]/(double)100;
    BMI[i] = (kg[i]/(metre*metre) + 0.05) * 10;
    bmi[i] = BMI[i]/(double)10;
    count++;
  }

  printf("      BMI  肥満度分類\n");
  
  for(i=0; i < count; i++){
    printf("%d人目 %.1f ", i+1, bmi[i]);
    hantei = bmi_hantei(bmi[i]);

    switch(hantei){
    case -1: printf("低体重\n");
      break;
    case 0: printf("普通体重\n");
      count2++;
      break;
    case 1: printf("肥満(1度)\n");
      break;
    case 2: printf("肥満(2度)\n");
      break;
    case 3: printf("肥満(3度)\n");
      break;
    case 4: printf("肥満(4度)\n");
      break;
    }

  }
    per = 100*(double)count2/(double)count + 0.5;
    printf("\n肥満度分類が普通体重である人の割合は%dパーセントです。\n", per);
  return 0;
}

int bmi_hantei(double x){
    if(x < 18.5) return -1;
    else if(18.5 <= x && x < 25) return 0;
    else if(35 <= x && x < 30) return 1;
    else if (30 <= x && x < 35) return 2;
    else if (35 <= x && x < 40) return 3;
    else return 4;
  }
  

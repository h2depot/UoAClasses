#include <stdio.h>
#include "prog01.h"

#define Y 2024
#define M 10
#define D 28

My_record input(void);
void output(My_record);
int get_age(My_record);

int main(){
  My_record data;
  data = input();
  output(data);
  get_age(data);

  return 0;
}

My_record input(){
  My_record data;
  printf("--------データ入力--------\n");
  printf("名字 ->");
  scanf("%s",data.lastname);
  printf("名前 ->");
  scanf("%s",data.firstname);
  printf("性別 (Male/Female) ->");
  scanf("%s",data.gender);
  printf("生まれた年 (西暦) ->");
  scanf("%d",&data.birthday[0]);
  printf("生まれた月 ->");
  scanf("%d",&data.birthday[1]);
  printf("生まれた日 ->");
  scanf("%d",&data.birthday[2]);
  return data;
}

void output(My_record data){
  printf("\n");
  printf("--------データ出力--------\n");
  printf("年齢基準日: %d/%d/%d\n",Y,M,D);
  printf("\n");
  printf("氏名: %s %s\n",data.lastname,data.firstname);
  printf("性別: %s\n",data.gender);
  printf("生年月日: %d/%d/%d\n",data.birthday[0],data.birthday[1],data.birthday[2]);
}

int get_age(My_record data){
    int age;

    if(data.birthday[1] < M){
      age = Y - data.birthday[0];
    }else if(data.birthday[1] == M){
      if(data.birthday[2]<D){
      age = Y - data.birthday[0];
      }else if(D  <= data.birthday[2]){
      age = Y - data.birthday[0] - 1 ;
      }
    }else if(data.birthday[1] > M){
      age = Y - data.birthday[0] - 1;
    }
    printf("年齢: %d\n",age);
    return 0;
}
#include <stdio.h>
#include "prog01.h"

#define Y 2024
#define M 10
#define D 28
#define N 20

My_record input(void);
void output(My_record);
int get_age(My_record);

int main(){
  My_record data[N];
  int i;

  printf("\n");
  printf("--------データ出力--------\n");
  printf("年齢基準日: %d/%d/%d\n",Y,M,D);
  printf("\n");

  for(i=0;;i++){
    data[i] = input();
    if(data[i].birthday[0] == -1)break;
    output(data[i]);
  }
  return 0;
}

My_record input(){
  My_record data;
  int i,status;

  status = scanf("%s",data.lastname);
  if(status == EOF){
    data.birthday[0]= -1;
    return data;
  }
  scanf("%s",data.firstname);
  scanf("%s",data.gender);
  scanf("%d",&data.birthday[0]);
  scanf("%d",&data.birthday[1]);
  scanf("%d",&data.birthday[2]);

  return data;
}

void output(My_record data){

  printf("氏名: %-10s %-10s, ",data.lastname,data.firstname);
  printf("性別: %-6s, ",data.gender);
  printf("生年月日: %4d/%2d/%2d, ",data.birthday[0],data.birthday[1],data.birthday[2]);
  get_age(data);
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
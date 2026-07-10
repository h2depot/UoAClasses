#include<stdio.h>
#include<stdlib.h>

#define TARGET 500
#define NMAX 12

void count_money(int,int);

int n,count=0;
int A[NMAX];

int main(){
    int i,j;
    int flag=0;

    for(i=0;i<NMAX;i++)scanf("%d",&A[i]);

    count_money(0,0);

    printf("%d\n",count);

  return 0;
}

void count_money(int input, int sum){
    if(sum==TARGET){
      count++;
      return;
    }else if(input==NMAX){
      return;
    }

    count_money(input+1,sum);
    count_money(input+1,sum+A[input]);
}


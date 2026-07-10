#include<stdio.h>
#include<stdlib.h>

#define TARGET 400
#define NMAX 12

int count_money(int,int);

int n,count=0;
int A[NMAX];

int main(){
    int i,j,min=-1;
    int flag=0;

    for(i=0;i<NMAX;i++)scanf("%d",&A[i]);

    for(i=TARGET+1;i<=TARGET+100;i++){
        if(count_money(0,0)==i){
            if(i>=430 && min>i)min=i;
        }
    }

    printf("%d\n",min);

  return 0;
}

int count_money(int input, int sum){
    if(sum>=TARGET){
      count++;
      return sum;
    }else if(input==NMAX){
      return -1;
    }

    count_money(input+1,sum);
    count_money(input+1,sum+A[input]);
}


#include<stdio.h>
#include<stdlib.h>

int rec(int,int);

int n,q;
int A[2000],M[2000];

int main(){
    int i,j;
    int flag=0;

    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&A[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++)scanf("%d",&M[i]);

    for(i=0;i<q;i++){
        flag=0;
        for(j=0;j<n;j++){
            if(rec(j,M[i])){
                printf("yes\n");
                j=n;
                flag=1;
            }
        }
        if(flag!=1)printf("no\n");
    }
  return 0;
}

int rec(int i,int m){
    if(m==0) return 1;
    if(i>=n) return 0;
    
    if(rec(i+1,m)==1){
      return 1;
    }if(rec(i+1,m-A[i])==1){
      return 1;
    }
}
#include<stdio.h>
#include<stdlib.h>

#define INFTY 1000000001
#define NMAX 1000001
#define TARGET 100

void margeSort(int*,int,int);
void marge(int*,int,int,int);

int n,count=0;

int main(){
    int i,j,S[NMAX];

  
  for(i=0;i<NMAX;i++)scanf("%d",&S[i]);

  margeSort(S,0,NMAX);
  for(i=NMAX-1;i>NMAX-10;i--)printf("%d %d\n",NMAX-i,S[i]);
  for(i=0;i<10;i++)printf("%d %d\n",+1+i,S[i]);
  printf("%d\n",S[500000]);
  
  return 0;
}

void margeSort(int *A,int left,int right){
  int mid;

    if(left+1<right){
      mid=(left+right)/2;
      margeSort(A,left,mid);
      margeSort(A,mid,right);
      marge(A,left,mid,right);
    }
}

void marge(int *A,int left,int mid,int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  int *L=(int *)malloc((n1+1)*sizeof(int));
  int *R=(int *)malloc((n2+1)*sizeof(int));

  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
    if(L[i]<=R[j]){
        A[k]=L[i];
        i++;
    }else{
        A[k]=R[j];
        j++;
    }
        count++;
  }
    free(L);
    free(R);
}



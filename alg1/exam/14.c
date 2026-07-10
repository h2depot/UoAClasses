#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2000000
#define NMAX 1000000

void insert(int *,int);
void increase_S(int *,int,int);
int extractMax(int *);
void maxheapify(int *,int);

int height=0;

int main(){
  int n,i;
  int S[MAX];
  long long sum=0;

  for(i=0;i<NMAX;i++){
    scanf("%d",&n);
    if(n==0)extractMax(S);
    else insert(S,n);
  }

  for(i=0;i<height;i++){    
    sum+=(long long)S[i];
  }

  printf("%lld\n",sum);


  return 0;
}

void insert(int*S,int k){
height++;
S[height]=-1;
increase_S(S,height,k);
}

void increase_S(int *S,int h,int key){
  int i;
  int tmp;
  if(key<S[h])return;
  S[h]=key;
  while(h>0 && S[h/2]<S[h]){
        tmp=S[h];
        S[h]=S[h/2];
        S[h/2]=tmp;
        h=h/2;
  }
}

int extractMax(int * S){
int max;

max=S[0];
S[0]=S[height];
height--;
maxheapify(S,0);

return max;
}

void maxheapify(int*A,int i){
      int l = i*2;
    int r = i*2+1;
    int largest,tmp;

    if(l<=height && A[l]>A[i])largest=l;
    else largest=i;

    if(r<=height && A[r]>A[largest])largest=r;

    if(largest != i){
      tmp = A[i];
      A[i]=A[largest];
      A[largest]=tmp;
      maxheapify(A,largest);
    }
}
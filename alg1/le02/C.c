#include <stdio.h>
#include <stdlib.h>

#define NMAX 36

struct array{
    int a;
    char c;
};

void BubbleSort(struct array*, int);
void SelectionSort(struct array*,int);
int Stable(struct array*,struct array*,int);

struct array Bubble[NMAX],Select[NMAX];

int main(){
  int n;
  int i;
  struct array C[NMAX];

  scanf("%d",&n);
  if(!(n>=1 && n<=NMAX)){
    exit(1);
  }

  for(i=0;i<n;i++){
    scanf("\n%c",&C[i].c);
    scanf("%d",&C[i].a);
  }

  for(i=0;i<n;i++){
    Bubble[i]=C[i];
  }
  for(i=0;i<n;i++){
    Select[i]=C[i];
  }
 
  BubbleSort(Bubble,n);
  SelectionSort(Select,n); 

  for(i=0;i<n-1;i++){
    printf("%c%d ",Bubble[i].c,Bubble[i].a);
  }
    printf("%c%d\n",Bubble[i].c,Bubble[i].a);
  
  if(Stable(Bubble,C,n)==0)printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n-1;i++){
    printf("%c%d ",Select[i].c,Select[i].a);
  }
    printf("%c%d\n",Select[i].c,Select[i].a);
  
  if(Stable(Select,C,n)==0)printf("Stable\n");
  else printf("Not stable\n");


  return 0;
}

void BubbleSort(struct array *Bubble, int n){
  int i,j;
  struct array tmp;

  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
        if(Bubble[j].a < Bubble[j-1].a){
          tmp=Bubble[j];
          Bubble[j]=Bubble[j-1];
          Bubble[j-1]=tmp;
        }
    }
  }
}

void SelectionSort(struct array *Select, int n){
  int i,j;
  int minj;
  struct array tmp;

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
        if(Select[j].a <Select[minj].a){
            minj=j;
        }
    }
    if(i!=minj){
      tmp=Select[i];
      Select[i]=Select[minj];
      Select[minj]=tmp;
    }
  }

}

int Stable(struct array *C,struct array *A,int n){
int i,j,k;
int num,count=0;
struct array Back;

for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(C[i].a==C[j].a){
            num = C[i].a;
            //printf("--%c%d--%c%d--\n",C[i].c,num,C[j].c,C[j].a);
          if(num == Back.a){
            //printf("Entered back A\n");
           for(k=count;k<n;k++){
            //printf("%c%d\n",A[k].c,A[k].a);
            if(A[k].a==num && A[k].c != C[i].c){
             // printf("%c\n",A[k].c);
              return 1;
            }else if(A[k].a==num && A[k].c == C[i].c){
              if(C[i].a!=C[j+1].a){
                count=k+1;
              }
               // printf("count = %d\n",count);
                k=n;
               //printf("k ended\n");
            }
           }
          }else {
            for(k=0;k<n;k++){
            count=0;
           // printf("%c%d\n",A[k].c,A[k].a);
            if(A[k].a==num && A[k].c != C[i].c){
              //printf("%c\n",A[k].c);
              return 1;
            }else if(A[k].a==num && A[k].c == C[i].c){
                count=k+1;
                //printf("count = %d\n",count);
                k=n;
                //printf("k ended\n");
            }
            }
          }
        }
    }
    Back = C[i];
  //printf("i j ended\n");
}
return 0;
}

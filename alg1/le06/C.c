#include <stdio.h>
#include <stdlib.h>

struct trump{
  char mark;
  int num;
};

int partition(struct trump *,int,int);
void quicksort(struct trump *,int,int);
int Stable(struct trump*,struct trump*,int);

int main(){
    int n;
    int i;

    scanf("%d",&n);
    struct trump *A=(struct trump *)malloc(n*sizeof(struct trump));
    struct trump *Copy=(struct trump *)malloc(n*sizeof(struct trump));    
    for(i=0;i<n;i++){
      scanf(" %c",&A[i].mark);
      scanf("%d",&A[i].num);
      Copy[i]=A[i];
    }

    quicksort(A,0,n-1);
    if(Stable(A,Copy,n)==0)printf("Stable\n");
    else printf("Not stable\n");
    for(i=0;i<n;i++)printf("%c %d\n",A[i].mark,A[i].num);

    free(A);
    free(Copy);

    return 0;
}

int partition(struct trump *A,int p,int r){
    int i,j;
    struct trump x,tmp;

    x=A[r];
    i=p-1;
    for(j=p;j<r;j++){
        if(A[j].num<=x.num){
            i++;
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
    }
    tmp=A[i+1];
    A[i+1]=A[r];
    A[r]=tmp;
    return i+1;
}

void quicksort(struct trump *A,int p,int r){
    int q;
    if(p<r){
      q=partition(A,p,r);
      quicksort(A,p,q-1);
      quicksort(A,q+1,r);
    }
}

int Stable(struct trump *C,struct trump *A,int n){
int i,j,k;
int num,count=0;
struct trump Back;

for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(C[i].num==C[j].num){
            num = C[i].num;
            //printf("--%c%d--%c%d--\n",C[i].c,num,C[j].c,C[j].a);
          if(num == Back.num){
            //printf("Entered back A\n");
           for(k=count;k<n;k++){
            //printf("%c%d\n",A[k].c,A[k].a);
            if(A[k].num==num && A[k].mark != C[i].mark){
             // printf("%c\n",A[k].c);
              return 1;
            }else if(A[k].num==num && A[k].mark == C[i].mark){
              if(C[i].num!=C[j+1].num){
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
            if(A[k].num==num && A[k].mark != C[i].mark){
              //printf("%c\n",A[k].c);
              return 1;
            }else if(A[k].num==num && A[k].mark == C[i].mark){
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
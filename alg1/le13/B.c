#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NMAX 362881

typedef struct Puzzle{
  int f[9];
  int zero;
  int stage;
}Puzzle;

void enqueue(Puzzle);
Puzzle dequeue();
int simulate_Puzzle(Puzzle);
int hashash(Puzzle);

Puzzle queue[NMAX];
int head=0,tail=0;
bool visit[362880] = {false};

const int movement[4]={-1,1,-3,3};

int main(){
  int i;
  Puzzle input;
  input.stage=0;

  for(i=0;i<9;i++){
    scanf("%d",&input.f[i]);
    if(input.f[i]==0)input.zero=i;
  }
  int answer=simulate_Puzzle(input);
  printf("%d\n",answer);

  return 0;
}

void enqueue(Puzzle input){
  int next = (tail+1)%NMAX;
  queue[tail]=input;
  tail=next;
}

Puzzle dequeue(){
  Puzzle val=queue[head];
  head=(head+1)%NMAX;
  return val;
}

int simulate_Puzzle(Puzzle input){
  int i,j,k=0,tmp;

  enqueue(input);
  visit[hashash(input)]=true;

  while(head!=tail){
    k++;
    //printf("again\n");
    Puzzle current = dequeue();

    bool checker=true;
    for(i=0;i<8;i++){
      if(current.f[i]!=i+1){
        checker=false;
        break;
      }
    }
    if(checker==true)return current.stage;

    for(i=0;i<4;i++){
      int neoz=current.zero+movement[i];
      if(neoz<0 || neoz>=9)continue;
      if ((current.zero % 3 == 2 && movement[i] == 1) || (current.zero % 3 == 0 && movement[i] == -1)) continue;

      Puzzle neop=current;
      neop.stage=current.stage+1;
      neop.zero=neoz;
      tmp=neop.f[neoz];
      neop.f[neoz]=neop.f[current.zero];
      neop.f[current.zero]=tmp;

      int hash=hashash(neop);
      //for(j=0;j<9;j++)printf("%d",neop.f[j]);
     // printf("\n");
      //printf("hash=%d\n",hash);
      if(visit[hash]==false) {
        visit[hash]=true;
        enqueue(neop);
       // printf("enqueue\n");
      }
    }
  }
  //printf("head=%d,tail=%d,k=%d\n",head,tail,k);
  return -1;
}

int hashash(Puzzle input){
  int h=0, fact=1,count;
  int i,j;
  for(i=8;i>=0;i--){
      count=0;
      for(j=i+1;j<9;j++){
        if(input.f[j]<input.f[i])count++;
      }
      h+=count*fact;
      fact*=(9-i);
    }
    return h;
}









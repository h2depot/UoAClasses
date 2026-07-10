#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMAX 100000

typedef struct{

  char name[10];
  int time;

}Array;

void enqueue(char*,int);
Array dequeue(void);

Array array[AMAX];
int head=0;
int tail=0;

int main(){
  int i,j;
  int n,q,count=0;
  char name_tmp[10];
  int time_tmp;
  
  scanf("%d",&n);
  scanf("%d",&q);

  for(i=0;i<n;i++){
    scanf("%s",name_tmp);
    scanf("%d",&time_tmp);
    enqueue(name_tmp,time_tmp);
  }
   /*for(i=head;i<tail;i++){
     printf("%s %d\n",array[i].name,array[i].time);
   }*/
  while(1){
    if(head==tail)break;
    if(array[head].time>q){
      count+=q;
      enqueue(array[head].name,array[head].time-q);
      dequeue();
    }else{
     count += array[head].time;
     printf("%s %d\n",array[head].name,count);
     dequeue();
    }
  }


  return 0;
}

void enqueue(char* name_tmp,int time_tmp){
  int next=(tail+1)%AMAX;

  if(next==head){
    printf("Queue overflow!\n");
    exit(1);
  }
  strcpy(array[tail].name,name_tmp);
  array[tail].time=time_tmp;
  tail=next;
}

Array dequeue(){
  Array val;

  if(head==tail){
    printf("Queue is empty!\n");
    exit(2);
  }
  val = array[head];
  head = (head+1)%AMAX;
  return val;
}


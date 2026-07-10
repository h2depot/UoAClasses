/***************************************
 * lec13-2b.c
 *
 * キューのデータ挿入・取り出し毎にキューの内容を表示して、
 * 動作が目に見えるようにした。
 ***************************************/
#include <stdio.h>
#include <stdlib.h>

#define QSIZE 100

void enqueue(int);
int dequeue(void);

int isFull(void);
int isEmpty(void);

int queue[QSIZE];
int head = 0;
int tail = 0;

int main(){
  int data, status, i;

  while (1) {
    printf("input>> ");
    status = scanf("%d", &data);
    if (status != 1) break;

    if (data == 0) printf("Data: %d\n", dequeue() );
    else enqueue(data);

    printf("  [Queue] "); 
    for ( i=head; i!=tail; i=(i+1)%QSIZE ) printf("%d ", queue[i]);
    printf("\n");
  }

  return 0;
}

void enqueue(int num){
  int next = (tail+1)%QSIZE;
  if (isFull() == 1) {
    printf("Queue overflow!\n");
    exit (2);
  }
  queue[tail] = num;
  tail = next;
}

int dequeue(void){
  int val;

  if (isEmpty() == 1) {
    printf("Queue is empty!\n");
    exit (3);
  }
  val = queue[head];
  head = (head+1)%QSIZE;
  return val;
}

int isFull(void){
    int next = (tail+1)%QSIZE;
    int x;
  if (next == head) {
    x = 1;
  }
  else{
    x = 0;
  }
  return x;
}

int isEmpty(void){
  int x;
  if (head == tail){
    x = 1;
  }
  else{
    x = 0;
  }
  return x;
}

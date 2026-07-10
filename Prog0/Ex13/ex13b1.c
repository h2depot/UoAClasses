#include <stdio.h>
#include <stdlib.h>

#define STSIZE 100

void push(int);
int pop(void);

int stack[STSIZE];
int top = 0;

int main(){
  int data, status, i, detector, booler;

  while(1){
    printf("--- Input [+] to push, [-] to pop, [0] to detect --- >>");
    status = scanf("%d", &data);
    if (status != 1)break;

    if (data < 0) printf("Data: %d\n", pop());
    else if (data == 0) {
      booler = 0;
      printf("Detect what ? :");
      scanf("%d", &detector);
      
      for (i=0;i<top;i++){
	if (detector == stack[i]){
          booler = 1;
	  printf("%d exists at stack[%d]\n", detector,i);
	}
      }
	
	if (booler == 0){
	  printf("%d not in stack!\n", detector);
	  exit(4);
	}
	
    }
    else push(data);

    printf(" [Stack] ");
    for (i=0; i<top;i++) printf("%d ", stack[i]);
    printf("\n");
  }
  return 0;
}

void push(int num){
  if (top == STSIZE){
    printf("Stack Over flow!\n");
    exit(2);
  }
  stack[top] = num;
  top++;
}

int pop(void){
  if (top == 0){
    printf("Stack is empty!\n");
    exit(3);
  }
  top--;
  return stack[top];
}



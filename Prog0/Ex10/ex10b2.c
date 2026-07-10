#include <stdio.h>
#define ARRAY 10

int main()
{
  int i, j;
  int num, rev_num;
  int count;
  while(1){
  
    fprintf(stderr, "Enter a number: ");
    scanf("%d", &num);
    if (num == 0) break;
    if (num < 0) {
      fprintf(stderr,"An error occured!\n");
      break;
    }

    for (rev_num = 0; num >0; num /= 10){
      rev_num = rev_num*10 + num%10;
    }

    printf("%d\n",rev_num);

 
  }

  
}

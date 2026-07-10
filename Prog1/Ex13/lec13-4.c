#include <stdio.h>
#include <stdlib.h>

#define TATE 3

int main()
{
  int *arr[TATE],i,j,yoko;

  printf("yoko -> ");
  scanf("%d",&yoko);
  for(i = 0; i < TATE; i++)
    arr[i] = (int *)malloc(sizeof(int) * yoko);
  
  for(i = 0; i < TATE; i++)
    for(j = 0; j < yoko; j++) 
      arr[i][j] = i + j + 1;
  
  printf("size : %d\n",sizeof(arr));
  for(i = 0; i < TATE; i++){
    for(j = 0; j < yoko; j++) 
      printf("%2d ",arr[i][j]);
    printf("\n");
  }
  
  for(i = 0; i < TATE; i++) free(arr[i]);

  return 0;
}

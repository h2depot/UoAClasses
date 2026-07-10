#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXW 100
#define MAXR 128

int main()
{
  char *array[MAXW], va[MAXR];
  int i,j;

  for(i=0;;i++){
    if(scanf("%s",va)==EOF)break;
    array[i]=(char *)malloc(strlen(va)*sizeof(char));
    strcpy(array[i],va);
  }
  printf("\n");
  for(j=0;j<i;j++){
    printf("%d: %s [%d]\n",j,array[j],strlen(array[j]));
    free(array[j]);
  }

  return 0;
}

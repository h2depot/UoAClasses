#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXW 100
#define MAXR 128

void lconv(char *);

int main()
{
  char *array[MAXW], va[MAXR];
  int cnt[MAXW],flag=0;
  int i,j;

  for(i=0;i<MAXW;i++){
    cnt[i]=0;
  }

  for(i=0;;i++){
    flag=0;
    if(scanf("%s",va)==EOF)break;
    lconv(va);
    for(j=0;j<i;j++){
      if(strcmp(array[j],va)==0){
        printf("entered same!\n");
        cnt[j]++;
        flag=1;
        i -= 1;
      }
    }
    if(flag==0){
      array[i]=(char *)malloc(strlen(va)*sizeof(char));
      strcpy(array[i],va);
      cnt[i]++;
    }
  }
  printf("\n");
  for(j=0;j<i;j++){
    printf("%d: %s [%d](%d)\n",j,array[j],strlen(array[j]),cnt[j]);
    free(array[j]);
  }

  return 0;
}

void lconv(char *s){
  int i,j;

  //printf("Entered function!\n");
  for(i=0;s[i]!='\0';i++){
    s[i]=tolower(s[i]);
    if(s[i]==',' || s[i]=='.'){
     s[i]='\0';
     break;
    }
  }
}

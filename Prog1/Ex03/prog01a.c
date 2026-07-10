#include <stdio.h>
#include <stdlib.h>

int main(){
  char c;
  int count = 0;
  int lcount = 0;

  FILE *fpin, *fpout;

  if((fpin = fopen("input1.txt","r"))==NULL ){
    fprintf(stderr,"Failed to open: input1.txt\n");
    exit(1);
  }

  if((fpout = fopen("output1.txt","w"))==NULL){
    fprintf(stderr,"Failed to open: output1.txt\n");
    fclose(fpin);
    exit(2);
  } 

  while((c=fgetc(fpin))!=EOF){
    printf("%c", c);
    fprintf(fpout,"%c",c);
    count++;
    if(c == '\n')lcount++;
  }

  fprintf(stderr, "%d characters (%d lines) are read and copied.\n", count, lcount);

  fclose(fpin);
  fclose(fpout);

  return 0;
}

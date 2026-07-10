#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
  char c;

  FILE *fpin, *fpout;

  if((fpin = fopen("input1.txt","r"))==NULL ){
    fprintf(stderr,"Failed to open: input1.txt\n");
    exit(1);
  }

  if((fpout = fopen("output1b.txt","w"))==NULL){
    fprintf(stderr,"Failed to open: output1.txt\n");
    fclose(fpin);
    exit(2);
  } 

  while((c=fgetc(fpin))!=EOF){
    printf("%c", c);
    fprintf(fpout,"%c",c);
  }
  fclose(fpin);
  fputc('\n',fpout);
  fpin = fopen("input1.txt","r");

  while((c=fgetc(fpin))!=EOF){
    printf("%c", toupper(c));
    fprintf(fpout,"%c",toupper(c));
  }

  fclose(fpin);
  fclose(fpout);
  
  return 0;
}

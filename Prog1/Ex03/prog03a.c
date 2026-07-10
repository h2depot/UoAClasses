#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
  char buf[1000];
  int i=0,n;
  char c;
  FILE *fpin,*fpout;

  fpin = fopen("input1.txt","r");
  fpout = fopen("output3.txt","w");
  while(1){
    if((c=fgetc(fpin))==EOF)break;
    buf[i] = c;
    i++;
  }
  fclose(fpin);

  for(n=0;n<i;n++){
    fprintf(fpout,"%c",buf[n]);
  }    
  fputc('\n',fpout);
  for(n=0;n<i;n++){
    fprintf(fpout,"%c",tolower(buf[n]));
  }
  for(n=i-1;n>=0;n--){
    fprintf(fpout,"%c",buf[n]);
  }
  fputc('\n',fpout);
  fclose(fpout);  
  return 0; 
}
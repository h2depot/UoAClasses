#include <stdio.h>
#include <stdlib.h>

int main(){
  int count=0;
  int status1,status2;
  int flag=0;
  char c1,c2; 
  FILE *fp1,*fp2;

  fp1 = fopen("output3.txt","r");
  fp2 = fopen("output3_sample.txt","r");

  while(1){
    status1 = fscanf(fp1,"%c",&c1); 
    status2 = fscanf(fp2,"%c",&c2);
    if(status1==EOF && status2==EOF)break;
    count++;
    if(c1==c2){
    continue;
    }else {
     printf("Two files are different at %d byte.\n",count);
     flag=1;
     break;
    }
  }

  if(flag==0)printf("Two files are identical.\n");

  fclose(fp1);
  fclose(fp2);

  return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
  int num,max = 0,min=INT_MAX,sum=0,count=0;
  double ave;
  FILE *fpin,*fpout;
  
  fpin = fopen("input2.txt","r");

  
  while(1){

  if(fscanf(fpin,"%d",&num) == EOF) break;
  count++;
  if(num>=max)max=num;
  else if(num<=min)min=num;
  sum += num;

  }
  fclose(fpin);
  fpout = fopen("result2.txt","w");
  ave = (double)sum/count;  
  fprintf(fpout,"max = %d, min = %d, average = %f\n",max,min,ave);
  fclose(fpout);

  return 0;
}
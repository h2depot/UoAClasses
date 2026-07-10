#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBJECT_NUM 5 
     
typedef struct{
    char id[10];          
    char name[10];         
	int score[SUBJECT_NUM]; 
	int sum;                
	double ave;            
	char grade;             
}Record;

char grade(Record);
void result(Record);

int main(int argc, char *argv[]){
  Record record[20];
  FILE *fp;
  int i,j;
  int status,count=0,flag;
  char input[10];

  if(argc != 2){
	printf("Error! Usage: ./a.out datafilename\n");
	exit(1);
  }

  fp = fopen(argv[1],"r");
  if(fp == NULL){
	printf("Cannot open data file !\n");
	exit(2);
  }


  for(i=0;;i++){
   //printf("entered fori!\n");
   record[i].sum = 0;
   status = fscanf(fp,"%s",&record[i].id);
   if(status == EOF)break;
   //printf("entered fscanf!\n");
   fscanf(fp,"%s",&record[i].name);
   for(j=0;j<SUBJECT_NUM;j++){
	fscanf(fp,"%d",&record[i].score[j]);
	record[i].sum += record[i].score[j];
	count++;
   }
   //printf("get out from forj!\n");
   record[i].ave = (double)record[i].sum/SUBJECT_NUM;
   record[i].grade = grade(record[i]);
  //printf("get out from function grade!\n");
   result(record[i]);
   //printf("get out from function result!\n");
  }
  fclose(fp);

  while(1){
	flag=0;
	printf("Input a student name/ID: ");
	status = scanf("%s",&input);
	if(status == EOF)break;
    if(input[0]>='0' && input[0]<='9'){
      for(i=0;i<count;i++){
		if(strcmp(input,record[i].id)==0){
			result(record[i]);
			flag=1;
		}
	  }
	}else if((input[0]>='a'&&input[0]<='z') || (input[0]>='A'&&input[0]<'Z')){
      for(i=0;i<count;i++){
		if(strcmp(input,record[i].name)==0){
			result(record[i]);
			flag=1;
		}
	  }
	}else{
		printf("You put wrong character!\n");
		continue;
	}

	if(flag==0){
		printf("This student does not exist!\n");
		continue;
	}
  }

  return 0;
}

char grade(Record record){
	if(record.ave < 35){
		return 'F';
	}else if(record.ave >=35 && record.ave < 50){
		return 'D';
	}else if(record.ave >= 50 && record.ave < 65){
		return 'C';
	}else if(record.ave >= 65 && record.ave < 80){
		return 'B';
	}else if(record.ave >= 80){
		return 'A';
	}
}

void result(Record record){
  int j;
   //printf("entered function result!\n");
  printf("%s %-11s ",record.id,record.name);
  for(j=0;j<SUBJECT_NUM;j++){
	printf("%3d ",record.score[j]);
  }
  printf("%3d %5.1f %c\n",record.sum,record.ave,record.grade);
}
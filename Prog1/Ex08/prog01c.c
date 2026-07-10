#include <stdio.h>

#define N 20

    typedef struct{
    	int id;           /* ID */
    	char name[12];    /* 名前 */
    	int year;        /* 学年 */
    	char subject[12]; /* 科目名 */
    	char grade;      /* 成績 */
    }StudentInfo;

void PrintInfo(StudentInfo);
void PrintInfoPtr(StudentInfo *);
int InputInfo(StudentInfo *);

int main(){
    int i,j;
    StudentInfo studentdata[N];

    for(i=0;;i++){
        if(InputInfo(&studentdata[i])==EOF)break;
    }

    printf("構造体の値渡し (PrintInfo)\n");
    for(j=0;j<i;j++){
    PrintInfo(studentdata[j]);
    }
    printf("構造体のアドレス値渡し (PrintInfoPtr)\n");
    for(j=0;j<i;j++){
    PrintInfoPtr(&studentdata[j]);
    }

    return 0;
}

void PrintInfo(StudentInfo student){
  printf("%d %12s %d %12s %c\n",student.id,student.name,student.year,student.subject,student.grade);
}

void PrintInfoPtr(StudentInfo *studentp){
  printf("%d %12s %d %12s %c\n",studentp->id,studentp->name,studentp->year,studentp->subject,studentp->grade);
}

int InputInfo(StudentInfo *studentp){
  int status;
  status = scanf("%d",&studentp->id);
  if(status == EOF)return status;
  scanf("%s",studentp->name);
  scanf("%d",&studentp->year);
  scanf("%s",studentp->subject);
  scanf(" %c",&studentp->grade);
  //printf("function moved\n");

}
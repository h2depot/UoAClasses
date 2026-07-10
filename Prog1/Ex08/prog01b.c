#include <stdio.h>

    typedef struct{
    	int id;           /* ID */
    	char name[12];    /* 名前 */
    	int year;        /* 学年 */
    	char subject[12]; /* 科目名 */
    	char grade;      /* 成績 */
    }StudentInfo;

void PrintInfo(StudentInfo);
void PrintInfoPtr(StudentInfo *);

int main(){
    StudentInfo studentdata[2] = {
        {1319991,
        "Fukushima",
        3,
        "Literacy",
        'B'},
        {1319992,
        "Wakamatsu",
        2,
        "Programming",
        'A'}
    };
    printf("構造体の値渡し (PrintInfo)\n");
    PrintInfo(studentdata[0]);
    PrintInfo(studentdata[1]);
    printf("構造体のアドレス値渡し (PrintInfoPtr)\n");
    PrintInfoPtr(&studentdata[0]);
    PrintInfoPtr(&studentdata[1]);

    return 0;
}

void PrintInfo(StudentInfo student){
  printf("%d %s %d %s %c\n",student.id,student.name,student.year,student.subject,student.grade);
}

void PrintInfoPtr(StudentInfo *studentp){
  printf("%d %s %d %s %c\n",studentp->id,studentp->name,studentp->year,studentp->subject,studentp->grade);
}
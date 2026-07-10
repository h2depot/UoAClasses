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
    StudentInfo student1 = {
        1319991,
        "Fukushima",
        3,
        "Literacy",
        'B'
    };
    StudentInfo student2 = {
        1319992,
        "Wakamatsu",
        2,
        "Programming",
        'A'
    };
    printf("構造体の値渡し (PrintInfo)\n");
    PrintInfo(student1);
    PrintInfo(student2);
    printf("構造体のアドレス値渡し (PrintInfoPtr)\n");
    PrintInfoPtr(&student1);
    PrintInfoPtr(&student2);

    return 0;
}

void PrintInfo(StudentInfo student){
  printf("%d %s %d %s %c\n",student.id,student.name,student.year,student.subject,student.grade);
}

void PrintInfoPtr(StudentInfo *studentp){
  printf("%d %s %d %s %c\n",studentp->id,studentp->name,studentp->year,studentp->subject,studentp->grade);
}
#include <stdio.h>

#define MAX_ST_NUM 50                 
#define MAX_SCORE 120                  
int student_id[MAX_ST_NUM];            
int abs_score[MAX_ST_NUM];              
char abs_grade[MAX_ST_NUM];           
int rel_score[MAX_ST_NUM];              
char rel_grade[MAX_ST_NUM];            
int grade_dist[2][5];                 
char cgrade[5]={'F','D','C','B','A'};   
int num_student;                        
double abs_ave=0.0;                     
double rel_ave=0.0;

int calib(int);

int main(){
  int i=0;
  int n;
  int abs_sum=0,rel_sum=0;
  
  while(1){   
    if(scanf("%d",&student_id[i])==EOF)break;
    scanf("%d",&abs_score[i]);
    i++;
  }

  num_student = i;

  for(n=0;n<num_student;n++){
    rel_score[n]= calib(abs_score[n]);
  }


  for(n=0;n<num_student;n++){
    abs_sum+=abs_score[n];
    rel_sum+=rel_score[n];
    
    if(abs_score[n]>=0 && abs_score[n]<=34){
      abs_grade[n] ='F';
      grade_dist[0][4]++;
    }
    else if(abs_score[n]>=35 && abs_score[n]<=49){
      abs_grade[n] ='D';
      grade_dist[0][3]++;
    }
    else if(abs_score[n]>=50 && abs_score[n]<=64){
      abs_grade[n] ='C';
      grade_dist[0][2]++;
    }
    else if(abs_score[n]>=65 && abs_score[n]<=79){
      abs_grade[n] ='B';
      grade_dist[0][1]++;
    }
    else if(abs_score[n]>=80){
      abs_grade[n] ='A';
       grade_dist[0][0]++;
    }

    
    if(rel_score[n]>=0 && rel_score[n]<=34){
      rel_grade[n] ='F';
      grade_dist[1][4]++;
    }
    else if(rel_score[n]>=35 && rel_score[n]<=49){
      rel_grade[n] ='D';
      grade_dist[1][3]++;
    }
    else if(rel_score[n]>=50 && rel_score[n]<=64){
      rel_grade[n] ='C';
      grade_dist[1][2]++;
    }
    else if(rel_score[n]>=65 && rel_score[n]<=79){
      rel_grade[n] ='B';
      grade_dist[1][1]++;
    }
    else if(rel_score[n]>=80 && rel_score[n]<=100){
      rel_grade[n] ='A';
      grade_dist[1][0]++;
    }
  }

  abs_ave=(double)abs_sum/num_student;
  rel_ave=(double)rel_sum/num_student;

  printf("ID   点数 評価 点数 評価\n");
  printf("     (補正前)  (補正後)\n");
  printf("-------------------------\n");
  for(n=0;n<num_student;n++)printf("%d %3d %c %3d %c\n",student_id[n],abs_score[n],abs_grade[n],rel_score[n],rel_grade[n]);
  printf("-------------------------\n");
  printf("統計\n学生数 %d人 補正前平均点 %.1f 補正後平均点 %.1f\n",num_student,abs_ave,rel_ave);
  printf("評価分布\n");
  printf("補正前");
  for(n=0;n<5;n++)printf(" %c %d",cgrade[4-n],grade_dist[0][n]);
  printf("\n");
  printf("補正後");
  for(n=0;n<5;n++)printf(" %c %d",cgrade[4-n],grade_dist[1][n]);
  printf("\n");

  return 0;
}

int calib(int score){
  int newscore;
  double dscore;

  dscore = (double)score / 120 *100;

  newscore = dscore + 0.5;

  return newscore;
}

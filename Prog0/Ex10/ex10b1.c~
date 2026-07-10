#include <stdio.h>
#include <stdlib.h>
#define STN 20
#define SUB 9

int main()
{
  int i, j, mat[STN][SUB], sub,stn, sum = 0,data,sum2 = 0;
  int data1,data2,result;

  sub = scanf("%d", &data1);

  stn = scanf("%d", &data2);


  for (i=0; i<data2; i++){
    for (j=0; j<data1; j++){
    result = scanf("%d", &mat[i][j]);
    if(result == EOF) break;
    if(result != 1) exit(1);
    }
  }

  printf("科目数:%d,  学生数:%d\n", data1,data2);

  for (i=0; i<data2; i++){
    sum = 0;
    for (j=0; j<data1; j++){
      printf("%d   ", mat[i][j]);
      sum += mat[i][j];
    }
    printf(" :%4.1f\n", (double)sum/data1);
  }

    for (i=0; i<data1; i++){
      sum2=0;
    for (j=0; j<data2; j++){
      sum2 += mat[j][i];
    }
    printf("%4.1f ", (double)sum2/data2);

  }
    
  return 0;
}

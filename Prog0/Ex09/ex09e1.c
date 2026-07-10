#include <stdio.h>
#define NUM 3

int main()
{
  int map[NUM][NUM];
  int i, j, m, n;
  int flag = 0, subflag = 0;
  int countx, county, countz;
  int countx2, county2, countz2;
  int counth;

  for (i=0 ; i<NUM ; i++)
    for (j=0 ; j<NUM ; j++)
      map[i][j] = 0;

  while(1){

    for (i=0 ; i<NUM ; i++){
      for (j=0 ; j<NUM ; j++){
	if (map[i][j]==1) printf("(%d %d) ⚪︎", i, j);
	else if (map[i][j]==-1) printf("(%d %d) × ", i, j);
	else printf("(%d %d)     ", i, j);
      }
      printf("\n");
    }

    if (flag==0) {
      printf("⚪の番です\n座標を行・列の順で入力してください：");
      scanf("%d%d", &m, &n);
      if (m >= 0 && m <= 2 && n >= 0 && n <= 2 && map[m][n] != -1 && map[m][n]!= 1){
      map[m][n] = 1;
      flag = 1;
      subflag = 0;
      }else if (map [m][n] == 1 || map[m][n] == -1){
	subflag = 1;
	printf("そこには打てません！\n");
      }else if (m < 0 || m> 2){
	subflag = 1;
	printf("盤の範囲外です。\n");
      }

      while (subflag == 1){
	printf("もう一度入力してください：");
	
	scanf("%d%d", &m, &n);
        if (m >= 0 && m <= 2 && n >= 0 && n <= 2 && map[m][n] != -1 && map[m][n]!= 1){
        map[m][n] = 1;
        flag = 1;
	subflag = 0;
        }
      }
    }else{
      printf("×の番です\n座標を行・列の順で入力してください：");
      scanf("%d%d", &m, &n);
      if (m >= 0 && m <= 2 && n >= 0 && n <= 2 && map[m][n] != 1 && map[m][n]!= -1){
      map[m][n] = -1;
      flag = 0;
      subflag = 0;
      }else if (map [m][n] == 1|| map[m][n] == -1){
	subflag = 1;
	printf("そこには打てません！\n");
      }else if (m < 0 || m> 2){
	subflag = 1;
	printf("盤の範囲外です。\n");
      }

      while(subflag == 1){
	printf("もう一度入力してください：");
	
	scanf("%d%d", &m, &n);
        if (m >= 0 && m <= 2 && n >= 0 && n <= 2 && map[m][n] != 1 && map[m][n]!= -1){
        map[m][n] = -1;
        flag = 0;
	subflag = 0;
        }
    }

      counth = 0;

      for (i=0;i<NUM;i++){
	countx = 0;
	county = 0;
	countz = 0;
	countx2 = 0;
	county2 = 0;
	countz2 = 0;
	if (map[i][i] == -1) countz2++;	
	if (map[i][i] == 1) countz++;
	for(j=0;j<NUM;j++){
	  if (map[i][j] == 1) countx++;
	  if (map[j][i] == 1) county++;
	  if (map[i][j] == -1) countx2++;
	  if (map[j][i] == -1) county2++;
	  if (map[i][j] == 1 || map [i][j] == -1)counth++;
	  
        if (countx == 3 || county == 3 || countz == 3 ){
	printf("⚪の勝ち！\n");
	break;
      }else if (map[0][2] ==1 && map[1][1]==1 && map[2][0]==1){
	printf("⚪の勝ち！\n");
	break;       
      }

      if (countx2 == 3 || county2 == 3 || countz2 == 3 ){
	printf("×の勝ち！\n");
	break;
      }else if (map[0][2] ==1 && map[1][1]==1 && map[2][0]==1){
	printf("×の勝ち！\n");
	break;	
      }

      if (counth == 9){
	printf("引き分け！\n");
	break;
      }
      
	}
      }


     
  }
  }

  return 0;
}

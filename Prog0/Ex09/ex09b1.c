#include <stdio.h>

int main()
{
  int array[4][3]={1,3,5,2,4,6,7,9,11,8,10,12};
  int key, num;
  int i, j;

  printf("行要素と列要素どちらを表示したいか選択してください\n（行要素:0, 列要素:1）");
  scanf("%d", &key);



  if (key == 0){

  printf("表示したい列番号を入力してください : ");
  scanf("%d", &num);
    
    if (num >=0 && num <= 3){
    for(j=0;j<3;j++){
      printf("%2d ", array[num][j]);
    }
    printf("\n");
    }else{
      printf("行の範囲外です\n");
    }
  }
  else if (key == 1){

  printf("表示したい列番号を入力してください : ");
  scanf("%d", &num);
    
    if (num >= 0 &&num <= 2){
    for(j=0;j<4;j++){
      printf("%2d\n", array[j][num]);      
    }
    }else{
      printf("列の範囲外です\n");
    }
  }else{
    for(i=0;i<4;i++){
      for(j=0;j<3;j++){
	printf("%2d ", array[i][j]);
	  }
      printf("\n");
    }
  }

  return 0;

}

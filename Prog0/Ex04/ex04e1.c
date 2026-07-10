#include <stdio.h>

int main()

{
  int size, dest;

  printf("サイズを入力してください( 小…1, 中…2, 大…3 )  ");
  scanf("%d", &size);
  printf("行き先を入力してください( 福島県内…1, 宮城県…2, 山形県…3, 岩手県…4, 秋田県…5, 青森県…6 )  ");
  scanf("%d", &dest);

  switch(size){
  case 1:
    {
      switch(dest){
      case 1:
	printf("運賃は800円です\n");
	break;
	
      case 2:
      case 3:
	printf("運賃は1000円です\n");
	break;
	
      case 4:
	printf("運賃は1200円です\n");
	break;
	
      case 5:
	printf("運賃は1400円です\n");
	break;
	
      case 6:
	printf("運賃は1600円です\n");
	break;
	
      default:
	printf("地域の番号が不正です\n");
      }
      break;
    }

  case 2:
    {
      switch(dest){
      case 1:
	printf("運賃は1000円です\n");
	break;
	
      case 2:
      case 3:
	printf("運賃は1200円です\n");
	break;
	
      case 4:
	printf("運賃は1400円です\n");
	break;
	
      case 5:
	printf("運賃は1600円です\n");
	break;
	
      case 6:
	printf("運賃は1800円です\n");
	break;
	
      default:
	printf("地域の番号が不正です\n");
      }
      break;
    }

  case 3:
    {
      switch(dest){
      case 1:
	printf("運賃は1200円です\n");
	break;
	
      case 2:
      case 3:
	printf("運賃は1400円です\n");
	break;
	
      case 4:
	printf("運賃は1600円です\n");
	break;
	
      case 5:
	printf("運賃は1800円です\n");
	break;
	
      case 6:
	printf("運賃は2000円です\n");
	break;
	
      default:
	printf("地域の番号が不正です\n");
      }
      break;
    }

  default:
    printf("サイズの番号が不正です\n");
  }
  return 0;
}

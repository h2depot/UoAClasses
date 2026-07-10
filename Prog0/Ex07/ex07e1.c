#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i;
  int score[240];
  int hist[11];

  srand((unsigned int)time(NULL));

  for ( i = 0 ; i < 240 ; i++ )
    {
      score[i] = rand() % (100 + 1);
    }

  for ( i = 0 ; i < 240 ; i++ )
    {
      if (score[i] >= 0 && score[i] <= 9) hist[0]++;
      else if (score[i] >= 10 && score[i] <= 19) hist[1]++;
      else if (score[i] >= 20 && score[i] <= 29) hist[2]++;
      else if (score[i] >= 30 && score[i] <= 39) hist[3]++;
      else if (score[i] >= 40 && score[i] <= 49) hist[4]++;      
      else if (score[i] >= 50 && score[i] <= 59) hist[5]++;
      else if (score[i] >= 60 && score[i] <= 69) hist[6]++;
      else if (score[i] >= 70 && score[i] <= 79) hist[7]++;
      else if (score[i] >= 80 && score[i] <= 89) hist[8]++;
      else if (score[i] >= 90 && score[i] <= 99) hist[9]++;
      else hist[10]++;
    }
  
  for ( i = 0 ; i < 11 ; i++ )
    {
      if ( i < 10) printf("%d点から%d点の人は%d人です\n", i * 10, i *10 + 9, hist[i]);
      else printf("100点の人は%d人です\n", hist[i]);
    }
  
  return 0;
  
}

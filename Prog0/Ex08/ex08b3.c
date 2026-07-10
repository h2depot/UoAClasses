#include <stdio.h>

int main()
{
  int i;
  int event[10] = {1602,1395,987,1215,1591,2000,645,1776,1415,1333};

  for (i = 0;i < 10;i++)
    {
      if (1185 <= event[i] && event[i] <= 1333)printf("%d年は鎌倉時代です\n",event[i]);
      else if (1336 <= event[i] && event[i] <= 1573)printf("%d年は室町時代です\n",event[i]);
      else if (1576 <= event[i] && event[i] <= 1600)printf("%d年は安土桃山時代です\n",event[i]);
      else if (1603 <= event[i] && event[i] <= 1868)printf("%d年は江戸時代です\n",event[i]);
      else printf("%d年は4つの時代以外です\n",event[i]);
    }

  return 0;
}

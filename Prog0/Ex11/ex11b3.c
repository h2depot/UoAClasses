#include<stdio.h>

int sectime(int,int,int);

int main()
{
  int a,b,c,d;
  int x,y,z,w;
  int resec;
  int t1,t2,t3;

  printf("時刻1の時・分・秒を整数値で入力してください : ");
  scanf("%d%d%d", &a,&b, &c);

    printf("時刻2の時・分・秒を整数値で入力してください : ");
  scanf("%d%d%d", &x,&y, &z);

  d = sectime(a,b,c);
  w = sectime(x,y,z);

  printf("時刻1は0時0分0秒から数えて %d 秒\n", d);
  printf("時刻1は0時0分0秒から数えて %d 秒\n", w);

  resec = w - d;

  t1 = resec/3600;
  t2 = resec%3600/60;
  t3 = resec%3600%60;

  printf("時刻1と時刻2の時間差は%d時間%d分%d秒です\n",t1,t2,t3);

  return 0;
}

int sectime(int a1,int b1,int c1)
{
  int n;

  n = 3600*a1+60*b1+c1;

  return n;
}

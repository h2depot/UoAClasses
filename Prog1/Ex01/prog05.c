#include <stdio.h>

int main(){
  int n;
  int size;
  char a;
  short b;
  int c;
  long d;
  float e;
  double f;
  char g[10];
  short h[10];
  int z[10];
  long j[10];
  float k[10];
  double l[10];

  printf("sizeof(  char) : %d\n", sizeof(a));
  printf("sizeof( short) : %d\n", sizeof(b));
  printf("sizeof(   int) : %d\n", sizeof(c));
  printf("sizeof(  long) : %d\n", sizeof(d));
  printf("sizeof( float) : %d\n", sizeof(e));
  printf("sizeof(double) : %d\n", sizeof(f));
  
  size = 0;
  for (n=0;n<10;n++)size += sizeof(g[n]);
  printf("sizeof(  char[10]) : %d\n",size);

  size = 0;
  for (n=0;n<10;n++)size += sizeof(h[n]);
  printf("sizeof( short[10]) : %d\n",size);

  size = 0;
  for (n=0;n<10;n++)size += sizeof(z[n]);
  printf("sizeof(   int[10]) : %d\n",size);

  size = 0;
  for (n=0;n<10;n++)size += sizeof(j[n]);
  printf("sizeof(  long[10]) : %d\n",size);

  size = 0;
  for (n=0;n<10;n++)size += sizeof(k[n]);
  printf("sizeof( float[10]) : %d\n",size);

  size = 0;
  for (n=0;n<10;n++)size += sizeof(l[n]);
  printf("sizeof(double[10]) : %d\n",size);
  return 0;
}

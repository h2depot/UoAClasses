#include <stdio.h>
#define EPS 1.0e-6

double f(double,double);
double df(double);

int main()
{
  double a,x,fx,dfx;

  a = 2;
  x = a;
  printf("x(k-1)\t\tfx\t\tdfx\t\tx(k)\t\tf(x,%f)\n",a);
  while ((fx = f(x,a)) > EPS){
    dfx = df(x);
    printf("%f\t%f\t%f", x, fx, dfx);
    x = x - fx/dfx;
    printf("\t%f\t%12.10f\n", x, f(x,a));
  }
  printf("sqrt(%f) : %12.10f\n", a, x);

  return 0;
}

double f(double x, double a)
{
  double fx;
  fx = x*x - a;
  return fx;
}

double df(double x)
{
  double dfx;
  dfx = 2.0*x;
  return dfx;
}

#include <cstdio>
#include <cmath>

#ifndef MINERR
#define MINERR 1E-6
#endif

typedef double (* vFunctionCall)(double x);

double secante(vFunctionCall fun, double x0, double x1) {
  double x2;
  do {
    x2=(x1-((x0-x1)/(fun(x0)-fun(x1))*fun(x1)));
    x0=x1;
    x1=x2;
  } while ( fabs (x1-x2) > MINERR );

  return x2;
}

double f(double x) {
  return exp(-x) - x;
}

double f2(double x) {
  return log(x);
}

int main(int argc, char const *argv[]) {
  fprintf(stderr, "%f\n", secante(f2, 5, 0.5));
  return 0;
}

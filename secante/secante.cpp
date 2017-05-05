#include <cstdio>
#include <cmath>

#ifndef MINERR
#define MINERR 0.001
#endif

typedef double (* vFunctionCall)(double x);

double secante(vFunctionCall fun, double x1, double x2) {
  double x0;
  int i = 0;
  do {
    x0=x1;
    x1=x2;
    x2 = x1 - (fun(x1) * (x0 - x1)) / (fun(x0) - fun(x1));
    i++;
    fprintf(stderr, "========== Iteracion: %d ==========\n", i);
    fprintf(stderr, "x_%d: %f\n", i+1, x2);
    fprintf(stderr, "f(x_%d): %f\n", i+1, fun(x2));
    fprintf(stderr, "Error: %f\n", fabs(x1 - x2));
  } while ( fabs (x1-x2) > MINERR );

  fprintf(stderr, "=====================================\nIteraciones: %d\n", i);
  fprintf(stderr, "Error: %f\n", fabs(x1 - x2));
  return x2;
}

double f(double x) {
  return x * log10(x) - 10;
}

int main(int argc, char const *argv[]) {
  fprintf(stderr, "%f\n", secante(f, 8, 9));
  return 0;
}

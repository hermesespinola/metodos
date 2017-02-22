#include <cstdio>
#include <cmath>
#include <iostream>

typedef double (* vFunctionCall)(double x);

// a - array of coeficients
// d - degree of the polynomial function
// r -
// s -
double bairstow(vFunctionCall fun, double *a, int d, double r, double s) {
  double dn, dr, ds, drn, dsn, eps;
  int iter;
  double *b = (double *) malloc(d * sizeof(double));
  double *c = (double *) malloc(d * sizeof(double));
  r = s = 0;
  dr = 1;
  ds = 0;
  eps = 1e-14;
  iter = 1;

  while ((abs(dr) + fabs(ds) > eps)) {
    b[1] = a[1] - r;
    c[1] = b[1] - r;

    for (int i = 2; i <= d; i++) {
      b[i] = a[i] - r * b[i - 1] - s * b[i - 2];
      c[i] = b[i] - r * c[i - 1] - s * c[i - 2];
    }

    dn=c[d-1] * c[d-3] - c[d-2] * c[d-2];
    drn = b[d] * c[d-3] - b[d-1] * c[d-2];
		dsn = b[d-1] * c[d-1] - b[d] * c[d-2];

    if (abs(dn) < 1e-16) {
      dn = drn = dsn = 1;
    }

    dr = drn / dn;
    ds = dsn / dn;

    r += dr;
    s += ds;
    iter++;
  }
  for (int i = 0; i < d - 1; i++) {
    a[i] = b[i];
  }

  a[d] = s;
  a[d - 1] = r;
  return 0;
}

double pol(double x, double *c, int degree) {
  double result;
  for (int i = 0; i < degree; i++) {
    result += c[i] * pow(x, degree - i);
  }
  return result + c[degree - 1];
}

int main(int argc, char const *argv[]) {
  int length = 5;
  double *c = new double[length] {1,2,3,4,5};
  std::cout << pol(2, c, 5) << '\n';
}

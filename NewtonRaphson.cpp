#include <iostream>
#include <cmath>

#define ITER 1000
#define MINERR 1E-15

using namespace std;

typedef double (* vFunctionCall)(double x);

double newtonRaphson(vFunctionCall fun, vFunctionCall der, double x0) {
  if (der(x0) == 0) {
    throw invalid_argument("Math Error");
  }

  double y = fun(x0);
  int i = 0;

  while (abs(y) > MINERR) {
    x0 = x0 - (y / der(x0));

    y = fun(x0);
    if (i > ITER) {
      return x0;
    }

    i++;
  }

  return x0;
}

double f(double x) {
  return pow(x, 3) + 5 * x - 10;
}

double df(double x) {
  return 3 * pow(x, 2) + 5;
}

int main() {
  cout << newtonRaphson(f, df, 1000000000000000) << endl;
  return 0;
}

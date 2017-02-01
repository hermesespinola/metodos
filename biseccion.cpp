#include <iostream>
#include <cmath>

#define ITER 1000
#define MINERR 1E-15

using namespace std;

typedef double (* vFunctionCall)(double x);

bool sameSign(double x, double y) {
  return (x <= 0 && y <= 0) || (x >= 0 && y >= 0);
}

double biseccion(vFunctionCall fun, double x0, double x1) {
  double y0 = fun(x0);
  double y1 = fun(x1);

  if (y0 == 0) {
    return x0;
  } else if (y1 == 0) {
    return x1;
  }

  if (sameSign(y0, y1)) {
    throw invalid_argument("received f(x0) and f(x1) of same sign");
  }

  int i = 0;
  double x, y;
  while (i < ITER) {
    x = (x0 + x1) / 2;
    y = fun(x);

    if (abs(y) <= MINERR) {
      return x;
    }

    if (sameSign(y, y0)) {
      // go left
      x0 = x;
      y0 = y;
    } else {
      // go right
      x1 = x;
      y1 = y;
    }
    i++;
  }

  return x;
}

double someFun(double x) {
  return sin(x) + 2*x - 1;
}

double moreFun(double x) {
  return x * x * x - 6 * x * x + 3 * x + 10;
}

double fun(double x) {
  return pow(x, 4) - 2 * pow(x, 3) - 3 * pow(x, 2) + 4 * x + 4;
}

int main() {
  // cout << biseccion((vFunctionCall)fun, -10, 10) << endl;
  cout << biseccion((vFunctionCall)someFun, -10, 10) << endl;
  cout << biseccion((vFunctionCall)moreFun, -2, 6) << endl;
  return 0;
}

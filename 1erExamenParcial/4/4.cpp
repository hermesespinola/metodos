#include <iostream>
#include <cmath>

#define ITER 1000
#define MINERR 1E-3

using namespace std;

typedef double (* vFunctionCall)(double x);

bool sameSign(double x, double y) {
  return x * y >= 0;
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
      break;
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

  cout << "Error absoluto: " << abs(y) << endl;
  cout << "# iteraciones: " << i << endl;
  return x;
}

double fun(double x) {
  double pi = 3.1415926535897;
  return log(pow(x, 2) + 1) - exp(x / 2) * cos(pi * x);
}

int main() {
  cout << "Raíz encontrada con bisección en x = [0, 1]: " << biseccion(fun, 0, 1) << endl << endl;
  cout << "Raíz encontrada con bisección en x = [0, 3]: " << biseccion(fun, 0, 3) << endl << endl;
  cout << "Raíz encontrada con bisección en x = [0, 4]: " << biseccion(fun, 0, 4) << endl;
  return 0;
}

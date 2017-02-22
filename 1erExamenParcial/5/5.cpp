#include <iostream>
#include <cmath>

#define MINERR 0.00001

using namespace std;

typedef double (* vFunctionCall)(double x);

double newtonRaphson(vFunctionCall fun, vFunctionCall der, double x) {
  int i = 0;
  double x1, y, dy, err;

  do {
    x1 = x;               // make x equal to the last calculated value.
    y = fun(x1);         //  evaluate the function.
    dy = der(x1);       //   evaluate the derivative of the function.
    x = x1 - (y / dy); //    calculate the next guess from x, y and dy.
    err = abs(x-x1);  //     calcular el error absoluto iterativo
    i++;
  } while(err >= MINERR);  // if |x_(i+1)-x_(i)| remains greater than the desired accuracy, continue the loop

  cout << "error absoluto iterativo: " << err << endl;
  cout << "# iteraciones: " << i << endl;
  return x1;
}

double f(double x) {
  return cos(3 * x) - x;
}

double df(double x) {
  return - (3 * sin(3 * x)) - 1;
}

int main() {
  cout << "Raíz con x0 = 1: " << newtonRaphson(f, df, 0) << endl << endl;
  cout << "Raíz con x0 = 0.9: " << newtonRaphson(f, df, 0.9) << endl << endl;
  cout << "Raíz con x0 = -1: " << newtonRaphson(f, df, -1) << endl << endl;
  cout << "Raíz con x0 = -4: " << newtonRaphson(f, df, -4) << endl;
  return 0;
}

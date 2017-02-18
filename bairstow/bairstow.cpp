#include <cstdio>
#include <cmath>
#include <iostream>

typedef double (* vFunctionCall)(double x);

double bairstow(vFunctionCall fun, double *c) {
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

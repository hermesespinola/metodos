#include <iostream>
#include <cmath>

using namespace std;

void lineal(){
  double x1, x2, y1, y2, x, y;
  cout << "x1: ";
  cin >> x1;
  cout << "y1: ";
  cin >> y1;
  cout << "x2: ";
  cin >> x2;
  cout << "y2: ";
  cin >> y2;
  cout << "x: ";
  cin >> x;
  y = y1 + (y2 - y1)/(x2 - x1) * (x - x1);
  cout << "Approximated value of y = " << y << endl;
}

double f(double x){
  return log(x);
}

void evaluar(double a0, double a1, double a2, double x){
  double y, err_r, err_abs, err_p;
  y = a0 + a1*x + a2*x*x;
  cout << "f("<< x << ") = " << y << endl;
  err_abs = abs(f(x) - y);
  err_r = err_abs / f(x);
  err_p = err_r * 100;
  cout << "Error absoluto = " << err_abs << endl;
  cout << "Error relativo = " << err_r << endl;
  cout << "Error porcentual = " << err_p << "%" << endl;
}

void cuadratica(){
  double x0 = 1, x1 = 4, x2 = 6;
  double y0 = 0, y1 = 1.386294, y2 = 1.791759;
  double b0, b1, b2;
  double a0, a1, a2;
  b0 = y0;
  b1 = (y1 - y0) / (x1 - x0);
  b2 = ((y2 - y1) / (x2 - x1) - (y1 - y0) / (x1 - x0))/ (x2 - x0);
  cout << "b2 = " << b2 << ", b1 = " << b1 << ", b0 = " << b0 << endl;
  a2 = b2;
  a1 = b1 - b2*x0 - b2*x1;
  a0 = b0 - b1*x0 + b2*x0*x1;
  cout << endl << "f(x) = " << a0 << " + " << a1 << "x + " << a2 << "x^2" << endl;
  evaluar(a0,a1,a2,5);
}

int main(){
  //lineal();
  cuadratica();
  return 0;
}
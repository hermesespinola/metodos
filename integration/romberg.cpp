#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
  return exp( x );
}

double trapezoid(double a, double b, int n) {
  double h = (b - a) / n;
  double sum = 0;
  for(double i = a + h; i < b; i += h) {
    sum += 2*f(i);
  }
  sum += f(b) + f(a);
  sum *= h/2;
  cout << "Trapezoid Approximation = " << sum << endl;
  return sum;
}

double romberg_help(double a, double b, int k) {
  return ( pow(4,k)*b - a ) / ( pow(4,k) - 1 );
}

void print_array(double *a, int n) {
  cout << "[";
  for(int i = 0; i < n - 1; i++) {
    cout << a[i] << ",";
  }
  cout << a[n - 1] << "]" << endl;
}

double romberg(int no_of_approximations, double a, double b) {
  int *number = new int[no_of_approximations];
  double *approximations = new double[no_of_approximations];
  for(int i = 0; i < no_of_approximations; i++) {
    cout << "Number of Trapezoids for approximation "<< i <<" = ";
    cin >> number[i];
  }

  for(int i = 0; i < no_of_approximations; i++) {
    approximations[i] = trapezoid(a, b, number[i]);
  }

  for(int j = 1; j < no_of_approximations; j++) {
    for(int i = 0; i < no_of_approximations - j; i++) {
      approximations[i] = romberg_help(approximations[i], approximations[i+1], j);
      //print_array(approximations, no_of_approximations);
    }
  }
  cout << "Integral = " << approximations[0] << endl;
  return approximations[0];
}

int main() {
  double a, b;
  int no_of_approximations;
  cout << "Initial value (a): "; cin >> a;
  cout << "Final value (b): "; cin >> b;
  cout << "Number of Initial Approximations: "; cin >> no_of_approximations;
  romberg(no_of_approximations, a, b);
  return 0;
}
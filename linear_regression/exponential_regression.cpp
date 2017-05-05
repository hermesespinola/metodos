#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

double eval(double alpha, double beta, double x){
  return alpha*exp(beta*x);
}

double *exponential_regression(double *X, double *Y, unsigned size) {
  double x_sum, y_sum, x2_sum, logy_sum, xlogy_sum;

  for (size_t i = 0; i < size; i++) {
    x_sum += X[i];
    y_sum += Y[i];
    x2_sum += X[i] * X[i];

    logy_sum += log(Y[i]);
    xlogy_sum += X[i] * log(Y[i]);
  }

  double mu_x = x_sum / size;
  cout << "mu_x = " << mu_x << endl;
  double mu_y = y_sum / size;
  cout << "x2_sum = " << x2_sum << endl;
  cout << "mu_y = " << mu_y << endl;
  double mu_logy = logy_sum / size;
  cout << "mu_logy = " << mu_logy << endl;
  cout << "logy_sum = " << logy_sum << endl;
  cout << "xlogy_sum = " << xlogy_sum << endl;

  double a1 = (size * xlogy_sum - x_sum * logy_sum) / (size * x2_sum - x_sum * x_sum);
  cout << "a1 = " << a1 << endl;
  double a0 = (mu_logy - a1 * mu_x);
  cout << "a0 = " << a0 << endl;
  double alpha = exp(a0);
  cout << "alpha = exp(a0) = " << alpha << endl;
  double beta = a1;
  cout << "beta = a1 = " << beta << endl;

  printf("Equation: Y_guess = exp(%f) * exp(%f * X)\n", a0, a1);
  printf("Alpha = %f, Beta = %f\n", alpha, beta);

  // correlation coeficient
  double st, sr;
  for (size_t i = 0; i < size; i++) {
    sr += pow(Y[i] - eval(alpha, beta, X[i]), 2);
    st += pow(Y[i] - mu_y, 2);
  }

  cout << "st = " << st << endl;
  cout << "sr = " << sr << endl;

  // standard error
  double std_err = sqrt(abs(sr / (size - 2)));
  cout << "Standard error: " << std_err << '\n';

  // Determination coefficient
  double r2 = (st - sr) / st;
  cout << "Determination coefficient: " << r2 << '\n';
  cout << "Correlation coefficient: " << sqrt(abs(r2)) << '\n';

  cout << "a1: " << a1 << "\t" << "a0: " << a0 << endl;

  return new double[2] {alpha, beta};
}

int main(int argc, char const *argv[]) {
  if (argc < 4) {
    cerr << "Invalid number of arguments" << '\n';
    return -1;
  }

  ifstream x_stream(argv[1], ios::in);
  ifstream y_stream(argv[2], ios::in);

  istringstream ss(argv[3]);
  int size;
  if (!(ss >> size)) {
    cerr << "Invalid number " << argv[3] << '\n';
  }

  if (!x_stream.is_open() | !y_stream.is_open()) {
    cerr << "Unable to open file\n";
    return -1;
  }

  double *X = new double[size];
  double *Y = new double[size];

  // Read files
  cout << "| X\t| Y |" << '\n';
  cout << "| :---- | :---- |" << '\n';
  for (int i = 0; x_stream && y_stream && i < size; i++) {
    double x, y;
    x_stream >> x;
    y_stream >> y;

    X[i] = x;
    Y[i] = y;

    cout << "| " << x << "\t| " << y << " |" << endl;
  }
  x_stream.close();
  y_stream.close();

  auto a = exponential_regression(X, Y, size);
  cout << "porcentaje para 5000 horas: " << eval(a[0], a[1], 5000) << endl;

  return 0;
}

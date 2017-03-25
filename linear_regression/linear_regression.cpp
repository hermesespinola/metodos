#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double *linear_regression(unsigned n, string x_file, string y_file) {
  double s_x, s_y, s_x2, s_p;

  double *xs = (double *) calloc(n, sizeof(double));
  double *ys = (double *) calloc(n, sizeof(double));

  ifstream x_stream(x_file);
  ifstream y_stream(y_file);

  cout << "X" << "\t" << "y" << endl;
  cout << "----" << "\t" << "----" << endl;
  for (size_t i = 0; x_stream && y_stream && i < n; i++) {
    double x, y;
    x_stream >> x;
    y_stream >> y;

    xs[i] = x;
    ys[i] = y;

    s_x += x;
    s_y += y;
    s_x2 += x * x;
    s_p += x * y;

    cout << x << "\t" << y << endl;
  }

  x_stream.close();
  y_stream.close();

  double mu_x = s_x / n;
  double mu_y = s_y / n;

  double a1 = (n * s_p - s_x * s_y) / (n * s_x2 - s_x * s_x);
  double a0 = (mu_y - a1 * mu_x);

  // correlation coeficient
  double st, sr;
  for (unsigned i = 0; i < n; i++) {
    sr += pow(ys[i] - a0 - a1 * xs[i], 2);
    st += pow(ys[i] - mu_y, 2);
  }

  // standard error
  double std_err = sqrt(sr / (n - 2));
  std::cout << "Standard error: " << std_err << '\n';

  // Determination coefficient
  double r2 = (st - sr) / st;
  std::cout << "Determination coefficient: " << r2 << '\n';
  std::cout << "Correlation coefficient: " << sqrt(r2) << '\n';

  cout << "a1: " << a1 << "\t" << "a0: " << a0 << endl;

  return new double[2] {a0, a1};
}

int main(int argc, char const *argv[]) {
  linear_regression(15, "temp_diff.txt", "kWh.txt");

  return 0;
}

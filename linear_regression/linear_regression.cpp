#include <iostream>
#include <fstream>

using namespace std;

double linear_regression(double n, string x_file, string y_file) {
  double s_x, s_y, s_x2, s_p, avg_x, avg_y, a0, a1;


  ifstream x_stream(x_file);
  ifstream y_stream(y_file);

  cout << "X" << "\t" << "y" << endl;
  cout << "----" << "\t" << "----" << endl;
  for (size_t i = 0; x_stream && y_stream && i < n; i++) {
    double x, y;
    x_stream >> x;
    y_stream >> y;

    s_x += x;
    s_y += y;
    s_x2 += x * x;
    s_p += x * y;

    cout << x << "\t" << y << endl;
  }

  x_stream.close();
  y_stream.close();

  avg_x = s_x / n;
  avg_y = s_y / n;

  a1 = (n * s_p - s_x * s_y) / (n * s_x2 - s_x * s_x);
  a0 = (avg_y - a1 * avg_x);

  cout << "a1: " << a1 << "\t" << "a0: " << a0 << endl;

  return a0;
}

int main(int argc, char const *argv[]) {
  linear_regression(15, "temp_diff.txt", "kWh.txt");

  return 0;
}

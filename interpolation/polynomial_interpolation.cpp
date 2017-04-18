#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return log(x);
}

void polynomial(double x) {
    double x0 = 1, x1 = 4, x2 = 6;
    
    double b0 = f(x0);
    double b1 = (f(x1) - f(x0)) / (x1 - x0);
    double b2 = ((f(x2) - f(x1) / (x2 - x1)) - b2) / (x2 - x0);

    double a0 = b0 - b1 * x0 + b2 * x0 * x1;
    double a1 = b1 - b2 * x0 - b2 * x1;
    double a2 = b2;
    
    double y = b0 + b1 * (x - x0) + b2 * (x - x0) * (x - x1);
    cout << "y = " << y << endl;

    // error

}

double newton_interpolation(double *X, double x, unsigned n) {
    double *F = new double[n];

    for (unsigned i = 0; i < n; i++) {
        F[i] = f(X[i]);
    }

    for (int j = 1; j < n; j++)
        for (int k = n - 1; k >= j; k--)
            F[k] = (F[k] - F[k - 1]) / (X[k] - X[k - j]);

    double fn = 0;
    double a = 1;
    for (int i = 0; i < n; i++) {
        fn += a * F[i];
        a *= (x - X[i]);
    }

    return fn;
}

int main() {
    unsigned n = 3;
    double X[] = {1, 4, 6};
    double x = 5;
    cout << f(x) << endl;
    cout << newton_interpolation(X, x, n) << endl;
    return 0;
}
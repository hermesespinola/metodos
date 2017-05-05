#include <iostream>
#include <cmath>

using namespace std;

double newton_interpolation(double X[], double Y[], double x, unsigned n) {
    double *F = new double[n];

    for (unsigned i = 0; i < n; i++) {
        F[i] = Y[i];
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
    int n = 5;
    double X[] = {1, 2, 2.5, 4, 7};
    double Y[] = {1, 0.5, 0.4, 0.25, 0.14};

    cout << newton_interpolation(X, Y, 3, n) << endl;
    return 0;
}
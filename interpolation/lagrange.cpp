#include <iostream>

double L(unsigned i, double x, double X[], unsigned n) {
    double result = 1;
    for (unsigned j = 0; j < n; j++)
        if (i != j) result *= (x - X[j]) / (X[i] - X[j]);
        
    return result;
}

double lagrange(double x, double X[], double Y[], unsigned n) {
    double result = 0;
    for (unsigned i = 0; i < n; i++)
        result += L(i, x, X, n) * Y[i];

    return result;
}

int main() {
    double X[] = {1, 4, 6};
    double Y[] = {0, 1.386294, 1.791760};
    unsigned n = 3;
    double x = 2;
    std::cout << lagrange(x, X, Y, n) << '\n';
    return 0;
}

#include <iostream>

using namespace std;

double sum(double *values, int from, int to, int step) {
    double s = 0;
    for (int i = from; i < to; i += step) {
        s += values[i];
    }
    return s;
}

double simpson_third(double *F, double a, double b, int n) {
    return (b - a) / (n * 3) * (F[0] + 4 * sum(F, 1, n - 2, 2) + 2 * sum(F, 2, n - 3, 2) + F[n-1]);
}

double simpson_eighth(double *F, double a, double b, int n) {
    return (b- a) / 8 * (F[0] + 3 * F[1] + 3 * F[2] + F[3]);
}

int main() {
    double a[] = {3, 4, 5, 6, 7};
    cout << "cosa: " << simpson_third(a, 3, 7, 5) << endl;
    return 0;
}
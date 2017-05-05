#include <iostream>
#include <cmath>

using namespace std;

typedef double function_call (double x);

enum rayman_side { l, r };

double cosa(double x) {
    return 0.2 + 25 * x - 200 * pow(x, 2) + 675 * pow(x, 3) - 900 * pow(x, 4) + 400 * pow(x, 5);
}

double f(double x) {
    return exp(pow(x, 2));
}

double trapecio(function_call f, double a, double b, unsigned n) {
    double h = (b - a) / n;
    double sum = 0;
    for (double x = a + h; x < b; x += h) {
        sum += f(x);
    }
    return h * (f(a) + 2 * sum + f(b)) / 2;
}

double rayman(function_call f, double a, double b, unsigned num_rect, rayman_side side) {
    double S = 0;
    double delta_x = (b - a) / num_rect;
    if (side == r) {
        for (double x = a + delta_x; x <= b; x += delta_x) {
            S += f(x) * delta_x;
        }
    } else {
        for (double x = a; x + delta_x <= b; x += delta_x) {
            S += f(x) * delta_x;
        }
    }
    return S;
}

int main() {
    cout << "trapecio: e^x^2 from 0 to 1: " << trapecio(f, 0, 1, 4) << endl;
    return 0;
}

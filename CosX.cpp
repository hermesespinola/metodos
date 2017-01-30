#include <iostream>
#include <cmath>

#define ITER 50
#define MINERR 1E-10

using namespace std;

double factorial(double n) {
    double f = 1;
    for (int c = 2; c <= n; c++) {
	f = f*c;
    }
    return f;
}

double coseno(double x) {
    double result = 0;
    for (int i = 0; i < ITER; i++ ) {
	result = result + pow(-1, i) * pow(x, 2*i) / factorial(2*i);
    }
    return result;
}

int testCoseno(double x) {
    double result, e_abs, e_rel;
    int i;
    do {
        result = result + pow(-1, i) * pow(x, 2*i) / factorial(2*i);
        e_abs = cos(x) - result;
        e_rel = abs(e_abs / cos(x));
        i++;
    } while (e_rel < MINERR);
    return i;
}


int main() {
    double x;
    cout << "Angulo en radianes: ";
    cin >> x;
    double h = coseno(x);
    double y = cos(x);
    cout << "cos aprox: " << h << endl;
    cout << "cos real: " << y << endl;
    cout << "Error absoluto: " << y - h << endl;
    cout << "Error relativo: " << (y - h) / h << endl;
    cout << "Min iterations until convergence: " << testCoseno(x) << endl;
}


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct complex_number {
  double r, i;
};

void synthetic_division(vector<double> &pol, vector<double> &res, vector<double> &aux, double r, double s) {
  int i, j, degree = pol.size() - 1;

  for (i = degree, j = 0; i >= 0; i--, j++) {
    if (i == degree) {
      res[j] = pol[j];
    } else if (i == degree - 1) {
      res[j] = pol[j] + res[j - 1] * r;
    } else {
      res[j] = pol[j] + res[j - 1] * r + res[j - 2] * s;
    }
  }

  for (i = degree, j = 0; i >= 0; i--, j++) {
    if (i == degree) {
      aux[j] = res[j];
    } else if (i == degree - 1) {
      aux[j] = res[j] + aux[j - 1] * r;
    } else {
      aux[j] = res[j] + aux[j - 1] * r + aux[j - 2] * s;
    }
  }
}

void bairstow(vector<double> &pol, vector<complex_number*> &roots, double pi, double qi, double err) {
  while (pol.size() > 3) {
    vector<double> res(pol.size(), 0.0);
    vector<double> aux(pol.size(), 0.0);

    double p = pi;
    double q = qi;
    double dp = 0.0;
    double dq = 0.0;
    double error_p = 1.0;
    double error_q = 1.0;

    do {
      // Initialize aux arrays to 0
      for (unsigned i = 0; i < res.size(); i++) {
        res[i] = 0;
        aux[i] = 0;
      }

      synthetic_division(pol, res, aux, p, q);

      cout << "Result (B) array: {";
      for (unsigned i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size()-1){
          cout << ", ";
        }
      }
      cout << "}" << endl << endl;

      int deg = pol.size() - 1;
      double d = aux[deg - 2] * aux[deg - 2] - aux[deg - 1] * aux[deg - 3];
      dp = (-res[deg - 1] * aux[deg - 2] + res[deg] * aux[deg - 3]) / d;
      dq = (-aux[deg - 2] * res[deg] + aux[deg - 1] * res[deg - 1]) / d;

      error_p = dp / p;
      error_q = dq / q;
      p += dp;
      q += dq;
    } while (abs(error_p) > err && abs(error_q) > err);

    cout << endl;
    // 2 Roots
    double det = pow(p, 2) + 4 * q;

    complex_number *r1 = new complex_number;
    complex_number *r2 = new complex_number;
    if (det < 0) {
      r1->r = p / 2;
      r1->i = sqrt(-det) / 2;
      r2->r = p / 2;
      r2->i = -sqrt(-det) / 2;
    }
    else {
      r1->r = (p + sqrt(det)) / 2;
      r1->i = 0;
      r2->r = (p - sqrt(det)) / 2;
      r2->i = 0;
    }
    roots.push_back(r1);
    roots.push_back(r2);

    res = vector<double>(pol.size(), 0.0);
    aux = vector<double>(pol.size(), 0.0);

    synthetic_division(pol, res, aux, p, q);

    // Adjust polynomial
    for (unsigned i = 0; i < pol.size() - 2; i++) {
      pol[i] = res[i];
    }
    pol.pop_back();
    pol.pop_back();


    cout << "Polynomial Update" << endl << "------------------------------" << endl;
    cout << "{";
    for (unsigned i = 0; i < pol.size(); i++) {
      cout << pol[i];
      if (i < pol.size()-1){
        cout << ", ";
      }
    }
    cout << "}" << endl;
  }


  if (pol.size() == 3) {
    int p = -pol[1];
    int q = -pol[2];
    double det = pow(p, 2) + 4 * q;

    complex_number *r1 = new complex_number;
    complex_number *r2 = new complex_number;
    if (det < 0) {
      r1->r = p / 2;
      r1->i = sqrt(-det) / 2;
      r2->r = p / 2;
      r2->i = -sqrt(-det) / 2;
    }
    else {
      r1->r = (p + sqrt(det)) / 2;
      r1->i = 0;
      r2->r = (p - sqrt(det)) / 2;
      r2->i = 0;
    }
    roots.push_back(r1);
    roots.push_back(r2);
  }
  else if (pol.size() == 2) {
    complex_number *r = new complex_number;
    r->r = -pol[1] / pol[0];
    r->i = 0;
    roots.push_back(r);
  }
}

void print_pol(double *coeficients, unsigned degree) {
  for (unsigned i = 0; i < degree - 1; i++) {
    cout << coeficients[i] << "x^" << degree - i - 1 << " + ";
  }
  cout << coeficients[degree - 1] << '\n';
}

int main(int argc, char const *argv[]) {
  double coeficients[] = {6.7, -4, 0, 3.2, -3, 8, 1.2, 2, 0, 1, -4};
  vector<double> polynomial(coeficients, coeficients + sizeof(coeficients) / sizeof(double));
  vector<complex_number *> roots;
  double p = -1, q = -1;

  cout << "Original polynomial: ";
  print_pol(coeficients, polynomial.size());

  cout << '\n' << "Bairstow: " << '\n';
  bairstow(polynomial, roots, p, q, 1e-4);

  std::cout << "Roots:" << '\n';
  for (unsigned i = 0; i < roots.size(); i++) {
    if (roots[i]->i != 0) {
      cout << roots[i]->r << " + " << roots[i]->i << "i" << endl;
    }
    else {
        cout << roots[i]->r << endl;
    }
  }
}

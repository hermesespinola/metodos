#include <iostream>

double access(double* matrix, unsigned width, unsigned i, unsigned j) {
  return matrix[i + j * width];
}

double *gs(unsigned width, double* A, double* B, double error_th) {
  // solutions array
  double *solutions = (double *) calloc(width, sizeof(double));
  double tempSol;

  unsigned iter = 0;
  bool has_error = true;
  while (has_error) {
    has_error = false;

    // calculate approximation
    for (size_t pivot = 0; pivot < width; pivot++) {

      // calculate each solution
      double sum = 0;
      for (size_t i = 0; i < width; i++) {
        if (i == pivot) continue;
        sum =  access(A, width, pivot, i) * solutions[i];
      }

      tempSol = (B[pivot] - sum) / access(A, width, pivot, pivot);

      // calculate iterative error
      has_error = has_error || abs(tempSol - solutions[pivot]) >= error_th;
      solutions[pivot] = tempSol;
    }
    iter++;
  }

  std::cout << "Iteraciones: " << iter << '\n';
  return solutions;
}

int main(int argc, char const *argv[]) {
  unsigned width = 3;
	double A[] = {2,-1,1,1,2,-1,1,1,1};
	double B[] = {1,26,30};

  double* sol = gs(width, A, B, 1e-5);

  for (size_t i = 0; i < width; i++) {
    std::cout << sol[i] << ", ";
  } std::cout << std::endl;

  return 0;
}

#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

#ifndef MINERR
#define MINERR 1e-15
#endif

double* gs(int A[][3], int B[], int l) {

	double *sol = (double *) calloc(l, sizeof(int));
	double *OS = (double *) calloc(l, sizeof(int));
	double *E = (double *) calloc(l, sizeof(int));

	int c = 0;

	bool error = false;

	while(!error) {
		for (int i = 0; i < l; ++i) {
			double sum = 0;
			for (int j = 0; j < l; ++j) {
				if (j != i)
				{
					sum += A[i][j]*sol[j];
				}
			}
			OS[i] = sol[i];
			sol[i] = (B[i] - sum)/A[i][i];

			E[i] = (sol[i]-OS[i]);
		}

		for (int i = 0; i < l; ++i) {
			if(abs(E[i]) > MINERR) {
				break;
			}
			error = true;
		}
		c++; // pun intended
	}

	return sol;
}

int main(){
	int A[][3] = {{2,-1,1},
										{1,2,-1},
										{1,1,1}};
	int B[] = {7,6,12};

	double *sol = gs(A, B, 3);

	for (size_t i = 0; i < 3; i++) {
		cout << sol[i] << ", ";
	} cout << endl;

	return 0;
}

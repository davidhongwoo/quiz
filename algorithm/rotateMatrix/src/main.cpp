#include <iostream>

using namespace std;

int getElement(size_t N, int* matrix, size_t row, size_t col) {
	return *(matrix + row * N + col);
}

void printMatrix(size_t N, int* matrix) {
	cout << "----------------------" << endl;
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			cout << *(matrix + i*N + j) << "  ";
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
}

void rotateMatrix(size_t N, int* matrix) {
	for (size_t depth = 0; depth < N/2; depth++) {
		size_t n = N - depth;
		for (size_t j = depth; j < n - 1; j++) {
			int tmp = matrix[depth*N + j];
			// matrix[depth*N + j] = matrix[(N-j-1)*N + depth];
			// matrix[(N-j-1)*N + depth] = matrix[(N-1)*N + N-j-1];
			// matrix[(N-1)*N + N-j-1] = matrix[j*N + N-1];
			// matrix[j*N + N-1] = tmp;
			matrix[depth*N + j] = matrix[(N-j-1)*N + depth];
			matrix[(N-j-1)*N + depth] = matrix[(n-1)*N + N-j-1];
			matrix[(n-1)*N + N-j-1] = matrix[j*N + n-1];
			matrix[j*N + n-1] = tmp;
		}
		printMatrix(N, matrix);
	}
}


int main(int argc, char** argv) {
	const size_t N = 5;
	// int src[16] = { 1,  2,  3,  4,
	// 				5,  6,  7,  8,
	// 				9,  10, 11, 12,
	// 				13, 14, 15, 16};
	int src[N*N] = {1,  2,  3,  4,  5,
					6,  7,  8,  9,  10,
					11, 12, 13, 14, 15,
					16, 17, 18, 19, 20,
					21, 22, 23, 24, 25};

	cout << "sizeof matrix: " << sizeof(src) << endl;
	printMatrix(N, src);
	rotateMatrix(N, src);
	printMatrix(N, src);

	return 0;
}

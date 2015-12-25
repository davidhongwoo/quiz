#include <iostream>
#include <cstring>

using namespace std;

void print(int n) {
	cout << n << " ";
}

int main(int argc, char** argv) {
	int N = -1;
	if (argc != 2)
		return -1;

	N = atoi(argv[1]);
	if (N < 0)
		return -2;

	int distance = N;
	int rotateCount = N/2 + N%2;

	int target = -1;

	cout << endl;
#if 1 
	// start from right below, ccw
	distance = N;
	rotateCount = N/2 + N%2;
	target = N*N;
	while (rotateCount > 0) {
		print(target);

		distance--;
		for (int i = 0; i < distance; i++) {
			target = target - N;
			print(target);
		}
		for (int i = 0; i < (distance); i++) {
			print(--target);
		} for (int i = 0; i < (distance); i++) {
			target = target + N;
			print(target);
		}
		distance--;
		for (int i = 0; i < (distance); i++) {
			print(++target);
		}

		target = target - N;
		rotateCount--;
	}
#endif

	cout << endl;
#if 1
	// start from left below, cw
	distance = N;
	rotateCount = N/2 + N%2;
	target = N*(N-1)+1;
	while (rotateCount > 0) {
		print(target);

		distance--;
		for (int i = 0; i < distance; i++) {
			target = target - N;
			print(target);
		}
		for (int i = 0; i < (distance); i++) {
			print(++target);
		}
		for (int i = 0; i < (distance); i++) {
			target = target + N;
			print(target);
		}
		distance--;
		for (int i = 0; i < (distance); i++) {
			print(--target);
		}

		target = target - N;
		rotateCount--;
	}
#endif

	cout << endl;
#if 1
	// start from upper right of inside grid to out, cw
	distance = N;
	rotateCount = N/2 + N%2;
	target = -1;
	if (N%2) {
		target = (N*N + 1) / 2;
		distance = 2;
	} else {
		target = (N*N - N + 2) / 2;
		distance = 3;
	}
	rotateCount--;
	print(target);
	if ((N%2) == 0) {
		target = target + N;
		print(target);
		print(--target);
		target = target - N;
		print(target);
	}

	while (rotateCount > 0) {
		target = target - N;
		for (int i = 0; i < distance; i++) {
			if (i != 0)
				target++;
			print(target);
		}
		for (int i = 0; i < distance; i++) {
			target = target + N;
			print(target);
		}
		for (int i = 0; i < distance; i++) {
			print(--target);
		}
		for (int i = 0; i < distance; i++) {
			target = target - N;
			print(target);
		}

		rotateCount--;
		distance = distance + 2;
	}
#endif
	cout << endl;

	return 0;
}


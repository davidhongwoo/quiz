#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isSorted() {
	int N = 0;
	cin >> N;
	if (N > 100)
		return false;

	char matrix[N][N];
	for (int i = 0; i < N; i++) {
		cin >> &matrix[i][0];
		sort(&matrix[i][0], &matrix[i][N]);
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] < matrix[i-1][j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int num_testcase = 0;
	cin >> num_testcase;
	if (num_testcase > 100)
		return -1;

	vector<bool> results;
	while (num_testcase-- > 0) 
		results.push_back(isSorted());
	for (bool r : results)
		cout << (r ? "YES" : "NO") << endl;
	return 0;
}

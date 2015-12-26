#include <iostream>
#include <cstring>
#include <list>
#include <map>

using namespace std;

int pow(int n, int power) {
	if (n == 0)
		return 0;
	if (power == 0)
		return 1;
	int result = n;
	while (--power > 0) {
		result = result * n;
	}
	return result;
}

int main(int argc, char** argv) {
	if (argc != 2)
		return -1;

	int N = -1;
	N = atoi(argv[1]);
	int originN = N;

	map<int, int> primeFactorMap;

	int divider = 2;
	while (true) {
		int count = 0;
		while (true) {
			if ((N % divider) == 0) {
				N = N / divider;
				count++;
			} else {
				break;
			}
		}
		if (count != 0) {
			primeFactorMap.insert(make_pair(divider, count));
		}
		if ((divider >= originN) || (N == 1))
			break;
		divider++;
	}

	int in = 1;
	int out = 1;
	map<int, int>::iterator iter = primeFactorMap.begin();
	map<int, int>::iterator endIter = primeFactorMap.end();
	for (; iter != endIter; ++iter) {
		if ((iter->second % 2) == 0) {
			out = out * pow(iter->first, iter->second / 2);
		} else {
			if (iter->second != 1) {
				out = out * pow(iter->first, iter->second / 2);
			}
			in = in * iter->first;
		}
	}

	cout << out << " * sqrt(" << in << ")" << endl;

	return 0;
}


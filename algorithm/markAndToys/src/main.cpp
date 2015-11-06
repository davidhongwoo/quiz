#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	vector<int> prices;
	for(int i = 0; i < n; i++) {
		int p; cin >> p;
		prices.push_back(p);
	}

	sort(prices.begin(), prices.end());
	long count = 0;
	for(int i = 0; i < n; i++) {
		if (prices[i] < k) {
			k = k - prices[i];
			count++;
		} else {
			break;
		}
	}

	cout << count << endl;

	return 0;
}

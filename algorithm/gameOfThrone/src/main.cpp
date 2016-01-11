#include <iostream>
#include <string>
using namespace std;

// https://www.hackerrank.com/challenges/game-of-thrones

void flip(int& i, char c) {
	if (i & (1 << c))
		i = i & (~(1 << c));
	else
		i = i | (1 << c);
}

int main() {
	string s;
	cin>>s;

	int index = 0;
	for (auto a : s)
		flip(index, a - 'a');

	int count = 0;
	for (size_t i = 0; i < 32; ++i) {
		if (0x1 & (index >> i)) {
			if (++count > 1) {
				break;
			}
		}
	}

	if (count > 1)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}

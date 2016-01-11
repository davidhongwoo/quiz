#include <iostream>
#include <vector>
#include <string>

using namespace std;

// https://www.hackerrank.com/challenges/the-love-letter-mystery

size_t calcMinimumOperation(const string& str) {
	size_t length = str.length();
	size_t count = length / 2;
	size_t result = 0;
	const char* p = str.c_str();
	for (size_t i = 0; i < count; ++i) {
		size_t diff = 0;
		if (p[i] > p[length - 1 - i]) 
			diff = p[i] - p[length - 1 - i];
		else
			diff = p[length - 1 - i] - p[i];
		result += diff;
	}

	return result;
}

int main(int argc, char** argv) {
	size_t count = 0;
	cin >> count;
	vector<string> inputs;
	while (count--) {
		string temp;
		cin >> temp;
		inputs.push_back(temp);
	}

	for (auto str : inputs)
		cout << calcMinimumOperation(str) << endl;

	return 0;
}

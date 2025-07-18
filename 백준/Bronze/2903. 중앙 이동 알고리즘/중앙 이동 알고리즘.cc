#include <iostream>

using namespace std;

int main() {

	int n;
	int dot = 2;

	cin >> n;

	for (int i = 0; i < n; i++) {
		dot += dot - 1;
	}

	int result = dot * dot;
	cout << result;

	return 0;
}

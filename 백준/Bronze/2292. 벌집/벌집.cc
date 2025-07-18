#include <iostream>

using namespace std;

int main() {

	int n;
	int max = 1;
	int cnt = 0;
	int result = 0;

	cin >> n;

	while (n > max) {
		cnt++;
		max = max + cnt * 6;
	}

	result = cnt + 1;

	cout << result;

	return 0;
}

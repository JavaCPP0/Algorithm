#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;

	cin >> n;
	long long count = n;

	for (long long i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			count = count - count / i;

			while (n % i == 0) {
				n /= i;
			}
		}
	}

	if (n > 1) {
		count = count - count / n;
	}

	cout << count;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	long long min, max;

	cin >> min >> max;

	vector<bool> a(max - min+1, true);

	for (long long i = 2; i * i <= max; i++) {
		long long pow = i * i;
		long long start_idx = min/pow;
		if (min % pow != 0) start_idx++;

		for (long long j = start_idx; j * pow <= max; j++) {
			a[pow * j - min] = false;
		}

	}

	for (long long i = 0; i <= max-min; i++) {
		if (a[i]) {
			count++;
		}
	}

	cout << count;
	return 0;
}
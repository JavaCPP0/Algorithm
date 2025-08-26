#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<int> arr(m + 1);

	for (int i = 2; i < m + 1; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(m); i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= m; j+=i) {
			arr[j] = 0;
		}
	}
	for (int i = n; i < m+1;i++) {
		if (arr[i] != 0) {
			cout << arr[i] << "\n";
		}
	}

	return 0;
}
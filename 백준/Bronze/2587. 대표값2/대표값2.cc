#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> arr(5);
	int total = 0;

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	sort(arr.begin(), arr.end());
	cout << total / 5 << "\n";
	cout << arr[2];

	return 0;
}
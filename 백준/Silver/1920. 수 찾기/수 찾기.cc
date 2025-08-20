#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		int target;
		bool found = false;

		cin >> target;

		int start = 0, end = arr.size() - 1;

		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (arr[mid] > target) {
				end = mid - 1;

			}
			else if (arr[mid] < target) {
				start = mid + 1;
			}
			else {
				found = true;
				break;
			}
		}

		if (found) {
			cout << "1" << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	}

	return 0;
}
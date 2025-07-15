#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    int n,m;
	int count = 0;
    cin >> n >> m;

    vector<int> arr(n);

	int start_index = 0;
	int end_index = n-1;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

    sort(arr.begin(), arr.end());

	while (start_index < end_index) {
		int sum = arr[start_index] + arr[end_index];
		if (sum < m) {
			start_index++;
		}

		else if (sum > m) {
			end_index--;
		}

		else {
			count++;
			start_index++;
			end_index--;
		}
	}

	cout << count << "\n";

    return 0;
}

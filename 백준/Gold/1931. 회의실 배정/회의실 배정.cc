#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		//종료시간 기준으로 정렬하기 위해 반대로 저장
		arr[i].first = end;
		arr[i].second = start;
	}

	sort(arr.begin(), arr.end());

	int count = 0;
	int end = -1;

	for (int i = 0; i < n; i++) {
		if (arr[i].second >= end) {
			count++;
			end = arr[i].first;
		}
	}

	cout << count;

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int data1 = 0, data2 = 0;
	int sum = 0;
	int n;

	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;

		pq.push(data);
	}



	while (pq.size() != 1) {
		data1 = pq.top();
		pq.pop();

		data2 = pq.top();
		pq.pop();

		sum += data1 + data2;
		pq.push(data1 + data2);
	}

	cout << sum << "\n";

	return 0;
}
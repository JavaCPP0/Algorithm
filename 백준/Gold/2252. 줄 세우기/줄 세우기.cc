#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n + 1);
	vector<int> count(n + 1, 0);
	queue<int> q;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		count[b]++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (count[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int data = q.front();
		q.pop();
		cout << data << " ";
		for (int next : arr[data]) {
			count[next]--;
			if (count[next] == 0) {
				q.push(next);
			}
		}
	}

	return 0;
}
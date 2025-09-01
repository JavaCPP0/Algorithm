#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
void BFS(vector<vector<int>>& arr, vector<int>& visited, int i);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, start;

	cin >> n >> m >> k >> start;

	vector<vector<int>> arr(n+1);
	vector<int> visited(n + 1, -1);
	vector<int> answer;

	for (int i = 1; i < m+1; i++) {
		int x, y;
		cin >> x >> y;

		arr[x].push_back(y);
	}

	BFS(arr, visited, start);

	for (int i = 0; i <= n; i++) {
		if (visited[i] == k) {
			answer.push_back(i);
		}
	}

	if (answer.empty()) cout << -1;
	else {
		sort(answer.begin(), answer.end());
		for (int num : answer) {
			cout << num << "\n";
		}
	}

	return 0;
}

void BFS(vector<vector<int>>& arr, vector<int>& visited, int num) {
	queue<int> q;
	q.push(num);
	visited[num]++;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i : arr[temp]) {
			if (visited[i] == -1) {
				visited[i] = visited[temp] + 1;
				q.push(i);
			}
		}
	}

}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
void BFS(vector<vector<int>>& arr, vector<int>& visited, vector<int>& answer, int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int maxVal = 0;

	cin >> n >> m;

	vector<vector<int>> arr(n + 1);
	vector<int> visited(n + 1, false);
	vector<int> answer(n + 1, 0);


	for (int i = 1; i < m + 1; i++) {
		int x, y;
		cin >> x >> y;

		arr[x].push_back(y);
	}



	for (int i = 0; i < n + 1; i++) {
		fill(visited.begin(), visited.end(), false);
		BFS(arr, visited, answer, i);
	}


	for (int i = 0; i < n + 1; i++) {
		if (answer[i] >= maxVal) {
			maxVal = answer[i];
		}
	}

	for (int i = 0; i < n + 1; i++) {
		if (answer[i] == maxVal) {
			cout << i << " ";
		}
	}


	return 0;
}

void BFS(vector<vector<int>>& arr, vector<int>& visited, vector<int>& answer, int num) {
	queue<int> q;
	q.push(num);
	visited[num] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i : arr[temp]) {
			if (visited[i] == 0) {
				visited[i] = true;
				answer[i] += 1;
				q.push(i);
			}
		}
	}

}

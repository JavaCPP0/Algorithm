#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& arr, vector<bool>& visited, int i);
void BFS(vector<vector<int>>& arr, vector<bool>& visited, int i);


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int node,edge,start;
	cin >> node >> edge >> start;

	vector<vector<int>> arr(node + 1);
	vector<bool> visited(node +1,false);

	for (int i = 0; i < edge; i++) {
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}

	for (int i = 1; i <= node; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	DFS(arr, visited, start);
	cout << "\n";

	fill(visited.begin(), visited.end(), false);

	BFS(arr, visited, start);

	return 0;
}


void DFS(vector<vector<int>>& arr, vector<bool>& visited, int num) {
	if (visited[num]) return;
	visited[num] = true;
	cout << num << " ";

	for (int i : arr[num]) {
		DFS(arr,visited,i);
	}
}

void BFS(vector<vector<int>>& arr, vector<bool>& visited, int num) {
	queue<int> q;
	q.push(num);
	visited[num] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		cout << temp << " ";

		for (int i : arr[temp]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}

}

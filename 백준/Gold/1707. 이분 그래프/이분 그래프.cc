#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& arr, vector<bool>& visited, vector<int>& check, int num);
static bool isEven;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	vector<vector<int>> arr;
	vector<bool> visited;
	vector<int> check;

	for (int i = 0; i < k; i++) {
		int node, edge;
		cin >> node >> edge;

		arr.resize(node + 1);
		visited.resize(node + 1, false);
		check.resize(node + 1);
		isEven = true;

		for (int j = 0; j < edge; j++) {
			int a, b;
			cin >> a >> b;

			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		for (int j = 1; j <= node; j++) {
			if (isEven) {
				DFS(arr, visited, check, j);
			}
			else {
				break;
			}
		}

		if (isEven) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

		for (int j = 0; j <= node; j++) {
			arr[j].clear();
			visited[j] = false;
			check[j] = 0;
		}
	}

	return 0;
}

void DFS(vector<vector<int>>& arr, vector<bool>& visited, vector<int>& check, int num) {
	visited[num] = true;

	for (int i : arr[num]) {
		if (!visited[i]) {
			check[i] = (check[num] + 1) % 2;
			DFS(arr, visited, check, i);
		}
		else if (check[num] == check[i]) {
			isEven = false;
		}
	}
}
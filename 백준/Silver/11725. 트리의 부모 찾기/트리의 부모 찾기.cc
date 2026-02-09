#include <iostream>
#include <vector>

using namespace std;

void DFS(int num);
vector<int> answer;
vector<bool> visited;
vector<vector<int>> tree;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	visited.resize(n + 1);
	answer.resize(n + 1);
	tree.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;

		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	DFS(1);

	for (int i = 2; i <= n; i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}

void DFS(int num) {
	visited[num] = true;

	for (int i : tree[num]) {
		if (!visited[i]) {
			answer[i] = num;
			DFS(i);
		}

	}
}

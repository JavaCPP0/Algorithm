#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> tree;
static vector<bool> visited;
static int n;
static int deletedNode;
static int answer;

void DFS(int num);

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	tree.resize(n);
	visited.resize(n, false);
	int root = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num != -1) {
			tree[i].push_back(num);
			tree[num].push_back(i);
		}
		else {
			root = i;
		}
	}

	cin >> deletedNode;

	if (deletedNode == root) {
		cout << 0 << "\n";
	}
	else {
		DFS(root);
		cout << answer << "\n";
	}

	return 0;
}

void DFS(int num) {
	visited[num] = true;
	int cNode = 0;

	for (int i : tree[num]) {
		if (visited[i] == false && i != deletedNode) {
			cNode++;
			DFS(i);
		}
	}
	if (cNode == 0) {
		answer++;
	}
}
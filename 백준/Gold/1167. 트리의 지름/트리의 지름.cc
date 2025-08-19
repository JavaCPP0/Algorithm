#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static int v;

typedef pair<int, int> edge;

static vector<vector<edge>> arr;
static vector<bool> visited;
static vector<int> dist;

void BFS(int num);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int max = 1;

	cin >> v;

	arr.resize(v+1);

	for (int i = 0; i < v; i++) {
		int node;
		cin >> node;

		while (true) {
			int target, dis;
			cin >> target;
			if (target == -1) break;
			cin >> dis;

			arr[node].push_back({ target, dis });
		}
	}

	dist = vector<int>(v + 1, 0);
	visited = vector<bool>(v + 1, false);

	BFS(1);

	for (int i = 2; i <= v; i++) {
		if (dist[max] < dist[i]) {
			max = i;
		}
	}

	fill(dist.begin(), dist.end(), 0);
	fill(visited.begin(), visited.end(), false);
	BFS(max);

	sort(dist.begin(), dist.end());
	cout << dist[v];

	return 0;
}

void BFS(int num) {
	queue<int> q;
	q.push(num);
	visited[num] = true;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (edge i : arr[temp]) {
			if (!visited[i.first]) {
				visited[i.first] = true;
				q.push(i.first);
				dist[i.first] = dist[temp] + i.second;
			}
		}
	}

}

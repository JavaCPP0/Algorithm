#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void munion(int a, int b);
int find(int a);
vector<int> parent;

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
};


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, E;
	cin >> N >> E;

	int usedEdge = 0;
	int answer = 0;

	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	parent.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		pq.push(Edge{s,e,v});
	}

	while (usedEdge < N - 1) {
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e)) {
			munion(now.s, now.e);
			answer += now.v;
			usedEdge++;
		}
	}
	cout << answer;

	return 0;
}

void munion(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int find(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}
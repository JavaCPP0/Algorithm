#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

typedef tuple<int, int, int> edge;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, e;

	cin >> n >> e;

	vector<edge> edges;
	vector<long long> distance(n + 1, LLONG_MAX);


	for (int i = 0; i < e; i++) {
		int start, end, time;
		cin >> start >> end >> time;

		edges.push_back(make_tuple(start, end, time));
	}

	distance[1] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < e; j++) {
			int start = get<0>(edges[j]);
			int end = get<1>(edges[j]);
			int time = get<2>(edges[j]);
			if (distance[start] != LONG_MAX && distance[end] > distance[start] + time) {
				distance[end] = distance[start] + time;
			}
		}
	}

	bool cycle = false;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < e; j++) {
			int start = get<0>(edges[j]);
			int end = get<1>(edges[j]);
			int time = get<2>(edges[j]);
			if (distance[start] != LONG_MAX && distance[end] > distance[start] + time) {
				cycle = true;
			}
		}
	}

	if (!cycle) {
		for (int i = 2; i <= n; i++) {
			if (distance[i] == LLONG_MAX) {
				cout << "-1" << "\n";
			}
			else {
				cout << distance[i] << "\n";
			}
		}
	}
	else {
		cout << -1 << "\n";
	}



	return 0;
}
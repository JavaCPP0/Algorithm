#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 10000001));

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i == j) dist[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
			int s, e, v;

			cin >> s >> e >> v;
			if(dist[s][e]>v) dist[s][e] = v;
	}

	for (int k = 1; k < n + 1; k++) {
		for (int j = 1; j < n + 1; j++) {
			for (int i = 1; i < n + 1; i++) {
				if (dist[j][i] > dist[j][k] + dist[k][i])dist[j][i] = dist[j][k] + dist[k][i];
			}
		}
	}


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (dist[i][j] == 10000001) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
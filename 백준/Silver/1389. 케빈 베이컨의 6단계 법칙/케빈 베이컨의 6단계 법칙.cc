#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dist[101][101];

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = 10000001;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		int s, e;
		cin >> s >> e;

		dist[s][e] = 1;
		dist[e][s] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int min = 100001;
	int answer = -1;

	for (int i = 1; i <= N; i++) {
		int total = 0;
		for (int j = 1; j <= N; j++) {
			total += dist[i][j];
		}
		if (min > total) {
			min = total;
			answer = i;
		}
	}

	cout << answer;

	return 0;

}
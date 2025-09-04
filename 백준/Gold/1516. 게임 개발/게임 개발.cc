#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> arr(n + 1);
	vector<int> timeCost(n + 1);
	vector<int> indegree(n + 1);
	vector<int> answer(n + 1,0);
	queue<int> q;


	for (int i = 1; i <= n; i++) {
		cin >> timeCost[i];
		while (true) {
			int a;
			cin >> a;
			if (a != -1) {
				arr[a].push_back(i);
				indegree[i]++;
			}
			else {
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int data = q.front();
		q.pop();
		for (int next : arr[data]) {
			indegree[next]--;
			answer[next] = max(answer[next],answer[data] + timeCost[data]);
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << answer[i] + timeCost[i] << "\n";
	}


	return 0;
}
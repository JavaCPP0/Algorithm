#include <iostream>
#include <vector>

using namespace std;

void unite(vector<int>& arr, int a, int b);
int find(vector<int>& arr, int a);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	vector<int> arr(n + 1);
	int node[201][201];
	int route[1001];

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> node[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> route[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (node[i][j] == 1) {
				unite(arr,i, j);
			}
		}
	}

	for (int i = 2; i <= m; i++) {
		if (find(arr, route[1]) != find(arr, route[i])) {
			cout << "NO" << "\n";
			return 0;
		}
	}

	cout << "YES" << "\n";

	return 0;
}

void unite(vector<int>& arr, int a, int b) {
	a = find(arr, a);
	b = find(arr, b);

	if (a != b) {
		arr[b] = a;
	}
}

int find(vector<int>& arr, int a) {
	if (arr[a] == a)return a;
	return arr[a] = find(arr, arr[a]);
}
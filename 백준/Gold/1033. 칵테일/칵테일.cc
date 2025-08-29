#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

long long gcd(long long a, long long b);
void DFS(vector<vector<tuple<int, int, int>>>& arr, vector<bool>& visited, vector<long long>& d, int i);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	long long lcm = 1;
	vector<vector<tuple<int, int, int>>> arr(n);
	vector<bool> visited(n, false);
	vector<long long> d(n);

	for (int i = 0; i < n - 1; i++) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		arr[a].push_back(make_tuple(b, p, q));
		arr[b].push_back(make_tuple(a, q, p));

		lcm *= (1LL * p * q) / gcd(p, q); // 1LL 곱해 안전
	}

	d[0] = lcm;
	DFS(arr, visited, d, 0);

	long long mgcd = d[0];

	for (int i = 1; i < n; i++) {
		mgcd = gcd(mgcd, d[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << d[i] / mgcd << ' ';
	}

	return 0;
}

void DFS(vector<vector<tuple<int, int, int>>>& arr, vector<bool>& visited, vector<long long>& d, int num) {

	visited[num] = true;

	for (tuple<int, int, int> i : arr[num]) {
		int next = get<0>(i);

		if (!visited[next]) {
			d[next] = d[num] * get<2>(i) / get<1>(i);
			DFS(arr, visited, d, next);
		}
	}
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else {
		return gcd(b, a % b);
	}
}

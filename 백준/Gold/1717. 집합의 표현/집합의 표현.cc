#include <iostream>
#include <vector>

using namespace std;

void unite(vector<int>& arr, int a, int b);
int find(vector<int>& arr,int a);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	vector<int> arr(n + 1);

	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int req, a, b;

		cin >> req >> a >> b;

		switch (req)
		{
		case 0:
			unite(arr,a, b);
			break;
		case 1:
			if (find(arr, a) == find(arr, b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

void unite(vector<int>& arr,int a, int b) {
	a = find(arr,a);
	b = find(arr,b);
	if (a != b) {
		arr[b] = a;
	}
}

int find(vector<int>& arr,int a) {
	if (arr[a] == a) return a;
	return arr[a] = find(arr,arr[a]);
}
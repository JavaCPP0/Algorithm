#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n;

	unordered_map<int, int> um;

	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;

		um[card]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int card;
		cin >> card;
		cout << um[card] << " ";
	}

	return 0;
}
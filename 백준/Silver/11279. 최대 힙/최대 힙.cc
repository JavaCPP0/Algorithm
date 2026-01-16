#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	priority_queue<int> pq;


	cin >> n;

	for (int i = 0; i < n; i++) {
		int cal;
		cin >> cal;

		if (cal == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				int max = pq.top();
				pq.pop();
				cout << max << "\n";
			}
		}
		else {
			pq.push(cal);
		}
	}

	return 0;
}
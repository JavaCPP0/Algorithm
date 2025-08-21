#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int zero = 0, one = 0;
	int sum = 0;
	int n;

	cin >> n;

	priority_queue<int> ppq;
	priority_queue<int, vector<int>, greater<int>> mpq;

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;

		if (data == 0) zero++;
		else if (data == 1) one++;
		else if (data < 0) mpq.push(data);
		else ppq.push(data);
	}

	while (ppq.size() > 1) {
		int data1 = ppq.top();
		ppq.pop();

		int data2 = ppq.top();
		ppq.pop();

		sum += data1 * data2;
	}

	if (!ppq.empty()) {
		sum += ppq.top();
		ppq.pop();
	}

	while (mpq.size() > 1) {
		int data1 = mpq.top();
		mpq.pop();

		int data2 = mpq.top();
		mpq.pop();

		sum += data1 * data2;
	}

	if (!mpq.empty()) {
		if (zero>0) {
			mpq.pop();
		}
		else {
			sum += mpq.top();
			mpq.pop();
		}
	}


	cout << sum + one << "\n";

	return 0;
}
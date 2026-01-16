#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int m;
		cin >> m;

		priority_queue<int> maxH; //중앙보다 낮은 값
		priority_queue<int, vector<int>, greater<int>> minH; //중앙보다 큰 값
		vector<int> mids;

		for (int j= 0; j < m; j++) {
			int num;
			cin >> num;

			// 중앙값 이하는 maxH에 중앙값 초과는 minH에

			if (maxH.empty() || num <= maxH.top()) maxH.push(num);
			else minH.push(num);

			if (maxH.size() < minH.size()) {
				maxH.push(minH.top());
				minH.pop();
			}
			else if (maxH.size() > minH.size() + 1) {
				minH.push(maxH.top());
				maxH.pop();
			}

			// 홀수번째 수 라면 사이즈가 큰 큐의 top을 출력

			if (j % 2 == 0) {
				mids.push_back(maxH.top());
			}
		}
		cout << mids.size() << "\n";
		for (int k = 0; k < (int)mids.size(); k++) {
			cout << mids[k];
			if ((k + 1) % 10 == 0 || k == (int)mids.size() - 1) cout << "\n";
			else cout << " ";
		}
	}


	return 0;
}
#include <iostream>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int count = 1;//자기 자신을 카운트하고 시작
	int start_index = 1;
	int end_index = 1;
	int sum = 1;

	while (end_index != n) {
		if (sum == n) {
			count++;
			end_index++;
			sum = sum + end_index;
		}

		else if (sum > n) {
			sum = sum - start_index;
			start_index++;
		}

		else {
			end_index++;
			sum = sum + end_index;
		}
	}
	cout << count << "\n";

	return 0;
}
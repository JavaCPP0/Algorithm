#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, v;

	cin >> a >> b >> v;

	// v에서 a를 한 번 미리 빼고 a-b로 나눈값에 +1

	v = v - a;
	int result = v / (a - b) + 1;
	if (v % (a - b) > 0) {
		result++;
	}
	
	cout << result;

	return 0;
}

#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	// 첫번째 숫자로 두번째 숫자가 나누어 떨어지면 factor
	// 두번째 숫자로 첫번째 숫자가 나누어 떨어지면 multiple
	// 둘다 아니라면(나머지가 남으면) neither

	while (true) {
		cin >> a >> b;
		if (a <= 0 || b <= 0) break;

		if (a < b && b%a ==0) {
			cout << "factor" << "\n";
		}
		else if(a > b && a % b == 0){
			cout << "multiple" << "\n";
		}
		else {
			cout << "neither" << "\n";
		}
	}

	return 0;
}

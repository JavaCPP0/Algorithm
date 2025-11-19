#include <iostream>
#include <string>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int count = 0, x = 666;

	cin >> n;

	while (true) {
		if (to_string(x).find("666") != string::npos) count++;
		
		if (count == n) {
			cout << x;
			return 0;
		}
		x++;

	}

	return 0;
}
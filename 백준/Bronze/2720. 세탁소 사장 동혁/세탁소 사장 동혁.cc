#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {

	int t;


	cin >> t;

	vector<int> arr(t);

	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	for (int j = 0; j < t; j++) {

		string result = "";

		result += to_string(arr[j] / 25) + " ";
		arr[j] = arr[j] % 25;

		result += to_string(arr[j] / 10) + " ";
		arr[j] = arr[j] % 10;

		result += to_string(arr[j] / 5) + " ";
		arr[j] = arr[j] % 5;

		result += to_string(arr[j] / 1) + " ";
		arr[j] = arr[j] % 1;

		cout << result << endl;
	}

	return 0;
}
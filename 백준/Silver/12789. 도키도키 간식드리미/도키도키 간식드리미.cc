#include <iostream>
#include <stack>

using namespace std;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> stack;
	int n, turn = 1;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == turn) {
			turn++;
			while (!stack.empty() && stack.top() == turn) {
				stack.pop();
				turn++;
			}
		}
		else {
			stack.push(num);
		}
	}

	for (int i = 0; i < stack.size(); i++) {
		if (stack.top() == turn) {
			stack.pop();
			turn++;
		}
		else {
			cout << "Sad";
			return 0;
		}
	}

	cout << "Nice";

	return 0;
}
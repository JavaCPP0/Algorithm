#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;

	cin >> x;

	int sum = 1;
	int preSum = 0;
	int line = 1;
	int index = 0;
	int numerator = 0;
	int denominator = 0;

	while (x > sum) { // 몇번째줄인가?
		line++;
		preSum = sum;
		sum += line;
	}

	index = x - preSum; // i번째줄 몇번째인가?

	if (line % 2 == 0) {//짝수라면 분자는 증가하고 분모는 감소한다.
		numerator = index;
		denominator = line - index + 1;
	}
	else {// 홀수라면 분모는 증가하고 분자는 감소한다.
		numerator = line - index + 1;
		denominator = index;
	}

	cout << numerator << "/" << denominator;

	return 0;
}

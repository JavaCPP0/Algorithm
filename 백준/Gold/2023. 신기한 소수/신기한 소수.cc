#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void DFS(int num, int pv, int& n);
bool isPrime(int num);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[4] = { 2, 3, 5, 7 };

	for (int a: arr) {
			DFS(a, 1, n);
	}

	return 0;
}

bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void DFS(int num,int pv, int& n){
	if (pv == n) {
		//자릿수가 n개면 출력
		if (isPrime(num)) {
			cout << num << "\n";
		}
		return;
	}

	for (int i = 1; i < 10; i += 2) {
		if (isPrime(num*10+i)) {
			DFS(num * 10 + i, pv+1,n);
		}
	}
}

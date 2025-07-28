#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int start = 0, end = 0, sum = 0, count = 0;

    vector<int> arr;

    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            arr.push_back(i);
        }
    }

    while (true) {
        if (sum == n) { // 구간합이 n과 같다면
            count++;
            sum -= arr[start]; // 구간합에서 맨 왼쪽 원솟값을 빼고
            start++; // 시작 포인터 한칸 오른쪽으로 이동
        }
        else if(sum<n){// 구간합이 n보다 작으면
            if (end == arr.size()) break; // 끝 포인터가 마지막에 도달하면 종료
            sum += arr[end]; //구간합에 끝 포인터 원솟값을 넣고
            end++; //끝 포인터 한칸 오른쪽으로 이동
        }
        else {
            sum -= arr[start]; // 구간합에서 맨 왼쪽 원솟값을 빼고
            start++; // 시작 포인터 한칸 오른쪽으로 이동
        }
    }

    cout << count;

    return 0;
}

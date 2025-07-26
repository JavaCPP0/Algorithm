#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int start = 0, end = 0, sum = 0;
    int min_len = n+1;

    while (true) {
        if (sum >= s) { // 구간합이 s이상이면
            min_len = min(min_len, end - start); //최솟값 저장
            sum -= arr[start]; // 구간합에서 맨 왼쪽 원솟값을 빼고
            start++; // 시작 포인터 한칸 오른쪽으로 이동
        }
        else if (end == n) break; // 끝 포인터가 마지막에 도달하면 종료
        else {// 구간합이 s보다 작으면
            sum += arr[end]; //구간합에 끝 포인터 원솟값을 넣고
            end++; //끝 포인터 한칸 오른쪽으로 이동
        }
    }

    if (min_len == n+1) cout << 0;
    else cout << min_len;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int start = 1; //최소간격
    int end = arr[n - 1] - arr[0]; // 최대 간격
    int ans = 0;

    while (start <= end) {
        int mid = (start + end) / 2; // 거리 후보
        int count = 1;               // 첫 집에 이미 설치했다고 가정
        int pre = arr[0];            // 마지막 설치 위치

        for (int i = 1; i < n; i++) {
            if (arr[i] - pre >= mid) {
                count++;
                pre = arr[i];
            }
        }

        if (count >= c) {      // mid 간격으로 C개 이상 설치 가능
            ans = mid;         // 이 mid는 후보
            start = mid + 1;   // 더 큰 간격 시도
        }
        else {               // C개 설치 못 함 → 간격 줄이기
            end = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}

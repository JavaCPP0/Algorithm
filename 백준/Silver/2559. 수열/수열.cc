#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int max = INT_MIN;

    cin >> n >> k;

    int front = 1;
    int back = front + k - 1;

    vector<int> arr(n+1);

    //온도들의 누적합 벡터를 만들고
    //투포인터를 사용하는데 간격은 k만큼
    // max값을 업데이트하며 슬라이딩 윈도우
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }

    while (back <= n) {
        if (max < arr[back] - arr[front - 1]) max = arr[back] - arr[front - 1];
        front ++ ;
        back++;
    }

    cout << max;

    return 0;
}

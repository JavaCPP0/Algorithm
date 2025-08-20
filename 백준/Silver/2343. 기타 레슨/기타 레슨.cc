#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int start = 0;
    int end = 0;

    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (start < arr[i]) {
            start = arr[i];
        }
        end += arr[i];
    }

    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0;
        int count = 1;

        for (int i = 0; i < n; i++) {
            if (sum + arr[i] > mid) {
                count++;
                sum = arr[i];
            }
            else {
                sum += arr[i];
            }
        }

        if (count <= m) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << start << "\n";

    return 0;
}

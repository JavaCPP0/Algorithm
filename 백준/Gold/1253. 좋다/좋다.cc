#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int result = 0;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int k = 0; k < n; k++) {
        int start = 0;
        int end = n - 1;
        
        while (start < end) {
            int sum = arr[start] + arr[end];

            if (sum > arr[k]) end--;
            else if (sum < arr[k]) start++;
            else {
                if (start != k && end != k) {
                    result++;
                    break;
                }
                else if (start == k) start++;
                else if (end == k) end--;

            }
        }
    }

    cout << result;

    return 0;
}

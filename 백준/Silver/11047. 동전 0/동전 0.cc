#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    int result = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (coin[i] <= k) {
            int quotient = k / coin[i];
            result += quotient;
            k -= quotient * coin[i];
        }
    }

    cout << result << "\n";
    return 0;
}

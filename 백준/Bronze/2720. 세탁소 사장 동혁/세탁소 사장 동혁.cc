#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> units = { 25, 10, 5, 1 };

    vector<int> arr(t);
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }

    for (int j = 0; j < t; j++) {
        int value = arr[j];
        for (int unit : units) {
            cout << value / unit << " ";
            value %= unit;
        }
        cout << '\n';
    }

    return 0;
}

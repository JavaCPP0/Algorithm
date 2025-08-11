#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[10001] = {0};

    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        arr[num]++;
    }

    for (int i = 0; i < 10001; i++) {
        if (arr[i] != 0) {
            for (int j = 0; j < arr[i]; j++) {
                cout << i << "\n";
            }
        }
    }

}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int total = 0;
    cin >> n;

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i < n; i++) {
        int key = p[i];
        int j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = key;
    }

    for (int i = 1; i < n; i++) {
        p[i] = p[i] + p[i - 1];
    }

    for (int i = 0; i < n; i++) {
        total += p[i];
    }

    cout << total;

}
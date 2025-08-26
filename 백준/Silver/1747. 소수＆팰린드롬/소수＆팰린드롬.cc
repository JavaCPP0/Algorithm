#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    const int MAXN = 10000000;

    vector<int> arr(MAXN + 1, 0);


    for (int i = 2; i <= MAXN; i++) arr[i] = i;

    int limit = sqrt(MAXN);
    for (int i = 2; i <= limit; i++) {
        if (arr[i] == 0) continue;
        for (long long j = 1LL * i * i; j <= MAXN; j += i) {
            arr[j] = 0;
        }
    }

    for (int i = max(n, 2); i <= MAXN; i++) {
        if (arr[i] == 0) continue;

        string s = to_string(i);
        int start = 0, end = (int)s.size() - 1;
        bool ok = true;
        while (start < end) {
            if (s[start] != s[end]) { ok = false; break; }
            start++; end--;
        }
        if (ok) {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}

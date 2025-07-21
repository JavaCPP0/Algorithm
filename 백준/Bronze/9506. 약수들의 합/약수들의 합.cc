#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while (true) {
        int n;
        int result = 0;
        cin >> n;

        if (n == -1) return 0;

        vector<int> df;  // 작은 약수
        vector<int> db;   // 큰 약수

        int root = static_cast<int>(sqrt(n));

        for (int i = 1; i <= root; i++) {
            if (n % i == 0) {
                df.push_back(i);
                if (i != n / i) {
                    db.insert(db.begin(), n / i);
                }
            }
        }

        df.insert(df.end(), db.begin(), db.end());

        for (int i = 0; i < df.size() - 1; i++) {
            result += df[i];
        }

        if (result == n) {

            cout << n << " " << "=";
            for (int i = 0; i < df.size() - 1; i++) {
                cout << " " << df[i] << " ";
                if (i + 1 < df.size() - 1) cout << "+";
            }
        }
        else {
            cout << n << " is NOT perfect.";
        }
        cout << "\n";
    }

    return 0;
}

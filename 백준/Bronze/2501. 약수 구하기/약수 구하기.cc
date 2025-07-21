#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

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

    if (df.size() >= k) {
        cout << df[k - 1];
    }
    else {
        cout << "0";
    }



    return 0;
}

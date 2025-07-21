#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    for (int i = 0; i < d.size(); i++) {
        if (!isPrime(d[i])) {
            d.erase(d.begin() + i);
            i--;
        }
    }

    cout << d.size();

    return 0;
}

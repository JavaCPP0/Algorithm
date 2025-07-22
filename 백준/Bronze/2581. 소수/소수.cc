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
    int m, n;
    int min = 0;
    int sum = 0;

    cin >> m >> n;

    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            sum += i;
            if (min == 0) min = i;
        }
    }

    if (min == 0) cout << -1;
    else {
        cout << sum << "\n";
        cout << min;
    }

    return 0;
}
